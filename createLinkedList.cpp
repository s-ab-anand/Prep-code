#include<iostream>
#include<fstream>
#include<new>
#include<cstdlib>
#include<string>
#include<sstream>
#include "node.h"
using namespace std;

class MyLinkedList{
public:
    struct Node* head;
  public:
    MyLinkedList();
    struct Node* addNode(int val);
    struct Node* addNodefromFile(MyLinkedList);
    int travelList(int counter);
    void printList();
};
//member function declarations
MyLinkedList::MyLinkedList()
{
  head = NULL;
}
struct Node* MyLinkedList::addNode(int val)
{
  Node* myNode = new Node();
  myNode->val = val;
  myNode->next = NULL;
  if (head){
    myNode->next = head;
    head = myNode;
    return head;
  } else {
    head = myNode;
    return head;
  }
}

/*struct Node* MyLinkedList::travelList(int counter){
  struct Node* start;
  int c = 0;
  start = head;
  if (counter == 1){
    return head->val;
  } else if (counter < 0){
    return -1;
  } else {

  }
}*/
void MyLinkedList::printList(){
  struct Node* start;
  start = head;
  while(start){
    cout<<start->val<<"\t";
    start = start->next;
  }
  cout<<"\n";
}
void readinFile(MyLinkedList* obj)
{
  ifstream myFile ("arrInt_100.txt");
  string line; int num = 0;
  if (myFile.is_open()){
    while(getline(myFile, line, ',')){
      stringstream sobj(line);
      sobj >> num;
      (*obj).addNode(num);
    }
  }
}

int getNodeNum(MyLinkedList* obj, int num){
  struct Node* start;
  struct Node* travel;
  start = (*obj).head; travel = start;
  int count = 1;
  while (travel){
    count++;
    travel = travel->next;
  }
  //int fquat = count/4; int squat = count/2; int tquat = 3*(count/4);
  travel = start; count = 1;
  while (travel){
    if (count == num){
      //cout<<"First quartile value in the list = "<<travel->val<<"\n";
      return travel->val;
    }
    /*if (count == squat){
      cout<<"Second quartile value in the list = "<<travel->val<<"\n";
    }
    if (count == tquat){
      cout<<"Third quartile value in the list = "<<travel->val<<"\n";
    }*/
    travel = travel->next;
    count++;
  }
  return -1;
}

int equalLinkedList(struct Node* head1, struct Node* head2)
{
  struct Node* list1 = head1; struct Node* list2 = head2;
  while (list1 && list2){
    if (list1->val != list2->val){
      return -1;
    }
    list1 = list1->next;
    list2 = list2->next;
  }
  if (!list1){
    if (!list2){
      return 1;
    } else{
      return -1;
    }
  }
  return -1;
}

struct Node* reverseLinkedList(struct Node* head1)
{
  struct Node* first = head1;
  struct Node* second = first->next;
  struct Node* third = second->next;
  first->next = NULL;
  second->next = first;
  first = second; second = third;
  while (third->next){
    third = third->next;
    second->next = first;
    first = second; second = third;
  }
  third->next = first;
  return third;
}

void newprintList(struct Node* list1){
  struct Node* start;
  start = list1;
  while(start){
    cout<<start->val<<"\t";
    start = start->next;
  }
  cout<<"\n";
}

void reversePrint(struct Node* list)
{
  if (list->next == NULL){
    cout<<list->val<<"\t";
  } else{
    reversePrint(list->next);
    cout<<list->val<<"\t";
  }

}
// Main function
int main(int argc, char* argv[])
{
  MyLinkedList myList1;
  //myList.addNode(1);
  //myList.addNode(2);

  // creating a list of 100 nodes
  readinFile(&myList1);
  //myList.printList();
  newprintList(myList1.head);
  // values of the first, second and third quaters of the list
//  cout<<getNodeNum(&myList, 25)<<"\n";
//  cout<<getNodeNum(&myList, 50)<<"\n";
//  cout<<getNodeNum(&myList, 100)<<"\n";
  cout<<"Printing reverse\n";
  //newprintList(reverseLinkedList(myList1.head));
  MyLinkedList myList2;
  readinFile(&myList2);
  struct Node* head2 = reverseLinkedList(myList2.head);
  //cout<< equalLinkedList(myList1.head, head2)<<"\n";
  reversePrint(head2);
  // search for a value in the linked list

}
