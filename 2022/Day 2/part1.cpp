#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

// 1 for Rock, 2 for Paper, and 3 for Scissors
// A for Rock, B for Paper, and C for Scissors
// X for Rock, Y for Paper, and Z for Scissors

int points[MAXN];
char translate[MAXN];

void initMove(){
    points['A'] = 1;
    points['B'] = 2;
    points['C'] = 3;
    translate['X'] = 'A';
    translate['Y'] = 'B';
    translate['Z'] = 'C';
}

int game(char p2, char p1){
    if(p1 == p2){
        return 3;
    }

    // ROCK
    if(p1 == 'A' && p2 == 'B'){
        return 0;
    }

    if(p1 == 'A' && p2 == 'C'){
        return 6;
    }

    // PAPER
    if(p1 == 'B' && p2 == 'A'){
        return 6;
    }

    if(p1 == 'B' && p2 == 'C'){
        return 0;
    }

    // SCISSOR
    if(p1 == 'C' && p2 == 'A'){
        return 0;
    }

    if(p1 == 'C' && p2 == 'B'){
        return 6 ;
    }
}

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;
    char p1;
    char p2;

    initMove();

    while (getline(inputFile, line)) {
        char p1 = line[0];
        char p2 = line[2];
        
        result += game(p1, translate[p2]) + points[translate[p2]];
    }

    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}