#ifndef STACK1_H
#define STACK1_H
#endif

class Stack1 {
  int top;
  int arr[10];
public:
  Stack1();
  bool isEmpty();
  void push(int num);
  int pop();
  int getTop();
};
