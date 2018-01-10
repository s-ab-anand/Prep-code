#include <iostream>
#include <fstream>
#include <new>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
// Chose a pivot element. It may be the last, the median or the first element.
// We have two indices, i and j. i starts at low -1 and j starts at low.
// scan through the array using j and any element found less than pivot is swapped
// using i and i is incremented. This ensures that elements preceeeding index i
// are all less than pivot making all elements after i greater than pivot. At the
// end, swap index i + 1 with pivot and return i + 1 and partition pivot index.
// Subsequent recursive calls to quicksort are done on indices 0 and p-1 , p + 1
// and end of array.
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

/* This is another variation of partition function that considers pairs of
elements and swaps them if the left element in the pair is bigger than the right
element
*/
int partition2(std::vector<int> &arr, int low, int high)
{
  int pivot = arr.at(high);
  int i = low - 1; int j = high + 1;
  while(1){
    do{
      i++;
    }while (arr.at(i) < pivot);

    do{
      j--;
    }while (arr.at(j) > pivot);
    if(i >= j){
      return j;
    }
    iter_swap(arr.begin()+i, arr.begin()+j);
  }
  return j;
}

/* Time complexity: partition function needs just one sweep of the array so it
is O(n). quicksort function does partition on every subarray left and right of
the pivot. Assuming equal elements on either sides of pivot, we need 2*O(lg n)
calls for partition function so total time complexity would be 2*O(nlogn) =
O(nlogn). No extra space needed so space complexity is O(1) i.e. inplace.
*/
void quicksort(vector<int> &arr, int low, int high)
{
  if (low < high){
    int p = partition2(arr, low, high);
    cout<<p<<endl;
    quicksort(arr, low, p-1);
    quicksort(arr, p+1, high);
  }
}

int main(int argc, char *argv[])
{
  vector<int> arr;
  int size, i, elem;
  cout<<"Enter the size of array"<<endl;
  cin>>size;
  for (i = 0; i < size; i++){
    cout<<"enter the element"<<endl;
    cin>>elem;
    arr.push_back(elem);
  }
  quicksort(arr, 0, size-1);
  for (i = 0; i < size; i++){
    cout<<arr.at(i)<<"\t";
  }
  cout<<endl;
}
