#include <iostream>    	// IO operations
#include "linkedlist.h"  // Linked lists files

using namespace std;
// Function Prototype
int readInt(string); // function that reads in input from standard input

// START OF MAIN PROCESSING
int main()
{

   int choice;
   int item;
   int pos;
   LinkedList a;

   cout << "This program demonstrates the linked list. " << endl;
   cout << "Initially, you will be asked to create the list." << endl;
   cout << "You will be later prompted to manipulate the list." <<endl << endl;

   cout << "*******************************************************" << endl;
   cout << "1: isEmpty() (Indicate whether the list is empty)\n";
   cout << "2: size() (Count the number of items in the list)\n";
   cout << "3: printList()  (Print the content of the current list)\n";
   cout << "4: clear() (Clears or empties the list\n";
   cout << "5: push_front(int)(Insert an element at the beginning of the list)\n";
   cout << "6: push_back(int) (Append an element to the end of the list)\n";
   cout << "7: insert(int position, int value) (Insert an element at given position)\n";
   cout << "8: insert(int value) (Insert an element in order ) \n";
   cout << "9: pop_front()(Remove an element at the beginning of the list)\n";
   cout << "10: pop_back(int) (Remove an element to the end of the list)\n";
   cout << "11: removeAtPos(int) (Return and delete a node at a given position)\n";
   cout << "12: remove(int value) (Remove an element from the list ) \n";

   cout << "99: Quit   (Quit the program)\n";
   cout << "*******************************************************" << endl << endl;
   cout << "\n   Please enter your choice here:  ";
   cin >> choice;

  while(choice != 99)
  {
    int choiceInt = choice;

    switch(choiceInt)
    {
      case 1:  //isEMPTY : Indicate whether the list is empty
        cout << "isEmpty Test" << endl;
        cout << endl<< endl;
        break;

      case 2:  // SIZE: Count the number of items in the list
        cout << "size Test: ";
        a.getCount();
        cout << endl<< endl;
        break;

      case 3: // PRINTLIST: Print the content of the current list
        a.printList();
        cout << endl<< endl;
        break;

      case 4:  //CLEAR: Clears or empties the list
        a.clear();
        a.printList();
        cout << endl<< endl;
        break;

      // INSERTION METHODS
      case 5:  // PUSH_FRONT: Insert an element at the beginning of the list
        cout << "PUSH_FRONT FUNCTION TEST\n\n" ;
        cout << "enter number: ";
        cin >> item;
        a.push_front(item);
        a.printList();
        cout << endl<< endl;
        break;

      case 6: 	 // PUSH_BACK: Append an element to the end of the list
        cout << "PUSH_BACK FUNCTION TEST\n \n";
        cout << "enter number: ";
        cin >> item;
        a.push_back(item);
        a.printList();
        cout << endl<< endl;
        break;

      case 7: 	 // INSERT: Insert an element at given position
        int  pos;
        cout << "please enter position: ";
        cin >> pos;
        cout << "please enter an integer value: ";
        cin >> item;
        try
        {
          a.insert(pos, item);
          a.printList();
        } catch(int exception)
        {
          cout << "OUT OF BOUNDS\n";
        }
        cout << endl<< endl;
        break;

      case 8: 	 // INSERT: Insert an element in order
        cout << "enter integer value: ";
        cin >> item;
        try
        {
          a.insert(item);
        }
        catch(int e)
        {
          if(e==8001){cout << "Item Not Found" << endl;}
          else if(e==8002){cout << "Index Out of Bounds" << endl;}
          else if(e==8003){cout << "List is Empty" << endl;}
        }
        a.printList();
        cout << endl<< endl;
        break;

      // DELETION METHODS
      case 9: // POP_FRONT : Remove first element in list
        a.pop_front();
        a.printList();
        cout << endl<< endl;
        break;

      case 10: // POP_BACK: Remove last element in list
        a.pop_back();
        a.printList();
        cout << endl<< endl;
        break;

      case 11: // REMOVEATPOS: Return and delete a node at a given position
        cout << "What position do you want to remove: ";
        cin >> item;
        try
        {
          a.removeAtPos(item);
        }
        catch(int e)
        {
          if(e==8001){cout << "Item Not Found" << endl;}
          else if(e==8002){cout << "Index Out of Bounds" << endl;}
          else if(e==8003){cout << "List is Empty" << endl;}
        }
        a.printList();
        cout << endl<< endl;
        break;

      case 12: // REMOVEP: Return a specific element
        cout << "Enter integer: ";
        cin >> item;
        try
        {
        a.remove(item);
        }
        catch(int e)
        {
          if(e==8001){cout << "Item Not Found" << endl;}
          else if(e==8002){cout << "Index Out of Bounds" << endl;}
          else if(e==8003){cout << "List is Empty" << endl;}
        }
        a.printList();
        cout << endl<< endl;
        break;

      default:
        cout << "\n Invalid choice. Please try again.\n";
        break;
    }

	cout<<"\n   Please enter your next choice here:  ";
	cin>>choice;
   }
   cout<<"\n Bye\n";
   return 0;
}

int readInt(string descr)
{
  int item;
  cout << "\n   Please enter an integer value " << descr;
  cin >> item;

	while (cin.fail()) // no extraction took place
  {
    cout << "\n Please try again:";
    cin.clear(); // reset the state bits back to goodbit so we can use ignore()
    cin.ignore(1000, '\n'); // clear out the bad input from the stream
    cin >> item;
  }

   while (item < 0)
   {
      cout << "\n Please try again:";
      cin >> item;
   }
   return item;
}
