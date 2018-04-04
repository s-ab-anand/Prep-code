#include <iostream>
#include <fstream>
#include <cstdlib>
#include <new>
#include <sstream>
#include <string>
#include <climits>


using namespace std;

//linked list implementation
struct node {
  int val;
  struct node *next;
};

struct node *top = NULL;
struct node *headptr = NULL;

void pushStack(int num)
{
  node* newNode = new node();
  newNode->val = num;
  newNode->next = NULL;
  if (top != NULL){
    top->next = newNode;
    top = top->next;
  } else {
    top = newNode;
    headptr = newNode;
  }
}

int popStack()
{
  if (top == NULL){
    cout << "Empty stack" <<endl;
    return INT_MIN;
  }
  node *ptr = headptr;
  while (ptr->next != top){
    ptr = ptr->next;
  }
  int val = top->val; ptr->next = NULL;
  node *extra = top; top = ptr;
  free(extra);
  return val;
}

int peek()
{
  if (top == NULL){
    cout << "Empty stack" <<endl;
    return INT_MIN;
  } else {
    return top->val;
  }
}

int main (int argc, char* argv[])
{
  cout << peek() << endl;
  ifstream myFile(argv[1]);
  int num; string line;
  if (myFile.is_open()){
    while(getline(myFile, line, ',')){
      stringstream sobj(line);
      sobj >> num;
      pushStack(num);
    }
  }

  cout << peek() <<endl;

  cout << popStack() << endl;
  cout << peek() << endl;

  return 0;
}
