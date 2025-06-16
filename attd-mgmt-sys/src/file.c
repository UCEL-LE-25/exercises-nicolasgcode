#include "include/file.h"
#include "include/table.h"
#include "include/date.h"
#include "include/menus.h"
#include "include/typedefs.h"
#include "include/user.h"
#include "include/helpers.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <ctype.h>

File createFile(AttdTable *table)
{

  File file;

  char filename[256];
  char file_path[1024];

  printf("subject %s ", table->subject);
  printf("date: %02d%02d%04d", table->createdAt.month, table->createdAt.day, table->createdAt.year);

  snprintf(filename, sizeof(filename), "%s%s_%02d%02d%04d.txt",
           ATTD_PREFIX, table->subject, table->createdAt.month, table->createdAt.day, table->createdAt.year);
  printf("filename %s", filename);

  strncpy(file.name, filename, sizeof(file.name) - 1);
  file.name[sizeof(file.name) - 1] = '\0';

  strncpy(file.location, DEFAULT_FILE_PATH, sizeof(file.location) - 1);

  snprintf(file_path, sizeof(file_path), "%s%s", file.location, file.name);

  createPhysicalFile(file_path);

  writeFile(file_path, table);

  backupFile(&file, file_path);

  return file;
}

void createUserFile()
{
  clearScreen();

  File file;

  char filename[256];
  char file_path[1024];

  snprintf(filename, sizeof(filename), "%s.dat",
           USERS_FILE);

  strncpy(file.name, filename, sizeof(file.name) - 1);
  file.name[sizeof(file.name) - 1] = '\0';

  strncpy(file.location, DEFAULT_USER_FILE_PATH, sizeof(file.location) - 1);

  snprintf(file_path, sizeof(file_path), "%s%s", file.location, file.name);

  printf("Creating file: %s\n", file_path);

  FILE *fp = fopen(file_path, "wb");

  if (!fp)
  {
    perror("Error creating user file");
    abort();
  }

  User root = createDefaultUser();
  fwrite(&root, sizeof(User), 1, fp);
  fclose(fp);
  printf("Default root user created: %s\n", root.username);
}

int backupFile(File *file, char *file_path)
{

  char bkp_path[1024];

  snprintf(bkp_path, sizeof(bkp_path), "%s%s%s", DEFAULT_BKP_PATH, file->name,
           BACKUP_SUFFIX);

  FILE *src = fopen(file_path, "r");

  FILE *dst = fopen(bkp_path, "w");

  int ch;

  while ((ch = fgetc(src)) != EOF)
  {
    fputc(ch, dst);
  }

  fclose(src);
  fclose(dst);

  printf("Backup created: %s\n", bkp_path);

  return 0;
}

void createPhysicalFile(char *file_path)
{

  printf("Creating file: %s\n", file_path);

  FILE *fp = fopen(file_path, "a");

  if (fp)
    fclose(fp);
  else
  {
    perror("Error creating file");
    abort();
  }
}

void writeUserFile(User user)
{
  char file_path[1024];
  snprintf(file_path, sizeof(file_path), "%s%s.dat",
           DEFAULT_USER_FILE_PATH, USERS_FILE);

  FILE *file = fopen(file_path, "ab");
  if (!file)
  {
    printf("Error opening users file.\n");
    return;
  }

  fwrite(&user, sizeof(User), 1, file);

  fclose(file);
}

void writeFile(char *file_path, AttdTable *table)
{
  FILE *fp = fopen(file_path, "w");
  if (!fp)
  {
    perror("Error writing to file");
    abort();
  }

  fprintf(fp, "StudentId,Name,LastName");
  for (int day = 1; day <= table->days; day++)
  {
    fprintf(fp, ",D%d", day);
  }
  fprintf(fp, "\n");

  for (int i = 0; i < table->classSize; i++)
  {
    fprintf(fp, "%d,%s,%s", table->students[i].studentId,
            table->students[i].name, table->students[i].lastName);

    for (int j = 0; j < table->days; j++)
    {
      fprintf(fp, ",%d", table->students[i].attendance[j]);
    }
    fprintf(fp, "\n");
  }

  fclose(fp);
}

void getAllFiles()
{
  DIR *d = opendir(DEFAULT_FILE_PATH);
  if (!d)
  {
    perror("Could not open directory");
    return;
  }

  struct dirent *entry;
  char subjects[100][50];
  int count = 0;

  while ((entry = readdir(d)) != NULL)
  {
    char fullpath[512];
    snprintf(fullpath, sizeof(fullpath), "%s%s", DEFAULT_FILE_PATH, entry->d_name);

    struct stat st;
    if (stat(fullpath, &st) == 0 && S_ISREG(st.st_mode) &&
        strstr(entry->d_name, ATTD_PREFIX) == entry->d_name)
    {
      char copy[256];
      strcpy(copy, entry->d_name);

      char *token = strtok(copy, "_");
      token = strtok(NULL, "_");

      int exists = 0;
      for (int i = 0; i < count; i++)
      {
        if (strcmp(subjects[i], token) == 0)
        {
          exists = 1;
          break;
        }
      }

      if (!exists && token)
      {
        strcpy(subjects[count], token);
        count++;
      }
    }
  }

  closedir(d);

  if (count == 0)
  {
    printf("No tables found.\n");
    return;
  }

  printf("Available tables:\n");
  for (int i = 0; i < count; i++)
  {
    printf("* %s\n", subjects[i]);
  }
}

FILE *getFile(const char *subject, char *outPath)
{
  DIR *d = opendir(DEFAULT_FILE_PATH);
  if (!d)
  {
    perror("Could not open directory");
    return NULL;
  }

  struct dirent *entry;
  char targetFile[512] = "";
  time_t latestTime = 0;

  while ((entry = readdir(d)) != NULL)
  {
    if (strstr(entry->d_name, ATTD_PREFIX) == entry->d_name)
    {
      char copy[256];
      strcpy(copy, entry->d_name);

      char *token = strtok(copy, "_");
      token = strtok(NULL, "_");

      if (token && strcmp(token, subject) == 0)
      {
        char fullpath[512];
        snprintf(fullpath, sizeof(fullpath), "%s%s", DEFAULT_FILE_PATH, entry->d_name);

        struct stat st;
        if (stat(fullpath, &st) == 0)
        {
          if (st.st_mtime > latestTime)
          {
            latestTime = st.st_mtime;
            strcpy(targetFile, fullpath);
          }
        }
      }
    }
  }

  closedir(d);

  if (strlen(targetFile) == 0)
  {
    printf("Table not found for: '%s'.\n", subject);
    return NULL;
  }

  printf("Table found '%s':\n\n", subject);

  FILE *f = fopen(targetFile, "r");
  if (!f)
  {
    perror("Could not open file");
    return NULL;
  }

  strcpy(outPath, targetFile);

  return f;
}

int loadStudentsFromFile(FILE *table, AttdTable *attdTable)
{
  rewind(table);

  char line[512];
  int studentCount = 0;
  int dayCount = 0;

  if (!fgets(line, sizeof(line), table))
  {
    printf("Couldn't read header.\n");
    return 0;
  }

  int columnCount = 0;
  char *token;
  char headerCopy[512];
  strcpy(headerCopy, line);

  token = strtok(headerCopy, ",\r\n");
  while (token != NULL)
  {
    columnCount++;
    token = strtok(NULL, ",\r\n");
  }

  if (columnCount < 3)
  {
    printf("Invalid header, columns missing.\n");
    return 0;
  }

  dayCount = columnCount - 3;

  while (fgets(line, sizeof(line), table))
  {
    if (studentCount >= MAX_STUDENTS)
      break;

    char *lineCopy = strdup(line);
    if (!lineCopy)
    {
      perror("Couldn't read line.");
      return 0;
    }

    token = strtok(lineCopy, ",\r\n");
    if (!token)
    {
      free(lineCopy);
      continue;
    }
    attdTable->students[studentCount].studentId = atoi(token);

    token = strtok(NULL, ",\r\n");
    if (!token)
    {
      free(lineCopy);
      continue;
    }
    strcpy(attdTable->students[studentCount].name, token);

    token = strtok(NULL, ",\r\n");
    if (!token)
    {
      free(lineCopy);
      continue;
    }
    strcpy(attdTable->students[studentCount].lastName, token);

    for (int d = 0; d < dayCount; d++)
    {
      token = strtok(NULL, ",\r\n");
      if (!token)
      {
        printf("There are days missing for student: #%d\n", studentCount + 1);
        free(lineCopy);
        return 0;
      }
      attdTable->students[studentCount].attendance[d] = atoi(token);
    }

    free(lineCopy);
    studentCount++;
  }

  attdTable->classSize = studentCount;
  attdTable->days = dayCount;

  rewind(table);
  return 1;
}

void deleteFile(FILE *table, char *filePath)
{
  char confirm;

  fclose(table);

  printf("Do you really want to delete the file? (y/n): ");
  scanf(" %c", &confirm);

  confirm = tolower(confirm);

  if (confirm == 'y')
  {
    if (remove(filePath) == 0)
    {
      printf("File deleted successfully: %s\n", filePath);
    }
    else
    {
      perror("Error deleting file");
    }
  }
}

int loadUsersFromFile(loadedUsers *loaded)
{
  char file_path[1024];
  snprintf(file_path, sizeof(file_path), "%s%s.dat",
           DEFAULT_USER_FILE_PATH, USERS_FILE);

  FILE *file = fopen(file_path, "rb");
  if (!file)
  {
    printf("Couldn't read file.\n");
    loaded->count = 0;
    return 0;
  }

  loaded->count = 0;
  while (fread(&loaded->users[loaded->count], sizeof(User), 1, file) == 1 &&
         loaded->count < MAX_USERS)
  {
    loaded->count++;
  }

  fclose(file);
  return loaded->count;
}

void saveUsersToFile(loadedUsers *users)
{
  char file_path[1024];
  snprintf(file_path, sizeof(file_path), "%s%s.dat",
           DEFAULT_USER_FILE_PATH, USERS_FILE);

  FILE *file = fopen(file_path, "wb");
  if (!file)
  {
    printf("Error opening users file for saving.\n");
    return;
  }

  fwrite(users->users, sizeof(User), users->count, file);

  fclose(file);
}
