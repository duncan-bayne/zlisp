#include <stdio.h>
#include "test_helpers.h"

char *strdup(char *str)
{
  char *buffer = malloc(strlen(str) + 1);
  strcpy(buffer, str);
  return buffer;
}

int *intdup(int n)
{
  int *buffer;

  buffer = malloc(sizeof(int));
  assert(buffer);
  *buffer = n;

  return buffer;}

void assert_equal_str(char *expected, char *actual)
{
  if (strncmp(expected, actual, TEST_BUFFER_SIZE) == 0) {
    return;
  } else {
    printf("expected '%s', got '%s'", expected, actual);
    assert(0);
  }
}
