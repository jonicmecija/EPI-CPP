#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include "test_framework/generic_test.h"
using std::string;
using std::vector;

vector<vector<string>> FindAnagrams(const vector<string>& dictionary) {
  // TODO - you fill in here.
  
  // map that holds
  // keys : sorted string
  // value : vector of related anagrams

  // store sorted into map

  // loop thru input
    // if sorted string is in dictionary, add to that dictionary element's vector

  std::unordered_map<string, vector<string>> myHash;

  for(int i = 0; i < dictionary.size(); i++){
    string word = dictionary[i];
    std::sort(word.begin(), word.end());
    if(myHash.find(word) == myHash.end()){
      // not 
      myHash.insert({word,{}});
    }
    else{
      continue;
    }
  }

  for(int i = 0; i < dictionary.size(); i++){
    string word = dictionary[i];
    std::sort(word.begin(), word.end());
    if(myHash.find(word) == myHash.end()){
      // not 
      continue;
    }
    else{
      myHash.at(word).push_back(dictionary[i]);
    }
  }

  vector<vector<string>> output;
  for(const auto &pair : myHash){
    if(pair.second.size() >= 2){
    output.push_back(pair.second);

    }
  }


  return output;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"dictionary"};
  return GenericTestMain(args, "anagrams.cc", "anagrams.tsv", &FindAnagrams,
                         UnorderedComparator{}, param_names);
}
