#include "parser.h"

int _is_whitespace(char chr)
{
  return (chr < 33);
}

int _is_numeric(char chr)
{
  return (chr >= '0' && chr <= '9');
}

int _is_string(char chr)
{
  return (chr == '"');
}

int _is_symbol(char chr)
{
  return ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z'));
}

cons_cell *_parse_int(char *s_expression)
{
  long *number;

  number = malloc(sizeof(long));
  *number = atol(s_expression);

  return new_cell(number, FLAG_IS_INT, NULL, FLAG_IS_EMPTY);
}

cons_cell *_parse_string(char *s_expression)
{
  long length;
  char *string;
  char *delimiter;

  delimiter = strchr(s_expression + 1, '"');
  length = (delimiter - s_expression);
  string = malloc(length + 1);
  strncpy(string, s_expression + 1, length - 1);
  string[length] = 0;

  return new_cell(string, FLAG_IS_STRING, NULL, FLAG_IS_EMPTY);
}

cons_cell *_parse_symbol(char *s_expression)
{
  long length;
  char *string;
  char *tmp;

  length = 0;
  tmp = s_expression;
  while (_is_symbol(*tmp)) {
    length++;
    tmp++;
  }

  string = malloc(length + 1);
  strncpy(string, s_expression, length);
  string[length] = 0;

  return new_cell(string, FLAG_IS_SYMBOL, NULL, FLAG_IS_EMPTY);
}

cons_cell *parse(char *s_expression)
{
  if (_is_numeric(*s_expression)) {
    return _parse_int(s_expression);
  }

  if (_is_string(*s_expression)) {
    return _parse_string(s_expression);
  }

  if (_is_symbol(*s_expression)) {
    return _parse_symbol(s_expression);
  }

  assert(0);
  return NULL;
}
