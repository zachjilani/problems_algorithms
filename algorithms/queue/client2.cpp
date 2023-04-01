//CS311 Yoshii FALL21
//INSTRUCTION:
//Look for ** to complete this program
//The string output should match my hw1queueDemo.out
// NEVER delete my comments!!!!
//=========================================================
//HW#: HW1P2 queue application (generate all strings)
//Your name: Zach Jilani
//Complier:  g++
//File type: client program client2.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program: create a queue that will add A, B, and C and will continually append to
// a string until an Overflow Exception is thrown and caught.
//Algorithm: Use an indefinitely true while loop on a queue that has three elements in it.
// looping it will add each new element to the queue and continue cycling until all possible
// permutations have been created with what was already inside the queue.
int main()
{
  //  place "A", "B", "C" in the queue
  queue myQ;
  myQ.add("A");
  myQ.add("B");
  myQ.add("C");
  string perm;

  while(true) //  while loop -- indefinitely while(true)
  {
    try
	  {
      myQ.remove(perm);
      if (perm.length() <= 3){
        cout << perm << endl;
      }
      myQ.add(perm + "A");
      myQ.add(perm + "B");
      myQ.add(perm + "C"); // do the steps noted in the notes
	  }
    catch (queue::Underflow)
	  {
      cerr << "Underflow Exception, check if queue is empty" << endl;
      break;
    }
    catch (queue::Overflow)
    {
      cerr << "Overflow Exception, check count." << endl;
      break;
    }
  }// end of loop

}

