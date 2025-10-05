#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


// One function works for all data types.  This would work
// even for user defined types if operator '>' is overloaded
template <typename T>
T myMax(T x, T y)
{
   return (x > y)? x: y;
}
 
void generic_comparison()
{
  cout << endl << "-------------------------------------------- " <<endl;
  cout << "generic_comparison results : " <<endl;
  cout << myMax<int>(3, 7) << endl;  // Call myMax for int
  cout << myMax<double>(3.0, 10.0) << endl; // call myMax for double
  cout << myMax<char>('g', 'e') << endl;   // call myMax for char
}


void read_csv(){
    ifstream input_from_file("data.csv");

    cout << endl << "-------------------------------------------- " <<endl;
    string line;
    vector < vector <string >> data ;
    while (getline(input_from_file, line)) {

        line += ",";

        stringstream ss(line);

        string word;

        vector<string> words;

        while (getline(ss, word, ',')){

            words.push_back(word);
	    cout  << word << "  ";
	}

        cout <<  " --> number of cols : " << words.size() << endl;
	for (auto c: words)
    		std::cout << c << ' ';
    }
}
int main() {

    read_csv();
    generic_comparison() ;
    return 0;
}