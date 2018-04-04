#include <iostream>
#include <cstdlib>
#include <climits>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int arr[100]; int s_top = -1; int t_top = 100;

void push_s(int num)
{
  if (s_top == (t_top -1)){
    cout << "Overflow" << endl;
  } else {
    arr[++s_top] = num;
  }
}

int pop_s()
{
  if (s_top == -1){
    cout << "Underflow" << endl;
    return INT_MIN;
  } else {
    return arr[s_top--];
  }
}

int pop_t()
{
  if (t_top == 100){
    cout << "Underflow" << endl;
    return INT_MAX;
  } else {
    return arr[t_top++];
  }
}

void push_t(int num)
{
  if (t_top == (s_top + 1)){
    cout << "Overflow" << endl;
  } else {
    arr[--t_top] = num;
  }
}
int main(int argc, char *argv[])
{

  int num; string line; int count = 1;
  // read in the file and alternatively add in each stack
  ifstream myfile(argv[1]);
  if (myfile.is_open()){
    while(getline(myfile, line, ',')){
      stringstream obj(line);
      obj >> num;
      if (count%2 == 1){
        push_s(num);
      } else {
        push_t(num);
      }
      count++;
    }
  }

  cout << arr[s_top] << "\t" << arr[t_top] << endl;
  cout << pop_s() << "\t" << pop_t() << endl;
  cout << arr[s_top] << "\t" << arr[t_top] << endl;
  return 0;
}
