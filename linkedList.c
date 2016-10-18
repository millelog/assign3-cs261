#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>


struct Link* listInsertionSort(struct Link* head) {

  /*
   * This function should perform an insertion sort on the list whose head is
   * provided as the function's argument, so that the values in the list are
   * sorted in ascending order, starting at the head.
   *
   * The sort should be done without allocating any new Link structs or any
   * other auxiliary data structures.
   *
   * Return a pointer to the new head of the list.
   */
   if( head==NULL || head->next == NULL)
    return head;

   struct Link* current = head->next;
   struct Link* iter = head;

   while(current != NULL){

     iter = head;

     while(iter->next != current){

       if(iter->value > current->value){

         TYPE temp = current->value;
         current->value = iter->value;
         iter->value = temp;

       }
       else{
         iter = iter->next;
       }
     }
     current = current->next;
   }
  return head;

}


struct Link* reverseList(struct Link* head) {

  /*
   * This function should iteratively reverse the list whose head is provided
   * as the function's argument.
   *
   * The reversal must be done totally in place, i.e. you may not allocate any
   * new Link structs or any other auxiliary data structures.
   *
   * Return a pointer to the new head of the list.
   */
   if(head == NULL || head->next == NULL){
     return head;
   }

   struct Link* prev = NULL;
   struct Link* current = head;
   struct Link* next = head->next;
   while(next!=NULL){
     current->next = prev;
     prev = current;
     current = next;
     next = next->next;
   }
   current->next = prev;
   head = current;
   return head;

}


struct Link* reverseListRecursive(struct Link* head){

  /*
   * Write this function for extra credit.  It should do the exact same thing
   * as reverseList() above, except it should do it recursively instead of
   * iteratively (i.e. no loops allowed).
   *
   * Again, you may not allocate any new Link structs or any other auxiliary
   * data structures.  You may, however, define an auxiliary function to help
   * you do the recursion.
   *
   * Return a pointer to the new head of the list.
   */
   if(head == NULL || head->next==NULL)
    return head;
   struct Link* second = head->next;
   head->next = NULL;
   struct Link* list = reverseListRecursive(second);

   second->next = head;
   return list;

  return head;

}
