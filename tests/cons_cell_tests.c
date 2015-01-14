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

void run_cons_cell_tests()
{
  RUN_TEST(_test_cons_cell_empty);
}
