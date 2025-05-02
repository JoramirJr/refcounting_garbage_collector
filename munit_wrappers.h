#ifndef MUNIT_WRAP_H
#define MUNIT_WRAP_H

#include <stdio.h>
#include <stdlib.h>

#include "munit.h"

#define munit_case(tag, name, body) \
  static MunitResult name(const MunitParameter params[], void* data) body

#define munit_test(name, fn) \
  (MunitTest){ "/" name, fn, NULL, 1, NULL }

#define munit_null_test \
  { NULL, NULL, NULL, 0, NULL }

#define assert_int(actual, op, expected, msg) \
  do { \
    if (!((actual) op (expected))) { \
      fprintf(stderr, "Assertion failed: %s\n  Actual: %d\n  Expected: %d\n  Comparison: %s\n", \
              msg, (actual), (expected), #op); \
      exit(EXIT_FAILURE); \
    } \
  } while (0)


#define munit_suite(name, tests) \
  (MunitSuite){ "/" name, tests, NULL, 1, MUNIT_SUITE_OPTION_NONE }

#endif 
