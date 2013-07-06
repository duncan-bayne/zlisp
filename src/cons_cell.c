#include "cons_cell.h"

void _print_dotted_pair(char *buffer, cons_cell *cell);
void _print_list(char *buffer, cons_cell *cell);

void _print_dotted_pair(char *buffer, cons_cell *cell)
{
  long car;
  long cdr;

  car = *((long *)cell->car);
  cdr = *((long *)cell->cdr);
  sprintf(buffer, "(%ld . %ld)", car, cdr);
}

void _print_list(char *buffer, cons_cell *cell)
{
  cons_cell *current;
  int chars;
  long car;

  chars = sprintf(buffer, "(");
  buffer += chars;

  for (current = cell; current != NULL; current = current->cdr) {
    car = *((long *)cell->car);
    chars = sprintf(buffer, "%ld ", car);
    buffer += chars;
  }

  buffer--;
  sprintf(buffer, ")");
}

cons_cell *new_cell(void *car, cell_flags car_flags, void *cdr, cell_flags cdr_flags)
{
  cons_cell *cell;

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
  if (!(cell->car_flags & FLAG_IS_POINTER) && !(cell->cdr_flags & FLAG_IS_POINTER)) {
    _print_dotted_pair(buffer, cell);
    return;
  }

  _print_list(buffer, cell);
}
