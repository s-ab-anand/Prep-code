#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <climits>
#include <sstream>
#include <new>
using namespace std;

struct node {
  int val;
  struct node* next;
};
struct node* last = NULL;

bool isEmpty()
{
  return (last == NULL) ? true : false;
}
void addNode (struct node* l, int num)
{
  if (!isEmpty()){
    struct node* newNode = new node();
    newNode->val = num; newNode->next = last->next;
    last->next = newNode; last = last->next;
  } else {
    struct node* newNode = new node();
    newNode->val = num; newNode->next = newNode;
    last = newNode;
  }
}

struct node* searchList(int num)
{
  if (isEmpty())
    return NULL;
  if (last->val == num)
    return last;
  struct node* head = last->next;
  while (head != last){
    if (head->val == num){
      return head;
    } else {
      head = head->next;
    }
  }
  return NULL;
}
void deleteNode(int num)
{
  struct node* ptr = searchList(num);
  if (ptr != NULL){
    struct node* ptr2 = ptr->next;
    if (ptr2 == ptr){
      //cout << "deleted node with value " << ptr->val << endl;
      delete ptr; ptr = NULL; last = NULL;
    } else {
      while (ptr2->next != ptr){
        ptr2 = ptr2->next;
      }
      ptr2->next = ptr->next;
      if (ptr == last){
        last = ptr2;
      }
      //cout << "deleted node with value " << ptr->val << endl;
      delete ptr; ptr = NULL;
    }
  }
}

void findMid()
{
  if (!isEmpty())
  {
    struct node* first; struct node* second;
    first = last->next; second = last->next;
    do{
      second = (second->next)->next;
      first = first->next;
    }while (second != last && second != last->next);
    cout << "the mid value is " << first->val << endl;
  } else {
    cout << "Empty list" << endl;
  }
}
void displayList()
{
  if (!isEmpty()){
    struct node* head = last->next;
    while (head != last){
      cout<< head->val << "-->";
      head = head->next;
    }
    cout << last->val << endl;
  } else {
    cout << "Empty list" << endl;
  }
}
int main(int argc, char* argv[])
{
  int num; string line;
  struct node* list = new node();
  ifstream myfile(argv[1]);
  if (myfile.is_open()){
    while (getline(myfile, line, ',')){
      stringstream obj(line);
      obj >> num;
      addNode(list, num);
    }
  }
  displayList(); findMid();
  deleteNode(8); displayList(); findMid();
  deleteNode(11); displayList(); findMid();
  deleteNode(1); displayList(); findMid();
  deleteNode(2); displayList(); findMid();
  deleteNode(3); displayList(); findMid();
  deleteNode(4); displayList(); findMid();
  deleteNode(5); displayList(); findMid();
  deleteNode(6); displayList(); findMid();
  deleteNode(7); displayList(); findMid();
  deleteNode(9); displayList(); findMid();
  deleteNode(10); displayList(); findMid();

  myfile.close();
  return 0;
}
