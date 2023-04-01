//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS

// =======================================================
// HW#: HW3P1 llist
// Your name: Zach Jilani
// Compiler:  g++
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
//typedef char el_t;  // int for now but can change later
#include "elem.h"
//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
  void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //Checks if the llist has nodes or not
  bool isEmpty();
    
  //Displays elem field of all nodes in list
  void displayAll();

  //makes a new node and puts it at the front of the llist
  void addFront(el_t);
    
  //makes a new node and puts it at the end of the llist
  void addRear(el_t);

  //removes the front node if possible and returns its elem field
  void deleteFront(el_t&);
  
  //---------------------------------------
    
  //removes the rear node if possible and returns its elem field
  void deleteRear(el_t&);
    
  //Removes node at Ith location
  void deleteIth(int, el_t&);  // calls moveTo

  //Inserts a node at Ith location
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};
