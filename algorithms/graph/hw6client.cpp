// CS311 Yoshii FALL21
// HW6 Client file
// INSTRUCTION: Complete this file and comment using How to Comment file.
//---------------------------------------------

// ================================================
// HW#: HW6 dgraph client
// Name: Zach Jilani
// File type:  client file  (tester)
// ================================================

#include <iostream>
#include "dgraph.h" // includes

// comments
int main()
{
  //0.Declare dgraph object
  //1.fillTable()
  //2.displayGraph()
  //while (the user does not want to stop)
  //a.the user will specify which vertex
  //b.findOutDegree of the vertex and display the result
  //b.findAdjacency of the vertex and display the result (see Hint)
  //c.catch exception to display error mesg but do not exit
  //end of while

  dgraph A; //graph object
  char in; //input from user
  slist l1; //slist object

  A.fillTable();

  A.displayGraph();
  bool flag;

  do{
    try{
      flag = true;
      cout << "Enter vertex name or enter 0 to exit:";
      cin >> in;
      if(in == '0'){
        flag = false;
        A.displayGraph();
        return 0;
      }
      cout << A.findOutDegree(in) << " edges comes out to " << endl;
      l1 = A.findAdjacency(in);
      (l1).displayAll();
    }catch(dgraph::BadVertex){
      cerr << "Error: Bad vertex. Choose a different vertex." << endl;
    }
  }while(flag);
}

/*
Hint:
  slist l1;
  l1 = G.findAdjacency('a');
  // how do you display l1?  Hint: it is an slist from HW3.

*/
