#include <iostream>
#include <string>
#include <bitset>
using namespace std;
bool checkPermutation(string str1, string str2)
{
  bool check = false;
  if (str1.length() != str2.length())
    return false;
  string::iterator it1, it2, it3;
  for (it1 = str1.begin(), it2 = str2.begin(); it1 != str1.end() && it2 != str2.end(); ++it1, ++it2)
  {
    it3 = it2; int found = 0;
    if (*it1 != *it2){
      while(*it3 != *it1 && it3 != str2.end()){
        ++it3;
      }
      if (*it3 == *it1){
        char temp = *it2; *it2 = *it3; *it3 = temp;
      } else {
        return false;
      }
    }
  }
  check = true;
  return check;

}
int main()
{
  string name, str1, str2;
  cout<<"Enter first string: "<<endl;
  cin>>str1;
  cout<<"Enter the second string: "<<endl;
  cin>>str2;
  bool ifPerm = checkPermutation(str1, str2);
  if (ifPerm){
    cout<<"Yes, they are permutations"<<endl;
  } else {
    cout<<" They are not permuatations"<<endl;
  }
  return 0;
}
