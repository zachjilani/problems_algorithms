// CS311 Yoshii FALL21 Complete all functions with their comments
// NEVER delete my comments!!
// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Zach Jilani
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h"

// ** Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist()
{ cout << "slist constructor:" << endl;}


// positions always start at 1

int slist::search(el_t key){
  Node *P = Front;
  int index = 1;
  while(P != NULL){
    if (P -> Elem == key){
      return index;
    }
    P = P -> Next;
    index++;
  }
  return 0;
}
// don't forget to throw OutOfRange for bad pos
// You must use moveTo to go to the pos

void slist::replace(el_t element, int pos){
  if(pos <= 0 || pos > Count){
    throw OutOfRange();
  }
  Node *P;
  moveTo(pos, P);
  P -> Elem = element;
}

bool slist::operator==(const slist& OtherOne){
  // if not the same length, return false immediately
  if(this -> Count != OtherOne.Count){
    return false;
  }else{
    Node *P1 = this -> Front;
    Node *P2 = OtherOne.Front;
    // if the same lengths,
    //check each node to see if the elements are the same
    for (int i = 0; i < this -> Count; i++){
      if (P1 -> Elem != P2 -> Elem){
        return false;
      }else{
        P1 = P1 -> Next;
        P2 = P2 -> Next;
      }
    }
    return true;
  }
}
