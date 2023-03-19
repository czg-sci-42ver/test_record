/*
 * main.c
 */
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>

#include "../lib/random.h"
#include "float-half.h"


unsigned f2u(float f) { return *(unsigned*)&f; }

float u2f(unsigned u) { return *(float*)&u; }

int main(int argc, char* argv[]) {
  init_seed();
  unsigned long long total = 0;
  int round = 0;
  for (unsigned long long n = 0; !round; n = n + 1) {
    // if (n == (unsigned long long)0x0FFFFFFFF+1) {
    if (n == (unsigned long long)0xFFFF) {
      round++;
    }
    total++;
    
    unsigned r = random_int();
    

    float f = u2f(r);
    float fdiv2 = f * 0.5;
    if (isnan(f)) {
      assert(float_half(r) == r);
    } else {
      assert(u2f(float_half(r)) == fdiv2);
    }
  }
}
