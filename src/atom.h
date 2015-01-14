#ifndef __atom_h__
#define __atom_h__

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

enum atom_types {
  ATOM_TYPE_INT,
  ATOM_TYPE_FLOAT,
  ATOM_TYPE_SYMBOL,
  ATOM_TYPE_STRING
};

typedef unsigned int atom_type;

union atom_contents {
  int integer;
  float floating;
  char *symbol;
  char *string;
};

typedef struct atom
{
  atom_type type;
  union atom_contents contents;
} atom;

atom *create_atom(atom_type type, union atom_contents *contents);
void free_atom(atom *atom);

#endif /* __atom_h__ */
