#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;

    int depth = 0;
    int foward = 0;

    if (inputFile.is_open()){
        while(getline(inputFile, line))
            if(line.find("up") == 0)
                depth -= stoi(line.substr(line.length()-1,line.length()));
            else if(line.find("down") == 0)
                depth += stoi(line.substr(line.length()-1,line.length()));
                else foward += stoi(line.substr(line.length()-1,line.length()));
    }
    result = foward * depth;
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}