#include <iostream>
#include <string>
#include <bitset>

int main()
{
  std::string name;
  std::cout<<"Enter your name \n";
  std::cin>>name; // discards whitespaces; also cout buffer flushed
  std::cout<<"Your name is "<<name<<std::endl; //cout buffer flushed due to endl
  // check if string has all unique characters
  /* Before attempting to solve this question, ask if the string is utf or ascii
  ASCII charset length is 128 bit and unicode is 2^21. Extended ASCII is 256
  length charset as they use the 8th bit for some characters. In normal ascii
  8th bit is used for error parity.
  */
  // Time complexity is O(n); space complexity is O(n)
  std::cout<<"Size of string is "<<name.size()<<" bytes"<<std::endl;
  if (name.size() > 128){
    std::cout<<"Not unique"<<std::endl;
    return -1;
  }
  bool charArr[128];
  int i;
  for (i = 0; i < 128; i++){
    charArr[i] = false;
  }
  for (std::string::iterator it = name.begin(); it!= name.end(); ++it){
    //std::cout<<*it<<"\t"<<(*it - 'A')<<"\t"<<(*it - 'a')<<std::endl;
    int index = *it;
    if (charArr[index]){
      std::cout<<"Not all unique"<<std::endl;
      break;
    } else {
      charArr[index] = true;
    }
  }
  // using only string data structure; time complexity O(n^2), space
  // complexity O(n)
  std::string orig;
  for (std::string::iterator it = name.begin(); it!= name.end(); ++it){
    std::size_t found = orig.find(*it);
    if (found == std::string::npos){
      std::string temp; temp.push_back(*it);
      orig.append(temp);
    } else {
      break;
    }
  }
  std::cout<<orig<<std::endl;

  // trying with a bit vector assuming only lowercase letters, saves space by a
  // factor of 8 as we use only one integer. For every char, we shift 1 in the
  // bit vector by that many positions then 'and' it with checker. If result is
  // 0 then we 'or' it with the bit vector of shifted 1. Now checker contains 1
  // at the position of char value. If that value is encountered again, the 'and'
  // will now produce a result > 1 indicating duplicate.
  std::cout<<"Now trying bit vector method"<<std::endl;
  int checker = 0;
  for (std::string::iterator it = name.begin(); it!= name.end(); ++it){
    int val = *it - 'a';
    std::cout<<val<<"\t"<<std::bitset<32>(1<<val)<<"\t"<<std::bitset<32>(checker)<<"\t"<<std::bitset<32>(checker & (1<<val))<<std::endl;
    if ((checker & (1<<val)) > 0){
      std::cout<<"Not unique"<<std::endl;
      break;
    } else {
      checker |= (1 << val);
    }

  }

  return 0;
}
