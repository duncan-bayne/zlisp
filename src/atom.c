#include <stdio.h>
#include "atom.h"

atom *create_atom(atom_type type, union atom_contents *contents)
{
  atom *new_atom;

  new_atom = malloc(sizeof(atom));
  assert(new_atom != NULL);
  new_atom->type = type;

  switch (type) {
  case ATOM_TYPE_INT:
    new_atom->contents.integer = contents->integer;
    break;
  case ATOM_TYPE_FLOAT:
    new_atom->contents.floating = contents->floating;
    break;
  case ATOM_TYPE_STRING:
    new_atom->contents.string = contents->string;
    break;
  case ATOM_TYPE_SYMBOL:
    new_atom->contents.symbol = contents->symbol;
    break;
  default:
    assert(0);
  }

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
    free(atom->contents.string);
    break;
  case ATOM_TYPE_SYMBOL:
    free(atom->contents.symbol);
    break;
  default:
    assert(0);
  }
}

