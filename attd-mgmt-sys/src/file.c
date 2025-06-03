#include "include/file.h"
#include "include/date.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

File createFile(char *subject, int id) {

  File file;

  char filename[256];
  char file_path[1024];

  Date date = getTodaysDate();

  printf("subject %s ", subject);
  printf("date: %02d%02d%04d", date.month, date.day, date.year);

  snprintf(filename, sizeof(filename), "%03d_%s%s_%02d%02d%04d.txt", id,
           ATTD_PREFIX, subject, date.month, date.day, date.year);
  printf("filename %s", filename);

  strncpy(file.name, filename, sizeof(file.name) - 1);
  file.name[sizeof(file.name) - 1] = '\0';

  strncpy(file.location, DEFAULT_FILE_PATH, sizeof(file.location) - 1);

  snprintf(file_path, sizeof(file_path), "%s%s", file.location, file.name);

  createPhysicalFile(file_path);

  backupFile(&file, file_path);

  return file;
}

int backupFile(File *file, char *file_path) {

  char bkp_path[1024];

  snprintf(bkp_path, sizeof(bkp_path), "%s%s%s", DEFAULT_BKP_PATH, file->name,
           BACKUP_SUFFIX);

  FILE *src = fopen(file_path, "r");

  FILE *dst = fopen(bkp_path, "w");

  int ch;

  while ((ch = fgetc(src)) != EOF) {
    fputc(ch, dst);
  }

  fclose(src);
  fclose(dst);

  printf("Backup created: %s\n", bkp_path);

  return 0;
}

void createPhysicalFile(char *file_path) {

  printf("Creating file: %s\n", file_path);

  FILE *fp = fopen(file_path, "a");

  if (fp)
    fclose(fp);
  else {
    perror("Error creating file");
    abort();
  }
}
