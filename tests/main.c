#include <stdio.h>
#include "../src/amsgraph.h"
#include "../src/amstext.h"
#include "test_helpers.h"
#include "atom_tests.h"
#include "lisp_tests.h"

int main(void)
{
  mode(2);

  run_atom_tests();
  run_lisp_tests();

  return 0;
}
