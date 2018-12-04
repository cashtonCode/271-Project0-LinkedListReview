#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <iostream>

#include "nodes.h"

using namespace std;

/******************************************************************
 Class LinkedList
 This class defines a data structure for a linked list of integers
*******************************************************************/
class LinkedList
{
  private:
   Node<int>* headNodePtr;

  public:
    int count;
    void getCount(){cout << count;}

 // METHODS
   LinkedList ();
   bool empty();
   void clear();
   int size();//**
   void printList();//**

 /* INSERTION
    A new node is created and inserted in the linked list.
	There are four cases considered while inserting a node:
		Insertion at the start
		Insertion at the end
		Insertion at a particular position
		Insertion in order
 */
   void push_front(int);//**
   void push_back(int);//**
   void insert(int position, int value);
   void insert(int);//**


 /* DELETION
	There are also four cases in which a node can be deleted:
		Deletion at the start
		Deletion at the end
		Deletion at a particular position
		Deletion of a particular value
*/
   int pop_front();//**
   int pop_back();//**
   int removeAtPos (int );
   int remove (int);

  // EXCEPTIONS THROWN
	static const int ItemNotFound = 8001;
	static const int IndexOutOfBoundsException = 8002;
	static const int ListIsEmpty = 8003;
};

/*=====================================================================
//     IMPLEMENTATION OF METHOD/FUNCTIONS
//=====================================================================
******************************************************************
 Class LinkedList
 Function:  Constructor
         Create am empty linked list
        This is indicated by a null pointer in the start of list (headNodePtr)
 *******************************************************************/
LinkedList::LinkedList()
{
	headNodePtr = NULL;
	count = 0;
}
/******************************************************************
 Class LinkedList
 Function:  size
 Parameters: None
  Returns an integer count of the number of items in the list
*******************************************************************/
int LinkedList::size()
{
  // Print each item on a new line
  cout << "size of list: " << count << endl;
}
/******************************************************************
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
*******************************************************************/
void LinkedList::printList ()
{
   // Print each item on a new line
   Node<int>* p;
      for (p = headNodePtr; p != NULL; p = p->getNext())
      {
        cout << p -> getCard() << endl;
      }
  }
 /******************************************************************
  Class LinkedList
  Function:  clear
  Parameters: None

  Removes and deletes all the entries of the list
  Function:  isEmpty
  Returns void
*******************************************************************/
void LinkedList::clear()
{
  // Print each item on a new line
  Node<int>* p;
  for (p = headNodePtr; p != NULL; p = p->getNext())
  {
    delete[] p;
    count--;
  }
  headNodePtr = NULL;
}
 /******************************************************************
  Class LinkedList
  Function:  isEmpty
  Parameters: None
  Returns a bool that indicates if the linked list is or is not empty
*******************************************************************/
bool LinkedList::empty()
{
  // Print each item on a new line
  if(headNodePtr == NULL)
  {
   return true;
  }
  else
    return false;
}
//   -----------------  INSERTIONS  --------------------//
/******************************************************************
 Class LinkedList
 Function:  push_front
        Inserts a new item at the front of the list
        This routing will create a Node object to contain the item to add
 Parameters: item to add to the list
 Return: void
*******************************************************************/
void LinkedList::push_front(int item)
{
	// The headNodePtr currently points to the first node in the list or NULL
	// Create the new node with the item given and point it to the same node (or NULL) as the head

	 //REPLACE THE LINE BELOW WITH YOUR OWN CODE
   //cout << "You must implement this function" <<endl;

	// Set the head node pointer equal to the new node, now the first one in the list
      //REPLACE THE LINE BELOW WITH YOUR OWN CODE
  Node<int>* newnode = new Node<int>(item, headNodePtr);
  headNodePtr = newnode;
  count++;

   // Now the head node points to the new node and the new node points to the rest of the list.
}
/******************************************************************
 Class LinkedList
 Function:  push_back
        Inserts a new item at the end of the list
        This routing will create a Node object to contain the item to add
 Parameters: item to add to the list
 Return: void
*******************************************************************/
void LinkedList::push_back (int item)
{
  Node<int>* temp = new Node<int>(item, NULL);
  Node<int>* p = headNodePtr;
  if(empty())
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
/******************************************************************
  Class LinkedList
  Function:  insert
          Insert an item in the list at the position specified in the parameter.

  Note: be sure to explicitly hand the situation when the new node
        is added to the front of the list

  Parameters: Position in the container where the new elements are inserted.
              Item to add.

  Return: Void
  Exception thrown:  IndexOutOfBoundsException
 *******************************************************************/
void  LinkedList::insert(int position, int item)
{
  Node<int>* prevPtr = NULL;
  Node<int>* currPtr = headNodePtr;
  Node<int>* newPtr = new Node<int>(item, NULL );

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
      cout<< "while LOOPING\n";
      prevPtr = currPtr;
      currPtr = currPtr -> getNext();
    }// while loop returns most current prevPtr and currPtr
    cout<< "END WHILE LOOP\n";
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
      currPtr = currPtr -> getNext();
      p++;
    }
    prevPtr -> setNext(newPtr);
    newPtr -> setNext(currPtr);
    return;
  }
}
/******************************************************************
  Class LinkedList
  Function:  insert
          Insert an item in the list IN ORDER. That is, it is inserted after all
          integers that are smaller than it and before integers that are larger than it
  Note: be sure to explicitly hand the situation when the new node
        is added to the front of the list
  Parameters: item to add.
  Return: Void
 *******************************************************************/
void  LinkedList::insert(int item)
{
  cout << "START INSERT FUNCTION!\n";
  Node<int>* newPtr = new Node<int>(item, NULL);
  Node<int>* prevPtr = NULL;
  Node<int>* currPtr = headNodePtr;
  //condition if stack is empty
  if(empty())
  {
    cout << "ITS EMPTY\n";
    headNodePtr = newPtr;
    count++;
    return;
  }

  //inserting at the top of list
  //headNodePtr equal to currPtr -> getCard()
  if(item < currPtr -> getCard())
  {
    newPtr -> setNext(headNodePtr);
    headNodePtr = newPtr;
    return;
  }

  //loops through while parameter item is greater than currPtr item
  cout<< "START LOOP\n";
  while((currPtr != NULL)&&(item >= currPtr -> getCard()))
  {
    cout<< "while LOOPING\n";
    prevPtr = currPtr;
    currPtr = currPtr -> getNext();
  }// while loop returns most current prevPtr and currPtr
  cout<< "END LOOP\n";
  //puts newPtr between prevPtr and currPtr
  prevPtr -> setNext(newPtr);
  newPtr -> setNext(currPtr);
}
//   -----------------  DELETIONS  --------------------//
/******************************************************************
 Class LinkedList
 Function:  pop_front
        Deletes anitem from the front of the list
        This routing will return the value of the node at the top of the list
        Removes that node from the list
 Parameters: none
 Return: value of the first node
 Exception Returned: ListIsEmpty if list is empty
*******************************************************************/
int LinkedList::pop_front()
{
  if(empty())
  {
    throw ListIsEmpty;
  }
  Node<int>* newPtr = new Node<int>;
  int item;
  newPtr = headNodePtr;
  item = newPtr -> getCard();
  headNodePtr = headNodePtr -> getNext();
  delete [] newPtr;
  count--;
  return item;
}
/******************************************************************
  Class LinkedList
  Function:  pop_back;
        Deletes an item from the back of the list
        This routing will return the value of the node at the end of the list
        Removes that node from the list
  Parameters: None
  Return: value of the last node
  Exception Returned: ListIsEmpty if list is empty
*******************************************************************/
int LinkedList::pop_back()
{
  if(empty())
  {
    throw ListIsEmpty;
  }
  Node<int>* p = headNodePtr;
  Node<int>* prevPtr = NULL;

  for (int i = 0; i < (count-1); i++)
  {
    prevPtr = p;
    p = p -> getNext();
  }
  int item = p -> getCard();
  delete [] p;
  prevPtr -> setNext(NULL);
  count--;
  return item;
}
/******************************************************************
 Class LinkedList
 Function: removeAtPos
        Remove an item from the list

	Note: be sure to handle the situation when this is the last node
	  in the list

 Parameters: item to remove.
 Return: item removed
 Exceptions thrown:  ListIsEmpty
 *******************************************************************/
int LinkedList::removeAtPos (int pos)
{
  Node<int>* prevPtr = headNodePtr;
  Node<int>* currPtr = headNodePtr;//was NULL
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
    int temp2 = headNodePtr->getCard();
    Node<int>* tempPtr = headNodePtr;
    headNodePtr = headNodePtr->getNext();
    delete tempPtr;
    return temp2;
  }
  //loops through while parameter item is greater than currPtr item
  int step = 1;
  while(/*(currPtr != NULL)&&(pos != currPtr -> getCard())*/step < pos)
  {
    prevPtr = currPtr;
    currPtr = currPtr -> getNext();
    step++;
  }// while loop returns currPtr as NULL |or| as =item=

  //if currPtr after while loop is =NULL=
  if(currPtr == NULL)
  {
    throw ItemNotFound;
  }
  //if currPtr after while loop is =item=

  //Node held in prevPtr now points to the node after currPtr
  prevPtr -> setNext(currPtr -> getNext());
  int item3 = currPtr->getCard();
  delete [] currPtr;
  count --;
  return item3;
}
/******************************************************************
 Class LinkedList
 Function:  remove
        Remove an item from the list

	Note: be sure to handle the situation when this is the last node
	  in the list

 Parameters: item to remove.
 Return: item removed
 Exceptions thrown:  ListIsEmpty
 *******************************************************************/
int  LinkedList::remove(int item)
{
  Node<int>* prevPtr = headNodePtr;
  Node<int>* currPtr = headNodePtr;//was NULL
  //condition if stack is empty
  if(empty())
  {
    throw ListIsEmpty;
  }
  //if item is not on a one-item list
  if((headNodePtr->getCard() != item) && (count == 1))
  {
    throw ItemNotFound;
  }
  //if item points to the first node in the list
  if(headNodePtr->getCard() == item)
  {
    int temp2 = headNodePtr->getCard();
    Node<int>* tempPtr = headNodePtr;
    headNodePtr = headNodePtr->getNext();
    delete tempPtr;
    return temp2;
  }
  //loops through while parameter item is greater than currPtr item
  while((currPtr != NULL)&&(item != currPtr -> getCard()))
  {
    prevPtr = currPtr;
    currPtr = currPtr -> getNext();
  }// while loop returns currPtr as NULL |or| as =item=

  //if currPtr after while loop is =NULL=
  if(currPtr == NULL)
  {
    throw ItemNotFound;
  }
  //if currPtr after while loop is =item=

  //Node held in prevPtr now points to the node after currPtr
  prevPtr -> setNext(currPtr -> getNext());
  int item3 = currPtr->getCard();
  delete [] currPtr;
  count --;
  return item3;
}

#endif
