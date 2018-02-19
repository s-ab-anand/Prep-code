#include <iostream>
#include <fstream>
#include <new>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int low, int high)
{
  int pivot = arr.at(high);
  int i = low -1; int j = low;
  while (j < high){
    if (arr.at(j) < pivot){
      i = i + 1;
      iter_swap(arr.begin()+i, arr.begin()+j);
    }
    j = j + 1;
  }
  iter_swap(arr.begin()+i+1, arr.begin()+high);
  return (i+1);
}
void quicksort(vector<int> &arr, int low, int high)
{
  if (low < high){
    int p = partition(arr, low, high);
    //cout<<p<<endl;
    quicksort(arr, low, p-1);
    quicksort(arr, p+1, high);
  }
}

int binarysearch(std::vector<int> v, int b, int e, int elem, int found){

  int mid = b + (e-b)/2;
  if (mid < b || mid > e){
    found = 0; return found;
  }
  if (v.at(mid) == elem){
    found =  1; return found;
  } else if (v.at(mid) < elem){
    found = binarysearch(v, mid+1, e, elem, found);
  } else{
    found = binarysearch(v, b, mid-1, elem, found);
  }
  return found;
}

int binIter(std::vector<int> v, int b, int e, int elem, int found){
  int mid = b + (e-b)/2;
  while (mid > b && mid < e){
    if (v.at(mid) == elem){
      return 1;
    } else if (v.at(mid) > elem){
      e = mid;
      mid = b + (e-b)/2;
      cout<<mid<<endl;
    } else {
      b = mid;
      mid = mid + (e-b)/2;
      cout<<mid<<endl;
    }
  }
  return found;
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
  int size, i, elem;
  // cout<<"Enter the size of array"<<endl;
  // cin>>size;
  // for (i = 0; i < size; i++){
  //   cout<<"enter the element"<<endl;
  //   cin>>elem;
  //   arr.push_back(elem);
  // }
  cin>>elem;
  cout<<endl;
  readinFile(arr);
  size = arr.size();
  quicksort(arr, 0, size-1);
  int truth = binIter(arr, 0, size-1, elem, 0);

  cout<<truth<<endl;
}
