#include <iostream>
#include <fstream>
#include <new>
#include <cstdlib>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

struct node {
  int val;
  struct node* next;
};
struct node* head = NULL;
struct node* head1 = NULL;
struct node* head2 = NULL;
struct node* result = NULL;

bool isEmpty(struct node* h)
{
  return (h == NULL) ? true : false;
}

void displayList(struct node* h)
{
  struct node* ptr = h;
  while (ptr!=NULL){
    cout << ptr->val << "-->";
    ptr = ptr->next;
  }
  cout << endl;
}

void addNode (struct node** h, int num)
{
  struct node* newNode = new node();
  newNode->val = num; newNode->next = *h;
  *h = newNode;
}

void getIntersection(struct node **head1, struct node **head2)
{
  struct node *a = *head1;
  struct node *b = *head2;

  while (a && b){
    if (a->val == b->val){
      //cout << "Common" << endl;
      addNode(&result, a->val);
      a = a->next; b = b->next;
    } else {
      if (a->val > b->val){
        a = a->next;
      } else {
        b = b->next;
      }
    }
  }
}

void getIntersectionR(struct node *head1, struct node *head2)
{
  if (head1 && head2){
    if (head1->val == head2->val){
      addNode(&result, head1->val);
      getIntersectionR(head1->next, head2->next);
    } else {
      if (head1->val > head2->val){
        getIntersectionR(head1->next, head2);
      } else {
        getIntersectionR(head1, head2->next);
      }
    }
  }
}

int main(int argc, char* argv[])
{
  int num; string line;
  ifstream myfile(argv[1]);
  if (myfile.is_open()){
    while (getline(myfile, line, '\n')){
      stringstream obj(line);
      obj >> num;
      addNode(&head1, num);
    }
  }
  displayList(head1);

  ifstream myfile1(argv[2]);
  if (myfile1.is_open()){
    while (getline(myfile1, line, '\n')){
      stringstream obj(line);
      obj >> num;
      addNode(&head2, num);
    }
  }
  displayList(head2);

  getIntersectionR(head1, head2);

  displayList(result);

  myfile.close(); myfile1.close();

  return 0;
}
