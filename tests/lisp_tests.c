#include "lisp_tests.h"

void _test_success();
void _test_failure();

void _test_success()
{
  assert(0 == 0);
}

void _test_failure()
{
  assert(1 == 0);
}

void lisp_tests()
{
  _test_success();
  _test_failure();
}
