#include "cons_cell.h"

char *_print_list(char *buffer, cons_cell *cell);
char *_print_value(char *buffer, void *ptr, cell_flags flags);

char *_print_value(char *buffer, void *ptr, cell_flags flags)
{
  if (flags & FLAG_IS_INT) {
    return buffer + sprintf(buffer, "%ld ", *((long *)ptr));
  }

  if (flags & FLAG_IS_STRING) {
    return buffer + sprintf(buffer, "\"%ls\" ", (char *)ptr);
  }

  if (flags & FLAG_IS_SYMBOL) {
    return buffer + sprintf(buffer, "%ls ", (char *)ptr);
  }

  if (flags & FLAG_IS_POINTER) {
    buffer = print_cell(buffer, (cons_cell *)ptr);
    return buffer + sprintf(buffer, " ");
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
char *print_cell(char *buffer, cons_cell *cell)
{
  cons_cell *current;

  buffer += sprintf(buffer, "(");

  for (current = cell; current != NULL; current = current->cdr) {
    buffer = _print_value(buffer, current->car, current->car_flags);
  }

  buffer--;
  buffer += sprintf(buffer, ")");
  return buffer;
}

void free_cell(cons_cell *cell)
{
  if (cell->car_flags & FLAG_IS_POINTER) {
    free_cell((cons_cell *)cell->car);
  }

  if (cell->cdr_flags & FLAG_IS_POINTER) {
    free_cell((cons_cell *)cell->cdr);
  }

  if (cell->car_flags & FLAG_IS_STRING) {
    free((char *)cell->car);
  }

  if (cell->cdr_flags & FLAG_IS_STRING) {
    free((char *)cell->cdr);
  }

  free(cell);
}
