#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define MAXN 9999

vector<string> grid;

ifstream inputFile("input.txt");

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
    int round[MAXN];
    int cube = 0;
    int maxPower = rows;

    for(int j = 0; j < cols; j++){
        maxPower = rows;
        for(int i = 0; i < rows; i++){
            if(grid[i][j] == 'O'){
                result += maxPower;
                maxPower--;
            }
            if(grid[i][j] == '#'){
                maxPower = rows - i - 1;
            }
        }     
    }

    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}
