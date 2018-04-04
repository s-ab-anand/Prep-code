#include <iostream>
#include <fstream>
#include <new>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;
void mergeTwo(std::vector<int> A, std::vector<int> B){
  int as = A.size()-1; int bs = B.size()-1;
  int e = A.size()+B.size()-1;

  while (bs >= 0){
    if (B.at(bs) > A.at(as)){
      A.at(e--) = B.at(bs--);
    } else {
      A.at(e--) = A.at(as--);
    }
  }
}

void readinFile(vector<int> &obj, string s)
{
  ifstream myFile (s);
  string line; int num = 0;
  if (myFile.is_open()){
    while(getline(myFile, line, ',')){
      stringstream sobj(line);
      sobj >> num;
      obj.push_back(num);
    }
  }
}

int main(int argc, char *argv[])
{
  vector<int> arr1, arr2;
  int sizeArr1, i, elem;
  // cout<<"Enter the size of array"<<endl;
  // cin>>sizeArr;
  // for (i = 0; i < sizeArr; i++){
  //   cout<<"enter the element"<<endl;
  //   cin>>elem;
  //   arr.push_back(elem);
  // }

  readinFile(arr1, argv[1]);
  readinFile(arr2, argv[2]);
  sizeArr1 = arr1.size();
  //cout<<sizeArr<<endl;
  //mergeSort(arr, 0, sizeArr-1);
  mergeTwo(arr1, arr2);

  for (i = 0; i < sizeArr1; i++){
    cout<<arr1.at(i)<<"\t";
  }
  cout<<endl;
}
