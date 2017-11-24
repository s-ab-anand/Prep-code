#include<iostream>
#include<cstdlib>
#include<chrono>
#include<sstream>

using namespace std;
using namespace std::chrono;

/*
Time complexity discussion: O(n). The approach used in bottom to top.
In brute force method, you place the function call f(n) = f(n-1) + f(n-2).
This recursive routine creates a binary tree so the time complexity turns out
to be O(2^n).
*/
double fib(int num)
{
  //using long instead of int
  int i; double* fibArr = new (nothrow) double[num];
  if (fibArr == nullptr){
    cout<<"Error!! Memory could not be allocated.";
  } else {
    fibArr[0] = 1; fibArr[1] = 1;
    for (i = 2; i < num; i++)
    {
      fibArr[i] = fibArr[i-1] + fibArr[i-2];
    }
  }
  return fibArr[num-1];
}
int main(int argc, char *argv[])
{
  int num;
  //checking if the number of command line arguments equal to 2
  if (argc != 2) {
    cout << "usage: "<<argv[0]<<" <number>" << '\n';
  } else {
    //converting string command line argument to integer
    istringstream ss(argv[1]);
    if (!(ss>>num))
      cerr<<"invalid number "<<argv[1]<<"\n";
  }
  cout<<"Size = "<<sizeof(double)<<"\n";
  double f = 0;
  //int num;
  //cout<<"Enter the number-- ";
  //cin>>num;

  //clocking the run time of the function, it's an approximate measure
  //need to run a few times and average it out
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  f = fib(num-1) + fib(num-2);
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>( t2 - t1 ).count();
  cout << "Time taken = " << duration <<"\n";
  cout<<"The fibonacci value is "<<to_string(f)<<"\n";
  return 0;
}
