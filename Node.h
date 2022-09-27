#pragma once
#include <string>
using namespace std;

class Node
{
public:
   string userID;
   int ticketNum;
   Node* up;
   Node* dp;

   Node(string id, int num);
   void PrintInfo();
};