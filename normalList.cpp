#include <iostream>
#include <fstream>
#include <new>
#include <cstdlib>
#include <string>
#include <sstream>
#include <climits>
#include <map>

using namespace std;

struct node {
  int val;
  struct node* next;
};
struct node* head = NULL;
struct node* head1 = NULL;
struct node* head2 = NULL;


bool isEmpty()
{
  return (head == NULL) ? true : false;
}

bool isEmpty(struct node* h)
{
  return (h == NULL) ? true : false;
}


void displayList()
{
  struct node* ptr = head;
  while (ptr!=NULL){
    cout << ptr->val << "-->";
    ptr = ptr->next;
  }
  cout << endl;
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

struct node* reverseListRec(struct node *curr)
{
  if (curr->next == NULL){
    head = curr;
    return curr;
  } else {
    struct node *ptr = reverseListRec(curr->next);
    ptr->next = curr;
    return curr;
  }
}
void reverseList2()
{
  if (!isEmpty()) {
    struct node *prev, *curr, *nn;
    prev = NULL; nn = NULL; curr = head;
    while (curr != NULL){
      nn = curr->next;
      curr->next = prev;
      prev = curr; curr = nn;
    }
    head = prev;
  }
}
void reverseList()
{
  if (!isEmpty()) {
    struct node *first, *second, *third;
    first = head;
    second = first->next;
    third = (head->next)->next;
    first->next = NULL;
    second->next = first;
    first = second;
    second = third;
    while (third->next != NULL){
      third = third->next;
      second->next = first;
      first = second;
      second = third;
    }
    third->next = first;
    head = third;
    }
}
void addNode (int num)
{
  if (!isEmpty()){
    struct node* newNode = new node();
    newNode->val = num; newNode->next = head;
    head = newNode;
  } else {
    struct node* newNode = new node();
    newNode->val = num; newNode->next = NULL;
    head = newNode;
  }
}

void addNode (struct node** h, int num)
{
  struct node* newNode = new node();
  newNode->val = num; newNode->next = *h;
  *h = newNode;

}

struct node* mergeSortedLists(struct node **head1, struct node **head2)
{
  struct node *ptr1, *ptr2, *indx;
  struct node * newHead = ((*head1)->val > (*head2)->val) ? *head1 : *head2;
  ptr1 = *head1; ptr2 = *head2;
  while (ptr1 && ptr2){
    if (ptr1->val > ptr2->val){
      while (ptr1->next && (ptr1->next)->val > ptr2->val){
        ptr1 = ptr1->next;
      }
      indx = ptr1->next;
      ptr1->next = ptr2;
      ptr1 = indx;
    } else {
      while (ptr2->next && (ptr2->next)->val > ptr1->val){
        ptr2 = ptr2->next;
      }
      indx = ptr2->next;
      ptr2->next = ptr1;
      ptr2 = indx;
    }
  }
  return newHead;
}
void pairwiseSwap()
{
  struct node *ptr = head;

  while (ptr && ptr->next){
    int temp = (ptr->next)->val;
    (ptr->next)->val = ptr->val;
    ptr->val = temp;
    ptr = (ptr->next)->next;
  }
}

void pairwiseSwapRec(struct node *head)
{
  cout << "swapping " << head->val << endl;
  if (head && head->next){
    int temp = (head->next)->val;
    head->next->val = head->val;
    head->val = temp;
  }
  if (head->next->next)
    pairwiseSwapRec(head->next->next);
}

void removeNode(struct node *head, struct node *n)
{
  struct node *ptr = head; struct node *prev = NULL;
  while (ptr){
    if (ptr == n){
      if (prev){
        prev->next = ptr->next;
        ptr->next = NULL;
        ptr = NULL;
      }
    } else {
      prev = ptr; ptr = ptr->next;
    }
  }
}
void detectDuplicate(struct node *head)
{
  struct node *ptr = head;
  std::map<int, int> mapList;
  while (ptr){
    if (mapList.find(ptr->val) == mapList.end()){
      mapList[ptr->val] = ptr->val;
      ptr = ptr->next;
    } else {
      //remove node
      //cout<<"Duplicate node " << ptr->val << endl;
      struct node *nextP = ptr->next;
      removeNode(head, ptr);
      ptr = nextP;
    }
  }
  std::map<int, int>::iterator it;
  for (it = mapList.begin();it != mapList.end(); ++it){
    cout << it->second << "\t" ;
  }
  cout << endl;
}
int main(int argc, char* argv[])
{
  int num; string line;
  ifstream myfile(argv[1]);
  if (myfile.is_open()){
    while (getline(myfile, line, ',')){
      stringstream obj(line);
      obj >> num;
      addNode(&head, num);
    }
  }
  displayList(head);
  pairwiseSwap();
  displayList(head);
  struct node *ptr = head;
  pairwiseSwapRec(head);
  displayList(head);
  detectDuplicate(head);
  displayList(head);
  /*if (myfile.is_open()){
    while (getline(myfile, line, '\n')){
      stringstream obj(line);
      obj >> num;
      addNode(&head1, num);
    }
  }
  displayList(head1);

  int num2; string line2;
  ifstream myfile1(argv[2]);
  if (myfile1.is_open()){
    while (getline(myfile1, line2, '\n')){
      stringstream obj(line2);
      obj >> num2;
      addNode(&head2, num2);
    }
  }
  displayList(head2);
  struct node* newHead = mergeSortedLists(&head1, &head2);
  //reverseList2();
  displayList(newHead);*/
  //struct node* curr = reverseListRec(head);
  //curr->next = NULL;
  //displayList();


}
