#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;

    if (inputFile.is_open()){
        int pastLine;
        int currentLine;

        getline(inputFile,line);
        pastLine = stoi(line);

        while (getline(inputFile,line)) {
            currentLine = stoi(line);
            if (currentLine > pastLine)
                result++;
            pastLine = currentLine;
        }
    }

    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}