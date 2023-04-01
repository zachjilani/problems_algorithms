// CS311 YOSHII FALL21

//==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: client file
// File type: client hw7client.cpp 
//==========================================

// ** Be sure to include both dgraph  and stack
#include "dgraph.h"
#include "stack.h"


// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main(){

  dgraph G;
  stack S;
  char V;
  int visited = 1;
  slist adjlist;


  // ** copy here the algorithm (read carefully) in the HW7
  // assignment sheet and use that for the comments.

  //   Display the graph before DFS begins.
  cout << "Filling table and displaying before DFS..." <<endl;
  G.fillTable();
  G.displayGraph();

  // Push A onto the stack to start.
  S.push('A');
  // While the stack is not empty do:
  // {
  //     	Remove a vertex v from the stack.
  // Display the vertex name.  E.G. “Removed B from stack”
  // If v is not marked yet (visit number is 0) then
  //     • mark it (visit it **) and inform the user E.G. “Visit B as 2”
  //     • get its adjacency list (slist)
  //         ◦ if no adjacent ones inform the user E.G. “Deadend reached – backup”
  //         ◦ else put adjacent ones on the stack (delete from the rear and push) informing the user
  // else inform the user E.G. “B had been visited already - backup.”
  // Display the stack clearly labeling it as the current stack
  // }
  while(S.isEmpty() != true){
    S.pop(V);
    cout << "removed " << V << " from stack" << endl;
    if(G.isMarked(V) == false){
      G.visit(visited, V);
      cout << "Visit " << V << " as " << visited << endl;
      visited++;
      adjlist = G.findAdjacency(V);
      cout << adjlist.isEmpty() << endl;
      if(adjlist.isEmpty()){
        cout << "in adj empty" << endl;
        cout << "Dead end, backup" << endl;
        cout << "Stack is:" << endl;
        S.displayAll();
      }else{
        cout << "Pushing ";
        adjlist.displayAll();
        while(adjlist.isEmpty() != true){
          adjlist.deleteRear(V);
          S.push(V);
        }
        cout << "Stack is: " << endl;
        S.displayAll();
      }
    }else{
      cout << V << " has been visited already, backup." << endl;
      cout << "Current stack is: " << endl;
      S.displayAll();
    }
  }
  G.displayGraph();
  //     Display the Graph nicely with visit numbers for all vertices.
  //  (**) visit numbers will start at 1 and increase as you traverse and visit.
}

