//CS311 Yoshii FALL21 Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//  You can copy from a Word document to emacs (contrl-right click)
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//  NEVER delete my comments!!!!
//EMACS HINT:
//  cntr-K cuts and cntr-Y pastes.
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Zach Jilani
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h"

llist::llist()
{ cout << "... in llist constructor..." << endl;
  Rear = NULL;
  Front = NULL;
  Count = 0;
}

llist::~llist()
{ cout << ".... in llist destructor..." << endl;
  el_t tmp;
  while (Count != 0){
    deleteFront(tmp);
  }
}

//PURPOSE: return true if Front and Rear are both pointing to NULL and Count is 0.
//PARAMETER: None
bool llist::isEmpty() {  // be sure to check all 3 data members
  if(Front == NULL  && Rear == NULL && Count == 0){
    return true;
  }else{
    return false;
  }
}

//PURPOSE: display each element of the list starting from Front, enclosed in  [ ] followed by endl.
//PARAMETER: None
void llist::displayAll(){
  cout << "[ ";
    if (Count == 0){
      cout << "Empty";
    }else{
      Node *P;
      P = Front;
      while (P != NULL){
	cout << P->Elem << " ";
	P = P->Next;
      }
    }
    cout << "]" << endl;
}  // be sure to display horizontally in [  ] with
// blanks between elements e.g. [ 1 2 3 4]
// You MUST use while (P != NULL) loop or you will not get the credit!

//PURPOSE: special case: if this is going to be the very first node, you must
//  	            create a new node and make Front and Rear point to it. Put NewNum in the Elem field
//     		        of this new node. Count is updated.
//         regular case:  add a new node at the rear and puts NewNum in the Elem field
//     		        of this new node. Count is updated.
//PARAMETER: NewNum of type el_t to be added to new Nodes Elem field
void llist::addRear(el_t NewNum) {  // comment the 2 cases
  //Special Case: if this is going to be the very first node, create a new node and make Front and Rear Point to it.
  //Put NewNum in the Elem field. Count is updated
  if (isEmpty()){
    Front = new Node; //Front now points to a new node
    Front->Elem = NewNum;
    Rear = Front; //Rear and Front point to the same node
    Rear->Next = NULL; //Take care of dangling pointer
    Count ++;
  }else{
    //Regular Case: Add a new node at the rear and puts NewNum in the Elem field. Count updated.
    Rear->Next = new Node;
    Rear = Rear->Next;
    Rear->Elem = NewNum;
    Rear->Next = NULL;
    Count ++;
  }
}

//PURPOSE: special case: if this is going to be the very first node, you must
//  	            create a new node and make Front and Rear point to it. Put NewNum in the Elem field
//     	          of this new node. Count is updated.
//         regular case:  add a new node at the front and puts NewNum in the Elem field
//     		        of this new node. Count is updated.
//PARAMETER: NewNum of type el_t to be added to new Nodes Elem field
void llist::addFront(el_t NewNum) {  // comment the 2 cases
//Special Case: If this is going to be the very first node, create a new node and make Front and Rear pointto it.
//Put NewNum in the Elem field
  if (isEmpty()){ //Same as addRear special case
    Front = new Node;
    Front->Elem = NewNum;
    Rear = Front;
    Rear->Next = NULL;
    Count ++;
  }else{
    //Regular Case: Add a new node at the front and puts NewNum in the Elem field. 
    //Count is uodated.
    Node *X;
    X = new Node;
    X->Elem = NewNum;
    X->Next = Front;
    Front = X;
    Count ++;
  }
}

//PURPOSE: error case: if the List is empty, throw an exception.
//         special case: if this is going to make the list empty, give back the front node element through OldNum 
//              (pass by reference) and also remove the front node. Count is updated.
//              Make sure both Front and Rear both become NULL.
//         regular case:  give back the front node element through OldNum (pass by reference)
//         		  and also remove the front node. Count is updated.
//PARAMETER: NewNum of type el_t passed by reference and given to a var to return the Elem
void llist::deleteFront(el_t& OldNum) {  // comment the 3 cases
  //Error Case: List is empty, throws exception
  if (isEmpty()){
    //Throw exception
    throw Underflow();
  }else if (Count == 1){
    //Special Case: If this causes the list to be empty, give back the front node element through OldNum.
    //Remove front node. Count is updated. Front and Rear become NULL
    OldNum = Front->Elem;
    Front = NULL;
    Rear = NULL;
    Count--;
  }else{
    //Regular Case: Give back the front node element through OldNum and also remove the front node.
    //Count is updated.
    OldNum = Front->Elem;
    Node *Second;
    Second = Front->Next;
    delete Front;
    Front = Second;
    Count --;
  }
}

//PURPOSE: error case: if empty, throw an exception.
//         special case: if this is going to make the list empty,
//              give back the rear node element through OldNum (pass by reference)
//         	    and also remove the rear node. Count is updated.
//              Make sure both Front and Rear become NULL).
//         regular case: give back the rear node element through OldNum (pass by reference)
//              and also remove the rear node. Count is updated.
//PARAMETER: NewNum of type el_t passed by reference and given to a var to return the Elem
void llist::deleteRear(el_t& OldNum){ // comment the 3 cases
  //Error Case: If empty throw exception
  if (isEmpty()){
    //Throw exception
    throw Underflow();
  }else if (Count == 1){
    //Special Case: If this makes the list empty give back the rear node element through OldNum.
    // Remove rear node. Count is updated. Front and Rear become NULL
    OldNum = Rear->Elem;
    Front = NULL;
    Rear = NULL;
    Count--;
  }else{
    //Regular Case: Give back the rear node element through OldNum and remove the rear node.
    //Count is updated
    Node *P;
    P = Front;
    while (P->Next != Rear){
      P = P->Next;}
    OldNum = Rear->Elem;
    delete Rear;
    Rear = P;
    Rear->Next = NULL;
    Count --;
  }
}



/* --- harder ones for case 2 and 3 follow -- */

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp){
  // moves temp J-1 times to go to the Jth node
  // for ( int K = ... ) temp = temp->Next;
  temp = Front;
  for (int K = 1; K <= J - 1; K++){
    temp = temp -> Next;
  }
}

//PURPOSE: Error cases: If I is an illegal value (i.e. > Count or < 1) throw an exception.
//     	   Special cases: this should simply call deleteFront (I = 1) or deleteRear (I == Count) for some cases.
//         Regular case: will delete the Ith node (I starts out at 1).  Count is updated.
//PARAMETER: position and elem
void llist::deleteIth(int I, el_t& OldNum){
  if (I > Count || I < 1){ //if position indicated is more than the nodes we have or less than 1
    throw OutOfRange();
  }else if(I == 1){ //if I is at position 1 just delete the front node
    deleteFront(OldNum);
  }else if(I == Count){ //if I is at the last position just delete the rear node
    deleteRear(OldNum);
  }else{ //otherwise delete a node indicated by int I. done by declaring two pointers; one points
  //to the one to be deleted through next
    Node *prevNode;
    Node *nextNode;
    moveTo(I - 1, prevNode); //move it to node preceeding index wanted
    moveTo(I + 1, nextNode);
    OldNum = prevNode -> Next -> Elem;
    delete prevNode -> Next;
    prevNode -> Next = nextNode;
    Count--; //decrement count
  }
 } // must use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.

//PURPOSE: Error cases: If I is an illegal value (i.e. > Count+1 or < 1) throw an exception.
//         Special cases: this should simply call addFront (I == 1) or addRear (I == Count+1) for some cases.
//         Regular case:  will add right before the Ith node.  Count is updated.
//PARAMETER: position and elem
void llist::insertIth(int I, el_t newNum){
  if (I > Count + 1 || I < 1){ //if position indicated is more than the nodes we have or less than 1
    throw OutOfRange();
  }
  else if(I == 1){ //if I is at position 1 just add the front node
    addFront(newNum);
  }else if(I == Count + 1){ //if I is at the rear just use addRear
    addRear(newNum);
  }else{
    //In the normal case, insert a node between two other nodes.
    //This is done using two pointers; one points to the node at
    //the node indicated. Then, a second node is declared and its elem
    //is set to the new num. The second node is placed between the
    //preceeding and next; P->next points to the new, the new points to the
    //previously sequential node.
    Node *P;
    Node *Q;
    Node *toAdd = new Node;
    toAdd -> Elem = newNum;
    moveTo(I - 1, P);
    moveTo(I, Q);
    P -> Next = toAdd;
    toAdd -> Next = Q;
    Count++;
  }
 } // must use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE:
//PARAMETER:
llist::llist(const llist& Original){
  //  this->'s data members need to be initialized here first
    Front = NULL; Rear = NULL; Count = 0;
    //  this-> object has to be built up by allocating new cells
    //  and copying the values from Original into each cell as we did with
    //  operator= above. To do this,
     // this-> object has to be built up by allocating new cells with OtherOne elements (**)
        Node* P;  // local pointer for OtherOne
        P = Original.Front;
        while (P != NULL)  // a loop which repeats until you reach the end of OtherOne.
        {
           this->addRear(P->Elem);    //P’s element is added to this->
           P = P->Next;                         // Go to the next node in OtherOne
        }
    //  Nothing to return because this is a constructor.
 } // use my code

//PURPOSE:
//PARAMETER:
llist& llist::operator=(const llist& OtherOne){
  el_t x;
     // First make sure this-> and OtherOne are not the same object.
     // To do this, compare the pointers to the objects .
     if (&OtherOne != this)  // if not the same
      {
        // this-> object has to be emptied first.
        while (! this->isEmpty()){
          this->deleteRear(x);
        }
        // this-> object has to be built up by allocating new cells with OtherOne elements (**)
        Node* P;  // local pointer for OtherOne
        P = OtherOne.Front;
        while (P != NULL)  // a loop which repeats until you reach the end of OtherOne.
        {
           this->addRear(P->Elem);    //P’s element is added to this->
           P = P->Next;                         // Go to the next node in OtherOne
         }
      }// end of if
     return *this;    // return the result unconditionally.  Note that the result is returned by reference.
 } // use my code

