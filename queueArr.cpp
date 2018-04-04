#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int arr[10];
int head = -1; int tail = -1;

void enqueue(int num)
{
  if ((head-tail) == 1 || (head + tail + 1) == 10){
    cout << "Overflow while inserting " << num << endl;
  } else {
    if (head == -1 && tail == -1){
      head++;
    }
    tail = (tail+1)%10;
    arr[tail] = num;
  }
}

int dequeue()
{
  if (head == -1){
    cout << "Underflow" << endl;
    return INT_MIN;
  }
  if (head == tail){
    int val = arr[head];
    head = -1; tail = head;
    return val;
  }
  int val = arr[head];
  head = (head + 1)%10;
  return val;
}

int main(int argc, char *argv[])
{
  int num; string line;
  ifstream myfile(argv[1]);
  if (myfile.is_open()){
    while(getline(myfile, line, ',')){
      stringstream obj(line);
      obj >> num;
      enqueue(num);
    }
  }
  cout << dequeue() << endl;
  cout << dequeue() << endl;
  cout << dequeue() << endl;
  // head at pos 3
  enqueue(12); enqueue(13); enqueue(14);
  // throw overflow error
  enqueue(15);
  cout << dequeue() << endl;
  cout << dequeue() << endl;
  cout << dequeue() << endl;
  cout << dequeue() << endl;
  cout << dequeue() << endl;
  cout << dequeue() << endl;
  cout << dequeue() << endl;
  cout << dequeue() << endl;
  cout << dequeue() << endl;
  cout << dequeue() << endl;
  cout << dequeue() << endl;

  return 0;
}
