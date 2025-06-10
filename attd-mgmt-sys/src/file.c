#include "include/file.h"
#include "include/table.h"
#include "include/date.h"
#include "include/menus.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

File createFile(char *subject, Student students[],
                int classSize, int days)
{

  File file;

  char filename[256];
  char file_path[1024];

  Date date = getTodaysDate();

  printf("subject %s ", subject);
  printf("date: %02d%02d%04d", date.month, date.day, date.year);

  snprintf(filename, sizeof(filename), "%s%s_%02d%02d%04d.txt",
           ATTD_PREFIX, subject, date.month, date.day, date.year);
  printf("filename %s", filename);

  strncpy(file.name, filename, sizeof(file.name) - 1);
  file.name[sizeof(file.name) - 1] = '\0';

  strncpy(file.location, DEFAULT_FILE_PATH, sizeof(file.location) - 1);

  snprintf(file_path, sizeof(file_path), "%s%s", file.location, file.name);

  createPhysicalFile(file_path);

  writeFile(file_path, students, classSize, days);

  backupFile(&file, file_path);

  return file;
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

void writeFile(char *file_path, Student students[], int classSize, int days)
{
  FILE *fp = fopen(file_path, "w");
  if (fp)
  {
    fprintf(fp, "StudentId,Name,LastName");
    for (int day = 1; day <= days; day++)
    {
      fprintf(fp, ",D%d", day);
    }
    fprintf(fp, "\n");

    for (int i = 0; i < classSize; i++)
    {
      fprintf(fp, "%d,%s,%s", students[i].studentId,
              students[i].name, students[i].lastName);

      for (int j = 0; j < days; j++)
      {
        fprintf(fp, ",%d", students[i].attendance[j]);
      }
      fprintf(fp, "\n");
    }
    fclose(fp);
  }
  else
  {
    perror("Error writing to file");
    abort();
  }
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

int loadStudentsFromFile(FILE *file, Student *students, int *classSize, int *days)
{
  rewind(file);

  char line[512];
  int studentCount = 0;
  int dayCount = 0;

  // Leer encabezado
  if (!fgets(line, sizeof(line), file))
  {
    printf("No se pudo leer el encabezado\n");
    return 0;
  }

  char *token = strtok(line, ",");
  int columnIndex = 0;
  while (token != NULL)
  {
    if (columnIndex >= 3)
      dayCount++;
    token = strtok(NULL, ",");
    columnIndex++;
  }

  while (fgets(line, sizeof(line), file))
  {
    if (studentCount >= MAX_STUDENTS)
      break;

    char *token = strtok(line, ",");
    if (!token)
      break;
    students[studentCount].studentId = atoi(token);

    token = strtok(NULL, ",");
    if (!token)
      break;
    strcpy(students[studentCount].name, token);

    token = strtok(NULL, ",");
    if (!token)
      break;
    strcpy(students[studentCount].lastName, token);

    for (int d = 0; d < dayCount; d++)
    {
      token = strtok(NULL, ",\n");
      if (!token)
      {
        printf("Faltan días de asistencia en línea %d\n", studentCount + 1);
        return 0;
      }
      students[studentCount].attendance[d] = atoi(token);
    }

    studentCount++;
  }

  *classSize = studentCount;
  *days = dayCount;
  rewind(file); // Opcional: por si se quiere usar el archivo de nuevo
  return 1;
}

void deleteFile(FILE *table, char *filePath)
{
  fclose(table);

  if (remove(filePath) == 0)
  {
    printf("Archivo eliminado correctamente: %s\n", filePath);
  }
  else
  {
    perror("Error al eliminar el archivo");
  }
}
