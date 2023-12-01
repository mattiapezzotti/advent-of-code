#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;
    int number;
    int sums[3] = {0,0,0};

    if (inputFile.is_open()){
        getline(inputFile,line);
        number = stoi(line);
        sums[0] += number;

        getline(inputFile,line);
        number = stoi(line);
        sums[0] += number;
        sums[1] += number;

        getline(inputFile,line);
        number = stoi(line);
        sums[0] += number;
        sums[1] += number;
        sums[2] += number;

        while(getline(inputFile,line)){
            number = stoi(line);
            sums[1] += number;

            if(sums[1] > sums[0])
                result++;
            
            sums[0] = sums[1];
            sums[1] = sums[2];
            sums[2] = 0;

            sums[1] += number;
            sums[2] += number;
        }
    }

    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}