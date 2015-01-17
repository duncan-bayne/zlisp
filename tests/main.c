#include <stdio.h>
#include "../src/amsgraph.h"
#include "../src/amstext.h"
#include "test_helpers.h"
#include "cons_cell_tests.h"
#include "eval_tests.h"
#include "lisp_tests.h"

int main(void)
{
  mode(2);

  run_cons_cell_tests();
  run_eval_tests();
  run_lisp_tests();

  return 0;
}
