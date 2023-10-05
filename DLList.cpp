#include "DLList.h"

/***************************************************************/
/* Programmer:  Martyna Wieczorek                              */        
/* Date:  September 25, 2023                                   */        
/* Purpose: PROJECT Part 1                                     */
/* Input: Sorted Linked List                                   */
/* Output: Unsorted Doubly Linked List                         */
/***************************************************************/

template <class T>
DLList<T> :: DLList()
{
   length = 0;
   first = NULL; 
   last = NULL;
   prev = NULL;
   front = NULL;
}

template <class T>     
DLList<T> :: ~DLList()
{ 
    destroy();
}

template <class T>        
DLList<T> :: DLList ( const DLList<T> & other)
{
   copy (other);
}

template <class T>        
const DLList<T> & DLList<T> :: operator= (const DLList<T> & other)
{
   if ( this != &other )
   {
      destroy ();
      copy (other);
   }
   return *this; 
}

template <class T>        
bool DLList<T> :: isEmpty()
{
   return first == NULL;
}
      
template <class T>        
void DLList<T> :: insertItemFront(T item)
{
   length++;
   node<T> * p = new node<T>;
   p->info = item;
  
   if ( first == NULL  )
   {
      p->next = NULL;
      p->back = NULL;
      first = p;
      last = p;
   }
   else
   {
      p->back = NULL;
      p->next = first;
      first ->back = p;
      first = p;
   }
}

template <class T>      
void DLList<T> :: insertItemBack(T item)
{
  length++;
  node<T> * p = new node<T>;
  p->info = item;
  if ( first == NULL  )
  {
    p->next = NULL;
    p->back = NULL;
    first = p;
    last = p;
  }
  else
  {
    p->next = NULL;
    p->back = last; 
    last ->next = p;
    last = p;
  }
}

template <class T>      
void DLList<T> :: deleteItem(T item)
{
   // for no items in the list
   if ( first == NULL)
      cout<<"\nLIST EMPTY OR ITEM NOT IN THE LIST\n";
   else
   {
      node<T> *p = first;

      // for one item on the list
      if ( item == first->info )
      {
         first = first->next;
         first -> back = NULL;
         delete p;
         length--;
      }
      else
      {
        // p is pointin to the first node in the list
        while( p != NULL && p->info != item ) 
        {
            p=p->next;
        }

        if(p==NULL)
        {
          cout<<"\nITEM NOT IN THE LIST\n";
        }
        // Deletes the found item with one pointer
        else
        {
          p->back->next = p->next;
          if(last == p)
          {
            last = p->back;   
          }
          else
          {
            p->next->back = p->back;
          }
          delete p;
          length--;
        }
      }
   }
}

template <class T>
void DLList<T> :: destroy()
{
    node<T> *p;

    while ( first != NULL )
      {
         p = first;
         first = first->next;
         delete p;
      }
    last = NULL;
    length = 0;
}

template <class T>
void DLList<T> :: copy ( const DLList<T> & other )
{
   length = other.length;
   if ( other.first == NULL )
   {
      first = NULL;
      last = NULL;
   }  
   else
   {
      first = new node<T>;
      first->info = other.first->info;
      
      node<T> *p = other.first->next;
      node<T> *q = first;

      while ( p != NULL )
        {
           q->next = new node<T>;
           q->next->back= q;
           q = q->next;
           q->info = p->info;
           p = p->next;
        }
       last = q;
       q->next = NULL;
   }
}

template <class T>        
int DLList<T> :: getLength()
{
   return length;
}

template <class T>        
bool DLList<T> :: searchItem(T item)
{
  node<T> *p = first;

  while ( p != NULL )
  {
    if ( p->info == item )
      return true;
    p = p->next;
  }
  return false;
}

template <class T>        
void DLList<T> :: printListFront()
{
   if ( first == NULL)
      cout<<"\nEMPTY LIST\n";
   else
   {
      cout<<"\nLIST from front to back:\n";
      node<T> *p = first;
      while ( p != NULL)
        {
           cout<<p->info<<"  ";
           p = p->next;
        }
   } 
}

template <class T>        
void DLList<T> ::printListBack()
{
   if ( first == NULL)
      cout<<"\nEMPTY LIST\n";
   else
   {
      cout<<"\nLIST from back to front:\n";
      node<T> *p = last; 
      while ( p != NULL)
        {
           cout<<p->info<<"  ";
           p = p->back;
        }
   } 
}
template <class T>   
void DLList<T> ::setIteratorFront()
{
  front=first;
}

template <class T>   
void DLList<T> ::moveIteratorFront()
{
  if(front->next != NULL)
    front=front->next;
  else
    front = NULL;
}

template <class T>   
int DLList<T> :: getIteratorFront()
{
  return front->info;
}

template <class T>   
void DLList<T> ::setIteratorBack()
{
  prev=last;
}

template <class T>   
void DLList<T> :: moveIteratorBack()
{
  if(prev->back != NULL)
    prev=prev->back;
  else
    prev = NULL;
}

template <class T>   
int DLList<T> :: getIteratorBack()
{
  return prev->info;
}