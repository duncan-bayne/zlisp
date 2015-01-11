#include <stdio.h>
#include "atom.h"

atom *create_atom(atom_type type)
{
  atom *new_atom;

  new_atom = malloc(sizeof(atom));
  assert(new_atom != NULL);
  new_atom->type = type;
  return new_atom;
}

void free_atom(atom *atom)
{
  switch (atom->type) {
  case ATOM_TYPE_INT:
    break;
  case ATOM_TYPE_FLOAT:
    break;
  case ATOM_TYPE_STRING:
    free(atom->contents);
    break;
  case   ATOM_TYPE_SYMBOL:
    free(atom->contents);
    break;
  default:
    assert(0);
  }
}

