#include <stdio.h>
#include "amsgraph.h"
#include "amstext.h"
#include "repl.h"

int main(void)
{
  mode(2);
  printf("%cZlisp%c - %c 2013 Duncan Bayne. Free Software (see http://wtfpl.net/).\r\n\r\n", 24, 24, 164);
  repl();
  return 0;
}
