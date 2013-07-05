#include "cons_cell.h"

cons_cell *new_cell(cell_payload car, cell_payload cdr, cell_flags flags)
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

/* TODO: buffer overrun */
void print_cell(char *buffer, cons_cell *cell)
{
  sprintf(buffer, "(%ld . %ld)", cell->car, cell->cdr);
}
