#pragma once
#include "suite.h"
#include <stdbool.h>

void addPages(Suite *suite);

void changeState(Suite *suite);

bool isValidOpt(int opt);

bool isValidQuantity(int pages);

bool isValidState(int state);

bool isActive(int opt, Suite *suite);
