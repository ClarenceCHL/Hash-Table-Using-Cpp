// Name: Haolun Cheng
// USC NetID: haolunch
// CSCI 455 PA5
// Fall 2021


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.

// Note2: it's good practice to *not* put "using" statement in *header* files.  Thus
// here, things from std libary appear as, for example, std::string

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

#include <string>
  

struct Node {
   std::string key;
   int value;

   Node *next;

   Node(const std::string &theKey, int theValue);

   Node(const std::string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.

/**
 * This method looks up the key in the given list
 * @param list to find the key
 * @param the target key string
 * @return the index of the matching target in the list
 */
int * listLookup(ListType list, std::string key);


/**
 * This method inserts a key-value pair into the front of the list
 * @param list to insert
 * @param key to insert into the node
 * @param value to insert into the node
 */
void listInsert(ListType & list, std::string key, int value);


/**
 * This method removes a node with target key
 * @param list to remove a node
 * @param target key to be removed
 * @return true if successfully removed and false otherwise
 */
bool listRemove(ListType & list, std::string target);


/**
 * This method prints out the whole list node by node
 * @param list to be printed
 */
void printList(ListType list);


/**
 * This method returns the length of the current list
 * @param list to obtain the length
 * @return length of the list
 */
int chainLength(ListType list);

// keep the following line at the end of the file
#endif
