// Brianna Zaffina
// CPSC 335
// Professor 

#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <tuple>
#include <stdexcept>
using namespace std;

class NewPriorityQueue

{
private:
	//String to determine the mode (stack, queue, or prioirtyqueue)
	string mode;
	//Priority Queue object (tried inheriteance but this was overall the most efficent / easiest)
	//Using a tuple to help keep order to maintain FIFO
	priority_queue<tuple<int, int, int>> priorityQ;
	//Stack object (FILO)
	stack<int> stack_;
	//Queue object (FIFO)
	queue<int> queue_;
	//Index to ensure priority queue dequeues in FIFO when elements have same priority
	int index; 

public:
	//Default Constructor
	NewPriorityQueue() : mode("priority"), index(0) {}

	//PriorityQueue Overloaded Constructor
	NewPriorityQueue(string mode) : mode(mode), index(0)
	{
		if (mode != "priority" && mode != "stack" && mode != "queue")
		{
			throw std::range_error("That is not a valid mode type, use a different mode"); //if the options are invalid
		}
	}

	//Push function that handles all cases
	void push(int item, int priority = -1) //Push for all three different types; -1 as a temp number so that we can 
	// see if the number provided has a specified priority
	{
		//If the priority is not provided, it uses the element provided as the priority
		if (priority == -1)
		{
			priority = item;
		}

		//Pushing a priority queue
		if (mode == "priority")
		{
			priorityQ.push({ priority, -index, item }); //Pushes an item with a given priority by the user,
			// If priority is not specified it takes the element itself as the priority
			// Uses negative index
			index++; // Order tracking
			// If two items of the same priority are specified, it uses FIFO behavior (reliant on the priority_queue class)
		}

		//Pushing a stack
		else if (mode == "stack")
		{
			stack_.push(item); //LIFO
		}

		//Pushing a queue
		else if (mode == "queue")
		{
			queue_.push(item); //FIFO
		}
	}

	//Pop functions w/ Edge Case Handeling
	int pop()
	{
		//Throws a range_error if the "new" queue is empty; cannot pop an empty queue
		if (is_empty())
		{
			throw std::range_error("Queue is empty. Cannot pop an empty queue.");
		}

		//Popping a priority queue
		if (mode == "priority")
		{
			int item = get<2>(priorityQ.top()); //sets "item" to the number associated with the priority
			//get<2> grabs the item in the 3rd position which is the actaul items value
			//it goes: priority, index, actual value
			//the item that is popped first will have the lowest index 
			priorityQ.pop(); //pops the element with highest priority (maxheap style since c++ is default to maxheap)
			return item; //returns the popped element
		}
		
		//Popping a stack
		else if (mode == "stack")
		{
			int item = stack_.top(); //sets the top of the stack (which would be the most recently entered elemnt) to item
			stack_.pop(); //pops this element
			return item; //returns the element
		}

		//Popping a queue
		else if (mode == "queue")
		{
			int item = queue_.front(); //Sets the "front" element to item
			queue_.pop(); //Pops this element
			return item; //returns the popped element
		}

		return -1; // Returns -1 (which it'll never reach) since pop is an int object (needs a return type). 
		// Because we have edge case handeling for it being empty & for the item not being 
		// a priority queue, stack, or queue, it won't ever reach -1
	}

	//If_empty() to show if the queue is empty
	bool is_empty() const
	{
		//Priority queue empty case
		if (mode == "priority")
		{
			return priorityQ.empty();
		}

		//Stack empty case
		else if (mode == "stack")
		{
			return stack_.empty();
		}
		
		//Queue empty case
		else if (mode == "queue")
		{
			return queue_.empty();
		}

		return true;
	}
};
