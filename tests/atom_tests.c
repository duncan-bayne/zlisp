#include "atom_tests.h"

void _test_atom_type();

void _test_atom_type()
{
  atom *subject;

  subject = create_atom(ATOM_TYPE_INT);
  assert(subject->type == ATOM_TYPE_INT);
  assert(subject->type != ATOM_TYPE_STRING);

  free_atom(subject);
}

void run_atom_tests()
{
  RUN_TEST(_test_atom_type);
}
