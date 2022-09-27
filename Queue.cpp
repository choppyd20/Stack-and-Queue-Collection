#include "Queue.h"

int Queue::push_back(string id, int ticketNum)
{
   Node* newNode = new Node(id, ticketNum);
   if (bottom == NULL)
   {
      bottom = newNode;
      top = newNode;
   }
   else
   {
      bottom->dp = newNode;
      newNode->up = bottom;
      bottom = newNode;
   }
   size++;
   printf("Pushed user %s @ ticket %i into container %s\n", id.c_str(), ticketNum, name.c_str());
   return 1;
}

int Queue::peek()
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

int Queue::pop()
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
         // popping only entry in queue
         delete top;
         top = NULL;
         bottom = NULL;
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