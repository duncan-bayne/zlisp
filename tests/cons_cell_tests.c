#include "cons_cell_tests.h"

void _test_cons_cell_empty();

void _test_cons_cell_empty()
{
  cons_cell *cell;

  cell = create_cons_cell(CONS_CELL_CAR_NIL + CONS_CELL_CDR_NIL, NULL, NULL);

  assert((cell->flags & CONS_CELL_CAR_NIL) == CONS_CELL_CAR_NIL);
  assert((cell->flags & CONS_CELL_CDR_NIL) == CONS_CELL_CDR_NIL);
  assert(cell->car == NULL);
  assert(cell->cdr == NULL);

  free_cons_cell(cell);
}

void _test_cons_cell_list_with_one_item()
{
  cons_cell *cell;
  atom *nine;
  union atom_contents contents;

  contents.integer = 9;
  nine = create_atom(ATOM_TYPE_INT, &contents);
  cell = create_cons_cell(CONS_CELL_CAR_ATOM + CONS_CELL_CDR_NIL, nine, NULL);

  assert((cell->flags & CONS_CELL_CAR_ATOM) == CONS_CELL_CAR_ATOM);
  assert((cell->flags & CONS_CELL_CDR_NIL) == CONS_CELL_CDR_NIL);
  assert(cell->car == nine);
  assert(cell->cdr == NULL);

  free_cons_cell(cell);
}

void _test_cons_cell_list_with_two_items()
{
  cons_cell *first_cell;
  cons_cell *second_cell;
  atom *four;
  union atom_contents four_contents;
  atom *two;
  union atom_contents two_contents;

  four_contents.integer = 4;
  four = create_atom(ATOM_TYPE_INT, &four_contents);

  two_contents.integer = 2;
  two = create_atom(ATOM_TYPE_INT, &two_contents);

  second_cell = create_cons_cell(CONS_CELL_CAR_ATOM + CONS_CELL_CDR_NIL, two, NULL);
  first_cell = create_cons_cell(CONS_CELL_CAR_ATOM + CONS_CELL_CDR_CONS_CELL, four, second_cell);

  assert((first_cell->flags & CONS_CELL_CAR_ATOM) == CONS_CELL_CAR_ATOM);
  assert((first_cell->flags & CONS_CELL_CDR_CONS_CELL) == CONS_CELL_CDR_CONS_CELL);
  assert((second_cell->flags & CONS_CELL_CAR_ATOM) == CONS_CELL_CAR_ATOM);
  assert((second_cell->flags & CONS_CELL_CDR_NIL) == CONS_CELL_CDR_NIL);
  assert(first_cell->car == four);
  assert(first_cell->cdr == second_cell);
  assert(second_cell->car == two);
  assert(second_cell->cdr == NULL);

  free_cons_cell(first_cell);
}

void run_cons_cell_tests()
{
  RUN_TEST(_test_cons_cell_empty);
  RUN_TEST(_test_cons_cell_list_with_one_item);
}
