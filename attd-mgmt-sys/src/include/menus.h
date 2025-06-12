#pragma once
#include "./typedefs.h"
#include <stdio.h>

void program(Session *session, loadedUsers *users);

void mainMenu(Session *session);

void tableMenu(Session *session);

void manageTableMenu(FILE *table, char *filePath, Session *session);

void showMenu();

void tableCreationMenu();

void reportMenu();
