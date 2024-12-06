#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

ifstream in;
ofstream out;

char grid[MAXN][MAXN];
int c;
int r;
long long int result = 0;

// 0 = ^ ; 1 = > ; 2 = v ; 3 = <
int direction = 0;
bool isOut = false;
pair<int,int> guardPosition;
pair<int,int> movements[4] = {
    make_pair(-1, 0),   // UP
    make_pair(0, 1),    // LEFT
    make_pair(1, 0),   // DOWN
    make_pair(0, -1)    // RIGHT
};

void printGrid(){
    for(int i = 0; i <= r; i++){
        for(int j = 0; j <= c; j++)
            out << grid[i][j];
        out << endl;        
    }
    out << endl;
}

int move(int direction){

    while(true){
        guardPosition.first += movements[direction].first;
        guardPosition.second += movements[direction].second;

        if(guardPosition.first > r + 1 || guardPosition.second > c + 1)
            return 4;

        if(grid[guardPosition.first][guardPosition.second] == '#')
            break;
        
        grid[guardPosition.first][guardPosition.second] = 'X';
    }

    guardPosition.first -= movements[direction].first;
    guardPosition.second -= movements[direction].second;
    
    return (direction + 1) % 4;
}

int main(){
    ifstream in;
    in.open ("dummyinput.txt");
    out.open("output.txt");
    string line;

    for (int i = 0; getline(in, line); i++){
        r = i;
        for(int j = 0; j < line.size(); j++){
            grid[i][j] = line[j];
            if(grid[i][j] == '^'){
                guardPosition.first = i;
                guardPosition.second = j; 
            }
            c = j;
        }
    }

    direction = 0;


    while(!isOut){
        direction = move(direction);

        if(direction == 4)
            isOut = true;
    }

    for(int i = 0; i <= r; i++)
        for(int j = 0; j <= c; j++)
            if(grid[i][j] == 'X' || grid[i][j] == '^')
                result++;

    out << "Result: " << result << endl;
    // out << "Time taken:" <<  (double)(clock() - tStart)/CLOCKS_PER_SEC << "s";
    
    in.close();
    out.close();

    return 0;
}