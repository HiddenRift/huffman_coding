#include "stdafx.h"
#include "HuffmanCodeTree.h"

HuffmanCodeTree::HuffmanCodeTree(string file)
{
	// initialise internal variables
	this->my_queue = new PriorityQueue;
	this->huffman_tree = new Tree;
	this->new_codes = new map<char, string>;
	this->compressed_data = new string;

	// aquire symbols
	SymbolFreq *symbols_collection = new SymbolFreq(file);
	// uncomment line to print symbold collection contents
	/*symbols_collection->debug_print_map();*/
	vector<tuple<char, int>*> *symbol_list = symbols_collection->get_list();

	// create leaf node for each tuple in list and push to priority queue
	for each (auto var in *symbol_list)
	{
		this->my_queue->push(this->huffman_tree->create_leaf(get<CHARACTER>(*var), get<CHARACTERNUM>(*var)));
	}


	//while More than 1 node present pop 2 nodes and reinsert a merged node of them
	while (this->my_queue->size() > 1)
	{
		node *node_a = this->my_queue->pop();
		node *node_b = this->my_queue->pop();
		this->my_queue->push(this->huffman_tree->merge_nodes(node_a, node_b));
	}

	// retrieve root node for tree traversal
	node *root = this->my_queue->pop();

	// Uncomment line below to print tree
	/*this->huffman_tree->pretty_print_tree(root, 0);*/

	//create temp string for fetching huffmancodes
	string *temp = new string("");
	this->get_all_paths(root, *temp);
	delete temp;

	// retrieve uncompressed string and iterate through it uing  var to lookup new
	// huffman code to append to the compressed data stream
	for each (char var in symbols_collection->get_uncompressed_data())
	{
		*this->compressed_data += (*this->new_codes)[var];
	}

	// delete symbols collection as no longer needed
	delete symbols_collection;
	
}

HuffmanCodeTree::~HuffmanCodeTree()
{
	delete this->my_queue;
	delete this->huffman_tree;
	delete this->new_codes;
}

void HuffmanCodeTree::print_new_codes()
{
	cout << "Printing new huffman codes: " << endl;
	// Iterate through map of new huffman codes outputting the pair of values
	for each (auto var in *this->new_codes)
	{
		cout << '\'' << var.first << "\' : " << var.second << endl;
	}
}

string HuffmanCodeTree::get_compressed_string(void)
{
	// dereference and return compressed data string
	return *this->compressed_data;
}

void HuffmanCodeTree::get_all_paths(const node * current_node, string & path)
{
	if (current_node->payload != NULL)
	{
		// ischaracter
		(*this->new_codes)[current_node->payload] = path;
	}
	else
	{
		// is branch
		// traverse 0
		get_all_paths(current_node->branch0, path += "0");
		path.pop_back();
		// traverse 1
		get_all_paths(current_node->branch1, path += "1");
		path.pop_back();
	}
}
