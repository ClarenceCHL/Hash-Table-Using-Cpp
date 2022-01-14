// Name: Haolun Cheng
// USC NetID: haolunch
// CSCI 455 PA5
// Fall 2021

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

using namespace std;

/**
 * Insert name and score of a student into the table
 * @param grades table to be inserted in
 */
void gradesInsert (Table * & grades){
   string name = ""; // student's name from user input
   int score = 0; // students's score from user input 
   bool insertResult = false; // display operation result 

   cin >> name; // name to be inserted
   cin >> score; // score to be inserted
   insertResult = grades->insert(name, score); // result of the insert opreation

   // If this name was already present, print a message to that effect, and don't do the insert.
   if (insertResult == false){ 
      cout << "Insert failed. Student " << name << " already existed." << endl;
   }
}

/**
 * Change the score of the given student
 * @param grades table to lookup the given student name and find its score
 */
void gradesChange (Table * & grades){
   string name = "";
   int score = 0;

   cin >> name;
   cin >> score;
   int *current = grades->lookup(name);
   if (current != NULL){ // if the score exists
      *current = score; // change the value of score 
   }
   else { // if the node does not exist
      cout << "Change failed. Student " << name << " is not in the table." << endl; // report error information
   }
}

/**
 * Lookup the name, and print out his or her score, or a message indicating that student is not in the table
 * @param grades table to lookup the given student name and find its score
 */
void gradesLookup (Table * & grades){
   string name = "";

   cin >> name;
   int * current = grades->lookup(name);  // find the score of the node
   if(current != NULL){ // if the node(score) exists
      cout << "Student "<< name << "'s score is " << *current << "." << endl;
   }
   else { // if the node does not exist
      cout << "Student " << name << " is not in the table." << endl;
   }
}

/**
 * Remove this student. If this student wasn't in the grade table, print a message to that effect
 * @param grades table to lookup the given student name and remove the student
 */
void gradesRemove (Table * & grades){
   string name = "";
   bool removeResult = false;

   cin >> name;
   removeResult = grades->remove(name); 
   if(removeResult == false){
      cout << "Removed failed. Student " << name << " is not in the table." << endl; // report error information
   }   
}

/**
 * Prints out all names and scores in the table
 * @param grades table to prints out all nodes
 */
void gradesPrint (Table * & grades){
   grades->printAll(); 
}

/**
 * Prints out the number of entries in the table
 * @param grades table to prints out the size
 */
void gradesSize (Table * & grades){
   int size = grades->numEntries();
   cout << "The table size is " << size << ". " << endl;
}

/**
 * Prints out statistics about the hash table at this point. Calls hashStats() method
 * @param grades table to report the statistics
 */
void gradesStats (Table * & grades){
   grades->hashStats(cout);
}

/**
 * Prints out a brief command summary
 */
void helpInfo(){ 
   cout << "insert name score    " << "Insert this name and score in the grade table." << endl;
   cout << "change name newscore " << "Change the score for name." << endl;
   cout << "lookup name          " << "Lookup the name, and print out his or her score." << endl;
   cout << "remove name          " << "Remove this student." << endl;
   cout << "print                " << "Print out all names and scores in the table." << endl;
   cout << "size                 " << "Print out the number of entries in the table." << endl;
   cout << "stats                " << "Print out statistics about the hash table at this point." << endl; 
   cout << "quit                 " << "Exit the program." << endl;
}

/**
 * Execute commands from user
 * @param grades table to execute the commands
 */
void commandExecution (Table * & grades){
   string command = "";

   bool cont = true;
   
   while (cont){
      cout << "cmd > ";
      cin >> command;
      if (command == "insert"){
         gradesInsert (grades);
      }
      else if (command == "change"){
         gradesChange (grades);
      }
      else if (command == "lookup"){
         gradesLookup (grades);
      }
      else if (command == "remove"){
         gradesRemove (grades);
      }
      else if (command == "print"){
         gradesPrint (grades);
      }
      else if (command == "size"){
         gradesSize (grades);
      }
      else if (command == "stats"){
         gradesStats (grades);
      }
      else if (command == "help"){
         helpInfo();
      }
      else if (command == "quit"){
         cont = false;
      }
      else {
         cout << "ERROR: invalid command" << endl;
         helpInfo();
      }
   }
}

int main(int argc, char * argv[]) {

   // gets the hash table size from the command line

   int hashSize = Table::HASH_SIZE;

   Table * grades;  // Table is dynamically allocated below, so we can call
   // different constructors depending on input from the user.

   if (argc > 1) {
      hashSize = atoi(argv[1]);  // atoi converts c-string to int

      if (hashSize < 1) {
         cout << "Command line argument (hashSize) must be a positive number" 
              << endl;
         return 1;
      }

      grades = new Table(hashSize);

   }
   else {   // no command line args given -- use default table size
      grades = new Table();
   }


   grades->hashStats(cout);

   // add more code here
   // Reminder: use -> when calling Table methods, since grades is type Table*

   commandExecution(grades);

   return 0;
}
