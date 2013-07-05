#ifndef  __cons_cell_h__
#define __cons_cell_h__

#include <stdlib.h>
#include <stdio.h>
#include "assert.h"

typedef struct cons_cell
{
  unsigned long car;
  unsigned long cdr;
  unsigned int flags;
} cons_cell;

cons_cell *new_cell(unsigned long car, unsigned long cdr, unsigned int flags);
void print_cell(cons_cell *cell);

#endif /* __cons_cell_h__ */
