// Name: Haolun Cheng
// USC NetID: haolunch
// CSCI 455 PA5
// Fall 2021

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

// for hash function called in private hashCode method defined below
#include <functional>

using namespace std;


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
   hashTable = new ListType[HASH_SIZE]();
   hashSize = HASH_SIZE;
   entries = 0;
}


Table::Table(unsigned int hSize) {
   hashTable = new ListType[hSize]();
   hashSize = hSize;
   entries = 0;
}


int * Table::lookup(const string &key) {
   int location = hashCode(key); // get the index location of the given key by finding its hashcode
   int * result = listLookup(hashTable[location], key); // find the key in the specified hashTable location
   return result; // return the address of the value that goes with the key
}


bool Table::remove(const string &key) {
   int location = hashCode(key); // get the index location of the given key by finding its hashcode
   bool result = listRemove(hashTable[location], key); // remove the node with the key
   if (result == true) entries--; // decrease one entry if removed
   return result;
}


bool Table::insert(const string &key, int value) {
   int * exist = lookup(key); // check if the node exist
   if (exist == NULL){ // if the node does not exist, we can insert
      int location = hashCode(key); // get the index location of the given key by finding its hashcode
      listInsert(hashTable[location], key, value); // insert the key-value pair
      entries++; // increase one entry if inserted
      return true;
   }
   return false; // return false if the node already exist
}


int Table::numEntries() const {
   return entries;
}


void Table::printAll() const {
   for (int i = 0; i < hashSize; i++){
      printList(hashTable[i]);
   }
}


void Table::hashStats(ostream &out) const {
   int validBucket = 0;
   int longest = 0;
   int length = 0;
   for (int i = 0; i < hashSize; i++){
      if (hashTable[i] != NULL){
         // count the number of non-empty bucket
         validBucket++;
      } 
      length = chainLength(hashTable[i]); // length of the chain in bucket i 
      if (length > longest){ // find the longest chain
         longest = length; 
      }
      length = 0;	
   }
   
   out << "number of buckets: " << hashSize << endl;
   out << "number of entries: " << entries << endl;
   out << "number of non-empty buckets: " << validBucket << endl;
   out << "longest chain: " << longest << endl;
}


// hash function for a string
// (we defined it for you)
// returns a value in the range [0, hashSize)
unsigned int Table::hashCode(const string &word) const {

   // Note: calls a std library hash function for string (it uses the good hash
   //   algorithm for strings that we discussed in lecture).
   return hash<string>()(word) % hashSize;

}


// add definitions for your private methods here

