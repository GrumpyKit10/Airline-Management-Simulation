#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
/*
 * It will iterate through all the lines in file and
 * call the given callback on each line.
 */
bool iterateFile(std::string fileName, std::function<void (const std::string & )> callback)
{
    // Open the File
    std::ifstream in(fileName.c_str());

    // Check if object is valid
    if(!in)
    {
        std::cerr << "Cannot open the File : "<<fileName<<std::endl;
        return false;
    }
    std::string str;

    // Read the next line from File untill it reaches the end.
    while (std::getline(in, str))
    {
        // Call the given callback
        callback(str);
    }
    //Close The File
    in.close();

    return true;
}
int main()
{
    std::vector<std::string> vecOfStr;

    //Call given lambda function for each line in file
    bool res = iterateFile("example.csv", [&](const std::string & str){
                                                // Add to vector
                                                vecOfStr.push_back(str);
                                            });
    if(res)
    {
        for(std::string & line : vecOfStr)
            std::cout<<line<<std::endl;
    }
}