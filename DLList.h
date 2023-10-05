#include <iostream>
using namespace std;

/******************************************************/
/* Programmer: Martyna Wieczorek                      */     
/* Date: September 25, 2023                           */    
/* Purpose:  Project 1 - Unsorted Doubly Linked List  */ /******************************************************/

#ifndef DLLIST_H
#define DLLIST_H

// Creating a node of the doubly linked list
template <class T>
struct node
{
   T info;
   node<T> *next;
   node<T> *back;
};

// Unsorted Doubly Linked List Class
template <class T>
class DLList 
{
   private:
      node<T> *first; 
      node<T> *last;
      int length;
      // Pointers for Iterators
      node<T> *front;
      node<T> *prev;
   public:
      //Constructor 
      DLList();
      // Destructor
      ~DLList();
      // Copy constructor
      DLList ( const DLList<T> & other);
      //Overload the assignment operator 
      const DLList<T> & operator= (const DLList<T> & other);
      //Returns current length of list
      int getLength();
      // Returns true if list is empty, false otherwise
      bool isEmpty();
      // Inserts parameter item to the front of the list
      void insertItemFront(T item);
      // Inserts parameter item to the back of the list
      void insertItemBack(T item);
      // Delete desired item from the list 
      void deleteItem(T item);
      // Returns true if parameter item is in the list, false otherwise
      bool searchItem(T item);
      //Print all items in the list from front to back
      void printListFront();
      //Print all items in the list from back to front
      void printListBack();
      // Function to copy a list
      void copy (const DLList<T> & other);
      // Destroy list function
      void destroy();
      // Sets the iterator 'front' to the beginning of the list
      void setIteratorFront();
      // Moves the iterator 'front' to the next element in the list
      void moveIteratorFront();
      // Returns the value of the element that the iterator 'front' is currently pointing to
      int getIteratorFront();
      // Sets the iterator 'prev' to the end of the list
      void setIteratorBack();
      // Moves the iterator 'prev' to the previous element in the list
      void moveIteratorBack();
      // Returns the value of the element that the iterator 'prev' is currently pointing to
      int getIteratorBack();
    
};
#endif