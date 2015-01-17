#include "cons_cell.h"

char *_strdup(char *str);
int *_intdup(int *n);

cons_cell *create_cons_cell(cons_cell_type car_type, cons_cell_type cdr_type, void *car, void *cdr)
{
  cons_cell *cell;

  cell = malloc(sizeof(cons_cell));
  assert(cell);

  cell->car_type = car_type;
  cell->cdr_type = cdr_type;
  cell->car = car;
  cell->cdr = cdr;

  return cell;
}

void debug_cell(cons_cell *cell)
{
  printf("\r\ncell @ %d - %d: car_type %d, cdr_type %d, car %d, cdr %d\r\n", cell, cell + sizeof(cons_cell), cell->car_type, cell->cdr_type, cell->car, cell->cdr);
}

cons_cell *dup_cell(cons_cell *cell)
{
  void *new_car;
  void *new_cdr;

  new_car = NULL;
  new_cdr = NULL;

  switch (cell->car_type) {
  case CONS_CELL_CONS_CELL:
    new_car = dup_cell(cell->car);
    break;
  case CONS_CELL_INT:
    new_car = _intdup((int *)cell->car);
    break;
  case CONS_CELL_STRING:
  case CONS_CELL_SYMBOL:
    new_car = _strdup((char *)cell->car);
    break;
  case CONS_CELL_NIL:
    new_car = NULL;
    break;
  default:
    assert(0);
  }

  switch (cell->cdr_type) {
  case CONS_CELL_CONS_CELL:
    new_cdr = dup_cell(cell->cdr);
    break;
  case CONS_CELL_INT:
    new_cdr = _intdup((int *)cell->cdr);
    break;
  case CONS_CELL_STRING:
  case CONS_CELL_SYMBOL:
    new_cdr = _strdup((char *)cell->cdr);
    break;
  case CONS_CELL_NIL:
    new_cdr = NULL;
    break;
  default:
    assert(0);
  }

  return create_cons_cell(cell->car_type, cell->cdr_type, new_car, new_cdr);
}

void free_cons_cell(cons_cell *cell)
{
  if (cell->car_type == CONS_CELL_CONS_CELL) {
    free_cons_cell((cons_cell *)cell->car);
  } else {
    if (cell->car) {
      free(cell->car);
    }
  }

  if (cell->cdr_type == CONS_CELL_CONS_CELL) {
    free_cons_cell((cons_cell *)cell->cdr);
  } else {
    if (cell->cdr) {
      free(cell->cdr);
    }
  }

  free(cell);
}

bool is_empty_list(cons_cell *cell)
{
  return (cell->car_type == CONS_CELL_NIL && cell->cdr_type == CONS_CELL_NIL);
}

char *_strdup(char *str)
{
  char *buffer = malloc(strlen(str) + 1);
  assert(buffer);
  strcpy(buffer, str);
  return buffer;
}

int *_intdup(int *n)
{
  int *buffer = malloc(sizeof(int));
  assert(buffer);
  *buffer = *n;
  return buffer;
}
