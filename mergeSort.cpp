#include <iostream>
#include <fstream>
#include <new>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void merge(std::vector<int> &v, int stIndx, int mdIndx, int eIndx){
  int i, j;
  i = stIndx; j = mdIndx+1;
  std::vector<int> c;
  while (i <= mdIndx && j <= eIndx){
    if (v.at(i) < v.at(j)){
      c.push_back(v.at(i));
      i++;
    } else {
      c.push_back(v.at(j));
      j++;
    }
  }

  while (i <= mdIndx){
    c.push_back(v.at(i));
    i++;
  }

  while (j <= eIndx){
    c.push_back(v.at(j));
    j++;
  }

  int k = 0;
  for (i = stIndx; i <= eIndx; i++){
    v[i] = c[k++];
  }
  c.clear();
}
void mergeSort(std::vector<int> &v, int stIndx, int eIndx){
  if (stIndx < eIndx){
    int mdIndx = (stIndx+eIndx)/2;
    mergeSort(v, stIndx, mdIndx);
    mergeSort(v, mdIndx+1, eIndx);
    merge(v, stIndx, mdIndx, eIndx);
  }
}

void readinFile(vector<int> &obj)
{
  ifstream myFile ("int100.txt");
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
  vector<int> arr;
  int sizeArr, i, elem;
  // cout<<"Enter the size of array"<<endl;
  // cin>>sizeArr;
  // for (i = 0; i < sizeArr; i++){
  //   cout<<"enter the element"<<endl;
  //   cin>>elem;
  //   arr.push_back(elem);
  // }

  readinFile(arr);
  sizeArr = arr.size();
  cout<<sizeArr<<endl;
  mergeSort(arr, 0, sizeArr-1);
  for (i = 0; i < sizeArr; i++){
    cout<<arr.at(i)<<"\t";
  }
  cout<<endl;
}
