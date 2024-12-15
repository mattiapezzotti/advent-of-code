#include <bits/stdc++.h>

using namespace std;

#define MAXN 200

ifstream in;
ofstream out;
long long int result = 0;

int grid[MAXN][MAXN];
int visited[MAXN][MAXN];
vector<pair<int,int>> startPoints;

int c, r;

void printVisited(){
    for(int i = 0; i <= r; i++){
        for(int j = 0; j <= c; j++){
            cout << visited[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void resetGrid(){
    for(int i = 0; i <= r; i++)
        for(int j = 0; j <= c; j++)
            visited[i][j] = false;
}

int searchPath(int i, int j, int searchFor){
    if(visited[i][j] || j < 0 || i < 0 || j > c || i > r || grid[i][j] != searchFor)
        return 0;

    visited[i][j] = true;
    searchFor++;

    if(grid[i][j] == 9)
        return 1;

    return  searchPath(i + 1, j, searchFor) + 
            searchPath(i - 1, j, searchFor) + 
            searchPath(i, j + 1, searchFor) + 
            searchPath(i, j - 1, searchFor);
}

int main(){
    //clock_t tStart = clock();

    ifstream in;
    in.open ("input.txt");
    out.open("output.txt");
    string line;

    for (int i = 0; getline(in, line); i++) {
        r = i;
        for(int j = 0; j < line.length(); j++){
            grid[i][j] = line[j] - '0';
            if(grid[i][j] == 0)
                startPoints.push_back(make_pair(i,j));
        }
        c = line.length() - 1;
    }

    for(auto s : startPoints){
        resetGrid();
        result += searchPath(s.first, s.second, 0);
    }
    
    
    out << "Result: " << result << endl;
    // out << "Time taken: " <<  (double)(clock() - tStart)/CLOCKS_PER_SEC << "s";
    
    in.close();
    out.close();

    return 0;
}