#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

#define MAXN 1001

ifstream inputFile;
string line;
long long int result = 42;

long long int myGamma;
long long int myEpsilon;

vector<int> mostCommon;
vector<int> leastCommon;

vector<string> linesCO2;
vector<string> linesOxygen;

int count[MAXN];


long long int convert(vector<int> vec){
    int num;
    int decimal;
    int length = vec.size();

    for(int i=0; i<length; i++){
        decimal += vec.at(vec.size() - 1) * pow(2,i);
        vec.pop_back();
    }

    return decimal;
}

void countBinary(vector<string> &lines, int col){
    for(auto x: lines)
        count[x[col] - '0']++;
}

void updateLines(vector<string> &lines, char winner, int col){
    for(int i=0; i<lines.size(); i++){
        if(lines.at(i)[col] != winner){
            lines.erase(lines.begin() + i);
            i--;
        }
    }
}

int main(){
    inputFile.open ("input.txt");
    
    if (inputFile.is_open()) {
        while(getline(inputFile,line)){
            linesOxygen.push_back(line);
            linesCO2.push_back(line);
        }
        
        for(int currentColumn = 0; currentColumn < line.length() && linesCO2.size() != 1; currentColumn++){
            count[0] = 0;
            count[1] = 0;

            countBinary(linesCO2, currentColumn);

            if(count[0] <= count[1])
                updateLines(linesCO2, '0', currentColumn);

            if(count[0] > count[1])
                updateLines(linesCO2, '1', currentColumn);
        }

        for(int currentColumn = 0; currentColumn < line.length() && linesOxygen.size() != 1; currentColumn++){
            count[0] = 0;
            count[1] = 0;     

            countBinary(linesOxygen, currentColumn);

            if(count[0] > count[1])
                updateLines(linesOxygen, '0', currentColumn);

            if(count[0] <= count[1])
                updateLines(linesOxygen, '1', currentColumn);
        }
    

        string co2 = linesCO2.at(0);
        string oxygen = linesOxygen.at(0);

        cout << co2 << " " << oxygen << endl;

        for(int i=0; i<co2.length(); i++){
            mostCommon.push_back(oxygen[i] - '0');
            leastCommon.push_back(co2[i] - '0');
        }

        myGamma = convert(mostCommon);
        myEpsilon = convert(leastCommon);
    }
        
    result = myGamma * myEpsilon;

    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}