#include "cons_cell_tests.h"

char *cts_buffer;

void _test_print_dotted_pair()
{
  long one = 1;
  const char *plus = "+";

  cons_cell *cell = new_cell(&one, FLAG_IS_INT, plus, FLAG_IS_SYMBOL);

  print_cell(cts_buffer, cell);
  assert(strncmp(cts_buffer, "(1 . +)", TEST_BUFFER_SIZE) == 0);
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

  print_cell(cts_buffer, cell_1);
  assert(strncmp(cts_buffer, "(1 + \"hello\")", TEST_BUFFER_SIZE) == 0);
  free(cell_1);
  free(cell_2);
  free(cell_3);
}

void _test_print_list_of_lists()
{
  long one = 1;
  long two = 2;
  long three = 3;
  long four = 4;

  cons_cell *cell_6 = new_cell(&four, FLAG_IS_INT, NULL, FLAG_IS_POINTER);
  cons_cell *cell_5 = new_cell(&three, FLAG_IS_INT, cell_6, FLAG_IS_POINTER);

  cons_cell *cell_4 = new_cell(&two, FLAG_IS_INT, NULL, FLAG_IS_POINTER);
  cons_cell *cell_3 = new_cell(&one, FLAG_IS_INT, cell_4, FLAG_IS_POINTER);

  cons_cell *cell_2 = new_cell(cell_5, FLAG_IS_POINTER, NULL, FLAG_IS_POINTER);
  cons_cell *cell_1 = new_cell(cell_3, FLAG_IS_POINTER, cell_2, FLAG_IS_POINTER);

  print_cell(cts_buffer, cell_1);
  assert(strncmp(cts_buffer, "((1 2) (3 4))", TEST_BUFFER_SIZE) == 0);

  free(cell_1);
  free(cell_2);
  free(cell_3);
  free(cell_4);
  free(cell_5);
  free(cell_6);
}

void run_cons_cell_tests()
{
  /* TODO: buffer overrun */
  cts_buffer = malloc(TEST_BUFFER_SIZE);

  RUN_TEST(_test_print_dotted_pair);
  RUN_TEST(_test_print_list);
  RUN_TEST(_test_print_list_of_lists);

  free(cts_buffer);
}
