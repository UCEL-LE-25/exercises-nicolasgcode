#pragma once
#include "./typedefs.h"
#include <stdio.h>

void loginMenu(Session *session);

void mainMenu(Session *session);

void tableMenu(Session *session);

void manageTableMenu(FILE *table, char *filePath);

void showMenu();

void tableCreationMenu();

void reportMenu();
