#ifndef __cons_cell_h__
#define __cons_cell_h__

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "atom.h"

enum cons_cell_flags {
  CONS_CELL_CAR_ATOM = 1,
  CONS_CELL_CAR_CONS_CELL = 2,
  CONS_CELL_CAR_NIL = 4,
  CONS_CELL_CDR_ATOM = 8,
  CONS_CELL_CDR_CONS_CELL = 16,
  CONS_CELL_CDR_NIL = 32
};

typedef unsigned int cons_cell_flags;

typedef struct cons_cell
{
  cons_cell_flags flags;
  void *car;
  void *cdr;
} cons_cell;

atom *create_cons_cell(cons_cell_flags flags, void *car, void *cdr);
void free_cons_cell(cons_cell *cell);

#endif /* __cons_cell_h__ */
