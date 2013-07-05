#include "lisp_tests.h"

void _test_success();
void _test_failure();

void test_print_cell()
{
  cons_cell *cell = new_cell(1, 2, 0);
  print_cell(cell);
}

void lisp_tests()
{
  test_print_cell();
}
