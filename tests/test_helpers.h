#ifndef __test_helpers_h__
#define __test_helpers_h__

#define RUN_TEST(a) printf("%s:%d ... ", __FILE__, __LINE__); a(); printf("OK\r\n");
#define TEST_BUFFER_SIZE 512

#endif /* __test_helpers_h__ */
