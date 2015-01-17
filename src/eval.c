#include <stdio.h>
#include "eval.h"

cons_cell *eval(cons_cell *input)
{
  return dup_cell(input);
}
