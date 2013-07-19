#include "cons_cell.h"

int _is_atom(cons_cell *cell);
int _is_list(cons_cell *cell);
char *_print_atom(char *buffer, cons_cell *cell);
char *_print_list(char *buffer, cons_cell *cell);
char *_print_value(char *buffer, cons_cell *cell);
void _free_cell(void *ptr, cell_flags flags);

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

void print_cell(char *buffer, cons_cell *cell)
{
  if (!cell) {
    sprintf(buffer, "nil");
    return;
  }

  if (_is_atom(cell)) {
    _print_atom(buffer, cell);
    return;
  }

  if (_is_list(cell)) {
    _print_list(buffer, cell);
    return;
  }

  assert(0);
}

void free_cell(cons_cell *cell)
{
  assert(cell);

  _free_cell(cell->car, cell->car_flags);
  _free_cell(cell->cdr, cell->cdr_flags);
}

void _free_cell(void *ptr, cell_flags flags)
{
  if (!ptr) {
    return;
  }

  if (flags & FLAG_IS_POINTER) {
    free_cell(ptr);
  }

  if ((flags & FLAG_IS_STRING)) {
    free(ptr);
  }

  if ((flags & FLAG_IS_INT)) {
    free(ptr);
  }
}

int _is_atom(cons_cell *cell)
{
  return (cell->cdr_flags & FLAG_IS_EMPTY);
}

int _is_list(cons_cell *cell)
{
  return (cell->cdr_flags & FLAG_IS_POINTER);
}

char *_print_atom(char *buffer, cons_cell *cell)
{
  return _print_value(buffer, cell);
}

char *_print_list(char *buffer, cons_cell *cell)
{
  void *current;

  buffer += sprintf(buffer, "(");
  for (current = cell; current != NULL; current = ((cons_cell *)current)->cdr) {
    buffer = _print_value(buffer, current);
    buffer += sprintf(buffer, " ");
  }
  buffer--;
  return buffer + sprintf(buffer, ")");
}

char *_print_value(char *buffer, cons_cell *cell)
{
  if (cell->car_flags & FLAG_IS_INT) {
    return buffer + sprintf(buffer, "%ld", *(long *)cell->car);
  }

  if (cell->car_flags & FLAG_IS_STRING) {
    return buffer + sprintf(buffer, "\"%s\"", (char *)cell->car);
  }

  if (cell->car_flags & FLAG_IS_SYMBOL) {
    return buffer + sprintf(buffer, "%s", (char *)cell->car);
  }

  if (cell->car_flags & FLAG_IS_POINTER) {
    return _print_list(buffer, (cons_cell *)cell->car);
  }

  // NOOP; this is the cell containing an empty list
  if (cell->car_flags & FLAG_IS_EMPTY) {
    return buffer;
  }

  assert(0);
  return NULL;
}
