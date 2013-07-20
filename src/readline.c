#include "readline.h"

void readline(char *buffer, long buffer_size)
{
  do {
    *buffer = waitchar();
    if (*buffer == '\r') {
      break;
    }
    printf("%c", *buffer);
    buffer++;
  } while (buffer < buffer + buffer_size);

  buffer = NULL;
  return;
}
