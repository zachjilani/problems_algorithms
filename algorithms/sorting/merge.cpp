// CS311 Merge Sort - plug in your combine and it should work
--------------------------------------------------------

using namespace std;
#include <iostream>
#include <vector>

void display(vector<int> X)
{ cout << "[ ";
  for (int i = 0; i < X.size(); i++)
    cout << X[i] << " ";
  cout << "]" << endl;
}

void combine( vector<int> A, vector<int> B, vector<int> &R )
{
    int n = A.size(); // you can find out the size of A using the
    int ia = 0, ib = 0; // size function. Treat A and B like arrays.
    // be careful -- R comes in as an empty vector with no slots so you have to use push_back
    while(ia < n && ib < n){
      cout << "comparison" << endl;
      if(A[ia] <= B[ib]){
        R.push_back(A[ia]);
        ia++;
      }
      else {
        R.push_back(B[ib]);
        ib++;
      }
    }
    if(ia < n){
      for(;ia < n; ia++){
        R.push_back(A[ia]);
      }
    }
    if(ib < n){
      for(;ib < n; ib++){
        R.push_back(B[ib]);
      }
    }
}


// sort N into R
void MergeSort(vector<int> N, vector<int>& R)
{ vector<int> L1, L2, L1R, L2R;

  // only one element, so done
  if (N.size() == 1) {R.push_back(N[0]); return;}

  cout << "Merge sort called on: "; display(N);

  // divide N into L1 and L2
  for (int i = 0; i < N.size()/2; i++)
    L1.push_back(N[i]);
  for (int i = N.size()/2; i < N.size(); i++)
    L2.push_back(N[i]);

  cout << "1st half:" << endl;
  display(L1);
  cout << "2nd half:" << endl;
  display(L2);

  // sort the first half and produce L1R
  MergeSort(L1, L1R);
  // sort the second half and produce L2R
  MergeSort(L2, L2R);

  // combine the sorted halves into sorted R
  combine(L1R, L2R, R);
}

int main()
{
  vector<int> Mine, Mine2;
  int a;
  cout << "Enter elements or -1 to stop" << endl;
  cout << "Element:"; cin >> a;
  while (a != -1)
    {
      Mine.push_back(a);
      cout << "Element:"; cin >> a;
    }
  MergeSort(Mine, Mine2);  // produce Mine2

  cout << "FINAL RESULT:" << endl;
  display(Mine2);
}
