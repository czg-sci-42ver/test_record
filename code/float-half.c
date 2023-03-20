/*
 * float-half.c
 */
#include <stdio.h>
#include <assert.h>
#include "float-half.h"

float_bits float_half(float_bits f) {
  unsigned sig = f >> 31;
  unsigned long rest = f & 0x7FFFFFFF;
  unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;
  unsigned frac_cp = f & 0x7FFFFF;

  int is_NAN_or_oo = (exp == 0xFF);
  if (is_NAN_or_oo) {
    return f;
  }

  /*
   * round to even, we care about last 2 bits of frac
   * not forget this
   *
   * 00 => 0 just >>1
   * 01 => 0 (round to even) just >>1
   * 10 => 1 just >>1
   * 11 => 1 + 1 (round to even) just >>1 and plus 1
   */
  int addition = (frac & 0x3) == 0x3;

  if (exp == 0) {
    /* Denormalized */
    frac >>= 1;
    frac += addition;
  } else if (exp == 1) {
    assert((rest & 0x7FFFFF)==frac);
    /* Normalized to denormalized */
    rest >>= 1;
    rest += addition;
    frac = rest & 0x7FFFFF;
    exp--;
    frac_cp=(frac_cp>>1)+(1u<<(23-1))+addition;
    if(frac_cp!=frac)
    {
      printf("%u %u",frac,frac_cp);
    }
  } else {
    /* Normalized */
    exp -= 1;
  }

  return sig << 31 | exp << 23 | frac;
}