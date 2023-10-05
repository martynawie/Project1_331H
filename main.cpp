#include "DLList.cpp"

/***************************************************************/
/* Programmer: Martyna Wieczorek                               */            
/* Date:  September 25, 2023                                   */        
/* Purpose: Test of Doubly linked list                         */
/* Input: user’s choice to perform an operation                */
/* Output: menu of choices and results of user’s operations.   */        /***************************************************************/

// Displays a menu of choices and returns the user's choice
int printMenu();

// Functions prototypes for testing 
void printFrontBack(DLList<int> &l);
void printBackFront(DLList<int> &);
void insertListItemFront (DLList<int> &);
void insertListItemBack (DLList<int> &);
void deleteListItem ( DLList<int> &);
void searchListItem ( DLList<int>); 

//************************** main program ************************/

int main()
{
   DLList<int> l;
   int choice;
   
   cout<<"\nOperations allowed on the unsorted list of integers are below."
      <<"\nPlease enter the number of your choice and press return.\n\n"; 

   choice = printMenu();

   while ( choice != 10 )
   {
       switch ( choice )
      {
         case 1 : insertListItemFront( l );
                  break;
        
         case 2 : insertListItemBack( l );
                  break;
    
         case 3 : deleteListItem ( l );
                  break;

         case 4 : l.printListFront();
                  break;

         case 5 : l.printListBack();
                  break;
                   
         case 6 : searchListItem ( l );
                  break;
                     
         case 7 : cout<<"\nThe list contains "<<l.getLength()
                      << " items\n\n";
                  break; 

         case 8 : printFrontBack(l);
                  break; 
        
         case 9 : printBackFront(l);
                  break; 
        
         default :cout<<"\nNumber is not correct. Please look at "
                      <<"choices and reenter\n\n";
                 break;
      }

      choice = printMenu();
   }

   DLList<int> l2; 

   l2 = l;   

   cout<<"\nPrinting a new list with the same values as the old list \n";
   
   l2.printListFront();
   l2.printListBack();
   
   cout<<"\nProgram terminated\n\n";
   
   return 0;
}

//********************functions implementation ********************//

// Displays the menu and returns the user's choice
int printMenu ()
{
   int c;

   cout<<"\n1: Add an item to the beginning of the list.";
   cout<<"\n2: Add an item to the end of the list.";
   cout<<"\n3: Delete an item from the list.";
   cout<<"\n4: Print the list from the beginning.";
   cout<<"\n5: Print the list from the end.";
   cout<<"\n6: Search the list for a given item";
   cout<<"\n7: Return the number of items in the list";
   cout<<"\n8: Print the list using Iterator from front to back";
   cout<<"\n9: Print the list using Iterator from back to front";
   cout<<"\n10: Quit.\n\n";
   cin>>c;

   return c;
}

// Function to print the list from front to back using an iterator
void printFrontBack(DLList<int> &l)
{
  l.setIteratorFront();
  for(int i = 0; i < l.getLength(); i++)
  {
    cout<<l.getIteratorFront()<<" ";
    l.moveIteratorFront();
  }
}

// Function to print the list from back to front using an iterator
void printBackFront(DLList<int> &l)
{
  l.setIteratorBack();
  for(int i = 0; i < l.getLength(); i++)
  {
    cout<<l.getIteratorBack()<<" ";
    l.moveIteratorBack();
  }
}

// Function to insert an item at the front of the list
void insertListItemFront ( DLList<int> &l )
{
   int num;  
      cout<<"\nEnter the number to insert : ";
      cin>>num;
      l.insertItemFront(num);
      cout<<"\nThe number has been inserted\n\n";
}

// Function to insert an item at the back of the list
void insertListItemBack ( DLList<int> &l )
{
   int num;  
      cout<<"\nEnter the number to insert : ";
      cin>>num;
      l.insertItemBack(num);
      cout<<"\nThe number has been inserted\n\n";
}

// Function to delete an item from the list
void deleteListItem ( DLList<int> &l )
{
   int num;
   cout<<"\nEnter the number to delete : ";
   cin>>num;
   if ( l.searchItem (num))
   { 
      l.deleteItem (num);
      cout<<"\nThe number has been deleted\n\n";
   }
   else  cout<<"\nThe number is NOT in the list\n\n";     
}

// Function to search for an item in the list
void searchListItem ( DLList<int> l )
{
   int num;
   cout<<"\nEnter the number to search for : ";
   cin>>num;
   if ( l.searchItem (num))
   
       cout<<"\nThe number is in the list\n\n";
   
   else  cout<<"\nThe number is NOT in the list\n\n";
}