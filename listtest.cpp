#include "Node.h"
#include "Project0.h"

/*Methods of Class LinkedList in Project0.h

void push_front (E item);       // inserts item to the front of the linked list
void push_back(E item);         // inserts item to the back  of the linked list
void insert_in_order(E item);   // inserts item in its proper order in the linked list
E pop_front();                  // returns and removes item from the front of the linked list
E pop_back();                   // returns and removes item from the back  of the linked list
int size();                     // returns the amount of items in the linked list
void print_all();               // returns the values from front-to-back of the linked list
*/

using namespace std;
int main()
{
  char pause;

  cout << "~~~~~Int~~~~~" << endl;

  LinkedList<int> a;

  cout << "Push Front (1) Test:" << endl;
  a.push_front(1);
  cout << "Current List: " << endl;
  a.print_all();
  //cin >> pause;

  cout << "Push Back (8) Test:" << endl;
  a.push_back(8);
  cout << "Current List: " << endl;
  a.print_all();
  cout << "Current Size: " << a.size() << endl;
  //cin >> pause;

  cout << "Insert In Order (2) Test:" << endl;
  a.insert_in_order(2);
  cout << "Current List: " << endl;
  a.print_all();
  cout << "Current Size: " << a.size() << endl;

  cout << "Insert In Order (9) Test:" << endl;
  a.insert_in_order(9);
  cout << "Current List: " << endl;
  a.print_all();
  cout << "Current Size: " << a.size() << endl;

  cout << "Insert In Order (7) Test:" << endl;
  a.insert_in_order(7);
  cout << "Current List: " << endl;
  a.print_all();
  cout << "Current Size: " << a.size() << endl;

  cout << "Insert In Order (5) Test:" << endl;
  a.insert_in_order(5);
  cout << "Current List: " << endl;
  a.print_all();
  cout << "Current Size: " << a.size() << endl;

  cout << "Insert In Order (6) Test:" << endl;
  a.insert_in_order(6);
  cout << "Current List: " << endl;
  a.print_all();
  cout << "Current Size: " << a.size() << endl;

  cout << "Insert In Order (7) Test:" << endl;
  a.insert_in_order(7);
  cout << "Current List: " << endl;
  a.print_all();
  cout << "Current Size: " << a.size() << endl;
  //cin >> pause;

  cout << "Pop Front (1) Test: ";
  cout << a.pop_front() << endl;
  cout << "Current List: " << endl;
  a.print_all();
  cout << "Current Size: " << a.size() << endl;
  //cin >> pause;

  cout << "Pop Back (3) Test: ";
  cout << a.pop_back() << endl;
  cout << "Current List: " << endl;
  a.print_all();
  cout << "Current Size: " << a.size() << endl;
  //cin >> pause;

/******************************************************************************/
cout << "~~~~~Char~~~~~" << endl;

LinkedList<char> b;

cout << "Push Front (A) Test:" << endl;
b.push_front('A');
cout << "Current List: " << endl;
b.print_all();
//cin >> pause;

cout << "Push Back (Z) Test:" << endl;
b.push_back('Z');
cout << "Current List: " << endl;
b.print_all();
cout << "Current Size: " << b.size() << endl;
//cin >> pause;

cout << "Insert In Order (M) Test:" << endl;
b.insert_in_order('M');
cout << "Current List: " << endl;
b.print_all();
cout << "Current Size: " << b.size() << endl;

cout << "Insert In Order (C) Test:" << endl;
b.insert_in_order('C');
cout << "Current List: " << endl;
b.print_all();
cout << "Current Size: " << b.size() << endl;

cout << "Insert In Order (V) Test:" << endl;
b.insert_in_order('V');
cout << "Current List: " << endl;
b.print_all();
cout << "Current Size: " << b.size() << endl;

cout << "Insert In Order (Y) Test:" << endl;
b.insert_in_order('Y');
cout << "Current List: " << endl;
b.print_all();
cout << "Current Size: " << b.size() << endl;

cout << "Insert In Order (T) Test:" << endl;
b.insert_in_order('T');
cout << "Current List: " << endl;
b.print_all();
cout << "Current Size: " << b.size() << endl;

cout << "Insert In Order (O) Test:" << endl;
b.insert_in_order('O');
cout << "Current List: " << endl;
b.print_all();
cout << "Current Size: " << b.size() << endl;
//cin >> pause;

cout << "Pop Front (A) Test: ";
cout << b.pop_front() << endl;
cout << "Current List: " << endl;
b.print_all();
cout << "Current Size: " << b.size() << endl;
//cin >> pause;

cout << "Pop Back (Z) Test: ";
cout << b.pop_back() << endl;
cout << "Current List: " << endl;
b.print_all();
cout << "Current Size: " << b.size() << endl;
//cin >> pause;

/******************************************************************************/



  return 0;
}
