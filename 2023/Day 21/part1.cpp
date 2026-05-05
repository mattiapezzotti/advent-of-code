#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

int rows = 0, cols = 0;
int startI, startJ;

ifstream inputFile("input.txt");
ofstream out("output.txt");
int maxSteps = 64;


struct Tile{
    char c;
    int d = maxSteps + 1;
    bool walkable;
    bool visited = false;
}garden[MAXN][MAXN];

bool outOfBounds(int i, int j){
    return (i == rows || j == cols || i < 0 || j < 0);
}


void printGarden() {
    out << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            out << garden[i][j].c;
        }
        out << endl;
    }      
}

void printGardenDistance() {
    out << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            out << garden[i][j].d << " ";
        }
        out << endl;
    }      
}

void printGardenWalkable() {
    out << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(garden[i][j].walkable)
                out << 'O';
            else out << garden[i][j].c;
        }
        out << endl;
    }      
}

void explore(int i, int j, int steps){
    if(outOfBounds(i,j) || steps > maxSteps || garden[i][j].c == '#'){
        return;
    }

    if(garden[i][j].visited){
        if(garden[i][j].d > steps)
            garden[i][j].d = steps;
        else
            return;
    }

    garden[i][j].d = steps;
    garden[i][j].visited = true;

    explore(i + 1, j, steps+1);
    explore(i - 1, j, steps+1);
    explore(i, j + 1, steps+1);
    explore(i, j - 1, steps+1);

    
}

void calculateDistance(){
    explore(startI, startJ, 0);
}

void calculateWalkable(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(garden[i][j].d <= maxSteps && garden[i][j].d % 2 == 0){
                garden[i][j].walkable = true;
            }
        }
    }
}

int main(){
    long long int result = 0;
    string line;

    for ( ; getline(inputFile, line); rows++) {
        for(int j = 0; j < line.length(); j++){
            garden[rows][j].c = line[j];
            if(garden[rows][j].c == 'S'){
                startI = rows;
                startJ = j;
            }
        }
        
        cols = line.length();
    }

    calculateDistance();
    calculateWalkable();

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(garden[i][j].walkable){
                result++;
            }
        }
    }
    
    out << "Result: " << result << endl;
    inputFile.close();
    return 0;
}