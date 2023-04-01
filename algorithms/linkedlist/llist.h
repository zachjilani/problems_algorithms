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
typedef int el_t;  // int for now but can change later

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{

 private:
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

  //PURPOSE: return true if Front and Rear are both pointing to NULL and Count is 0.
  bool isEmpty();

  //PURPOSE: display each element of the list starting from Front, enclosed in  [ ] followed by endl.
  void displayAll();

  //PURPOSE: special case: if this is going to be the very first node, you must
  //  	            create a new node and make Front and Rear point to it. Put NewNum in the Elem field
  //     	          of this new node. Count is updated.
  //         regular case:  add a new node at the front and puts NewNum in the Elem field
  //     		        of this new node. Count is updated.
  void addFront(el_t);

  //PURPOSE: special case: if this is going to be the very first node, you must
  //  	            create a new node and make Front and Rear point to it. Put NewNum in the Elem field
  //     		        of this new node. Count is updated.
  //         regular case:  add a new node at the rear and puts NewNum in the Elem field
  //     		        of this new node. Count is updated.
  void addRear(el_t);

  //PURPOSE: error case: if the List is empty, throw an exception.
  //         special case: if this is going to make the list empty, give back the front node element through OldNum 
  //              (pass by reference) and also remove the front node. Count is updated.
  //              Make sure both Front and Rear both become NULL.
  //         regular case:  give back the front node element through OldNum (pass by reference)
  //         		  and also remove the front node. Count is updated.
  void deleteFront(el_t&);

  //---------------------------------------

  //PURPOSE: error case: if empty, throw an exception.
  //         special case: if this is going to make the list empty,
  //              give back the rear node element through OldNum (pass by reference)
  //         	    and also remove the rear node. Count is updated.
  //              Make sure both Front and Rear become NULL).
  //         regular case: give back the rear node element through OldNum (pass by reference)
  //              and also remove the rear node. Count is updated.
  void deleteRear(el_t&);

  //**
  void deleteIth(int, el_t&);  // calls moveTo

  //**
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);

  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&);

};
