#ifndef LINKEDLISTTEMPLATE_H
#define LINKEDLISTTEMPLATE_H
#include <cstdlib>
#include <iostream>
#include "Node.h"
using namespace std;

/*******************************************************************************
 Class LinkedList
 This class defines a data structure for a linked list of integers
*******************************************************************************/
template<class E>
class LinkedList
{
private:
  Node<E>* headNodePtr;

public:
  int count;

/******************************************************************************/
  LinkedList();
  void push_front (E item);
  void push_back(E item);
  void insert_in_order(E item);// - inserts item in its proper order in the linked list
  E pop_front();
  E pop_back();
  int size();
  void print_all();
/******************************************************************************/

  static const int ItemNotFound = 8001;
	static const int IndexOutOfBoundsException = 8002;
	static const int ListIsEmpty = 8003;
};

/*******************************************************************************
 Class LinkedList
 Function:  Constructor
         Create am empty linked list
        This is indicated by a null pointer in the start of list (headNodePtr)
 ******************************************************************************/
template<class E>
LinkedList<E>::LinkedList()
{
  headNodePtr = NULL;
	count = 0;
}
/*******************************************************************************
 Class LinkedList
 Function:  push_front
        Inserts a new item at the front of the list
        This routing will create a Node object to contain the item to add
 Parameters: item to add to the list
 Return: void
*******************************************************************************/
template<class E>
void LinkedList<E>::push_front (E item)
{
  Node<E>* newnode = new Node<E>(item, headNodePtr);
  headNodePtr = newnode;
  count++;
}
/*******************************************************************************
 Class LinkedList
 Function:  push_back
        Inserts a new item at the end of the list
        This routing will create a Node object to contain the item to add
 Parameters: item to add to the list
 Return: void
*******************************************************************************/
template<class E>
void LinkedList<E>::push_back(E item)
{
  Node<E>* temp = new Node<E>(item, NULL);
  Node<E>* p = headNodePtr;
  if(count==0)
  {
    headNodePtr = temp;
    count++;
    return;
  }
  for (int i = 0; i < (count-1); i++)
  {
    p = p -> getNext();
  }
  p -> setNext(temp);
  count++;
}
/*******************************************************************************
  Class LinkedList
  Function:  insert_in_order
          Insert an item in the list IN ORDER. That is, it is inserted after all
          integers that are smaller than it and before integers that are larger than it
  Note: be sure to explicitly hand the situation when the new node
        is added to the front of the list
  Parameters: item to add.
  Return: Void
 ******************************************************************************/
template<class E>
void LinkedList<E>::insert_in_order(E item)// - inserts item in its proper order in the linked list
{
  Node<E>* newPtr = new Node<E>(item, NULL);
  Node<E>* prevPtr = NULL;
  Node<E>* currPtr = headNodePtr;
  //condition if stack is empty
  if(count==0)
  {
    headNodePtr = newPtr;
    count++;
    return;
  }

  //inserting at the top of list
  //headNodePtr equal to currPtr -> getItem()
  if(item < currPtr -> getItem())
  {
    newPtr -> setNext(headNodePtr);
    headNodePtr = newPtr;
    count++;
    return;
  }

  //loops through while parameter item is greater than currPtr item
  while((currPtr != NULL)&&(item >= currPtr -> getItem()))
  {
    prevPtr = currPtr;
    currPtr = currPtr -> getNext();
  }// while loop returns most current prevPtr and currPtr
  //puts newPtr between prevPtr and currPtr
  prevPtr -> setNext(newPtr);
  newPtr -> setNext(currPtr);
  count++;
}
/*******************************************************************************
 Class LinkedList
 Function:  pop_front
        Deletes anitem from the front of the list
        This routing will return the value of the node at the top of the list
        Removes that node from the list
 Parameters: none
 Return: value of the first node
 Exception Returned: ListIsEmpty if list is empty
*******************************************************************************/
template<class E>
E LinkedList<E>::pop_front()
{
  if(count==0)
  {
    throw ListIsEmpty;
  }
  Node<E>* newPtr = new Node<E>;
  int item;
  newPtr = headNodePtr;
  item = newPtr -> getItem();
  headNodePtr = headNodePtr -> getNext();
  delete [] newPtr;
  count--;
  return item;
}
/*******************************************************************************
  Class LinkedList
  Function:  pop_back;
        Deletes an item from the back of the list
        This routing will return the value of the node at the end of the list
        Removes that node from the list
  Parameters: None
  Return: value of the last node
  Exception Returned: ListIsEmpty if list is empty
*******************************************************************************/
template<class E>
E LinkedList<E>::pop_back()
{
  if(count==0)
  {
    throw ListIsEmpty;
  }
  Node<E>* p = headNodePtr;
  Node<E>* prevPtr = NULL;

  for (int i = 0; i < (count-1); i++)
  {
    prevPtr = p;
    p = p -> getNext();
  }
  int item = p -> getItem();
  delete [] p;
  prevPtr -> setNext(NULL);
  count--;
  return item;
}
/*******************************************************************************
 Class LinkedList
 Function:  size
 Parameters: None
  Returns an integer count of the number of items in the list
*******************************************************************************/
template<class E>
int LinkedList<E>::size()
{
  return count;
}
/*******************************************************************************
 Class LinkedList
 Function:  printList
        Walks through the list looking for a node at the position passed.
        The position starts counting at 1. That is the first node in the list
        is at position 1.
        If that node is found, it removes the node from the list
        and returns the value.

        If the node is not found, signal an  exception: NodeAtPositionNotFound

 Parameters:  None
 Result:  List of item values is sent to the standard output device
 Return: Void
*******************************************************************************/
template<class E>
void LinkedList<E>::print_all()
{
  Node<E>* p;
  for (p = headNodePtr; p != NULL; p = p->getNext())
  {
    cout << p -> getItem() << endl;
  }
}
#endif
