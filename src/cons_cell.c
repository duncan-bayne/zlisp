#include "cons_cell.h"

void _print_dotted_pair(char *buffer, cons_cell *cell);
void _print_list(char *buffer, cons_cell *cell);
char *_print_value(char *buffer, void *ptr, cell_flags flags);

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

  buffer += sprintf(buffer, "(");

  for (current = cell; current != NULL; current = current->cdr) {
    buffer = _print_value(buffer, current->car, current->car_flags);
  }

  buffer--;
  sprintf(buffer, ")");
}

char *_print_value(char *buffer, void *ptr, cell_flags flags)
{
  if (flags & FLAG_IS_INT) {
    return buffer + sprintf(buffer, "%ld ", *((long *)ptr));
  }

  if (flags & FLAG_IS_STRING) {
    return buffer + sprintf(buffer, "\"%ls\" ", (char *)ptr);
  }

  assert(0);
  return NULL;
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
