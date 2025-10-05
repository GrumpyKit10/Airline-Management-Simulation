/*
Name:	Matthew Wilson
Course:	CSCE 2110.002
Date:	11/15/21

This header file declares the member functions of the PlaneType hash table
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#ifndef PTHASH_H
#define PTHASH_H

class PTHash
{
	public:
		PTHash(string);//constructor
		
		int hash(string);//converts model name into hash index
		
		void display();//displays hash table contents
		
		void insert(string, string, int, int);//inserts item into hash table
		
		void update(string, string, int, int);//updates item in hashtable
		
		void select(int);//displays index of matching fly speed
	
	private:
		static const int size = 23;//table size
		
		struct node//data entry
		{
			string make = " ";
			string model = " ";
			int flyspeed = -999;
			int groundspeed = -999;
		//	node* next = NULL;
		};
		
		node* HashTable[size];//hash table
};

#endif