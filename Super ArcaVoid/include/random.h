/*  random.h
 *  Random number generation function declarations
 *  
 *  Gustavo Aranda <garanda@esat.es>
 *  October 2014
 */

#ifndef __RANDOM_H__
#define __RANDOM_H__


struct Range{
  int low;
  int high;
};


/// @brief Returns a random number in r
int Random(const Range& r);

/// @brief Returns a random number in [low, high]
int Random(int a, int b);

#endif  // __RANDOM_H__
