#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <climits>

using namespace std;

class MyQueue{
  int arr[10];
  int head, tail;
public:
  MyQueue();
  bool isEmpty();
  void enq(int num);
  bool oneElem();
  int deq();
};

MyQueue::MyQueue()
{
  head = -1; tail = -1;
}

bool MyQueue::isEmpty()
{
  return (head == -1)?true:false;
}

void MyQueue::enq(int num){
  //check for overflow
  if (((tail < head && (head - tail) == 1)) || ((tail > head) && ((tail + head) == 9))) {
    cout << "Overflow error" << endl;
  } else {
    //empty queue
    if (head == -1){
      head++;
    }
    tail++; arr[tail] = num;
  }
}

bool MyQueue::oneElem()
{
  return ((head == tail) && (head != -1)) ? true : false;
}
int MyQueue::deq()
{
  int val;
  // check for underflow
  if (isEmpty()){
    cout << "underflow" << endl;
    return INT_MIN;
  }
  val = arr[head];
  if (!isEmpty() && head == tail){
    head = -1; tail = -1;
  } else {
    head = head + 1;
  }
  return val;
}

class StackQ {
  MyQueue* q1;
  MyQueue* q2;
public:
  StackQ();
  void push(int num);
  int pop();
};
StackQ::StackQ()
{
  q1 = new MyQueue();
  q2 = new MyQueue();
}
void StackQ::push(int num)
{
  q1->enq(num);
  cout << "Pushed value " << num << endl;
}

int StackQ::pop(){
  while (!q1->oneElem()){
    q2->enq(q1->deq());
  }
  int val = q1->deq();
  while (!q2->isEmpty()){
    q1->enq(q2->deq());
  }
  return val;
}

int main(int argc, char *argv[])
{
  int num; string line;
  StackQ* s = new StackQ();
  ifstream myfile(argv[1]);
  if (myfile.is_open()){
    while (getline(myfile, line, ',')){
      stringstream obj(line);
      obj >> num;
      s->push(num);
    }
  }
  cout << s->pop() << endl;
  cout << s->pop() << endl;
  s->push(100);
  cout << s->pop() << endl;

  return 0;
}
