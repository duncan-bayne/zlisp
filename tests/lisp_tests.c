#include "lisp_tests.h"

void _test_heap_size();

void _test_heap_size()
{
  /* SDCC defaults to a 1kB heap size; check we have > 30kB to play with */
  void *block = malloc(30720);
  assert(block != NULL);
  free(block);
}

void run_lisp_tests()
{
  RUN_TEST(_test_heap_size);
}
