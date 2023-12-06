#include <bits/stdc++.h>

using namespace std;

#define MAXN 100

long long int result = 1;
long long int raceWin = 0;

vector<int> raceTime;
vector <int> raceRecord;
int maxDistance[MAXN];

int number;

void populateDistance(int maxTime){
    int travelTime;
    for(int i = 0; i <= maxTime; i++){
        travelTime = maxTime - i;
        maxDistance[i] = travelTime * i;
    }
}

void getRaceTime(string string){
    stringstream iss(string);
    while ( iss >> number ){
        raceTime.push_back( number );
    }
}

void getRaceRecord(string string){
    stringstream iss(string);
    while ( iss >> number ){
        raceRecord.push_back( number );
    }
}

int main(){
    ifstream inputFile;
    string line;
    inputFile.open ("dummyinput.txt");

    getline(inputFile, line);
    line = line.substr(line.find(":") + 1, line.length());
    getRaceTime(line);

    getline(inputFile, line);
    line = line.substr(line.find(":") + 1, line.length());
    getRaceRecord(line);

    for(int i = 0; i<raceRecord.size(); i++){
        raceWin = 0;
        populateDistance(raceTime[i]);
        for(int j = 0; j < raceTime[i]; j++){
            if(raceRecord[i] < maxDistance[j])
                raceWin++;
        }
        if(raceWin > 0)
            result *= raceWin;
    }
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}