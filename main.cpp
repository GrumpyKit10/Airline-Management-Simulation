#include "PTHash.h"
#include "PSHash.h"
#include "PHash.h"
//#include "passenger.h"

//vector<passengerNode> read(string infile);

int main()
{
	PHash plane1("DATA_Plane.CSV");
	
	plane1.display();
	
	plane1.insert(10, "MD", "MD11", "1/1/2001", "LOG");
	
	plane1.display();
	
	plane1.update(10, "DM", "MD11", "1/1/2001", "LOG");
	
	plane1.display();
	
	plane1.select("9/1/2002");
	
	PSHash plane("DATA_PlaneSeats.CSV");
	
	plane.display();
	
	plane.insert("MD", "MD11", "F", 140);
	
	plane.display();
	
	plane.update("DM", "MD11", "F", 140);
	
	plane.display();
	
	plane.select(20);
	
	PTHash plane2("Data_PlaneType.CSV");
	
	plane2.display();
	
	plane2.insert("MD", "MD12", 650, 185);
	
	plane2.display();
	
	plane2.update("DM", "MD12", 700, 200);
	
	plane2.display();
	
	plane2.select(650);
	
	return 0;
}

/*vector <passengerNode> read(string inFile){
	int counter = 0;
	
    ifstream input_from_file(inFile);

    cout << endl << "-------------------------------------------- " << endl;
    string line;
	vector <passengerNode> data ;
    
    while (getline(input_from_file, line)) {

        line += ",";

        stringstream ss(line);

        string word;

        while (getline(ss, word)){
			passengerNode *passenger = new passengerNode(word);

        	data.push_back(word);
		}
	}
	return data;
}*/