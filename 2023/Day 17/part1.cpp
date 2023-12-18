#include <bits/stdc++.h>

using namespace std;

#define MAXN 999

int rows = 0;
int cols = 0;
int maxMoves = 3;
ofstream outputFile("output.txt");

int grid[MAXN][MAXN];
bool alreadySeen[MAXN][MAXN][5][5];

struct Node{
    
}

void printGrid() {
    outputFile << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            outputFile << grid[i][j];
        }
        outputFile << endl;
    }      
}

bool outOfBounds(int x, int y){
    return (x == cols || y == rows || y < 0 || x < 0);
}

int heatLoss(int y, int x, int movesLeft, string dir){

}

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("dummyinput.txt");
    string line;
    int num;

    while (getline(inputFile, line)) {
        cols = line.length();
        for(int j = 0; j < cols; j++){
            num = line[j] - '0';
            grid[rows][j] = num;
        }
        rows++;
    }

    result = heatLoss(0, 0, maxMoves, "E", 0);
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}