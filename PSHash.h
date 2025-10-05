/*
Name:	Matthew Wilson
Course:	CSCE 2110.002
Date:	11/15/21

This header file declares the member functions of the PlaneSeats hash table
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#ifndef PSHASH_H
#define PSHASH_H

class PSHash
{
	public:
		PSHash(string);//constructor
		
		int hash(string);//converts model name into hash index
		
		void display();//displays hash table contents
		
		void insert(string, string, string, int);//inserts item into hash table
		
		void update(string, string, string, int);//updates item in hashtable
		
		void select(int);//displays index of matching number of seats
	
	private:
		static const int size = 23;//table size
		
		struct node//data entry
		{
			string make = " ";
			string model = " ";
			string seattype = " ";
			int seats = -999;
			node* next = NULL;
		};
		
		node* HashTable[size];//hash table
};

#endif