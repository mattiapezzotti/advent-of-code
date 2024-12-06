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
bool looped = false;

pair<int, int> guardPosition;
pair<int, int> initialGuardPosition;

set<pair<int, int>> possibleBarrelPosition;

vector<tuple<int, int, int>> startPositions;
tuple<int, int, int> position;

pair<int, int> testPosition;
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

void printPositions(){
    for(auto p : startPositions)
        out << get<0>(p) << " " << get<1>(p) << " " << get<2>(p) << endl;
    out << endl;
}

int move(int direction){
    while(true){
        guardPosition.first += movements[direction].first;
        guardPosition.second += movements[direction].second;

        if(guardPosition.first >= r + 1 || guardPosition.second >= c + 1 ||
            guardPosition.first < 0 || guardPosition.second < 0)
            return 4;
        

        if(grid[guardPosition.first][guardPosition.second] == '#' || 
            grid[guardPosition.first][guardPosition.second] == 'O')
            break;
    }

    guardPosition.first -= movements[direction].first;
    guardPosition.second -= movements[direction].second;
    
    return (direction + 1) % 4;
}

int moveFirst(int direction){
    while(true){
        guardPosition.first += movements[direction].first;
        guardPosition.second += movements[direction].second;

        if(guardPosition.first >= r + 1 || guardPosition.second >= c + 1 ||
            guardPosition.first < 0 || guardPosition.second < 0)
            return 4;

        if(grid[guardPosition.first][guardPosition.second] == '#')
            break;
        
        possibleBarrelPosition.insert(make_pair(guardPosition.first, guardPosition.second));
    }

    guardPosition.first -= movements[direction].first;
    guardPosition.second -= movements[direction].second;
    
    return (direction + 1) % 4;
}

int main(){
    clock_t tStart = clock();
    ifstream in;
    in.open ("input.txt");
    out.open("output.txt");
    string line;

    for (int i = 0; getline(in, line); i++){
        r = i;
        for(int j = 0; j < line.size(); j++){
            grid[i][j] = line[j];
            if(grid[i][j] == '^'){
                initialGuardPosition.first = i;
                initialGuardPosition.second = j;
            }
            c = j;
        }
    }

    direction = 0;
    guardPosition = initialGuardPosition;

    while(!isOut){
        direction = moveFirst(direction);

        if(direction == 4)
            isOut = true;
    }

    direction = 0;

    for(auto possiblePosition : possibleBarrelPosition){

        testPosition.first = possiblePosition.first;
        testPosition.second = possiblePosition.second;

        grid[testPosition.first][testPosition.second] = 'O';

        looped = false;
        isOut = false;
        direction = 0;

        startPositions.clear();
        position = make_tuple(initialGuardPosition.first, initialGuardPosition.second, direction);
        startPositions.push_back(position);

        guardPosition = initialGuardPosition;

        while(!isOut && !looped){
            direction = move(direction);

            position = make_tuple(guardPosition.first, guardPosition.second, direction);

            auto it = find(startPositions.begin(), startPositions.end(), position);

            if(it != startPositions.end()){
                looped = true;
                result++;
            }

            if(direction == 4)
                isOut = true;

            startPositions.push_back(position);
        }

        grid[testPosition.first][testPosition.second] = '.';
    }

    out << "Result: " << result << endl;
    out << "Time taken: " <<  (double)(clock() - tStart)/CLOCKS_PER_SEC << "s";
    
    in.close();
    out.close();

    return 0;
}