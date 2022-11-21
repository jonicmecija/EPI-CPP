#include <string>
#include <unordered_map>

#include "test_framework/generic_test.h"
using std::string;

bool CanFormPalindrome(const string& s) {
  // use unordered set

  // store each character, remove everytime you see same character

  std::unordered_set <char> mySet;
  
  for(char c : s){
    if(mySet.count(c)){
      mySet.erase(c);
    }
    else{
      mySet.insert(c);
    }
  }

  return mySet.size() <= 1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "is_string_permutable_to_palindrome.cc",
                         "is_string_permutable_to_palindrome.tsv",
                         &CanFormPalindrome, DefaultComparator{}, param_names);
}
