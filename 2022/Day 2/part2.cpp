#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

// 1 for Rock, 2 for Paper, and 3 for Scissors
// A for Rock, B for Paper, and C for Scissors
// X lose, Y draw, and Z win

int points[MAXN];
char translate[MAXN];

void initMove(){
    points['A'] = 1;
    points['B'] = 2;
    points['C'] = 3;
}

pair<char,int> game(char p1, char p2){
    if(p2 == 'Y'){
        return make_pair(p1, 3);
    }

    // ROCK
    if(p1 == 'A' && p2 == 'X'){
        return make_pair('C', 0);
    }

    if(p1 == 'A' && p2 == 'Z'){
        return make_pair('B', 6);
    }

    // PAPER
    if(p1 == 'B' && p2 == 'X'){
        return make_pair('A', 0);
    }

    if(p1 == 'B' && p2 == 'Z'){
        return make_pair('C', 6);
    }

    // SCISSOR
    if(p1 == 'C' && p2 == 'X'){
        return make_pair('B', 0);
    }

    if(p1 == 'C' && p2 == 'Z'){
        return make_pair('A', 6);
    }
}

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;
    char p1;
    char p2;
    pair<char,int> gameResult;

    initMove();

    while (getline(inputFile, line)) {
        char p1 = line[0];
        char p2 = line[2];
        
        gameResult = game(p1, p2);

        result += gameResult.second + points[gameResult.first];
    }

    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}