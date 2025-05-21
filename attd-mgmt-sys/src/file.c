#include "include/file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

File createFile(char *name) {

  File file;

  strncpy(file.name, name, sizeof(file.name) - 1);
  strncpy(file.location, DEFAULT_FILE_PATH, sizeof(file.location) - 1);

  char file_path[1024];
  snprintf(file_path, sizeof(file_path), "%s%s", file.location, file.name);

  printf("Creating file: %s\n", file_path);

  FILE *fp = fopen(file_path, "a");

  if (fp)
    fclose(fp);
  else {
    perror("Error creating file");
    abort();
  }

  printf("File created: %s file at: %s\n", file.name, file.location);

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
