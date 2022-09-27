#pragma once
#include <string>
#include "Node.h"

using namespace std;

class Queue
{
public:
   string name;
   int size;
   Node* top; //pointer to top node in stack
   Node *bottom;

   // Methods
   int push_back(string id, int ticketNum);
   int peek();
   int pop();

};