//CS311 Yoshii FALL21
//INSTRUCTION:
//Look for ** to complete this program (Use control-S)
//The output should match my hw1stackDemo.out
// NEVER delete my comments !!!
//=========================================================
//HW#: HW1P1 stack application (post-fix evaluation)
//Your name: Zach Jilani
//Complier:  g++
//File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: create a program using a stack data structure for a post fix calculator
//Algorithm: while there are items left in the stack, read an item. if its a char; push. if its an
// operand; try to pop twice, otherwise throw an error. if done sucessfully the new result will be pushed to the stack. after
// successfully iterating the stack, the result will be left at the top of the stack to be popped
// and shown. if there is anything left in the stack afterward it will throw an error
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  cout << "type a postfix expression: ";
  cin >> expression;

  int i = 0;  // character position within expression
  char item;  // one char out of the expression

  int box1;  // receive things from pop
  int box2;  // receive things from pop
  int res = 0; //for use with operands and operators

  while (expression[i] != '\0') // til the end of the expression
    {
    item = expression[i];  // current char
     try{

      if(expression.size()<3) throw "enter more than 2 characters"; //minimum size
      //checks operators
      if(expression[i]>47 && expression[i]<58){
        int number = postfixstack.charToInt(expression[i]); //converting to int
        postfixstack.push(number); //pushes to stack
       }else if((expression[i] == '+') || (expression[i] == '-') || (expression[i] == '*')){

         if(postfixstack.isEmpty()== true) throw Overflow();
         else postfixstack.pop(box1);

         if(postfixstack.isEmpty()== true) throw Underflow();
         else postfixstack.pop(box2);

         if(expression[i] == '-'){
          res = box2-box1;
         }
         else if(expression[i] == '+'){
           res = box2+box1;
         }
         else if(expression[i] == '*'){
           res = box2*box1;
         }
         else throw "error";
       }
    } // this closes try
      // Catch exceptions and report problems and quit the program now (exit(1)).
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow){
        cout << "Overflow: Use less integers in stack.";
        exit(1);
      }
      catch (stack::Underflow){
        cout << "Underflow: Use more than one integer, or have none remaining.";
        exit(1);
      }
      catch (char const* errormsg ) // for invalid item case
      {
        cout << "Error";
        exit(1);
      }
      // go back to the loop after incrementing i
      i++;
    }// end of while

 // After the loop successfully completes:
 // Pop the result and show it.
   postfixstack.pop(box1);
 // If anything is left on the stack, an incomplete expression
 // was found so also inform the user.
   try{
     if(postfixstack.isEmpty() != true) throw Error();
   } catch(char const* errormsg){
     cout << "Error."
     exit(1);
   }

}// end of the program
