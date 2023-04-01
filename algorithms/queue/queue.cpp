//INSTRUCTION: FALL21
//Look for ** using control-S
//Then, fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors
// NEVER delete my comments!!!
//=========================================================
//HW#: HW1P2 queue
//Your name: Zach Jilani
//Complier:  g++
//File type: queue cpp file  queue.cpp
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"

// constructor
queue::queue()
{
  count = 0;
  front = 0;
  rear = -1;// initialize data members as in the notes
}

//destructor
queue::~queue()
{ // nothing
}

// PURPOSE: returns true if queue is empty, otherwise false - checks count
bool queue::isEmpty()
{return count == 0;}

// PURPOSE: returns true if queue is full, otherwise false - checks count
bool queue::isFull()
{return count == MAX_SIZE;}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
  if(isFull()) throw Overflow();
  else {
    rear = (rear + 1) % MAX_SIZE; el[rear] = newElem; count++;
  }
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
  if(isEmpty()) throw Underflow();
  else {
    removedElem = el[front]; front = (front + 1) % MAX_SIZE; count --;
  }
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
  if(isEmpty()) throw Underflow();
  else {
    theElem = el[front];
    cout << theElem << endl;
  }
}

// PURPOSE: returns the current size to make it
// accessible to the client caller
int queue::getSize()
{return count;}

// PURPOSE: display everything in the queue horizontally
// from front to rear enclosed in [   ]
// if empty, displays [ empty ]
void queue::displayAll()
{  if (isEmpty()) { cout << "[ empty ]" << endl;}
  else
    {
      int j = front;
      cout << "[";
      for (int i = front; i <= front + count; i++)
	{ cout << el[i % MAX_SIZE] << endl; }
      cout << "]" << endl;
    }
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//calling remove followed by add.
void queue::goToBack()
{
  if(isEmpty()){
    throw Underflow();
  }
  else if(count == 1) {
    cout << "Only one element in queue." << endl;
  }
  else {
    el_t tmp; //temp variable
    remove(tmp);
    add(tmp);
  }
}

