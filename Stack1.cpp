#include <iostream>
#include <climits>
#include "Stack1.h"
using namespace std;
Stack1::Stack1()
{
  top = -1;
}

int Stack1::getTop()
{
  return top;
}
bool Stack1::isEmpty()
{
  return (top == -1)? true : false;
}
void Stack1::push(int num)
{
  if (top == 9){
    cout << "Overflow" << endl;
  } else {
    top++;
    arr[top] = num;
  }
}

int Stack1::pop()
{
  if (top == -1){
    return INT_MIN;
  } else {
    return arr[top--];
  }
}
