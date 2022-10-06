# Stack-and-Queue-Collection
## Overview
The purpose of this repository is to write a program that both implements and manages a collection of stacks and queue. In simple terms, each stack and queue will work the same data type, a node that stores entries comprised of a string representing a user id and an integer representing rhe user's ticket number. Also, each stack and queue should store a string that represents its container name and an integer representing the number of entries currently in the stack or queue.

## Commands
This program should implement a command line (text-based interface) capable of handling the following commands:   
  &nbsp; **exit** - exits the program   
  
  &nbsp; **load (file)** - parses the contents of the file as if they were entered from the command line  
  
  &nbsp; **display** - displays a list of the saved stacks and queues that were created. It should include the container type, the container name, and the current number of entries.  
  
  &nbsp; **create stack (container)** - creates a new stack labeled container. Should inform the user on a failure.  
  
  &nbsp; **create queue (container)** - creates a new queue labeled container. Should inform the user on a failure.  
  
  &nbsp; **find (container)** - finds the specified container and displays its type and current number of entries. Should inform the user on a failure.  
  
  &nbsp; **remove (container)** - Removes the specified container. Should inform the user of a failure.  
  
  &nbsp; **push (uid) (ticket number) into (container)** - Inserts the specified uid, ticker number pair into the specified container. Should inform the user of a failure.  
  
  &nbsp; **peek (container)** - displays the top most element of the container. Should inform the user of a failure.  
  
  &nbsp; **pop (container)** - removes the top most element of the container. Should inform the user of a failure.  
  
  &nbsp; **mpop (container) (n)** - performs the pop command n times; i.e. it removes the top n elements of the container. Should inform the user of how many elements were successfully removed from the container.  
  
