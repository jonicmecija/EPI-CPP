#include <string>
#include <unordered_map>

#include "test_framework/generic_test.h"
using std::string;

bool IsLetterConstructibleFromMagazine(const string& letter_text,
                                       const string& magazine_text) {
  // TODO - you fill in here.
  std::unordered_map<char, int> letterHash;

  // store char occurances of letter text
  for (char c : letter_text){
    letterHash[c]++;
  }

  for (char c : magazine_text){
    if(letterHash.find(c) == letterHash.end()){
      
    }else{
      if(letterHash.at(c)){
        letterHash[c]--;
        if(letterHash[c] == 0){
          letterHash.erase(c);
        }
      }
        
      if(letterHash.empty()){
        break;
      }
    }
  }

  return letterHash.empty();
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"letter_text", "magazine_text"};
  return GenericTestMain(args, "is_anonymous_letter_constructible.cc",
                         "is_anonymous_letter_constructible.tsv",
                         &IsLetterConstructibleFromMagazine,
                         DefaultComparator{}, param_names);
}
