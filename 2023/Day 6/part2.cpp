#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

long long int result = 1;
long long int raceWin = 0;

long long int raceTime;
long long int raceRecord;
long long int maxDistance[MAXN];
long long int travelTime;

long long int number;

int main(){
    ifstream inputFile;
    string line;
    inputFile.open ("input.txt");

    getline(inputFile, line);
    line = line.substr(line.find(":") + 1, line.length());
    line.erase(remove(line.begin(), line.end(), ' '), line.end());
    raceTime = stoll(line); 

    getline(inputFile, line);
    line = line.substr(line.find(":") + 1, line.length());
    line.erase(remove(line.begin(), line.end(), ' '), line.end());
    raceRecord = stoll(line);

    raceWin = 0;
    int i = 0;
    for(i = 0; i <= raceTime; i++){
        travelTime = raceTime - i;
        if(travelTime * i > raceRecord){
            break;
        }
    }

    result = raceTime - (i * 2) + 1;
    
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}