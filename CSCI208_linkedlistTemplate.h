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
template<class L>
class LinkedList
{
  private:
   Node<L>* headNodePtr;

  public:
    int count;
    void getCount(){cout << count;}

 // METHODS
   LinkedList ();
   bool empty();
   void clear();
   int size();
   void printList();

 /* INSERTION
    A new node is created and inserted in the linked list.
	There are four cases considered while inserting a node:
		Insertion at the start
		Insertion at the end
		Insertion at a particular position
		Insertion in order
 */
   void push_front(L);
   void push_back(L);
   void insert(int position, L value);
   void insert(L);


 /* DELETION
	There are also four cases in which a node can be deleted:
		Deletion at the start
		Deletion at the end
		Deletion at a particular position
		Deletion of a particular value
 */
  L pop_front();
  L pop_back();
  L removeAtPos (int);
  //L remove (int);
  L removeS(int);
  L removeR(int);

  // EXCEPTIONS THROWN
	static const int ItemNotFound = 8001;
	static const int IndexOutOfBoundsException = 8002;
	static const int ListIsEmpty = 8003;
};
/*==============================================================================
//                     IMPLEMENTATION OF METHOD/FUNCTIONS
//==============================================================================
********************************************************************************
 Class LinkedList
 Function:  Constructor
         Create am empty linked list
        This is indicated by a null pointer in the start of list (headNodePtr)
 ******************************************************************************/
template<class L>
LinkedList<L>::LinkedList()
{
	headNodePtr = NULL;
	count = 0;
}
/*******************************************************************************
 Class LinkedList
 Function:  size
 Parameters: None
  Returns an integer count of the number of items in the list
*******************************************************************************/
template<class L>
int LinkedList<L>::size()
{
  // Print each item on a new line
  cout << "size of list: " << count << endl;
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
template<class L>
void LinkedList<L>::printList()
{
   // Print each item on a new line
   Node<L>* p;
      for (p = headNodePtr; p != NULL; p = p->getNextPtr())
      {
        cout << p -> getItem() << endl;
      }
  }
/*******************************************************************************
  Class LinkedList
  Function:  clear
  Parameters: None

  Removes and deletes all the entries of the list
  Function:  isEmpty
  Returns void
*******************************************************************************/
template<class L>
void LinkedList<L>::clear()
{
  // Print each item on a new line
  Node<L>* p;
  for (p = headNodePtr; p != NULL; p = p->getNextPtr())
  {
    delete[] p;
    count--;
  }
  headNodePtr = NULL;
}
 /******************************************************************************
  Class LinkedList
  Function:  isEmpty
  Parameters: None
  Returns a bool that indicates if the linked list is or is not empty
*******************************************************************************/
template<class L>
bool LinkedList<L>::empty()
{
  // Print each item on a new line
  if(headNodePtr == NULL)
    return true;
  else
    return false;
}
//------------------------------  INSERTIONS  --------------------------------//
/*******************************************************************************
 Class LinkedList
 Function:  push_front
        Inserts a new item at the front of the list
        This routing will create a Node object to contain the item to add
 Parameters: item to add to the list
 Return: void
*******************************************************************************/
template<class L>
void LinkedList<L>::push_front(L item)
{
	// The headNodePtr currently points to the first node in the list or NULL
	// Create the new node with the item given and point it to the same node (or NULL) as the head

	// Set the head node pointer equal to the new node, now the first one in the list
  Node<L>* newnode = new Node<L>(item, headNodePtr);
  headNodePtr = newnode;
  count++;

   // Now the head node points to the new node and the new node points to the rest of the list.
}
/*******************************************************************************
 Class LinkedList
 Function:  push_back
        Inserts a new item at the end of the list
        This routing will create a Node object to contain the item to add
 Parameters: item to add to the list
 Return: void
*******************************************************************************/
template<class L>
void LinkedList<L>::push_back (L item)
{
  Node<L>* temp = new Node<L>(item, NULL);
  Node<L>* p = headNodePtr;
  if(empty())
  {
    headNodePtr = temp;
    count++;
    return;
  }
  for (int i = 0; i < (count-1); i++)
  {
    p = p -> getNextPtr();
  }
  p -> setNext(temp);
  count++;
}
/*******************************************************************************
  Class LinkedList
  Function:  insert
          Insert an item in the list at the position specified in the parameter.

  Note: be sure to explicitly hand the situation when the new node
        is added to the front of the list

  Parameters: Position in the container where the new elements are inserted.
              Item to add.

  Return: Void
  Exception thrown:  IndexOutOfBoundsException
 ******************************************************************************/
template<class L>
void  LinkedList<L>::insert(int position, L item)
{
  Node<L>* prevPtr = NULL;
  Node<L>* currPtr = headNodePtr;
  Node<L>* newPtr = new Node<L>(item, NULL );

  if((position < 0)||(position > count))
  {
    throw IndexOutOfBoundsException;
  }

  if(empty())
  {
    headNodePtr = newPtr;
    count++;
    return;
  }
  if(position == 1)
  {
    newPtr -> setNext(headNodePtr);
    headNodePtr = newPtr;
    count++;
    return;
  }

  // if(count < position)      was this
  while((currPtr != NULL)&&(position > count))   //testing this
  {
    count++;
    cout << "count: " << count << endl;
    cout << "COUNT IS LESS THAN POSITION\n";
    while(currPtr != NULL)
    {
      prevPtr = currPtr;
      currPtr = currPtr -> getNextPtr();
    }// while loop returns most current prevPtr and currPtr
    //puts newPtr between prevPtr and currPtr
    prevPtr -> setNext(newPtr);
    newPtr -> setNext(currPtr);
  }

  // while((currPtr != NULL)&&(position >= count))   was this
  if(position < count)      //testing this
  {
    count++;
    int p = 1;
    while(p != position)
    {
      prevPtr = currPtr;
      currPtr = currPtr -> getNextPtr();
      p++;
    }
    prevPtr -> setNext(newPtr);
    newPtr -> setNext(currPtr);
    return;
  }
}
/*******************************************************************************
  Class LinkedList
  Function:  insert
          Insert an item in the list IN ORDER. That is, it is inserted after all
          integers that are smaller than it and before integers that are larger than it
  Note: be sure to explicitly hand the situation when the new node
        is added to the front of the list
  Parameters: item to add.
  Return: Void
 ******************************************************************************/
template<class L>
void  LinkedList<L>::insert(L item)
{
  Node<L>* newPtr = new Node<L>(item, NULL);
  Node<L>* prevPtr = NULL;
  Node<L>* currPtr = headNodePtr;
  //condition if stack is empty
  if(empty())
  {
    //cout << "ITS EMPTY\n";
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
    return;
  }

  //loops through while parameter item is greater than currPtr item
  //while((currPtr != NULL)&&(item >= currPtr -> getItem()))
  while((currPtr != NULL)&&(item > currPtr -> getItem()))
  {
    prevPtr = currPtr;
    currPtr = currPtr -> getNextPtr();
  }// while loop returns most current prevPtr and currPtr
  //puts newPtr between prevPtr and currPtr
  prevPtr -> setNext(newPtr);
  newPtr -> setNext(currPtr);
}
//------------------------------  DELETIONS  ---------------------------------//
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
template<class L>
L LinkedList<L>::pop_front()
{
  if(empty())
  {
    throw ListIsEmpty;
  }
  Node<L>* newPtr = new Node<L>;
  L item;
  newPtr = headNodePtr;
  item = newPtr -> getItem();
  headNodePtr = headNodePtr -> getNextPtr();
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
template<class L>
L LinkedList<L>::pop_back()
{
  if(empty())
  {
    throw ListIsEmpty;
  }
  Node<L>* p = headNodePtr;
  Node<L>* prevPtr = NULL;

  for (int i = 0; i < (count-1); i++)
  {
    prevPtr = p;
    p = p -> getNextPtr();
  }
  L item = p -> getItem();
  delete [] p;
  prevPtr -> setNext(NULL);
  count--;
  return item;
}
/*******************************************************************************
 Class LinkedList
 Function: removeAtPos
        Remove an item from the list

	Note: be sure to handle the situation when this is the last node
	  in the list

 Parameters: item to remove.
 Return: item removed
 Exceptions thrown:  ListIsEmpty
 ******************************************************************************/
template<class L>
L LinkedList<L>::removeAtPos (int pos)
{
  Node<L>* prevPtr = headNodePtr;
  Node<L>* currPtr = headNodePtr;//was NULL
  //condition if stack is empty
  if(empty())
  {
    throw ListIsEmpty;
  }
  //if pos is larger than the list
  if(pos > count)
  {
    throw IndexOutOfBoundsException;
  }
  //if pos is the first in the list
  if(pos == 1)
  {
    L temp2 = headNodePtr->getItem();
    Node<L>* tempPtr = headNodePtr;
    headNodePtr = headNodePtr->getNextPtr();
    delete tempPtr;
    return temp2;
  }
  //loops through while parameter item is greater than currPtr item
  int step = 1;
  while(/*(currPtr != NULL)&&(pos != currPtr -> getItem())*/step < pos)
  {
    prevPtr = currPtr;
    currPtr = currPtr -> getNextPtr();
    step++;
  }// while loop returns currPtr as NULL |or| as =item=

  //if currPtr after while loop is =NULL=
  if(currPtr == NULL)
  {
    throw ItemNotFound;
  }
  //if currPtr after while loop is =item=

  //Node held in prevPtr now points to the node after currPtr
  prevPtr -> setNext(currPtr -> getNextPtr());
  L item3 = currPtr->getItem();
  delete [] currPtr;
  count --;
  return item3;
}
/*******************************************************************************
 Class LinkedList
 Function:  remove
        Remove an item from the list

	Note: be sure to handle the situation when this is the last node
	  in the list

 Parameters: item to remove.
 Return: item removed
 Exceptions thrown:  ListIsEmpty
 ******************************************************************************/
/*
template<class L>
L LinkedList<L>::remove(int item)
{
  Node<L>* prevPtr = headNodePtr;
  Node<L>* currPtr = headNodePtr;//was NULL
  //condition if stack is empty
  if(empty())
  {
    throw ListIsEmpty;
  }
  //if item is not on a one-item list
  if((headNodePtr->getItem() != item) && (count == 1))
  {
    throw ItemNotFound;
  }
  //if item points to the first node in the list
  if(headNodePtr->getItem() == item)
  {
    L temp2 = headNodePtr->getItem();
    Node<L>* tempPtr = headNodePtr;
    headNodePtr = headNodePtr->getNextPtr();
    delete tempPtr;
    return temp2;
  }
  //loops through while parameter item is greater than currPtr item
  while((currPtr != NULL)&&(item != currPtr -> getItem()))
  {
    prevPtr = currPtr;
    currPtr = currPtr -> getNextPtr();
  }// while loop returns currPtr as NULL |or| as =item=

  //if currPtr after while loop is =NULL=
  if(currPtr == NULL)
  {
    throw ItemNotFound;
  }
  //if currPtr after while loop is =item=

  //Node held in prevPtr now points to the node after currPtr
  prevPtr -> setNext(currPtr -> getNextPtr());
  L item3 = currPtr->getItem();
  delete [] currPtr;
  count --;
  return item3;
}
*/
/*******************************************************************************
 Class LinkedList
 Function:  remove
        Remove an item from the list

	Note: be sure to handle the situation when this is the last node
	  in the list

 Parameters: item to remove.
 Return: item removed
 Exceptions thrown:  ListIsEmpty
 ******************************************************************************/
template<class L>
L LinkedList<L>::removeS(int input)
{
  SUIT item;
  switch(input)
  {
    case 0: throw ItemNotFound;
      break;
    case 1: item = CLUBS;
      break;
    case 2: item = DIAMONDS;
      break;
    case 3: item = HEARTS;
      break;
    case 4: item = SPADES;
      break;
    default: throw ItemNotFound;
      break;
  }
  Node<L>* prevPtr = headNodePtr;
  Node<L>* currPtr = headNodePtr;//was NULL
  L temp2 = headNodePtr->getItem();
  SUIT comparison = temp2.getSUIT();
  //condition if stack is empty
  if(empty())
  {throw ListIsEmpty;}
  //if item is not on a one-item list
  if((comparison != item) && (count == 1))
  {throw ItemNotFound;}
  //if item points to the first node in the list
  if(comparison == item)
  {
    temp2 = headNodePtr->getItem();
    Node<L>* tempPtr = headNodePtr;
    headNodePtr = headNodePtr->getNextPtr();
    delete tempPtr;
    return temp2;
  }
  //loops through while parameter item is greater than currPtr item
  while((currPtr != NULL)&&(item != comparison))
  {
    prevPtr = currPtr;
    currPtr = currPtr -> getNextPtr();
    L temp3 = currPtr -> getItem();
    comparison = temp3.getSUIT();
  }// while loop returns currPtr as NULL |or| as =item=

  //if currPtr after while loop is =NULL=
  if(currPtr == NULL)
  {throw ItemNotFound;}
  //if currPtr after while loop is =item=

  //Node held in prevPtr now points to the node after currPtr
  prevPtr -> setNext(currPtr -> getNextPtr());
  L item3 = currPtr->getItem();
  delete [] currPtr;
  count --;
  return item3;
}
/*******************************************************************************
Class LinkedList
Function:  remove
      Remove an item from the list

Note: be sure to handle the situation when this is the last node
  in the list

Parameters: item to remove.
Return: item removed
Exceptions thrown:  ListIsEmpty
******************************************************************************/
template<class L>
L LinkedList<L>::removeR(int input)
{
  RANK item;
  switch(input)
  {
    case 0: throw ItemNotFound;
      break;
    case 1: item = ACE;
      break;
    case 2: item = TWO;
      break;
    case 3: item = THREE;
      break;
    case 4: item = FOUR;
      break;
    case 5: item = FIVE;
      break;
    case 6: item = SIX;
      break;
    case 7: item = SEVEN;
      break;
    case 8: item = EIGHT;
      break;
    case 9: item = NINE;
      break;
    case 10: item = TEN;
      break;
    case 11: item = JACK;
      break;
    case 12: item = QUEEN;
      break;
    case 13: item = KING;
      break;
    default: throw ItemNotFound;
      break;
  }
  Node<L>* prevPtr = headNodePtr;
  Node<L>* currPtr = headNodePtr;//was NULL
  L temp2 = headNodePtr->getItem();
  RANK comparison = temp2.getRANK();
  //condition if stack is empty
  if(empty())
  {throw ListIsEmpty;}
  //if item is not on a one-item list
  if((comparison != item) && (count == 1))
  {throw ItemNotFound;}
  //if item points to the first node in the list
  if(comparison == item)
  {
    temp2 = headNodePtr->getItem();
    Node<L>* tempPtr = headNodePtr;
    headNodePtr = headNodePtr->getNextPtr();
    delete tempPtr;
    return temp2;
  }
  //loops through while parameter item is greater than currPtr item
  while((currPtr != NULL)&&(item != comparison))
  {
    prevPtr = currPtr;
    currPtr = currPtr -> getNextPtr();
    L temp3 = currPtr -> getItem();
    comparison = temp3.getRANK();
  }// while loop returns currPtr as NULL |or| as =item=

  //if currPtr after while loop is =NULL=
  if(currPtr == NULL)
  {throw ItemNotFound;}
  //if currPtr after while loop is =item=

  //Node held in prevPtr now points to the node after currPtr
  prevPtr -> setNext(currPtr -> getNextPtr());
  L item3 = currPtr->getItem();
  delete [] currPtr;
  count --;
  return item3;
}
/*******************************************************************************
* PEEK
* Purpose: Returns the value of the head node
*******************************************************************************/

#endif
