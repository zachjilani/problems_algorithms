// CS311 Yoshii FALL21 - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//  NEVER delete my comments!!
//-----------------------------------------------------

// ============================================
// HW#: HW8 Hash Table
// Name: Zach Jilani
// File Type: implementation htable.cpp
// =============================================

using namespace std;
#include <iostream>
#include "htable.h"

htable::htable()
{}

htable::~htable()
{}

// a simple hash function that uses % TSIZE simply
int htable::hash(int key)
{ 
  return key % TSIZE;
}

// adds the element to the table and returns slot#
int htable::add(el_t element )
{
  int slot = hash(element.key);  // hash with the key part
  table[slot].addRear(element);// Note that this means adding the element to a slist in the slot
  return slot;
}

// finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
el_t htable::find(int skey)
{ 
  el_t E; //blank element
  int slot = hash(skey); // hash with skey
  el_t selement;  // this is the element to look for in slist
  selement.key = skey; // initialize selement with just the skey
  E = table[slot].search2(selement);// call slist's search2 with selement which returns the found element 
  return E;// return the found element from here (it could be blank)
}

// finds the element given the key  and deletes it from the table.
//  Returns the slot number.
int deleteIt(int key)
{
 int slot = hash(skey); // hash with skey
 el_t selement;  // this is the element to look for in slist
 selement.setkey(skey);//  initialize selement with just the skey
 int I = table[slot].search(selement);
 table[slot].deleteIth(I, selement); //  call slist's search which gives you the location I and then deleteIth
 return slot; //  return the slot number
}


// fills the table using the specified input file
void htable::fillTable(istream& fin)
{
  //  model this after HW6 to get data from the file the user specified
  //  which elem and slist functions do you call? List them here first.
  int key;
  string name;
  int age;
  char gender;
  while(fin >> key){
    fin >> name;
    fin >> age;
    fin >> gender;

    el_t elem (key, name, age, gender);
    add(elem);
  }
}

// displays the entire table with slot#s too
void htable::displayTable()
{
  for (int i = 0; i < 37; i++)
    { cout << i << ":" ;   
      table[i].displayAll(); // call slist's displayAll
    }
}

// saves into the specified file in the same format as the input file
void htable::saveTable(ostream& fout) 
{
  el_t anelement;//temp output elem
   for(int i = 0; i < TSIZE; i++)//for all slists in table
    {
      if(table[i].isEmpty())
	{
	  //nothing
	}else{
	while(!table[i].isEmpty())//loop through entire elem
	  {
	    table[i].deleteFront(anelement);//clean up elem from table
	    fout << anelement; //output elem of slist
	    fout << " ";
	  }
	fout << "\n";
      }
    }
}


