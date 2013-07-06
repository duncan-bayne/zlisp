#include "parser_tests.h"

char *pt_buffer;

void _test_parse_dotted_pair()
{
  cons_cell *cell;

  cell = parse("(1 . +)");

  print_cell(pt_buffer, cell);
  assert(strncmp(pt_buffer, "(1 . +)", TEST_BUFFER_SIZE) == 0);
  free_cell(cell);
}

void _test_parse_list()
{
  cons_cell *cell;

  cell = parse("(1 + \"hello\")");

  print_cell(pt_buffer, cell);
  assert(strncmp(pt_buffer, "(1 + \"hello\")", TEST_BUFFER_SIZE) == 0);
  free_cell(cell);
}

void _test_parse_list_of_lists()
{
  cons_cell *cell;

  cell = parse("((1 2) (3 4))");

  print_cell(pt_buffer, cell);
  assert(strncmp(pt_buffer, "((1 2) (3 4))", TEST_BUFFER_SIZE) == 0);
  free_cell(cell);
}

void run_parser_tests()
{
  pt_buffer = malloc(TEST_BUFFER_SIZE);

  RUN_TEST(_test_parse_dotted_pair);
  RUN_TEST(_test_parse_list);
  RUN_TEST(_test_parse_list_of_lists);

  free(pt_buffer);
}
