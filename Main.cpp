#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include "Stack.h"
#include "Queue.h"
#include "Node.h"

using namespace std;

class Container
{
public:
   string name;
   string type;
   Stack* stk;
   Queue* q;
   
};

vector<Container> ContainerList;

int ParseFile(string filename);


void ParseArgs(string list[5])
{
   // Determine Command
   if (list[0] == "exit")
   {
      exit(0);
   }
   if (list[0] == "load")
   {
      ParseFile(list[1]);
   }
   if (list[0] == "display")
   {
      printf("List of containers\n");
      if (ContainerList.size() == 0)
      {
         printf("   No containers found\n");
      }
      for (int i = 0; i < ContainerList.size(); i++)
      {
         if (ContainerList[i].type == "stack")
         {
            printf("   stack %s containing %i elements\n", ContainerList[i].name.c_str(), ContainerList[i].stk->size);
         }
         else
         {
            printf("   queue %s containing %i elements\n", ContainerList[i].name.c_str(), ContainerList[i].q->size);
         }
      }
   }
   if (list[0] == "create")
   {
      if (list[1] == "stack")
      {
         Container a;
         Stack* sp = new Stack;
         sp->name = list[2];
         sp->size = 0;
         a.name = list[2];
         a.type = "stack";
         a.stk = sp;
         ContainerList.push_back(a);
         printf("Successfully created the stack %s\n", list[2].c_str());
      }
      if (list[1] == "queue")
      {
         Container a;
         Queue* qp = new Queue;
         qp->name = list[2];
         qp->size = 0;
         a.name = list[2];
         a.type = "queue";
         a.q = qp;
         ContainerList.push_back(a);
         printf("Successfully created the queue %s\n", list[2].c_str());
      }
   }
   if (list[0] == "find")
   {
      bool tmp = true;
      for (int i = 0; i < ContainerList.size(); i++)
      {
         if (ContainerList[i].name == list[1])
         {
            tmp = false;
            if (ContainerList[i].type == "stack")
            {
               printf("The container %s contains %i elements and is a stack\n", ContainerList[i].name.c_str(), ContainerList[i].stk->size);
            }
            else
            {
               printf("The container %s contains %i elements and is a queue\n", ContainerList[i].name.c_str(), ContainerList[i].q->size);
            }
         }

      }
      if (tmp)
      {
         printf("The container %s doesn't exist\n", list[1].c_str());
      }
   }
   if (list[0] == "remove")
   {
      bool tmp = true;
      for (int i = 0; i < ContainerList.size(); i++)
      {
         if (ContainerList[i].name == list[1])
         {
            printf("The container %s was deleted\n", list[1].c_str());
            ContainerList.erase(ContainerList.begin() + i);
            tmp = false;
         }
      }
      if (tmp)
      {
         printf("The container %s doesn't exist", list[1].c_str());
      }
   }
   if (list[0] == "push")
   {
      bool tmp = true; // bool to determine if container exist
      for (int i = 0; i < ContainerList.size(); i++)
      {
         if (ContainerList[i].name == list[4])
         {
            tmp = false;
            if (ContainerList[i].type == "stack")
            {
               ContainerList[i].stk->push_front(list[1], stoi(list[2]));
            }
            else
            {
               ContainerList[i].q->push_back(list[1], stoi(list[2]));
            }
         }
      }
      if (tmp)
      {
         printf("The container %s doesn't exist\n", list[4].c_str());
      }
   }
   if (list[0] == "peek")
   {
      bool tmp = true; // bool to determine if container exist
      for (int i = 0; i < ContainerList.size(); i++)
      {
         if (ContainerList[i].name == list[1])
         {
            tmp = false;
            if (ContainerList[i].type == "stack")
            {
               ContainerList[i].stk->peek();
            }
            else
            {
               ContainerList[i].q->peek();
            }
         }
      }
      if (tmp)
      {
         printf("The container %s doesn't exist\n", list[4].c_str());
      }
   }
   if (list[0] == "pop")
   {
      bool tmp = true; // bool to determine if container exist
      for (int i = 0; i < ContainerList.size(); i++)
      {
         if (ContainerList[i].name == list[1])
         {
            tmp = false;
            if (ContainerList[i].type == "stack")
            {
               ContainerList[i].stk->pop();
            }
            else
            {
               ContainerList[i].q->pop();
            }
         }
      }
      if (tmp)
      {
         printf("The container %s doesn't exist\n", list[4].c_str());
      }
   }
   if (list[0] == "mpop")
   {
      bool tmp = true; // bool to determine if container exist
      for (int i = 0; i < ContainerList.size(); i++)
      {
         if (ContainerList[i].name == list[1])
         {
            tmp = false;
            if (ContainerList[i].type == "stack")
            {
               int success = 0;
               for (int j = 0; j < stoi(list[2]); j++)
               {
                  success += ContainerList[i].stk->pop();
               }
               printf("Successfully pop'd %i elements from container %s\n", success, list[1].c_str());
            }
            else
            {
               int success = 0;
               for (int j = 0; j < stoi(list[2]); j++)
               {
                  success += ContainerList[i].q->pop();
               }
               printf("Successfully pop'd %i elements from container %s\n", success, list[1].c_str());
            }
         }
      }
      if (tmp)
      {
         printf("The container %s doesn't exist\n", list[4].c_str());
      }
   }
}

int ParseFile(string filename)
{
   ifstream myfile;
   stringstream ss;
   string str;
   string list[5];

   myfile.open(filename);
   while (getline(myfile, str))
   {
      // Implement String Parse
      stringstream ss(str);
      string token;
      int num = 0;
      while (getline(ss, token, ' '))
      {
         list[num] = token;
         num++;
      }
      ParseArgs(list);
   }

   return 1;
}

int main()
{
   stringstream ss;
   string str;

   // Get line from std in
   while (getline(cin, str))
   {
      // Implement String Parse
      stringstream ss(str);
      string token;
      string list[5];
      int num = 0;
      // Parse line and get individual words
      while (getline(ss, token, ' '))
      {
         //printf(token.c_str());
         //printf("\n");

         list[num] = token;
         num++;
      }

      ParseArgs(list);


      /*
      // Determine Command
      if (list[0] == "exit")
      {
         return 0;
      }
      if (list[0] == "load")
      {
         ParseFile(list[1]);
      }
      if (list[0] == "display")
      {
         printf("List of containers\n");
         if (ContainerList.size() == 0)
         {
            printf("   No containers found\n");
         }
         for (int i = 0; i < ContainerList.size(); i++)
         {
            if (ContainerList[i].type == "stack")
            {
               printf("   stack %s containing %i elements\n", ContainerList[i].name.c_str(), ContainerList[i].stk->size);
            }
            else
            {
               printf("   queue %s containing %i elements\n", ContainerList[i].name.c_str(), ContainerList[i].q->size);
            }
         }
      }
      if (list[0] == "create")
      {
         if (list[1] == "stack")
         {
            Container a;
            Stack* sp = new Stack;
            sp->name = list[2];
            sp->size = 0;
            a.name = list[2];
            a.type = "stack";
            a.stk = sp;
            ContainerList.push_back(a);
            printf("Successfully created the stack %s\n", list[2].c_str());
         }
         if (list[1] == "queue")
         {
            Container a;
            Queue* qp = new Queue;
            qp->name = list[2];
            qp->size = 0;
            a.name = list[2];
            a.type = "queue";
            a.q = qp;
            ContainerList.push_back(a);
            printf("Successfully created the queue %s\n", list[2].c_str());
         }
      }
      if (list[0] == "find")
      {
         bool tmp = true;
         for (int i = 0; i < ContainerList.size(); i++)
         {
            if (ContainerList[i].name == list[1])
            {
               tmp = false;
               if (ContainerList[i].type == "stack")
               {
                  printf("The container %s contains %i elements and is a stack\n", ContainerList[i].name.c_str(), ContainerList[i].stk->size);
               }
               else
               {
                  printf("The container %s contains %i elements and is a queue\n", ContainerList[i].name.c_str(), ContainerList[i].q->size);
               }
            }
            
         }
         if (tmp)
         {
            printf("The container %s doesn't exist\n", list[1].c_str());
         }
      }
      if (list[0] == "remove")
      {
         bool tmp = true;
         for (int i = 0; i < ContainerList.size(); i++)
         {
            if (ContainerList[i].name == list[1])
            {
               printf("The container %s was deleted\n", list[1].c_str());
               ContainerList.erase(ContainerList.begin()+i);
               tmp = false;
            }
         }
         if (tmp)
         {
            printf("The container %s doesn't exist", list[1].c_str());
         }
      }
      if (list[0] == "push")
      {
         bool tmp = true; // bool to determine if container exist
         for (int i = 0; i < ContainerList.size(); i++)
         {
            if (ContainerList[i].name == list[4])
            {
               tmp = false;
               if (ContainerList[i].type == "stack")
               {
                  ContainerList[i].stk->push_front(list[1], stoi(list[2]));
               }
               else
               {
                  ContainerList[i].q->push_back(list[1], stoi(list[2]));
               }
            }
         }
         if (tmp)
         {
            printf("The container %s doesn't exist\n", list[4].c_str());
         }
      }
      if (list[0] == "peek")
      {
         bool tmp = true; // bool to determine if container exist
         for (int i = 0; i < ContainerList.size(); i++)
         {
            if (ContainerList[i].name == list[1])
            {
               tmp = false;
               if (ContainerList[i].type == "stack")
               {
                  ContainerList[i].stk->peek();
               }
               else
               {
                  ContainerList[i].q->peek();
               }
            }
         }
         if (tmp)
         {
            printf("The container %s doesn't exist\n", list[4].c_str());
         }
      }
      if (list[0] == "pop")
      {
         bool tmp = true; // bool to determine if container exist
         for (int i = 0; i < ContainerList.size(); i++)
         {
            if (ContainerList[i].name == list[1])
            {
               tmp = false;
               if (ContainerList[i].type == "stack")
               {
                  ContainerList[i].stk->pop();
               }
               else
               {
                  ContainerList[i].q->pop();
               }
            }
         }
         if (tmp)
         {
            printf("The container %s doesn't exist\n", list[4].c_str());
         }
      }
      if (list[0] == "mpop")
      {
         bool tmp = true; // bool to determine if container exist
         for (int i = 0; i < ContainerList.size(); i++)
         {
            if (ContainerList[i].name == list[1])
            {
               tmp = false;
               if (ContainerList[i].type == "stack")
               {
                  int success = 0;
                  for (int j = 0; j < stoi(list[2]); j++)
                  {
                     success += ContainerList[i].stk->pop();
                  }
                  printf("Successfully pop'd %i elements from container %s\n", success, list[1].c_str());
               }
               else
               {
                  int success = 0;
                  for (int j = 0; j < stoi(list[2]); j++)
                  {
                     success += ContainerList[i].q->pop();
                  }
                  printf("Successfully pop'd %i elements from container %s\n", success, list[1].c_str());
               }
            }
         }
         if (tmp)
         {
            printf("The container %s doesn't exist\n", list[4].c_str());
         }
      }
      */
   }
   
   while (1);
   return 0;
}