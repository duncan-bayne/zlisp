#include "cons_cell.h"

cons_cell *new_cell(unsigned long car, unsigned long cdr, unsigned int flags)
{
  cons_cell *cell;

  /* use malloc() for now, fix later */
  cell = malloc(sizeof(cons_cell));
  assert(cell);
  cell->car = car;
  cell->cdr = cdr;
  cell->flags = flags;
  return cell;
}

void print_cell(cons_cell *cell)
{
  printf("(%ld . %ld)\r\n", cell->car, cell->cdr);
}
