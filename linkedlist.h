#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

using namespace std;

class LinkedList;

class ListNode
{
  int offset;
  ListNode* next;
  
  ListNode(int data, ListNode* n):
    offset(data), next(n) {} 
  friend LinkedList;
  friend ostream& operator<<(ostream& os, const LinkedList& l);
}; //ListNode

class LinkedList
{
public:
 static const int EMPTY = -1; 
private:
 ListNode* head;
 friend ostream& operator<<(ostream& os, const LinkedList& l);
public:
  void initialize(int numSeats);
  ~LinkedList();
  int operator[](int seatNum) const;
  int& operator[](int seatNum); 
}; //LinkedList

#endif //_LINKEDLIST_H
