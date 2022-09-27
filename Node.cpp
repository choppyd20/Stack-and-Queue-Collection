#include "Node.h"

Node::Node(string id, int num)
{
   userID = id;
   ticketNum = num;
}
void Node::PrintInfo()
{
   printf("ID: %s , Ticket Number: %i\n", userID.c_str(), ticketNum);
}