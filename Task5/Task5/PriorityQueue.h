#pragma once
#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE
#include "node.h"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class PriorityQueue
{
public:
	PriorityQueue();
	node* pop();
	uint32_t size();
	void push(node *new_node);
	void print_queue();
	~PriorityQueue();

private:
	priority_queue<node*, vector<node*>, node> *my_queue;
};

#endif
