#include <stdio.h>
#include "../src/amsgraph.h"
#include "../src/amstext.h"
#include "test_helpers.h"
#include "lisp_tests.h"
#include "cons_cell_tests.h"
#include "parser_tests.h"

int main(void)
{
  mode(2);

  run_lisp_tests();
  run_cons_cell_tests();
  run_parser_tests();

  return 0;
}
