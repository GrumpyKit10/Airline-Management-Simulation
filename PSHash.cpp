/*
Name:	Matthew Wilson
Course:	CSCE 2110.002
Date:	11/15/21

This header file defines the member functions of the PlaneSeats hash table
*/

#include "PShash.h"

PSHash::PSHash(string file)
{		
	for(int i = 0; i < size; i++)
	{
		HashTable[i] = new node;
	}
	
	ifstream fin(file);
	
	string line, word, Make, Model, Type;
	int Seats = 0, i = 0;

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
		
		ss >> Make >> Model >> Type >> Seats;
		
		i = hash(Make);
		
		if(HashTable[i]->make == " ")
		{
			HashTable[i]->make = Make;
			HashTable[i]->model = Model;
			HashTable[i]->seattype = Type;
			HashTable[i]->seats = Seats;
		}
		
		else//handling collision by chaining
		{
			node *ptr = HashTable[i];
			
			node *temp = new node;
			
			temp->make = Make;
			temp->model = Model;
			temp->seattype = Type;
			temp->seats = Seats;
			
			while(ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			
			ptr->next = temp;
		}
	}
	
	fin.close();
}

int PSHash::hash(string key)
{
	int hash = 0;
	int index;
	
	for(unsigned int i = 0; i < key.length(); i++)
	{
		hash = hash + (int)key[i];
	}
	
	index = hash % size;//modulo hashing
	
	return index;
}

void PSHash::display()
{
	node* ptr = NULL;
	
	cout << "Maker\t" << "Model\t" << "Seat Type\t" << "Number of Seats" << endl;

	for(int i = 0; i < size; i++)
	{
		ptr = HashTable[i];
		
		if(ptr->make != " ")
		{			
			cout << ptr->make << "\t" << ptr->model << "\t\t";
			cout << ptr->seattype << "\t\t" << ptr->seats;
			cout << endl;
			
			while(ptr->next != NULL)
			{
				ptr = ptr->next;
				
				cout << ptr->make << "\t" << ptr->model << "\t\t";
				cout << ptr->seattype << "\t\t" << ptr->seats;
				
				cout << endl;
			}
		}
	}
	
	cout << endl;
}

void PSHash::insert(string mk, string md, string st, int s)
{
	int index = hash(st);
		
	if(HashTable[index]->seats != -999)
	{
		cout << "Error in plane seats table: need unique key from seats." << endl;
		
		return;
	}
	
	HashTable[index]->make = mk;
	HashTable[index]->model = md;
	HashTable[index]->seattype = st;
	HashTable[index]->seats = s;
}
		
void PSHash::update(string mk, string md, string st, int s)
{
	int index = hash(st);
	
	node* ptr = HashTable[index];
	
	if(ptr->make == " ")
	{
		cout << "Error in plane table: index is empty." << endl;
		
		return;
	}
	
	while(ptr->seats != s || ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	
	if(ptr->seats == s)
	{
		ptr->make = mk;
		ptr->model = md;
		ptr->seattype = st;
		ptr->seats = s;
	}
}

void PSHash::select(int s)
{
	int j = -1;
	int a[23];
	
	for(int i = 0; i < size; i++)
	{
		if(HashTable[i]-> seats == s)
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

		cout << "have " << s << " seats" << endl << endl;
	}
}

