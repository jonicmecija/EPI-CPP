#include <string>
#include <unordered_map>

#include "test_framework/generic_test.h"
using std::string;

bool IsLetterConstructibleFromMagazine(const string& letter_text,
                                       const string& magazine_text) {
  // TODO - you fill in here.
  std::unordered_map<char, int> letterHash;
  std::unordered_map<char, int> magHash;

  for (char c : letter_text){
    if(letterHash.find(c) == letterHash.end()){
      letterHash.insert({c, 1});
    }
    else{
      letterHash.at(c)++;
    }
  }
  for (char c : magazine_text){
    if(magHash.find(c) == magHash.end()){
      magHash.insert({c, 1});
    }
    else{
      magHash.at(c)++;
    }
  }

  //now that occurrances of both text are stored, compare
  // if(letterHash.size() != magHash.size()){
  //   return false;
  // }

  // every char in letter must be equal or less than that of occurances of that char in magazine

  for( auto pair : letterHash){
    if(magHash.find(pair.first) != magHash.end() && pair.second <= magHash[pair.first]){
      continue;
    }
    else{
      return false;
    }
  }
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"letter_text", "magazine_text"};
  return GenericTestMain(args, "is_anonymous_letter_constructible.cc",
                         "is_anonymous_letter_constructible.tsv",
                         &IsLetterConstructibleFromMagazine,
                         DefaultComparator{}, param_names);
}
