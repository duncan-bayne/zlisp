#include "cons_cell_tests.h"

char *cct_buffer;

void _test_print_list()
{
  long one = 1;
  char *plus = strdup("+");
  char *hello = strdup("hello");

  cons_cell *cell_3 = new_cell(hello, FLAG_IS_STRING, NULL, FLAG_IS_POINTER);
  cons_cell *cell_2 = new_cell(plus, FLAG_IS_SYMBOL, cell_3, FLAG_IS_POINTER);
  cons_cell *cell_1 = new_cell(&one, FLAG_IS_INT, cell_2, FLAG_IS_POINTER);

  print_cell(cct_buffer, cell_1);
  assert(strncmp(cct_buffer, "(1 + \"hello\")", TEST_BUFFER_SIZE) == 0);
  free_cell(cell_1);
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

  print_cell(cct_buffer, cell_1);
  assert(strncmp(cct_buffer, "((1 2) (3 4))", TEST_BUFFER_SIZE) == 0);

  free_cell(cell_1);
}

void run_cons_cell_tests()
{
  cct_buffer = malloc(TEST_BUFFER_SIZE);

  RUN_TEST(_test_print_list);
  RUN_TEST(_test_print_list_of_lists);

  free(cct_buffer);
}
