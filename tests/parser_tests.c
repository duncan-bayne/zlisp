#include "parser_tests.h"

char *pt_buffer;

void _test_parse_empty_list()
{
  cons_cell *cell = parse("()");

  print_cell(pt_buffer, cell);
  assert_equal_str("()", pt_buffer);
  free_cell(cell);
}

void _test_parse_nil()
{
  cons_cell *cell = parse("nil");
  print_cell(pt_buffer, cell);
  assert_equal_str("nil", pt_buffer);
}

void _test_parse_list()
{
  cons_cell *cell = parse("(1 + \"hello\")");

  print_cell(pt_buffer, cell);
  assert_equal_str("(1 + \"hello\")", pt_buffer);
  free_cell(cell);
}

void _test_parse_list_of_lists()
{
  cons_cell *cell = parse("((1 2) (3 4))");
  print_cell(pt_buffer, cell);
  assert_equal_str("((1 2) (3 4))", pt_buffer);

  free_cell(cell);
}

void _test_parse_int_atom()
{
  cons_cell *cell = parse("1");

  print_cell(pt_buffer, cell);
  assert_equal_str("1", pt_buffer);
  free_cell(cell);
}

void _test_parse_string_atom()
{
  cons_cell *cell = parse("\"one\"");

  print_cell(pt_buffer, cell);
  assert_equal_str("\"one\"", pt_buffer);
  free_cell(cell);
}

void _test_parse_symbol_atom()
{
  cons_cell *cell = parse("one");

  print_cell(pt_buffer, cell);
  assert_equal_str("one", pt_buffer);
  free_cell(cell);
}

void _test_parse_list_with_single_item()
{
  cons_cell *cell = parse("(1)");

  print_cell(pt_buffer, cell);
  assert_equal_str("(1)", pt_buffer);
  free_cell(cell);
}

void run_parser_tests()
{
  pt_buffer = malloc(TEST_BUFFER_SIZE);

  /* RUN_TEST(_test_parse_empty_list); */
  /* RUN_TEST(_test_parse_list); */
  /* RUN_TEST(_test_parse_list_of_lists); */
  /* RUN_TEST(_test_parse_list_with_single_item); */
  /* RUN_TEST(_test_parse_nil); */
  RUN_TEST(_test_parse_int_atom);
  RUN_TEST(_test_parse_string_atom);
  RUN_TEST(_test_parse_symbol_atom);

  free(pt_buffer);
}
