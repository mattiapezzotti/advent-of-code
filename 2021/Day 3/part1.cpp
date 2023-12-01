#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

#define MAXN 1001

long long int count[MAXN][MAXN];

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

int main(){
    int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;

    int gamma = 0;
    int epsilon = 0;

    vector<int> mostCommon;
    vector<int> leastCommon;

    int binary;
    int number;
    int length;

    if (inputFile.is_open()) {

        while(getline(inputFile,line)){
            length = line.length();

            for(int i=0; i < length; i++){
                number = stoi(line.substr(0,1));
                count[i][number]++;
                line = line.substr(1,line.length()-1);
            }
        }

        for(int i = 0; i < length; i++){
            if(count[i][0] > count[i][1]){
                mostCommon.push_back(0);
                leastCommon.push_back(1);
            }

            else{
                mostCommon.push_back(1);
                leastCommon.push_back(0);
            }
        }

        gamma = convert(mostCommon);
        epsilon = convert(leastCommon);

    }
            

    result = gamma * epsilon;
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}