#include "test_helpers.h"

char *strdup(char *str)
{
  char *buffer = malloc(strlen(str) + 1);
  strcpy(buffer, str);
  return buffer;
}
