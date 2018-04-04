#include <iostream>
#include <climits>
#include <sstream>
#include <string>
#include <cstdlib>
#include <new>
#include <fstream>

using namespace std;

struct node {
  int elem;
  struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

void enqueue(int val)
{
    node* newNode = new node();
    newNode->elem = val;
    newNode->next = NULL;
    if (head == NULL){
      head = newNode; tail = newNode;
    } else {
      tail->next = newNode; tail = tail->next;
    }
}

int dequeue()
{
  if (!head){
    cout << "Empty queue" << endl;
    return INT_MIN;
  } else {
    node* ptr = head;
    ptr = ptr->next;
    int val = head->elem;
    free(head);
    head = ptr;
    return val;
  }
}

int peekQ()
{
  if (!head){
    cout << "Empty queue" << endl;
    return INT_MIN;
  } else {
    return head->elem;
  }
}

int main(int argc, char*argv[])
{
  cout << peekQ() << endl;
  ifstream myFile(argv[1]);
  int num; string line;
  if (myFile.is_open()){
    while (getline(myFile, line, ',')){
      stringstream obj(line);
      obj >> num;
      enqueue(num);
    }
  }
  cout << peekQ() << endl;
  cout << dequeue() << endl;
  cout << peekQ() << endl;
  cout << dequeue() << endl;
  cout << dequeue() << endl;

  return 0;
}
