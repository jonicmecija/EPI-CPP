#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> PlusOne(vector<int> A) {
  int ptr = A.size() - 1;

  if(A[ptr] != 9){
    A.back()++;
  }else{
    while(A[ptr] == 9){
      A[ptr] = 0;

      if(ptr > 0){
        ptr--;
        if(A[ptr] != 9){
          A[ptr]++;
          break;
        }
        continue;
      }
      else if(ptr == 0){
        A.insert(A.begin(), 1);
        ptr--;
      }
    }
  }
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "int_as_array_increment.cc",
                         "int_as_array_increment.tsv", &PlusOne,
                         DefaultComparator{}, param_names);
}
