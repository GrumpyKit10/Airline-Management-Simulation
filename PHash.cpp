/*
Name:	Matthew Wilson
Course:	CSCE 2110.002
Date:	11/15/21

This header file defines the member functions of the Plane hash table
*/

#include "PHash.h"

PHash::PHash(string file)
{		
	for(int i = 0; i < size; i++)
	{
		HashTable[i] = new node;
	}
	
	ifstream fin(file);
	
	string line, word, Make, Model, LastMaint, LAstMaintA;
	int ID = 0, i = 0;

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
		
		ss >> ID >> Make >> Model >> LastMaint >> LAstMaintA;
		
		i = hash(ID);
		
		if(HashTable[i]->make == " ")
		{
			HashTable[i]->id = ID;
			HashTable[i]->make = Make;
			HashTable[i]->model = Model;
			HashTable[i]->lastMaint = LastMaint;
			HashTable[i]->lAstMaintA = LAstMaintA;
		}
		
		else//handling collision by linear probing
		{
			for(int i = 0; i < size; i++)
			{
				if(HashTable[i]->id == -999)
				{
					HashTable[i]->id = ID;
					HashTable[i]->make = Make;
					HashTable[i]->model = Model;
					HashTable[i]->lastMaint = LastMaint;
					HashTable[i]->lAstMaintA = LAstMaintA;
					
					break;
				}
			}
		}
	}
	
	fin.close();
}

int PHash::hash(int key)//mid-square hashing
{
	long int hash = key * 999;
	int index;
	
	hash *= hash;
	
	hash = hash / 10000;
	
	hash = hash % 100000000;//gets middle digits
	
	index = hash % size;
	
	return index;
}

void PHash::display()
{
	node* ptr;
	
	cout << "ID\t" << "Maker\t" << "Model\t\t" << "Last Maintained Date\t" << "Last Maintained Airport" << endl;

	for(int i = 0; i < size; i++)
	{
		ptr = HashTable[i];
		
		if(ptr->make != " ")
		{			
			cout << ptr->id << "\t";
			cout << ptr->make << "\t" << ptr->model << "\t\t\t";
			cout << ptr->lastMaint << "\t\t" << ptr->lAstMaintA;
		//	cout << "\t\t\tIndex: " << i;//testing
			cout << endl;
			
		}
	}
	
	cout << endl;
}


void PHash::insert(int ID, string mk, string md, string lm, string lma)
{
	int index = hash(ID);
	
	if(HashTable[index]->id != -999)
	{
		cout << "Error in plane table: need unique key from ID." << endl;
		
		return;
	}
	
	HashTable[index]->id = ID;
	HashTable[index]->make = mk;
	HashTable[index]->model = md;
	HashTable[index]->lastMaint = lm;
	HashTable[index]->lAstMaintA = lma;
	
}

void PHash::update(int ID, string mk, string md, string lm, string lma)
{
	int index = hash(ID);
	
	if(HashTable[index]->make == " ")
	{
		cout << "Error in plane table: index is empty." << endl;
		
		return;
	}
	
	HashTable[index]->id = ID;
	HashTable[index]->make = mk;
	HashTable[index]->model = md;
	HashTable[index]->lastMaint = lm;
	HashTable[index]->lAstMaintA = lma;
	
}

void PHash::select(string Date)
{
	int j = -1;
	int a[23];
	
	for(int i = 0; i < size; i++)
	{
		if(HashTable[i]->lastMaint == Date)
		{
			j++;
			
			a[j] = HashTable[i]->id;
		}
	}
	
	if(j > -1)
	{
		cout << "Select: Plane id(s): ";
		
		for(int i = 0; i <= j; i++)
		{
			cout << a[i] << ", ";
		}

		cout << "last maintained on " << Date << endl << endl;
	}
}

