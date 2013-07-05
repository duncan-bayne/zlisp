#ifndef  __cons_cell_h__
#define __cons_cell_h__

#include <stdlib.h>
#include <stdio.h>
#include "assert.h"

typedef unsigned int cell_flags;
typedef unsigned long cell_payload;

typedef struct cons_cell
{
  cell_payload car;
  cell_payload cdr;
  cell_flags flags;
} cons_cell;

cons_cell *new_cell(cell_payload car, cell_payload cdr, cell_flags flags);
void print_cell(char *buffer, cons_cell *cell);

#endif /* __cons_cell_h__ */
