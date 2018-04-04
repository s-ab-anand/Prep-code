#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <climits>
#include "Stack1.h"

using namespace std;

void enqueueStack(Stack1* s, int num)
{
  s->push(num);
  cout << "top " << s->getTop() << endl;
}

int dequeueStack(Stack1* s, Stack1* t)
{
  while (!s->isEmpty()){
    t->push(s->pop());
  }
  int val = t->pop();
  while (!t->isEmpty()){
    s->push(t->pop());
  }
  return val;
}
int main(int argc, char *argv[])
{
  int num; string line;
  Stack1* s = new Stack1(); Stack1* t = new Stack1();
  ifstream myfile(argv[1]);
  if (myfile.is_open()){
    while(getline(myfile, line, ',')){
      stringstream obj(line);
      obj >> num;
      enqueueStack(s, num);

    }
  }
cout << t->getTop() << endl;
  cout << dequeueStack(s,t) << endl;
  cout << dequeueStack(s,t) << endl;

  return 0;
}
