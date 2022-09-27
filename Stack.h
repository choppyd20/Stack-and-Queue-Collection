#pragma once
#include <string>
#include "Node.h"

using namespace std;

class Stack
{
public:
   string name;
   int size;
   Node* top; //pointer to top node in stack

   // Methods
   int push_front(string id, int ticketNum);
   int peek();
   int pop();

};