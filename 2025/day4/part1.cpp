#include <bits/stdc++.h>

using namespace std;

#define MAXN 200

ifstream in;
ofstream out;
long long int result = 0;

vector<vector<int>> grid(MAXN, vector<int>(MAXN, -1));

bool checkCell(int i, int j){
    if(grid[i][j] == -1) return false;

    int paper = 0;

    if(grid[i + 1][j] == 1) paper++;
    if(grid[i + 1][j - 1] == 1) paper++;
    if(grid[i + 1][j + 1] == 1) paper++;
    if(grid[i - 1][j] == 1) paper++;
    if(grid[i - 1][j + 1] == 1) paper++;
    if(grid[i - 1][j - 1] == 1) paper++;
    if(grid[i][j + 1] == 1) paper++;
    if(grid[i][j - 1] == 1) paper++;

    return paper < 4;
}

int main(){
    //clock_t tStart = clock();

    in.open("input.txt");
    out.open("output.txt");

    vector<string> raw;
    string line;
    while (getline(in, line))
        if (!line.empty()) raw.push_back(line);

    int rows = raw.size() + 1;
    int cols = raw[0].size() + 1;

    for (int r = 1; r < rows; r++)
        for (int c = 1; c < cols; c++)
            grid[r][c] = (raw[r-1][c-1] == '@') ? 1 : 0;

    for (int r = 1; r < rows; r++){
        for (int c = 1; c < cols; c++){
            if(grid[r][c] && checkCell(r, c))
                result++;
        }
    }

    out << "Result: " << result << endl;
    //out << "Time taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << "s";

    in.close();
    out.close();

    return 0;
}