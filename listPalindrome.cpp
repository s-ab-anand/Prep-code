#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include "node.h"
using namespace std;

bool checkPalindrome(struct Node* head, int count){
  struct Node* start, *end, *mid, *prev;
  start = head; end = start;
  while(end->next){
    prev = start;
    start = start->next;
    if (end->next->next){
      end = end->next->next;
    } else{
      start = prev;
      end = end->next;
    }
  }
  mid = start->next;
  struct Node* rev = mid->next;
  while(rev){
    mid->next = start;
    start = mid; mid = rev;
    rev = rev->next;
  }
  mid->next = start;
  start = head; count/=2;
  while (count > 0){
    if (start->val != mid->val){
      cout<<"Not palindromes" << endl;
      return false;
    } else {
      start = start->next; mid = mid->next;
      --count;
    }
  }
  cout<<"Palindrome"<<endl;
  return true;
}
int main(int argc, char* argv[])
{
  struct Node* head = NULL;
  if (argc < 0){
    cout<<"Insufficient arguments"<<endl;
    return 0;
  }
  if (argc > 1){
    for (int i = 0; i < (argc-1); i++){
      stringstream sobj(argv[i+1]);
      if (!head){
        Node* newNode = new Node();
        head = newNode;
        sobj >> head->val;
        head->next = NULL;
      } else {
        struct Node* start = head;
        while (start->next){
          start = start->next;
        }
        Node* newNode = new Node();
        sobj >> newNode->val;
        newNode->next = NULL;
        start->next = newNode;
      }
    }
  }
  struct Node* len = head; int count = 1;
  while (len->next){
    len = len->next;
    ++count;
  }
  cout<<"length of the list is "<<count<<endl;
  bool res = checkPalindrome(head, count);
  do{
    struct Node* curr = head;
    head = head->next;
    curr->next = NULL;
    free(curr);
  } while (head);
  return 0;
}
