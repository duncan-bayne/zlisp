#include "eval_tests.h"

void _test_eval_empty_list();
void _test_eval_atom();

void _test_eval_empty_list()
{
  cons_cell *cell;
  cons_cell *result;

  cell = create_cons_cell(CONS_CELL_NIL, CONS_CELL_NIL, NULL, NULL);
  result = eval(cell);

  CU_ASSERT(result != NULL);
  CU_ASSERT(result != cell);
  CU_ASSERT(!is_atom(result));
  CU_ASSERT(is_empty_list(result));

  free_cons_cell(cell);
  free_cons_cell(result);
}

void _test_eval_atom()
{
  cons_cell *cell;
  cons_cell *result;

  cell = create_cons_cell(CONS_CELL_INT, CONS_CELL_NIL, intdup(9), NULL);
  result = eval(cell);

  CU_ASSERT(result != NULL);
  CU_ASSERT(result != cell);
  CU_ASSERT(is_atom(result));
  CU_ASSERT(!is_empty_list(result));
  CU_ASSERT(*(int *)result->car == 9);

  free_cons_cell(cell);
  free_cons_cell(result);
}

void _test_eval_addition()
{
  cons_cell *plus;
  cons_cell *three;
  cons_cell *four;
  cons_cell *result;

  four = create_cons_cell(CONS_CELL_INT, CONS_CELL_NIL, intdup(4), NULL);
  three = create_cons_cell(CONS_CELL_INT, CONS_CELL_CONS_CELL, intdup(3), four);
  plus = create_cons_cell(CONS_CELL_SYMBOL, CONS_CELL_CONS_CELL, strdup("+"), three);

  result = eval(plus);
  CU_ASSERT(result != NULL);
  CU_ASSERT(is_atom(result));
  CU_ASSERT(!is_empty_list(result));
  CU_ASSERT(*(int *)result->car == 7);
}

void run_eval_tests()
{
  RUN_TEST(_test_eval_empty_list);
  RUN_TEST(_test_eval_atom);
  RUN_TEST(_test_eval_addition);
}
