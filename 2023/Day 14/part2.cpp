#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define MAXN 9999

vector<string> grid;
vector<vector<string>> grids;

ifstream inputFile("input.txt");
ofstream outputFile("output.txt");

void printGrid(const vector<string>& g) {
    outputFile << endl;
    for(auto l : g)
        outputFile << l << endl;
}

void pushNord(vector<string>& grid, int rows, int cols, int i, int j){
    if(i == 0)
        return;

    int r = 1;
    while(i - r >= 0 && grid[i - r][j] != 'O' && grid[i - r][j] != '#')
        r++;
    
    swap(grid[i - r + 1][j], grid[i][j]);
}

void pushWest(vector<string>& grid, int rows, int cols, int i, int j){
    if(j == 0)
        return;

    int r = 1;
    while(j - r >= 0 && grid[i][j - r] != 'O' && grid[i][j - r] != '#')
        r++;
    
    swap(grid[i][j - r + 1], grid[i][j]);
}

void pushSud(vector<string>& grid, int rows, int cols, int i, int j){
    if(i == rows - 1)
        return;

    int r = 1;
    while(i + r <= rows - 1 && grid[i + r][j] != 'O' && grid[i + r][j] != '#')
        r++;
    
    swap(grid[i + r - 1][j], grid[i][j]);
}

void pushEst(vector<string>& grid, int rows, int cols, int i, int j){
    if(j == cols - 1)
        return;

    int r = 1;
    while(j + r <= cols - 1 && grid[i][j + r] != 'O' && grid[i][j + r] != '#')
        r++;
    
    swap(grid[i][j + r - 1], grid[i][j]);
}

void rotateGrid(vector<string>& grid, int rows, int cols, char direction){
    if(direction == 'N' || direction == 'W')
        for(int j = 0; j < cols; j++){
            for(int i = 0; i < rows; i++){
                if(grid[i][j] == 'O'){
                    switch(direction){
                        case 'N':    
                            pushNord(grid, rows, cols, i, j);
                            break;
                        case 'W':    
                            pushWest(grid, rows, cols, i, j);
                            break;
                    }
                
                }
            }     
        }
    else
        for(int j = cols - 1; j >= 0; j--){
            for(int i = rows - 1; i >= 0; i--){
                if(grid[i][j] == 'O'){
                    switch(direction){
                        case 'S':    
                            pushSud(grid, rows, cols, i , j);
                            break;
                        case 'E':    
                            pushEst(grid, rows, cols, i, j);
                            break;

                    }
                
                }
            }     
        }
}

int checkCycle(vector<string>& grid){
    if(grid.empty())
        return -1;

    for(int i = 0; i < grids.size(); i++)
        if(grids[i] == grid)
            return i;

    return -1;
}

int main() {
    long long int result = 0;

    string line;
    int rows = 0;
    int cols = 0;

    while (getline(inputFile, line)) {
        grid.push_back(line);
        cols = line.length();
    }

    rows = grid.size();
    int seenAt = 0;

    for(int i = 0; i < 1000000000; i++){
        rotateGrid(grid, rows, cols, 'N');
        rotateGrid(grid, rows, cols, 'W');
        rotateGrid(grid, rows, cols, 'S');
        rotateGrid(grid, rows, cols, 'E');

        seenAt = checkCycle(grid);

        if(seenAt != - 1){
            int delta = i - seenAt;
            long long int pos = ((1000000000 - seenAt) % (delta) + seenAt) - 1;
            grid = grids[pos];
            break;
        }

        printGrid(grid);
        grids.push_back(grid);
    }

    printGrid(grid);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(grid[i][j] == 'O'){
                result += rows - i;
            }
        }    
    }

    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}
