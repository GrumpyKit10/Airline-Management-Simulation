#include "passenger.h"

passengerNode::passengerNode()
{
	ID = "";
	name = "";
	phone = "";
}

passengerNode::passengerNode(const string& input)
{
	char * cstr = new char [input.length()+1];
  	strcpy (cstr, input.c_str());

  // cstr now contains a c-string copy of str

 	char cID[32], cName[32], cPhone[32];

    ID = strcpy(cID, strtok(cstr , ","));
    name = strcpy(cName, strtok(NULL, ","));
    phone = strcpy(cPhone , strtok(NULL, ","));
}

void passengerNode::setID(string id) 
{
	ID = id;
}

void passengerNode::setName(string passName) 
{
	name = passName;
}

void passengerNode::setPhone(string passPhone) 
{
	phone = passPhone;
}

string passengerNode::getID() 
{
	return ID;
}

string passengerNode::getName() 
{
	return name;
}

string passengerNode::getPhone() 
{
	return phone;
}

void passengerNode::print() 
{
	cout << ID  << "     " << name << "   " << phone << endl;
}


passengerHash::passengerHash(int bucket) {
	this->buckets = bucket;
	table = new list<int>[buckets];
}

void passengerHash::insert(vector<passengerNode> data) {
	for(int i = 1; i < data.size(); i++){
		int key = std::stoi(data[i].getID());
		int index = hashingFunction(key);
		table[index].push_back(key);
	}
}

void passengerHash::output(vector<passengerNode> data) {
	cout << "ID\t" << "Name\t" << "Phone" << endl;
	for(int i = 0; i < buckets; i++) {
		for(auto x : table[i]) {
			data[i].print();
		}
		cout << endl;
	}
}