#ifndef PASSENGER_H
#define PASSENGER_H

#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstring>
#include <list>
using namespace std;

//Hashing function: Modulo
//Collision strategy: Chaining

class passengerNode
{
private:
	string ID;
	string name;
	string phone;
public:
	passengerNode();
	passengerNode(const string& input);
	void setID(string id);
	void setName(string passName);
	void setPhone(string passPhone);
	string getID();
	string getName();
	string getPhone();
	void print();
};

class passengerHash {
	int buckets; //number of buckets
	list<int> *table; //pointer to an array of buckets
public:
	passengerHash(int numBuckets); //constructor
	void insert(vector<passengerNode> data); //inserts x into hash table
	//int search(int key); //returns the location of x
	//void remove(int key); //removes x from hash table
	void output(vector<passengerNode> data); //displays all elements in the hash table
	int hashingFunction(int x) { //returns the 'key' value used by the hash table
		return (x % buckets);
	}
};

#endif