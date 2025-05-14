#pragma once

#include "constants.h"

typedef struct {
  int units;
  float prodCost = PROD_PROD_COST;
  float salePrice = PROD_SALE_PRICE;
} Product;

typedef struct {
  Product products[AVBL_PRODUCTS];
  float rentability;
} ProdPlant;

typedef struct {
  ProdPlant plant1;
  ProdPlant plant2;
  ProdPlant plant3;
} Company;

