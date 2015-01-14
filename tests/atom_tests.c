#include "atom_tests.h"

void _test_atom_float();
void _test_atom_integer();
void _test_atom_string();
void _test_atom_symbol();

void _test_atom_float()
{
  atom *subject;
  union atom_contents contents;

  contents.floating = 42.42;
  subject = create_atom(ATOM_TYPE_FLOAT, &contents);

  assert(subject->type == ATOM_TYPE_FLOAT);
  assert(subject->contents.floating == 42.42);

  free_atom(subject);
}

void _test_atom_integer()
{
  atom *subject;
  union atom_contents contents;

  contents.integer = 42;
  subject = create_atom(ATOM_TYPE_INT, &contents);

  assert(subject->type == ATOM_TYPE_INT);
  assert(subject->contents.integer == 42);

  free_atom(subject);
}

void _test_atom_string()
{
  atom *subject;
  union atom_contents contents;

  contents.string = strdup("arnold");
  subject = create_atom(ATOM_TYPE_STRING, &contents);

  assert(subject->type == ATOM_TYPE_STRING);
  assert(strcmp("arnold", subject->contents.string) == 0);

  free_atom(subject);
}

void _test_atom_symbol()
{
  atom *subject;
  union atom_contents contents;

  contents.string = strdup("arnold");
  subject = create_atom(ATOM_TYPE_SYMBOL, &contents);

  assert(subject->type == ATOM_TYPE_SYMBOL);
  assert(strcmp("arnold", subject->contents.symbol) == 0);

  free_atom(subject);
}

void run_atom_tests()
{
  RUN_TEST(_test_atom_integer);
  RUN_TEST(_test_atom_float);
  RUN_TEST(_test_atom_symbol);
  RUN_TEST(_test_atom_string);
}
