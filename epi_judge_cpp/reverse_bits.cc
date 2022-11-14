#include "test_framework/generic_test.h"
unsigned long long ReverseBits(unsigned long long x) {
  // TODO - you fill in here.
  long long result = 0, count = 64;

  while(count){

    result += (x & 1);

    count--;
    x>>=1;

    if(count){
      result<<=1;
    }
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "reverse_bits.cc", "reverse_bits.tsv",
                         &ReverseBits, DefaultComparator{}, param_names);
}
