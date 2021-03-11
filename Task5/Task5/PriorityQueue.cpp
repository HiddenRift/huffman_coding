#include "stdafx.h"
#include "PriorityQueue.h"

PriorityQueue::PriorityQueue()
{
	this->my_queue = new priority_queue<node*, vector<node*>, node>;
}

node * PriorityQueue::pop()
{
	// Check if queue is empty, if it is return null otherwise exec top and pop
	if (!this->my_queue->empty())
	{
		node* value = this->my_queue->top();
		this->my_queue->pop();
		return value;
	}
	else
	{
		return NULL;
	}
}

uint32_t PriorityQueue::size()
{
	//return number of items stored by the queue
	return this->my_queue->size();
}

void PriorityQueue::push(node * new_node)
{
	// push new node to the queue
	this->my_queue->push(new_node);
}

void PriorityQueue::print_queue()
{
	cout << "Printing Priority Queue:" << endl;

	// create temp store for nodes popped off queue
	auto temp_store = new vector<node*>;
	uint32_t queue_length = this->my_queue->size();

	// for each item output the number and info based on wht type of member it is
	for (size_t i = 0; i < queue_length; i++)
	{
		node *temp_node = this->my_queue->top();
		temp_store->push_back(temp_node);
		this->my_queue->pop();
		cout << i << ' ';
		if (temp_node->payload == NULL)
		{
			// if payload set to null then is a branch
			cout << "|Node weight: " << temp_node->weight << " |Branch 0: " << temp_node->branch0 << " |Branch 1: " << temp_node->branch1;
		}
		else
		{
			// if payload not null then is a leaf
			cout << "|Node weight: " << temp_node->weight << " |Node payload: " << temp_node->payload;
		}
		cout << endl;
	}

	// push all items back into the queue by iterating over temp store
	for each (auto var in *temp_store)
	{
		this->my_queue->push(var);
	}

	delete temp_store;
}


PriorityQueue::~PriorityQueue()
{
	delete this->my_queue;
}
