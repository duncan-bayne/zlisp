#include "repl.h"

void repl()
{
  cons_cell *cell;
  char *buffer;

  buffer = malloc(BUFFER_SIZE);

  while (1) {
    printf("zlisp> ");
    readline(buffer, BUFFER_SIZE);
    cell = parse(buffer);
    print_cell(buffer, cell);
    printf("%s\r\n", buffer);
    free_cell(cell);
  }
}
