#ifndef __test_helpers_h__
#define __test_helpers_h__

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

#define RUN_TEST(a) printf("%s:%d ... ", __FILE__, __LINE__); a(); printf("OK\r\n");
#define TEST_BUFFER_SIZE 512

char *strdup(char *str);
void assert_equal_str(char *expected, char *actual);

#endif /* __test_helpers_h__ */
