#pragma once
#ifndef SYMBOLFREQ
#define SYMBOLFREQ

#include <string>
#include <map>
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <fstream>
#define CHARACTER 0
#define CHARACTERNUM 1

using namespace std;

class SymbolFreq
{
public:
	SymbolFreq(const string &file_name);
	vector<tuple<char, int>*> *get_list(void);
	string get_uncompressed_data(void);
	~SymbolFreq(void);
	void debug_print_map(void);
private:
	vector<tuple<char, int>*> *sorted_map;
	string get_file_contents(const string &filename);
	string *uncompressed_data;
};


#endif
