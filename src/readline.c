#include "readline.h"

long readline(char *buffer, long buffer_size)
{
  sprintf(buffer, "9");
  buffer_size++;
  return 2;
}
