#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

ifstream in;
ofstream out;
long long int result = 0;

long long int split(int step, long long int n, long long int currentResult);
long long int blink(long long int stone, int step, long long int currentResult);
map<pair<long long int,int>, long long int> alreadySeen;

int digits(long long int n){
    return to_string(n).length();
}

int main(){
    clock_t tStart = clock();

    ifstream in;
    in.open ("input.txt");
    out.open("output.txt");
    string line;

    while (getline(in, line)) {
        stringstream ss(line);
        string number;
        long long int currentResult = 0;

        while(getline(ss, number, ' ')){
            result += blink(stoll(number), 75, currentResult);
            currentResult = 0;
        }
    }
    
    out << "Result: " << result << endl;
    out << "Time taken: " <<  (double)(clock() - tStart)/CLOCKS_PER_SEC << "s";
    
    in.close();
    out.close();

    return 0;
}

long long int split(int step, long long int n, long long int currentResult){
    string sn = to_string(n);
    long long int n1 = stoll(sn.substr(0, sn.length() / 2));
    long long int n2 = stoll(sn.substr(sn.length() / 2));

    return blink(n1, step - 1, currentResult) + blink(n2, step - 1, currentResult);
}

long long int blink(long long int stone, int step, long long int currentResult){
    pair<long long int,int> currentStone = make_pair(stone, step);

    if(alreadySeen.count(currentStone)){
        currentResult += alreadySeen[currentStone];
        return currentResult;
    }

    if (step == 0){
        return 1;
    }

    if(stone == 0)
        currentResult += blink(1, step - 1, currentResult);
        
    else{
        if(digits(stone) % 2 == 0)
            currentResult += split(step, stone, currentResult);
        else
            currentResult += blink(stone * 2024, step - 1, currentResult);
    }

    alreadySeen[currentStone] = currentResult;
    return currentResult;
}