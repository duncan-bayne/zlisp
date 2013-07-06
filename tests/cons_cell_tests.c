#include "cons_cell_tests.h"

const unsigned int BUFFER_SIZE = 512;
char *buffer;

void _test_sizes()
{
  /* we rely on the fact that floats are no longer than unsigned longs on this platform */
  assert(sizeof(float) <= sizeof(unsigned long));
  assert(sizeof(float) <= sizeof(cell_payload));
}

void _test_print_cell()
{
  cons_cell *cell = new_cell(1, FLAG_IS_INT, 2, FLAG_IS_INT);
  print_cell(buffer, cell);
  assert(strncmp(buffer, "(1 . 2)", BUFFER_SIZE) == 0);
}

void run_cons_cell_tests()
{
  /* TODO: buffer overrun */
  buffer = malloc(BUFFER_SIZE);

  RUN_TEST(_test_print_cell);
  RUN_TEST(_test_sizes);
}
