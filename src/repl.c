#include "repl.h"

void repl()
{
  cons_cell *cell;
  char buffer[BUFFER_SIZE];

  mode(2);
  printf("%cZlisp%c - %c 2013 Duncan Bayne. Free Software (see http://wtfpl.net/).\r\n\r\n", 24, 24, 164);

  while (1) {
    printf("zlisp> ");
    readline(buffer, BUFFER_SIZE);
    printf("\r\n");
    cell = parse(buffer);
    print_cell(buffer, cell);
    printf("%s\r\n", buffer);
    free_cell(cell);
  }
}
