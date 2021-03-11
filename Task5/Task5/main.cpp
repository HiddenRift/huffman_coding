// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HuffmanCodeTree.h"
#include <iostream>
using namespace std;

int main()
{
	auto compressor = new HuffmanCodeTree("ToCompress.txt");
	
	compressor->print_new_codes();
	cout << endl << "compressed bit string follows: " << endl;
	cout <<endl<< compressor->get_compressed_string() << endl;
    return 0;
}

