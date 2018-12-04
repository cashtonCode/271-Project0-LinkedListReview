#include <iostream>
#include <cstddef>
//#include "card.h"
using namespace std;

template<class M>
class Node
{
public:
Node();      //constructor
Node(M, Node*);   //parameter constructor
M getCard();     //getter for card
Node* getNext();  //getter for pointer
void setCard(M);   // setter for card
void setNext(Node*); //setter for pointer

private:
  M myCard;
  Node* next;
};

/*************************************************************************
                  **CONSTRUCTOR**
*Input: None

*Output: None 

*Description: sets the pointer to NULL

**************************************************************************/
template<class M>
Node<M>::Node()
{
next = NULL;
}

/*************************************************************************
                  **PARAMETER CONSTRUCTOR **
*Input: None

*Output: None

*Description: sets the 2 objects(pointer and object of type M) within the 
class equal to the parameters of the function

**************************************************************************/
template<class M>
Node<M>::Node(M newCard, Node<M>* newNode)
{
next = newNode;
myCard = newCard;
}

/*************************************************************************
                  **GETCARD FUNCTION **
*Input: None

*Output: object of type M

*Description: returns myCard object from within class

**************************************************************************/
template<class M>
M Node<M>::getCard()
{
return myCard;
}

/**************************************************************************
                  **SETCARD FUNCTION **
*Input: object of type M

*Output: None

*Description: sets Mycard equal to the parameter within the function

***************************************************************************/
template<class M>
void Node<M>::setCard(M newCard)
{
myCard = newCard;
}
/**************************************************************************
                  **GETNEXT FUNCTION **
*Input: None

*Output: pointer of templated Node class

*Description: returns the pointer next 

***************************************************************************/
template<class M>
Node<M>* Node<M>::getNext()
{
return next;
}

/**************************************************************************
                  **SETNEXT FUNCTION **
*Input: Pointer of templated class Node

*Output: None

*Description: sets the pointer next equal to the parameter within the function

***************************************************************************/
template<class M>
void Node<M>::setNext(Node<M>* arg_next)
{
next = arg_next;
}
