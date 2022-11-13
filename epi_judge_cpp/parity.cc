#include "test_framework/generic_test.h"
short Parity(unsigned long long x) {
  // TODO - you fill in here.

  // brute force solution

  uint8_t result = 0;

  // while(x){
  //   result ^= (x & 1);
  //   x >>= 1;
  // }
  // return result;

  // improved run time by erasing last bit set to one

  while(x){
    result ^= 1;
    x &= (x-1); // gets rid of last bit set to 1
  }

  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "parity.cc", "parity.tsv", &Parity,
                         DefaultComparator{}, param_names);
}
// g++ -pthread -std=c++14 -O3 -o count_bits count_bits.cc