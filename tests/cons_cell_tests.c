#include "cons_cell_tests.h"

const unsigned int BUFFER_SIZE = 512;
char *buffer;

void _test_print_dotted_pair()
{
  long one = 1;
  const char *plus = "+";

  cons_cell *cell = new_cell(&one, FLAG_IS_INT, plus, FLAG_IS_SYMBOL);

  print_cell(buffer, cell);
  assert(strncmp(buffer, "(1 . +)", BUFFER_SIZE) == 0);
  free(cell);
}

void _test_print_list()
{
  long one = 1;
  const char *plus = "+";
  const char *hello = "hello";

  cons_cell *cell_3 = new_cell(hello, FLAG_IS_STRING, NULL, FLAG_IS_POINTER);
  cons_cell *cell_2 = new_cell(plus, FLAG_IS_SYMBOL, cell_3, FLAG_IS_POINTER);
  cons_cell *cell_1 = new_cell(&one, FLAG_IS_INT, cell_2, FLAG_IS_POINTER);

  print_cell(buffer, cell_1);
  assert(strncmp(buffer, "(1 + \"hello\")", BUFFER_SIZE) == 0);
  free(cell_1);
  free(cell_2);
  free(cell_3);
}

void run_cons_cell_tests()
{
  /* TODO: buffer overrun */
  buffer = malloc(BUFFER_SIZE);

  RUN_TEST(_test_print_dotted_pair);
  RUN_TEST(_test_print_list);
}
