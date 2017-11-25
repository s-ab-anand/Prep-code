#include<iostream>
#include<fstream>
#include "node.h"
using namespace std;

class MyLinkedList{
  private:
    struct Node* head;
  public:
    MyLinkedList(){
      head = NULL;
    }
    struct Node* addNode(int val){
      Node* myNode = new Node();
      myNode->val = val;
      myNode->next = NULL;
      head = myNode;
      return head;
    }
    void printList(){
      struct Node* start;
      start = head;
      while(start){
        cout<<start->val<<"\t";
        start = start->next;
      }
      cout<<"\n";
    }

};
int main(int argc, char* argv[])
{
  MyLinkedList myList;
  myList.addNode(1);
  myList.addNode(2);
  myList.printList();
}
