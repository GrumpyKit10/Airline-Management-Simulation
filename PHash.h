/*
Name:	Matthew Wilson
Course:	CSCE 2110.002
Date:	11/15/21

This header file declares the member functions of the Plane hash table
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <tuple>
using namespace std;

#ifndef PHASH_H
#define PHASH_H	

typedef tuple <int, string, string, string, string> P;

class PHash
{
	public:
		PHash(string);//constructor
		
		int hash(int);//converts model name into hash index
		
		void display();//displays hash table contents
		
		void insert(int, string, string, string, string);//inserts item into hash table
		
		void update(int, string, string, string, string);//updates item in hashtable
		
		void select(string);//displays id of planes with matching maintained dates
	
	private:
		static const int size = 23;//table size
		
		struct node//data entry
		{
			int id = -999;
			string make = " ";
			string model = " ";
			string lastMaint = " ";
			string lAstMaintA = " ";
		};
		
		node* HashTable[size];//hash table
};

#endif