#ifndef  __test_helpers_h__
#define __test_helpers_h__

#define RUN_TEST(a) printf("%s:%d ... ", __FILE__, __LINE__); a(); printf("OK\r\n");

#endif /* __test_helpers_h__ */
