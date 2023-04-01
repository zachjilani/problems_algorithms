using namespace std;
#include <iostream>
#include <math.h>
// CS311 YOSHII FALL21
// The Algorithm is in Notes-4A so copy and paste it here!!!!!
// After x found not to be L[middle]
//    	there are n/2 entries in the second half and (if n even)
//            		   n/2 - 1 entries in the first half
//    	there are (n-1)/2 entries in both halves (if n odd)
//    	So, there are at most (floor n/2) entries in the chosen half.

//      	 W(n)  = 1 + W(floor of n/2)  	for n > 1
//     	 W(n) = 1 			for n = 1 (boundary condition)
//    	** This is called a Recurrence Relation! **

//   	 To find the closed form, expand it a few times.

//    	W(n) = 1 + W(floor of n/2)
//        	 	= 1 + 1 + W(floor of n/4)
//        		= 1 + 1 + 1 + W(floor of n/8)
//         		= 1 + 1 + 1 + ………..+ 1

//  	How many 1's will there be at the end?
//     	  For 	n/2  	1
//         		n/4  	2
//        	 	n/8 	3
//         		n/16	4
//         		n/2^K	K
//         		n/n       	???

//     	2^K = n when K = log n
//    	So, there will be log n 1’s at the very end.
// On Empress, control-rightclick will bring up the paste option.
// NEVER delete my comments!!!
// --------------------------------------------
// CS311 HW2P1 Binary Search
// Name: Zach Jilani
// Compiler: g++
// --------------------------------------------

// x is what we are looking for in L; first and last are slot numbers
// This recursive function returns the slot number in which x was found
// or -1
int binarySearch(int L[], int x, int first, int last)
{
  //  Be sure to check for first > last and
  //   first == last cases to
  //   end the recursion
  if(first <= last){
    //finding mid point
    int middle = floor((first+last)/2);
    if(x == L[middle]){
      //if x was the middle, just return middle
      return middle;
    }
    // as soon as the mid is found...
    cout << "comparing against an element in slot " << middle << endl;
    // The rest based on the notes
    //if x is less than the mid point, call binarySearch on itself to search only
    //the lower half of tree
    if(L[middle] > x){
      return binarySearch(L, x, first, middle - 1);
    }
    //if x is larger than the mid point, call binarySearch on itself to search only
    //the upper half of tree
    if(L[middle] < x){
      return binarySearch(L, x, middle + 1, last);
    }
  }
  //if the value was not in the tree or first > or = to last
  return -1;
}


int main()
{ int A[10];
  int e;  // to look for this

  // fixed elements for A
  A[0] = 1; A[1]= 3; A[2]=5; A[3]= 7; A[4]=9; A[5]=11; A[6]=13;
  A[7] =15; A[8]= 17; A[9]= 19;
  int n = sizeof(A)/sizeof(A[0]);

  cout << "What do you want to look for? ";
  cin >> e;

  // Call binarySearch here to look for e in A
  int respos = binarySearch(A, e, 0, n-1);

  if (respos == -1) cout << "Element not found" << endl;
  else cout << "Found it in position " << respos+1 << endl;

}
