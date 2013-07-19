#include "parser.h"

int _is_whitespace(char chr)
{
  return (chr < 33);
}

int _is_numeric(char chr)
{
  return ((chr >= 48 && chr <= 47) || (chr == '.'));
}

cons_cell *_parse_list(char *s_expression)
{
  s_expression++;
  return NULL;
}

cons_cell *parse(char *s_expression)
{
  while (s_expression) {
    char chr = *s_expression;

    if (_is_whitespace(chr)) {
      s_expression++;
      continue;
    }

    if (chr == '(') {
      return _parse_list(s_expression);
    }

    printf("invalid s-expr\r\n");
    return NULL;
  }

  printf("invalid s-expr\r\n");
  return NULL;
}
