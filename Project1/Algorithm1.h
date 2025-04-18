// Brianna Zaffina
// CPSC 335
// Professor Sugandha Bhandari

#pragma once
#include <iostream>
#include <string>
#include <queue>
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

			// If two items of the same priority are specified, it uses FIFO behavior (reliant on the priority_queue class)
		}

		//Pushing a stack
		else if (mode == "stack")
		{
			priorityQ.push({ 0, index, item }); // LIFO
		}

		//Pushing a queue
		else if (mode == "queue")
		{
			priorityQ.push({ 0, -index, item }); //FIFO
		}
		index++; // Order tracking
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
		int item = get<2>(priorityQ.top()); //sets "item" to the number associated with the priority

		//get<2> grabs the item in the 3rd position which is the actaul items value
		//it goes: priority, index, actual value
		//the item that is popped first will have the lowest index 
		priorityQ.pop(); //pops the element with highest priority (maxheap style since c++ is default to maxheap)	

		return item; //returns the popped element
	}

	//If_empty() to show if the queue is empty
	bool is_empty() const
	{
		return priorityQ.empty();
	}
};
