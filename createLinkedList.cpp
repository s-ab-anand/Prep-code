#include<iostream>
#include<fstream>
#include<new>
#include<cstdlib>
#include<string>
#include<sstream>
#include "node.h"
using namespace std;

class MyLinkedList{
  private:
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

int getNodeNum(MyLinkedList* obj){

}
// Main function
int main(int argc, char* argv[])
{
  MyLinkedList myList;
  //myList.addNode(1);
  //myList.addNode(2);

  // creating a list of 100 nodes
  readinFile(&myList);
  myList.printList();

  // values of the first, second and third quaters of the list
  cout<<getNodeNum(&myList, 25)<<"\n";
  cout<<getNodeNum(&myList, 50)<<"\n";
  cout<<getNodeNum(&myList, 100)<"\n";


  // search for a value in the linked list

}
