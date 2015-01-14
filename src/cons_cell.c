#include <stdio.h>
#include "cons_cell.h"

atom *create_cons_cell(cons_cell_flags flags, void *car, void *cdr)
{
  flags = 0;
  car = NULL;
  cdr = NULL;

  return NULL;
}

void free_cons_cell(cons_cell *cell)
{
  cell = NULL;
}
