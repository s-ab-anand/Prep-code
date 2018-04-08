#include <iostream>
#include <fstream>
#include <new>
#include <cstdlib>
#include <string>
#include <sstream>
#include <climits>
#include <vector>

using namespace std;

int searchArr(int *arr, int key, int size)
{
  int i = 0;
  while (i < size){
    if (arr[i] == key){
      return i;
    }
    i++;
  }
  return -1;
}

void toPost(int *in, int *pre, int n)
{
  int root = searchArr(in, pre[0], n);

  if (root != 0){
    toPost(in, pre+1, root);
  }
  if (root != n-1){
    toPost(in+root+1, pre+root+1, n-root-1);
  }
  cout << pre[0] << " ";

}
int main()
{
  int in[] = {4, 2, 5, 1, 3, 6};
  int pre[] = {1, 2, 4, 5, 3, 6};
  toPost(in, pre, 6);
  return 0;
}
