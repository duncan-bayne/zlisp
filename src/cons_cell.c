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
  free(cell);
}
