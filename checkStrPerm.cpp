#include <iostream>
#include <string>
#include <bitset>

int main(){
  // code to check if two strings are permutations of each others
  // need to get length and charset for each string
  std::cout<<"Enter the first string"<<std::endl;
  std::string str1, str2;
  std::cin>>str1;
  std::cout<<"Enter the second string"<<std::endl;
  std::cin>>str2;
  std::string::iterator itr1, itr2;
  // if not same length, definately not permutations of each other
  if (str1.length() != str2.length()){
    std::cout<<"Not permutations of each others";
  }

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
