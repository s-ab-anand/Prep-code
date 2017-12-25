#include <iostream>
#include <string>

int main()
{
  std::string name;
  std::cout<<"Enter your name \n";
  std::cin>>name; // discards whitespaces
  std::cout<<"Your name is "<<name<<std::endl;
  return 0;
}
