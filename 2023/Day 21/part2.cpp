#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

int rows = 0, cols = 0;
int startI, startJ;

ifstream inputFile("dummyinput.txt");
ofstream out("output.txt");
int maxSteps = 50;
long long int result = 0;

struct Tile{
    char c;
    int d = maxSteps + 1;
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

void explore(int i, int j, int steps){

    if(outOfBounds(i,j)){
        if(i == rows)
            i = 0;
        if(j == cols)
            j = 0;
        if(i < 0)
            i = rows - 1;
        if(j < 0)
            j = cols - 1;
    }

    if(steps > maxSteps || garden[i][j].c == '#'){
        return;
    }

    if(garden[i][j].visited){
        if(garden[i][j].d > steps){
            garden[i][j].d = steps;
        }
        else
            return;
    }

    garden[i][j].d = steps;
    if(steps % 2 == 0)
        result++;

    garden[i][j].visited = true;

    explore(i + 1, j, steps+1);
    explore(i - 1, j, steps+1);
    explore(i, j + 1, steps+1);
    explore(i, j - 1, steps+1);

    
}

void calculateDistance(){
    explore(startI, startJ, 0);
}

int main(){

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
    
    out << "Result: " << result << endl;
    inputFile.close();
    return 0;
}