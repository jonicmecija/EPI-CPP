#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
bool CanReachEnd(const vector<int>& max_advance_steps) {
  // TODO - you fill in here.
  int i = 0, furthest = 0, lastIndex = max_advance_steps.size()-1;

  while(furthest >= i && furthest <= lastIndex){
    furthest = std::max(furthest, max_advance_steps[i] + i);
    i++;
  }

  return furthest >= lastIndex;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"max_advance_steps"};
  return GenericTestMain(args, "advance_by_offsets.cc",
                         "advance_by_offsets.tsv", &CanReachEnd,
                         DefaultComparator{}, param_names);
}
