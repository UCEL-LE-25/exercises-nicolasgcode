#include "include/menus.h"
#include "include/typedefs.h"
#include <string.h>
int main(void) {

  Session session = {NULL};

  loginMenu(&session);
  return 0;
}
