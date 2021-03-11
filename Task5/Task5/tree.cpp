

#include "stdafx.h"
#include "Tree.h"


Tree::Tree()
{
	this->root = NULL;
}

node * Tree::create_leaf(char character, uint32_t weight)
{
	node *leaf = new node;
	leaf->branch0 = NULL;
	leaf->branch1 = NULL;
	leaf->payload = character;
	leaf->weight = weight;
	return leaf;
}

node * Tree::merge_nodes(node *branch0, node *branch1)
{
	// create new branch and set t as root
	node *branch = new node;
	this->set_root(branch);

	// append new information to it
	branch->branch0 = branch0;
	branch->branch1 = branch1;
	branch->payload = NULL;
	branch->weight = branch0->weight + branch1->weight;
	return branch;
}

void Tree::set_root(node * root)
{
	this->root = root;
}

void Tree::print_tree()
{
	if (this->root == NULL)
	{
		cout << "Root not set";
	}
	print_tree(this->root);
	//root is set

}

void Tree::pretty_print_tree(node *node, uint32_t indent)
{
	if (node == NULL)
		return;

	indent++;
	pretty_print_tree(node->branch0, indent);
	cout << endl;
	for (size_t i = 0; i < indent; i++)
	{
		cout << "          ";
	}
	if (node->payload == NULL)
		cout << "w: " << node->weight << " |c: ^" << endl;
	else
		cout << "w: " << node->weight << " |c: " << node->payload << endl;
	pretty_print_tree(node->branch1, indent);
} 

Tree::~Tree()
{
	//create destructor for the tree based on root
	this->delete_tree(this->root);
}

void Tree::print_tree(node * location)
{
	if (location->branch0 == NULL)
	{
		cout << location->payload << endl;
		return;
	}
	print_tree(location->branch0);
	print_tree(location->branch1);
	return;
}

void Tree::delete_tree(node *location)
{
	if (location->payload != NULL)
	{
		delete location;
	}
	else
	{
		// traverse
		delete_tree(location->branch0);
		delete_tree(location->branch1);
		// delete self 
		delete location;
	}

}


