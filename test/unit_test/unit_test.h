#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <iostream>
#include <cstdlib>
//#include "UTException.h"



#define UT_EQUAL(X, Y) \
  if ((X) != (Y)) \
  { \
    std::cout << "ERROR " << __FUNCTION__ << ": "<< X << " != " << Y << std::endl; \
    exit(1); \
  } \
  else \
  { \
    std::cout << "."; \
  }

// Tests if X is true
#define UT_ASSERT(X) \
  if (!(X)) \
  { \
    std::cout << "ERROR " << __FUNCTION__ << " Assertion failed on line "<< __LINE__ << std::endl; \
    exit(1); \
  } \
  else \
  { \
    std::cout << "."; \
  }

// Compare X and Y.  If they are equal up to SIG_FIGS decimal places, then they are equal.
#define UT_APPROX(X, Y, SIG_FIGS) \
  { \
    double x = (X); \
    double y = (Y); \
    int multiplier = 1; \
    for (int i=0; i<SIG_FIGS; i++) \
    { \
      multiplier *= 10; \
    } \
    x *= multiplier; \
    y *= multiplier; \
    int64_t xx = (int64_t) x; \
    int64_t yy = (int64_t) y; \
    xx /= multiplier; \
    yy /= multiplier; \
    UT_EQUAL(xx, yy) \
  }

#endif //UNIT_TEST_H