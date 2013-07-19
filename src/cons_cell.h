#ifndef __cons_cell_h__
#define __cons_cell_h__

#include <stdlib.h>
#include <stdio.h>
#include "assert.h"

#define FLAG_IS_INT 1
#define FLAG_IS_POINTER 2
#define FLAG_IS_STRING 4
#define FLAG_IS_SYMBOL 8
#define FLAG_IS_EMPTY 16

typedef unsigned int cell_flags;

typedef struct cons_cell
{
  void *car;
  cell_flags car_flags;
  void *cdr;
  cell_flags cdr_flags;
} cons_cell;

cons_cell *new_cell(void *car, cell_flags car_flags, void *cdr, cell_flags cdr_flags);
void print_cell(char *buffer, cons_cell *cell);
void free_cell(cons_cell *cell);

#endif /* __cons_cell_h__ */
