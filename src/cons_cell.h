#ifndef __cons_cell_h__
#define __cons_cell_h__

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum cons_cell_type {
  CONS_CELL_NIL,
  CONS_CELL_INT,
  CONS_CELL_FLOAT,
  CONS_CELL_STRING,
  CONS_CELL_SYMBOL,
  CONS_CELL_CONS_CELL
};

typedef unsigned short cons_cell_type;

typedef struct cons_cell
{
  cons_cell_type car_type;
  cons_cell_type cdr_type;
  void *car;
  void *cdr;
} cons_cell;

cons_cell *create_cons_cell(cons_cell_type car_type, cons_cell_type cdr_type, void *car, void *cdr);
cons_cell *dup_cell(cons_cell *cell);
void free_cons_cell(cons_cell *cell);
bool is_empty_list(cons_cell *cell);
void debug_cell(cons_cell *cell);

#endif /* __cons_cell_h__ */
