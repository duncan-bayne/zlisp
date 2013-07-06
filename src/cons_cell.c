#include "cons_cell.h"

cons_cell *new_cell(cell_payload car, cell_flags car_flags, cell_payload cdr, cell_flags cdr_flags)
{
  cons_cell *cell;

  /* use malloc() for now, fix later */
  cell = malloc(sizeof(cons_cell));
  assert(cell);
  cell->car = car;
  cell->car_flags = car_flags;
  cell->cdr = cdr;
  cell->cdr_flags = cdr_flags;
  return cell;
}

/* TODO: buffer overrun */
void print_cell(char *buffer, cons_cell *cell)
{
  sprintf(buffer, "(%ld . %ld)", cell->car, cell->cdr);
}
