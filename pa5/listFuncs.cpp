// Name: Haolun Cheng
// USC NetID: haolunch
// CSCI 455 PA5
// Fall 2021


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
   key = theKey;
   value = theValue;
   next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
   key = theKey;
   value = theValue;
   next = n;
}




//*************************************************************************
// put the function definitions for your list functions below

/**
 * This method looks up the key in the given list
 * @param list to find the key
 * @param the target key string
 * @return the index of the matching target in the list
 */
int * listLookup (ListType list, string key){
   ListType l = list;
   while(l != NULL){
      if (l->key == key){
         return &(l->value);
      }
      l = l->next;
   }
   return NULL;
}

/**
 * This method inserts a key-value pair into the front of the list
 * @param list to insert
 * @param key to insert into the node
 * @param value to insert into the node
 */
void listInsert (ListType & list, string key, int value) {
   list = new Node(key, value, list);
}

/**
 * This method removes a node with target key
 * @param list to remove a node
 * @param target key to be removed
 * @return true if successfully removed and false otherwise
 */
bool listRemove (ListType & list, string target) {
   if (list == NULL) return false;
   // if the first node matches the target, we delete the node
   if (list->key == target){
      ListType nuked = list;
      list = list->next;
      delete nuked;
      return true;
   }

   // if the first node does not match the target
   ListType p = list;
   while (p->next != NULL && p->next->key != target){
      p = p->next;
   }
   if (p->next == NULL){
      return false;
   } else {
      ListType nuked = p->next;
      p->next = p->next->next;
      delete nuked;
   }
   return true;
}

/**
 * This method prints out the whole list node by node
 * @param list to be printed
 */
void printList (ListType list){
   ListType p = list;
   while (p != NULL){
      cout << p->key << " " << p->value << endl;
      p = p->next;
   }
}

/**
 * This method returns the length of the current list
 * @param list to obtain the length
 * @return length of the list
 */
int chainLength (ListType list){
   int length = 0;
   ListType p = list;
   while (p != NULL){
      length++;
      p = p->next;
   }
   return length;
}