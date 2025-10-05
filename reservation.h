#ifndef reservation_H
#define reservation_H

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

class reservationNode
{
private:
	string passID;
	string FLNO;
	string FDate;
	string FromA;
	string ToA;
	string seatClass;
	string bookedDate;
	string cancelledDate;
public:
	reservationNode();
	reservationNode(const string& input);
	void setPassID(string id);
	void setFLNO(string flno);
	void setFDate(string date);
	void setFromA(string from);
	void setToA(string to);
	void setSeatClass(string seat);
	void setBooked(string booked);
	void setCancelled(string cancelled);
	string getID();
	string getFLNO();
	string getFDate();
	string getFromA();
	string getToA();
	string getSeatClass();
	string getBooked();
	string getCancelled();
	void print();
};

class reservationHash {
	int buckets; //number of buckets
	list<int> *table; //pointer to an array of buckets
public:
	reservationHash(int numBuckets); //constructor
	void insert(vector<reservationNode> data); //inserts x into hash table
	//int search(int key); //returns the location of x
	//void remove(int key); //removes x from hash table
	void output(vector<reservationNode> data); //displays all elements in the hash table
	int hashingFunction(int x) { //returns the 'key' value used by the hash table
		return (x % buckets);
	}
};

#endif