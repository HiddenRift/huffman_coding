#include "stdafx.h"
#include "SymbolFreq.h"

SymbolFreq::SymbolFreq(const string &file_name)
{
	this->uncompressed_data = new string(this->get_file_contents(file_name));
	// initialise vector of the sorted map
	this->sorted_map = new vector <tuple <char, int>*>;

	// map only exists for duration of the constructor so defined locally
	//map <char, int> charSorter;
	map <char, int> *charSorter = new map <char, int>;
	//auto *mappy = new map <char, int>;

	for each (char i in *this->uncompressed_data)
	{
		/*
		* if char does not exist then find() returns value == the end of map
		* if char is in map then increment otherwise add it and set its val to 1
		*/
		charSorter->find(i) != charSorter->end() ? (*charSorter)[i]++ : (*charSorter)[i] = 1;
	}

	// move contens of the map to tuple vector for storage and sorting
	for (map<char, int>::iterator iter = charSorter->begin(); iter != charSorter->end(); ++iter)
	{
		this->sorted_map->push_back(new tuple<char, int>{iter->first, iter->second});
	}

	// deallocate charsorter as no longer needed
	delete charSorter;

	// sort the vector based on CHARACTERNUM in ascending order 0 = lowest, 
	sort(this->sorted_map->begin(), this->sorted_map->end(), []
	(tuple<char, int> const *t1, tuple<char, int> const *t2)
	{
		return get<CHARACTERNUM>(*t1) > get<CHARACTERNUM>(*t2); 
	});

}

vector<tuple<char, int>*>* SymbolFreq::get_list(void)
{
	return sorted_map;
}

string  SymbolFreq::get_uncompressed_data(void)
{
	return *uncompressed_data;
}

SymbolFreq::~SymbolFreq(void)
{
	// delete tuples
	//var is tuple member of map
	for each (auto var in *sorted_map)
	{
		delete var;
	}
	// delete map
	delete this->sorted_map;
	delete this->uncompressed_data;
}

void SymbolFreq::debug_print_map(void)
{
	for each (auto var in *sorted_map)
	{
		cout << '\'' << get<CHARACTER>(*var) << "' : '" << get<CHARACTERNUM>(*var) << '\'' << endl;
	}
}

string SymbolFreq::get_file_contents(const string & filename)
{
	string file_contents;
	ifstream fh;
	fh.open(filename);
	getline(fh, file_contents);
	fh.close();
	return file_contents;
}

