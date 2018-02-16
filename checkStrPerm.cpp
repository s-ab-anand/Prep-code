#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include "quicksort.h"

std::string quicksort (std::string str)
{
  return NULL;
}
bool checkPermSort(std::string str1, std::string str2)
{
  // quick sort first string
  int size1 = static_cast<int>(str1.size());
  std::vector<char> v1;
  std::string::iterator itr;
  for (itr = str1.begin(); itr != str1.end(); ++itr){
    v1.push_back(*itr);
  }
  quicksort(v1, 0, size1);
  for (int i = 0; i < str1.length(); i++){
    std::cout<<v1.at(i)<<"\t";
  }
  std::cout<<std::endl;



  //quick sort second string
  return false;
}
bool checkPermute(std::string str1, std::string str2)
{
  std::string::iterator itr1, itr2, itr3;
  char temp;
  itr2 = str2.begin(); itr3 = itr2;
  for (itr1 = str1.begin(); itr1 != str1.end() && itr2 != str2.end(); ++itr1){
    if (*itr1 != *itr2){
      bool found = false;
      while (itr3 != str2.end()){
        ++itr3;
        if (*itr3 == *itr1){
          found = true;
          // swap
          temp = *itr3; *itr3 = *itr2; *itr2 = temp; ++itr2; itr3 = itr2;
          break;
        }
      }
      if (!found){
        return false;
      }
    } else {
      ++itr2;
    }
  }
  std::cout<<str1<<"\t"<<str2<<std::endl;
  return true;
}

int main(){
  // code to check if two strings are permutations of each others
  // need to get length and charset for each string
  // again since you forgot, ask if the strings can be uppercase and include
  // whitespaces.
  // current code is case sensitive but for case insensitive, you need to use
  // ASCII A-Z (65-90) and a-z (97-122)
  std::cout<<"Enter the first string"<<std::endl;
  std::string str1, str2;
  //std::cin>>str1;
  std::getline(std::cin, str1);
  std::cout<<"Enter the second string"<<std::endl;
  //std::cin>>str2;
  std::getline(std::cin, str2);

  std::string::iterator itr1, itr2;
  // if not same length, definately not permutations of each other
  if (str1.length() != str2.length()){
    std::cout<<"Not permutations of each others"<<std::endl;
    return 0;
  }
  std::cout<<checkPermute(str1, str2)<<std::endl;
  int hist[256] = {0};
  for (itr1 = str1.begin(); itr1 != str1.end(); ++itr1){
    int val = *itr1;
    hist[val] += 1;
  }

  for (itr2 = str2.begin(); itr2 != str2.end(); ++itr2){
    int val = *itr2;
    hist[val] -= 1;
  }
   for (int i = 0; i < 256; ++i){
     if (hist[i] != 0){
       std::cout<<"Not permutations\n";
       return 0;
     }
   }
   std::cout<<"Permutation\n";
}
