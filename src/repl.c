#include "repl.h"

void repl()
{
  cons_cell *cell;
  char *buffer;

  mode(2);
  printf("%cZlisp%c - %c 2013 Duncan Bayne. Free Software (see http://wtfpl.net/).\r\n\r\n", 24, 24, 164);

  buffer = malloc(BUFFER_SIZE);

  while (1) {
    printf("zlisp> ");
    readline(buffer, BUFFER_SIZE);
    cell = parse(buffer);
    print_cell(buffer, cell);
    printf("\r\n%s\r\n", buffer);
    free_cell(cell);
  }
}
