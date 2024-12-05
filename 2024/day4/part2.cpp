#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

ifstream in;
ofstream out;

string grid[MAXN];

int c = 0;
int r = 0;

bool searchBottom(int i, int j, char l){
    if(
        j + 1 <= c && j - 1 >= 0 && i - 1 >=0 && 
        grid[i - 1][j + 1] == l && 
        grid[i - 1][j - 1] == l
    )
        return true;
    return false;
}

bool searchTop(int i, int j, char l){
    if(
        j + 1 <= c && j - 1 >= 0 && i + 1 <= r && 
        grid[i + 1][j + 1] == l && 
        grid[i + 1][j - 1] == l
    )
        return true;
    return false;
}

bool searchRight(int i, int j, char l){
    if(
        i + 1 <= r && i - 1 >= 0 && j + 1 <= c && 
        grid[i - 1][j + 1] == l && 
        grid[i + 1][j + 1] == l
    )
        return true;
    return false;
}

bool searchLeft(int i, int j, char l){
    if(
        i + 1 <= r && i - 1 >= 0 && j - 1 >= 0 && 
        grid[i - 1][j - 1] == l && 
        grid[i + 1][j - 1] == l
    )
        return true;
    return false;
}

int searchMAS(int i, int j){

    if(searchBottom(i, j, 'M') && searchTop(i, j, 'S'))
        return 1;

    if(searchBottom(i, j, 'S') && searchTop(i, j, 'M'))
        return 1;

    if(searchLeft(i, j, 'S') && searchRight(i, j, 'M'))
        return 1;

    if(searchLeft(i, j, 'M') && searchRight(i, j, 'S'))
        return 1;

    return 0;
}

int main(){
    long long int result = 0;

    ifstream in;
    in.open ("input.txt");
    out.open("output.txt");
    string line;

    for (int i = 0; getline(in, line); i++) {
        grid[i] = line;
        c = line.length();
        r = i;
    }

    for(int i = 0; i <= r; i++)
        for(int j = 0; j <= c; j++)
            if(grid[i][j] == 'A')
                result += searchMAS(i,j);
    
    out << "Result: " << result << endl;
    
    in.close();
    out.close();

    return 0;
}