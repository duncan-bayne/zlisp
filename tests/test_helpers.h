#ifndef __test_helpers_h__
#define __test_helpers_h__

#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "assert.h"

#define RUN_TEST(a) printf("%s:%d ... ", __FILE__, __LINE__); a(); printf("OK\r\n");
#define TEST_BUFFER_SIZE 512

char *strdup(char *str);
long *longdup(long num);
void assert_equal_str(char *expected, char *actual);

#endif /* __test_helpers_h__ */
