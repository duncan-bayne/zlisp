#include "cons_cell_tests.h"

void _test_cons_cell_empty();
void _test_cons_cell_list_with_one_item();
void _test_cons_cell_list_with_two_items();

void _test_cons_cell_empty()
{
  cons_cell *cell;

  cell = create_cons_cell(CONS_CELL_NIL, CONS_CELL_NIL, NULL, NULL);
  CU_ASSERT(is_empty_list(cell));
  free_cons_cell(cell);
}

void _test_cons_cell_list_with_one_item()
{
  cons_cell *cell;

  cell = create_cons_cell(CONS_CELL_INT, CONS_CELL_NIL, intdup(9), NULL);

  CU_ASSERT(*(int *)cell->car == 9);
  CU_ASSERT(cell->cdr == NULL);

  free_cons_cell(cell);
}

void _test_cons_cell_list_with_two_items()
{
  cons_cell *four;
  cons_cell *two;

  two = create_cons_cell(CONS_CELL_INT, CONS_CELL_NIL, intdup(2), NULL);
  four = create_cons_cell(CONS_CELL_INT, CONS_CELL_CONS_CELL, intdup(4), two);

  CU_ASSERT(*(int *)four->car == 4);
  CU_ASSERT(four->cdr == two);

  CU_ASSERT(*(int *)two->car == 2);
  CU_ASSERT(two->cdr == NULL);

  free_cons_cell(two);
  free_cons_cell(four);
}

void run_cons_cell_tests()
{
  RUN_TEST(_test_cons_cell_empty);
  RUN_TEST(_test_cons_cell_list_with_one_item);
  RUN_TEST(_test_cons_cell_list_with_two_items);
}
