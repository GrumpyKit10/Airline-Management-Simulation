/*
Name:	Matthew Wilson
Course:	CSCE 2110.002
Date:	11/15/21

This header file defines the member functions of the PlaneType hash table
*/

#include "PThash.h"

PTHash::PTHash(string file)
{		
	for(int i = 0; i < size; i++)
	{
		HashTable[i] = new node;
	}
	
	ifstream fin(file);
	
	string line, word, Make, Model;
	int flys = 0, gros = 0, i = 0;

	getline(fin, line);
	
	while(getline(fin, line))
	{		
		for(unsigned int i = 0; i < line.length(); i++)
		{
			if(line[i] == ',')
			{
				line[i] = ' ';
			}
		}
		
		stringstream ss(line);
		
		ss >> Make >> Model >> flys >> gros;
		
		i = hash(Make);
		
		if(HashTable[i]->make == " ")
		{
			HashTable[i]->make = Make;
			HashTable[i]->model = Model;
			HashTable[i]->flyspeed = flys;
			HashTable[i]->groundspeed = gros;
		}
		
		else//handling collision by double hashing
		{
			i = (hash(Make) + hash(Model) + 1) % size;
			
			HashTable[i]->make = Make;
			HashTable[i]->model = Model;
			HashTable[i]->flyspeed = flys;
			HashTable[i]->groundspeed = gros;
		}
	}
	
	fin.close();
}

int PTHash::hash(string key)
{
	int hash = 0;
	int index;
	int M = 3;
	
	for(unsigned int i = 0; i < key.length(); i++)
	{
		hash = (hash * M) + (int)key[i];//multiplicative hashing
	}
	
	index = hash % size;
	
	return index;
}

void PTHash::display()
{
	node* ptr;
	
	cout << "Maker\t" << "Model\t" << "FlyingSpeed\t" << "GroundSpeed" << endl;

	for(int i = 0; i < size; i++)
	{
		ptr = HashTable[i];
		
		if(ptr->make != " ")
		{			
			cout << ptr->make << "\t" << ptr->model << "\t\t";
			cout << ptr->flyspeed << "\t\t" << ptr->groundspeed;
			cout << endl;
		}
	}
	
	cout << endl;
}

void PTHash::insert(string mk, string md, int fs, int gs)
{
	int index = hash(md);
		
	if(HashTable[index]->flyspeed != -999)
	{
		cout << "Error in plane type table: need unique key from make." << endl;
		
		return;
	}
	
	HashTable[index]->make = mk;
	HashTable[index]->model = md;
	HashTable[index]->flyspeed = fs;
	HashTable[index]->groundspeed = gs;
}

void PTHash::update(string mk, string md, int fs, int gs)
{
	int in = hash(md);
	
	if(HashTable[in]->make == " ")
	{
		cout << "Error in plane type table: index is empty." << endl;
		
		return;
	}
	
	for(int i = 0; i < size; i++)
	{
		if(HashTable[i]->flyspeed == fs)
		{
			HashTable[i]->make = mk;
			HashTable[i]->model = md;
			HashTable[i]->flyspeed = fs;
			HashTable[i]->groundspeed = gs;
		}
	}
}
		
void PTHash::select(int fs)
{
	int j = -1;
	int a[23];
	
	for(int i = 0; i < size; i++)
	{
		if(HashTable[i]-> flyspeed == fs)
		{
			j++;
			
			a[j] = i;
		}
	}
	
	if(j > -1)
	{
		cout << "Select: Plane(s) at index: ";
		
		for(int i = 0; i <= j; i++)
		{
			cout << a[i] << ", ";
		}

		cout << "have " << fs << " flying speed" << endl << endl;
	}
}
		
		