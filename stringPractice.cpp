#include <iostream>
#include <string>

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

  return 0;
}
