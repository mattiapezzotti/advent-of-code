#include <bits/stdc++.h>

using namespace std;

#define MAXN 999

struct Cell{
    char c;
    bool visited = false;
};

Cell grid[MAXN][MAXN];

bool alreadySeen[MAXN][MAXN][MAXN];

int rows = 0;
int cols = 0;
ofstream outputFile("output.txt");

void printGrid() {
    outputFile << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            outputFile << grid[i][j].c;
        }
        outputFile << endl;
    }      
}

bool outOfBounds(int x, int y){
    return (x == cols || y == rows || y < 0 || x < 0);
}

void printVisitedGrid() {
    outputFile << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(grid[i][j].visited)
                outputFile << "#";
            else
                outputFile << grid[i][j].c;
        }
        outputFile << endl;
    }      
}

void energize(int y, int x, string dir){
    //printVisitedGrid();

    int dirN;
    if(dir == "up")
        dirN = 0;
    if(dir == "down")
        dirN = 1;
    if(dir == "right")
        dirN = 2;
    if(dir == "left")
        dirN = 3;

    //cout << x << " " << y << " " << dir << " " << alreadySeen[y][x][dirN] << endl;

    if(outOfBounds(x,y) || alreadySeen[y][x][dirN]){
        return;
    }

    grid[y][x].visited = true;
    alreadySeen[y][x][dirN] = true;

    if(grid[y][x].c == '/'){
        if(dir == "right")
            energize(y - 1 , x, "up");
        if(dir == "left")
            energize(y + 1 , x, "down");
        if(dir == "up")
            energize(y , x + 1, "right");
        if(dir == "down")
            energize(y , x - 1, "left");
    }

    if(grid[y][x].c == '\\'){
        if(dir == "right")
            energize(y + 1 , x, "down");
        if(dir == "left")
            energize(y - 1 , x, "up");
        if(dir == "up")
            energize(y , x - 1, "left");
        if(dir == "down")
            energize(y , x + 1, "right");
    }

    if(grid[y][x].c == '|'){
        if(dir == "right" || dir == "left"){
            energize(y + 1 , x, "down");
            energize(y - 1 , x, "up");
        }
        if(dir == "up")
            energize(y - 1 , x, "up");
        if(dir == "down")
            energize(y + 1 , x, "down");
    }

    if(grid[y][x].c == '-'){
        if(dir == "up" || dir == "down"){
            energize(y , x + 1, "right");
            energize(y , x - 1, "left");
        }
        if(dir == "right")
            energize(y , x + 1, "right");
        if(dir == "left")
            energize(y, x - 1, "left");
    }
    
    if(grid[y][x].c == '.'){

        while(grid[y][x].c == '.' && !outOfBounds(x,y)){
            grid[y][x].visited = true;
            alreadySeen[y][x][dirN] = true;
            if(dir == "up")
                y--;
            if(dir == "down")
                y++;
            if(dir == "right")
                x++;
            if(dir == "left")
                x--;
        }

        energize(y , x, dir);
    }
}

void resetGrid(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            for(int d = 0; d < 4; d++)
                alreadySeen[i][j][d] = false;
            grid[i][j].visited = false;
        }
    }
}

int checkEnergy(){
    int energy = 0;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if(grid[i][j].visited)
                energy++;
    return energy;
}

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;

    while (getline(inputFile, line)) {
        cols = line.length();
        for(int j = 0; j < cols; j++){
            grid[rows][j].c = line[j];
        }
        rows++;
    }

    int maxEnergy = 0;

    for(int x = 0; x < cols; x++){
        energize(0, x, "down");
        maxEnergy = max(maxEnergy, checkEnergy());
        resetGrid();
        
    }

    for(int y = 0; y < rows; y++){
        energize(y, 0, "right");
        maxEnergy = max(maxEnergy, checkEnergy());
        resetGrid();
    }

    for(int x = 0; x < cols; x++){
        energize(rows - 1, x, "up");
        maxEnergy = max(maxEnergy, checkEnergy());
        resetGrid();
    }

    for(int y = 0; y < rows; y++){
        energize(y, cols - 1, "left");
        maxEnergy = max(maxEnergy, checkEnergy());
        resetGrid();
    }

    result = maxEnergy;
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}