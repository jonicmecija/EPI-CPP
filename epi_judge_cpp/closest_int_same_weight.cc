#include "test_framework/generic_test.h"
unsigned long long ClosestIntSameBitCount(unsigned long long x) {
  // TODO - you fill in here.

  // iterate thru x
  for(int i = 0; i<64; i++){

    if((x >> i & 1) != ((x >> (i + 1)) & 1)){
      x ^= (1UL << i) | (1UL << (i + 1));
      return x;
    }
  }
    // if two lowest bits differ
      // swap them
      // return updated x
  
  // 
  // return smallestBit;
  throw std::invalid_argument("all bits are 0 or 1.");
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "closest_int_same_weight.cc",
                         "closest_int_same_weight.tsv", &ClosestIntSameBitCount,
                         DefaultComparator{}, param_names);
}
