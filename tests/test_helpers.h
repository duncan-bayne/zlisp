#ifndef __test_helpers_h__
#define __test_helpers_h__

#include <string.h>
#include <malloc.h>

#define RUN_TEST(a) printf("%s:%d ... ", __FILE__, __LINE__); a(); printf("OK\r\n");
#define TEST_BUFFER_SIZE 512

char *strdup(char *str);

#endif /* __test_helpers_h__ */
