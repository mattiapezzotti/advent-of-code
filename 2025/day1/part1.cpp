#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

ifstream in;
ofstream out;
long long int result = 0;

int main(){
    //clock_t tStart = clock();

    ifstream in;
    in.open ("input.txt");
    out.open("output.txt");
    string line;
    char direction;
    int rotation;
    int dial = 50;

    while (getline(in, line)) {
        direction = line[0];
        rotation = stoi(line.substr(1));
        
        if (direction == 'R')
            dial += rotation;
        else
            dial -= rotation;

        dial %= 100;
        
        if (dial == 0)
            result++;
    }
    
    out << "Result: " << result << endl;
    // out << "Time taken: " <<  (double)(clock() - tStart)/CLOCKS_PER_SEC << "s";
    
    in.close();
    out.close();

    return 0;
}