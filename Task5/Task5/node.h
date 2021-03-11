#pragma once
#ifndef NODE
#define NODE
#include <iostream>

struct node
{
	node *branch0, *branch1;
	char payload;
	uint32_t weight;
	// compare 2 nodes by tBheir weights
	bool operator()(const node *a, const node *b)
	{
		return a->weight > b->weight;
	}
};

#endif // !NODE
