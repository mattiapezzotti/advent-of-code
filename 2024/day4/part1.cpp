#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

ifstream in;
ofstream out;

string grid[MAXN];

int c = 0;
int r = 0;

int searchXMAS(int i, int j){

    int result = 0;

    // Avanti
    if(i + 3 <= r && grid[i + 1][j] == 'M' && grid[i + 2][j] == 'A' && grid[i + 3][j] == 'S')
        result++;

    // Indietro
    if(i - 3 >= 0 && grid[i - 1][j] == 'M' && grid[i - 2][j] == 'A' && grid[i - 3][j] == 'S')
        result++;

    // Su
    if(j - 3 >= 0 && grid[i][j - 1] == 'M' && grid[i][j - 2] == 'A' && grid[i][j - 3] == 'S')
        result++;

    // Giu
    if(j + 3 <= c && grid[i][j + 1] == 'M' && grid[i][j + 2] == 'A' && grid[i][j + 3] == 'S')
        result++;

    // Su Destra
    if(i + 3 <= r && j - 3 >= 0 && grid[i + 1][j - 1] == 'M' && grid[i + 2][j - 2] == 'A' && grid[i + 3][j - 3] == 'S')
        result++;

    // Su Sinistra
    if(i - 3 <= r && j - 3 >= 0 && grid[i - 1][j - 1] == 'M' && grid[i - 2][j - 2] == 'A' && grid[i - 3][j - 3] == 'S')
        result++;

    // Giu Destra
    if(i + 3 <= r && j + 3 >= 0 && grid[i + 1][j + 1] == 'M' && grid[i + 2][j + 2] == 'A' && grid[i + 3][j + 3] == 'S')
        result++;

    // Giu Sinistra
    if(i - 3 <= r && j + 3 >= 0 && grid[i - 1][j + 1] == 'M' && grid[i - 2][j + 2] == 'A' && grid[i - 3][j + 3] == 'S')
        result++;

    return result;
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
            if(grid[i][j] == 'X')
                result += searchXMAS(i,j);
    
    out << "Result: " << result << endl;
    
    in.close();
    out.close();

    return 0;
}