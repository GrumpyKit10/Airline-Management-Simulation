#include "passenger.h"

vector<passengerNode> read(string infile);


int main() {
	string inFile;

	cout << "input file name: ";
	cin >> inFile;

    vector<passengerNode> data = read(inFile);

    passengerHash passengerTable(23);
	passengerTable.insert(data);
	passengerTable.output(data);

    return 0;
}


vector <passengerNode> read(string inFile){
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
}