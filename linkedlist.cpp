#include <iostream>
#include "linkedlist.h"

using namespace std;

void LinkedList::initialize(int numSeats)
{
  int i;
  head = NULL;
 
  for(i = 0; i < numSeats; i++)
    head = new ListNode(EMPTY, head);
	
} //initialize();

LinkedList::~LinkedList()
{
  
  for(ListNode *ptr = head; ptr; ptr = head)
  {
    head = ptr->next;
    delete ptr;
  } // for each ptr

} //~LinkedList()

int LinkedList::operator[](int seatNum) const
{
  int i;
  ListNode* ptr = head;

  for(i = 0; i < seatNum; i++)
     ptr = ptr->next;

  return ptr->offset;
} //operator[]const

int& LinkedList::operator[](int seatNum)
{
  int i;
  ListNode* ptr = head;

  for(i = 0; i < seatNum; i++)
    ptr = ptr->next;

  return ptr->offset;
} //operator[]nonconst

ostream& operator<<(ostream& os, const LinkedList& l)
{
  ListNode* ptr = l.head;

  while(ptr)
  {
    if(ptr->offset != LinkedList::EMPTY)
      os << 'X';
    else  // empty seat
      os << '-';
    ptr = ptr->next;
  } // while not NULL
  
  os << endl;
  return os;
} //showgrid()
