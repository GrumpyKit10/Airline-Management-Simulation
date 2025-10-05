#include "reservation.h"

reservationNode::reservationNode()
{
	passID = "";
	FLNO = "";
	FDate = "";
	FromA = "";
	ToA = "";
	seatClass = "";
	bookedDate = "";
	cancelledDate = "";
}

reservationNode::reservationNode(const string& input)
{
	char * cstr = new char [input.length()+1];
  	strcpy (cstr, input.c_str());

  // cstr now contains a c-string copy of str

 	char cID[32], cFLNO[32], cFDate[32], cFromA[32], cToA[32], cSeat[32], cBooked[32], cCancelled[32];

    passID = strcpy(cID, strtok(cstr , ","));
    FLNO = strcpy(cFLNO, strtok(NULL, ","));
    FDate = strcpy(cFDate , strtok(NULL, ","));
	FromA = strcpy(cFromA , strtok(NULL, ","));
	ToA = strcpy(cToA , strtok(NULL, ","));
	seatClass = strcpy(cSeat , strtok(NULL, ","));
	bookedDate = strcpy(cBooked , strtok(NULL, ","));
	cancelledDate = strcpy(cCancelled , strtok(NULL, ","));
}

void reservationNode::setPassID(string id) 
{
	passID = id;
}

void reservationNode::setFLNO(string flno) 
{
	FLNO = flno;
}

void reservationNode::setFDate(string date) 
{
	FDate = date;
}

void reservationNode::setFromA(string from) 
{
	FromA = from;
}

void reservationNode::setToA(string to) 
{
	ToA = to;
}

void reservationNode::setSeatClass(string seat) 
{
	seatClass = seat;
}

void reservationNode::setBooked(string booked) 
{
	bookedDate = booked;
}

void reservationNode::setCancelled(string cancelled) 
{
	cancelledDate = cancelled;
}

string reservationNode::getID() 
{
	return passID;
}

string reservationNode::getFLNO() 
{
	return FLNO;
}

string reservationNode::getFDate() 
{
	return FDate;
}

string reservationNode::getFromA() 
{
	return FromA;
}

string reservationNode::getToA() 
{
	return ToA;
}

string reservationNode::getSeatClass() 
{
	return seatClass;
}

string reservationNode::getBooked() 
{
	return bookedDate;
}

string reservationNode::getCancelled() 
{
	return cancelledDate;
}

void reservationNode::print() 
{
	cout << passID  << "     " << FLNO << "   " << FDate << FromA << ToA << seatClass << bookedDate << cancelledDate << endl;
}


reservationHash::reservationHash(int bucket) {
	this->buckets = bucket;
	table = new list<int>[buckets];
}

void reservationHash::insert(vector<reservationNode> data) {
	for(int i = 1; i < data.size(); i++){
		int key = std::stoi(data[i].getID());
		int index = hashingFunction(key);
		table[index].push_back(key);
	}
}

void reservationHash::output(vector<reservationNode> data) {
	cout << "ID\t" << "FLNO\t" << "FDate\t" << "FromA\t" << "ToA\t" << "Seat Class\t" << "Booked Date\t" << "Cancelled Date" << endl;
	for(int i = 0; i < buckets; i++) {
		for(auto x : table[i]) {
			data[i].print();
		}
		cout << endl;
	}
}