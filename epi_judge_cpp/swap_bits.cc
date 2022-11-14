#include "test_framework/generic_test.h"
#include <iostream>

long long SwapBits(long long x, int i, int j) {
  // TODO - you fill in here.
  int temp_i = 0;
  int temp_j = 0;

  temp_i = (x >> i) & 1;
  temp_j = (x >> j) & 1;

  if(temp_i != temp_j){
    // to get bit mask, shift from the left i or j times. OR them together.
    // XOR bit mask and input to swap the bits
    unsigned long long bit_mask = (1L << i) | (1L << j);
    x ^= bit_mask;
  } 
  
  return x;
}

//   i    j
// 0101_0110
// 0010_0010 ^ <-

// result
// 0111_0100

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "i", "j"};
  return GenericTestMain(args, "swap_bits.cc", "swap_bits.tsv", &SwapBits,
                         DefaultComparator{}, param_names);
}
