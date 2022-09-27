#include "Stack.h"

int Stack::push_front(string id, int ticketNum)
{
   Node* newNode = new Node(id, ticketNum);
   if (top == NULL)
   {
      top = newNode;
   }
   else
   {
      top->up = newNode;
      newNode->dp = top;
      top = newNode;
   }

   size++;
   printf("Pushed user %s @ ticket %i into container %s\n", id.c_str(), ticketNum, name.c_str());
   return 1;
}

int Stack::peek()
{
   if (top == NULL)
   {
      // No nodes have been added yet
      printf("ERROR: No nodes been added\n");
   }
   else
   {
      top->PrintInfo();
   }
   return 1;
}

int Stack::pop()
{
   if (top == NULL)
   {
      // No nodes have been added yet
      printf("ERROR: No nodes been added\n");
      return 0;
   }
   else
   {
      //printf("Popping %s\n", top->userID);
      if (top->dp == NULL)
      {
         // popping only entry in stack
         delete top;
         top = NULL;
      }
      else
      {
         top->dp->up = NULL;
         Node* tmp = top;
         top = top->dp;
         delete tmp;
      }
      size--;
      printf("Successfully pop'd from the container %s\n", name.c_str());
   }
   return 1;
}