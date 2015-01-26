/*  random.cc
 *  Random number generation function implementations
 *  
 *  Gustavo Aranda <garanda@esat.es>
 *  October 2014
 */

#include "../include/random.h"

#include <cstdlib>

int Random(const Range& r) {
  return r.low + rand() % ((r.high + 1) - r.low);
}

int Random(int low, int high) {
  return low + rand() % ((high + 1) - low);
}
