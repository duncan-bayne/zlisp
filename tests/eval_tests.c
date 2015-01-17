#include "eval_tests.h"

void _test_eval_empty_list();
void _test_eval_atom();

void _test_eval_empty_list()
{
  cons_cell *cell;
  cons_cell *result;

  cell = create_cons_cell(CONS_CELL_NIL, CONS_CELL_NIL, NULL, NULL);
  result = eval(cell);

  assert(result != NULL);
  assert(result != cell);
  assert(is_empty_list(result));

  free_cons_cell(cell);
  free_cons_cell(result);
}

void _test_eval_atom()
{
  cons_cell *cell;
  cons_cell *result;

  cell = create_cons_cell(CONS_CELL_INT, CONS_CELL_NIL, intdup(9), NULL);
  result = eval(cell);

  assert(result != NULL);
  assert(result != cell);
  assert(!is_empty_list(result));
  assert(*(int *)cell->car == 9);

  free_cons_cell(cell);
  free_cons_cell(result);
}

void run_eval_tests()
{
  RUN_TEST(_test_eval_empty_list);
  RUN_TEST(_test_eval_atom);
}
