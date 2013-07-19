#include "cons_cell_tests.h"

char *cct_buffer;

void _test_print_empty_list()
{
  cons_cell *cell = new_cell(NULL, FLAG_IS_EMPTY, NULL, FLAG_IS_POINTER);

  print_cell(cct_buffer, cell);
  assert_equal_str("()", cct_buffer);
  free_cell(cell);
}

void _test_print_nil()
{
  print_cell(cct_buffer, NULL);
  assert_equal_str("nil", cct_buffer);
}

void _test_print_list()
{
  long *one = longdup(1);
  char *plus = strdup("+");
  char *hello = strdup("hello");

  cons_cell *cell_3 = new_cell(hello, FLAG_IS_STRING, NULL, FLAG_IS_POINTER);
  cons_cell *cell_2 = new_cell(plus, FLAG_IS_SYMBOL, cell_3, FLAG_IS_POINTER);
  cons_cell *cell_1 = new_cell(one, FLAG_IS_INT, cell_2, FLAG_IS_POINTER);

  print_cell(cct_buffer, cell_1);
  assert_equal_str("(1 + \"hello\")", cct_buffer);
  free_cell(cell_1);
}

void _test_print_list_of_lists()
{
  long *one = longdup(1);
  long *two = longdup(2);
  long *three = longdup(3);
  long *four = longdup(4);

  cons_cell *cell_6 = new_cell(four, FLAG_IS_INT, NULL, FLAG_IS_POINTER);
  cons_cell *cell_5 = new_cell(three, FLAG_IS_INT, cell_6, FLAG_IS_POINTER);

  cons_cell *cell_4 = new_cell(two, FLAG_IS_INT, NULL, FLAG_IS_POINTER);
  cons_cell *cell_3 = new_cell(one, FLAG_IS_INT, cell_4, FLAG_IS_POINTER);

  cons_cell *cell_2 = new_cell(cell_5, FLAG_IS_POINTER, NULL, FLAG_IS_POINTER);
  cons_cell *cell_1 = new_cell(cell_3, FLAG_IS_POINTER, cell_2, FLAG_IS_POINTER);

  print_cell(cct_buffer, cell_1);
  assert_equal_str("((1 2) (3 4))", cct_buffer);

  free_cell(cell_1);
}

void _test_print_int_atom()
{
  long *one = longdup(1);

  cons_cell *cell = new_cell(one, FLAG_IS_INT, NULL, FLAG_IS_EMPTY);

  print_cell(cct_buffer, cell);
  assert_equal_str("1", cct_buffer);
  free_cell(cell);
}

void _test_print_string_atom()
{
  char *one = strdup("one");

  cons_cell *cell = new_cell(one, FLAG_IS_STRING, NULL, FLAG_IS_EMPTY);

  print_cell(cct_buffer, cell);
  assert_equal_str("\"one\"", cct_buffer);
  free_cell(cell);
}

void _test_print_symbol_atom()
{
  char *one = strdup("one");

  cons_cell *cell = new_cell(one, FLAG_IS_SYMBOL, NULL, FLAG_IS_EMPTY);

  print_cell(cct_buffer, cell);
  assert_equal_str("one", cct_buffer);
  free_cell(cell);
}

void _test_print_list_with_single_item()
{
  long *one = longdup(1);

  cons_cell *cell = new_cell(one, FLAG_IS_INT, NULL, FLAG_IS_POINTER);

  print_cell(cct_buffer, cell);
  assert_equal_str("(1)", cct_buffer);
  free_cell(cell);
}

void run_cons_cell_tests()
{
  cct_buffer = malloc(TEST_BUFFER_SIZE);

  RUN_TEST(_test_print_empty_list);
  RUN_TEST(_test_print_list);
  RUN_TEST(_test_print_list_of_lists);
  RUN_TEST(_test_print_list_with_single_item);
  RUN_TEST(_test_print_nil);
  RUN_TEST(_test_print_int_atom);
  RUN_TEST(_test_print_string_atom);
  RUN_TEST(_test_print_symbol_atom);

  free(cct_buffer);
}
