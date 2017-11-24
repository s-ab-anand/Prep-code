#include<iostream>
#include<cstdlib>
#include<chrono>
#include<sstream>

using namespace std;
using namespace std::chrono;

long fib(int n)
{
  if (n == 1 || n == 2) {
    return 1;
  }
  return fib(n-1)+fib(n-2);
}


int main(int argc, char *argv[])
{
  int num;
  //checking if the number of command line arguments equal to 2
  if (argc != 2) {
    cout << "usage: "<<argv[0]<<" <number>" << '\n';
  } else {
    istringstream ss(argv[1]);
    if (!(ss>>num))
      cerr<<"invalid number "<<argv[1]<<"\n";
  }
  long f = 0;
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
  cout<<"The fibonacci value is "<<f<<"\n";
  return 0;
}
