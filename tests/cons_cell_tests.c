#include "cons_cell_tests.h"

const unsigned int BUFFER_SIZE = 512;
char *buffer;

void test_print_cell()
{
  cons_cell *cell = new_cell(1, 2, 0);
  print_cell(buffer, cell);
  assert(strncmp(buffer, "(1 . 2)", BUFFER_SIZE) == 0);
}

void run_cons_cell_tests()
{
  /* TODO: buffer overrun */
  buffer = malloc(BUFFER_SIZE);

  RUN_TEST(test_print_cell);
}
