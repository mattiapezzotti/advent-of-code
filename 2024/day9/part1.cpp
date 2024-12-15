#include <bits/stdc++.h>

using namespace std;

#define MAXN 99999

ifstream in;
ofstream out;
long long int result = 0;

vector<int> newLine;

int currentId = 0;
int currentNumber;
int spaces = false;
int nextPoint;

int main(){
    //clock_t tStart = clock();

    ifstream in;
    in.open ("input.txt");
    out.open("output.txt");
    string line;
    

    while (getline(in, line)) {
        for(int i = 0; i < line.length(); i++){
            currentNumber = line[i] - '0';
            if(!spaces){
                for(int j = 0; j < currentNumber; j++)
                    newLine.push_back(currentId);
                currentId++;
            }
            else{
                for(int i = 0; i < currentNumber; i++)
                    newLine.push_back(-1);
            }
            spaces = !spaces;
        }
    }

    int i = newLine.size() - 1;
    int nextPoint = (find(newLine.begin(), newLine.end(), -1) - newLine.begin());

    for(; nextPoint < newLine.size(); nextPoint = (find(newLine.begin(), newLine.end(), -1) - newLine.begin())){
        while(newLine.at(i) == -1){
            newLine.at(i) = -2;
            i--;
        }

        newLine.at(nextPoint) = newLine.at(i);
        newLine.at(i) = -2;
        i--;
    }

    newLine.resize(i + 1);

    for(int i = 0; i < newLine.size(); i++){
        result += (newLine[i] * i);
    }

    out << "Result: " << result << endl;
    // out << "Time taken: " <<  (double)(clock() - tStart)/CLOCKS_PER_SEC << "s";
    
    in.close();
    out.close();

    return 0;
}