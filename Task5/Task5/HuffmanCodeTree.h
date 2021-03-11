#pragma once
#ifndef HUFFMANCODETREE
#define HUFFMANCODETREE
#include "PriorityQueue.h"
#include "Tree.h"
#include "SymbolFreq.h"
#include <string>
#include <map>


using namespace std;

class HuffmanCodeTree
{
public:
	HuffmanCodeTree(string file);
	~HuffmanCodeTree(void);
	void print_new_codes(void);
	string get_compressed_string(void);

private:

	void get_all_paths(const node*current_node, string &path);
	PriorityQueue *my_queue;
	Tree *huffman_tree;
	string *compressed_data;
	map <char, string> *new_codes;
};
 
#endif

