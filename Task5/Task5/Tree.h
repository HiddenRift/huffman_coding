#pragma once
#ifndef TREE
#define TREE
#include <iostream>
#include "node.h"

using namespace std;

class Tree
{
public:
	Tree();
	node *create_leaf(char character, uint32_t weight);
	node *merge_nodes(node *branch1, node *branch2);
	void set_root(node *root);
	void print_tree();

	// Tree printing algorithm adapted from
	// https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
	// when pretty printing leaves  show their character values and weight
	void pretty_print_tree(node *node, uint32_t indent);
	~Tree();

private:
	void print_tree(node *location);
	node *root;
	void delete_tree(node *location);

};

#endif
