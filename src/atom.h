#ifndef __atom_h__
#define __atom_h__

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

#define ATOM_TYPE_INT 1
#define ATOM_TYPE_FLOAT 2
#define ATOM_TYPE_SYMBOL 3
#define ATOM_TYPE_STRING 4

typedef unsigned int atom_type;

typedef struct atom
{
  atom_type type;
  void *contents;
} atom;

bool is_atom(void *item);
atom *create_atom(atom_type type);
void free_atom(atom *atom);

#endif /* __atom_h__ */
