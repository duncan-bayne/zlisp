#include "parser.h"

int _is_whitespace(char chr)
{
  return (chr < 33);
}

int _is_numeric(char chr)
{
  return (chr >= 48 && chr <= 57);
}

cons_cell *_parse_int(char *s_expression)
{
  long *number;

  number = malloc(sizeof(long));
  *number = atol(s_expression);

  return new_cell(number, FLAG_IS_INT, NULL, FLAG_IS_EMPTY);
}

cons_cell *parse(char *s_expression)
{
  if (_is_numeric(*s_expression)) {
    return _parse_int(s_expression);
  }

  assert(0);
  return NULL;
}
