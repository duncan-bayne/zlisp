#include <stdio.h>
#include "cons_cell.h"

cons_cell *create_cons_cell(cons_cell_flags flags, void *car, void *cdr)
{
  cons_cell *cell;

  cell = malloc(sizeof(cell));
  cell->flags = flags;
  cell->car = car;
  cell->cdr = cdr;

  return cell;
}

void free_cons_cell(cons_cell *cell)
{
  if ((cell->flags & CONS_CELL_CAR_ATOM) == CONS_CELL_CAR_ATOM) {
    free_atom((atom *)cell->car);
  }

  if ((cell->flags & CONS_CELL_CAR_CONS_CELL) == CONS_CELL_CAR_CONS_CELL) {
    free_cons_cell((cons_cell *)cell->car);
  }

  if ((cell->flags & CONS_CELL_CDR_ATOM) == CONS_CELL_CDR_ATOM) {
    free_atom((atom *)cell->cdr);
  }

  if ((cell->flags & CONS_CELL_CDR_CONS_CELL) == CONS_CELL_CDR_CONS_CELL) {
    free_cons_cell((cons_cell*)cell->cdr);
  }
}
