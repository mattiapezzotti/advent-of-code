#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

struct Tube{
    char tube;
    int depth;
    bool visited;
}tubeMap[MAXN][MAXN];

int startI;
int startJ;
int maxI;
int maxJ;
char nextTube;

void explore(int i, int j, int step){
    if(tubeMap[i][j].visited || i > maxI || j > maxJ || i < 0 || j < 0)
        return;

    tubeMap[i][j].visited = true;
    tubeMap[i][j].depth = step;

    switch(tubeMap[i][j].tube){
        case '|':

            // TOP
            nextTube = tubeMap[i - 1][j].tube;
            if(nextTube == '|' || nextTube == '7' || nextTube == 'F')
                explore(i - 1, j, step + 1);

            // BOT
            nextTube = tubeMap[i + 1][j].tube;
            if(nextTube == '|' || nextTube == 'L' || nextTube == 'J')
                explore(i + 1, j, step + 1);

            break;

        case '-':

            // DX
            nextTube = tubeMap[i][j + 1].tube;
            if(nextTube == '-' || nextTube == 'J' || nextTube == '7')
                explore(i, j + 1, step + 1);

            // SX
            nextTube = tubeMap[i][j - 1].tube;
            if(nextTube == '-' || nextTube == 'L' || nextTube == 'F')
                explore(i, j - 1, step + 1);

            break;

        case '7':

            // SX
            nextTube = tubeMap[i][j - 1].tube;
            if(nextTube == '-' || nextTube == 'L' || nextTube == 'F')
                explore(i, j - 1, step + 1);

            // BOT
            nextTube = tubeMap[i + 1][j].tube;
            if(nextTube == '|' || nextTube == 'L' || nextTube == 'J')
                explore(i + 1, j, step + 1);

            break;

        case 'J':

            // TOP
            nextTube = tubeMap[i - 1][j].tube;
            if(nextTube == '|' || nextTube == '7' || nextTube == 'F')
                explore(i - 1, j, step + 1);

            // SX
            nextTube = tubeMap[i][j - 1].tube;
            if(nextTube == '-' || nextTube == 'L' || nextTube == 'F')
                explore(i, j - 1, step + 1);
            
            break;

        case 'F':

            // DX
            nextTube = tubeMap[i][j + 1].tube;
            if(nextTube == '-' || nextTube == 'J' || nextTube == '7')
                explore(i, j + 1, step + 1);

            // BOT
            nextTube = tubeMap[i + 1][j].tube;
            if(nextTube == '|' || nextTube == 'L' || nextTube == 'J')
                explore(i + 1, j, step + 1);

            break;

        case 'L':

            // TOP
            nextTube = tubeMap[i - 1][j].tube;
            if(nextTube == '|' || nextTube == '7' || nextTube == 'F')
                explore(i - 1, j, step + 1);

            // DX
            nextTube = tubeMap[i][j + 1].tube;
            if(nextTube == '-' || nextTube == 'J' || nextTube == '7')
                explore(i, j + 1, step + 1);

            break;
    }
    return;
}

void deleteTubes(){
    for(int i = 0; i < maxI; i++){
        if(tubeMap[i][0].depth == 0)
            tubeMap[i][0].depth = -1;
    }

    for(int j = 0; j < maxJ; j++){
        if(tubeMap[0][j].depth == 0)
            tubeMap[0][j].depth = -1;
    }

    for(int i = 0; i < maxI; i++){
        if(tubeMap[i][maxJ - 1].depth == 0)
            tubeMap[i][maxJ - 1].depth = -1;
    }

    for(int j = 0; j < maxJ; j++){
        if(tubeMap[maxI - 1][j].depth == 0)
            tubeMap[maxI - 1][j].depth = -1;
    }

    for(int j = 1; j < maxJ - 1; j++){
        for(int i = 1; i < maxI - 1; i++){
            if(tubeMap[i][j].depth == 0){
                // TOP
                if(tubeMap[i - 1][j].depth == -1)
                    tubeMap[i][j].depth = -1;
                // BOTTOM
                if(tubeMap[i + 1][j].depth == -1)
                    tubeMap[i][j].depth = -1;
                // LEFT
                if(tubeMap[i][j - 1].depth == -1)
                    tubeMap[i][j].depth = -1;
                // RIGHT
                if(tubeMap[i][j + 1].depth == -1)
                    tubeMap[i][j].depth = -1;
            }   
        }
    }

    for(int i = 1; i < maxI - 1; i++){
        for(int j = 1; j < maxJ - 1; j++){
            if(tubeMap[i][j].depth == 0){
                // TOP
                if(tubeMap[i - 1][j].depth == -1)
                    tubeMap[i][j].depth = -1;
                // BOTTOM
                if(tubeMap[i + 1][j].depth == -1)
                    tubeMap[i][j].depth = -1;
                // LEFT
                if(tubeMap[i][j - 1].depth == -1)
                    tubeMap[i][j].depth = -1;
                // RIGHT
                if(tubeMap[i][j + 1].depth == -1)
                    tubeMap[i][j].depth = -1;
            }   
        }
    }

    for(int i = maxI - 2; i > 0; i--){
        for(int j = maxJ - 2; j > 0 ; j--){
            if(tubeMap[i][j].depth == 0){
                // TOP
                if(tubeMap[i - 1][j].depth == -1)
                    tubeMap[i][j].depth = -1;
                // BOTTOM
                if(tubeMap[i + 1][j].depth == -1)
                    tubeMap[i][j].depth = -1;
                // LEFT
                if(tubeMap[i][j - 1].depth == -1)
                    tubeMap[i][j].depth = -1;
                // RIGHT
                if(tubeMap[i][j + 1].depth == -1)
                    tubeMap[i][j].depth = -1;
            }   
        }
    }

    for(int j = maxJ - 2; j > 0 ; j--){
        for(int i = maxI - 2; i > 0; i--){
            if(tubeMap[i][j].depth == 0){
                // TOP
                if(tubeMap[i - 1][j].depth == -1)
                    tubeMap[i][j].depth = -1;
                // BOTTOM
                if(tubeMap[i + 1][j].depth == -1)
                    tubeMap[i][j].depth = -1;
                // LEFT
                if(tubeMap[i][j - 1].depth == -1)
                    tubeMap[i][j].depth = -1;
                // RIGHT
                if(tubeMap[i][j + 1].depth == -1)
                    tubeMap[i][j].depth = -1;
            }   
        }
    }
}

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("dummyinput.txt");
    string line;

    for (int l = 0; getline(inputFile, line); l++) {
        for(int c = 0; c < line.length(); c++){
            tubeMap[l][c].tube = line[c];
            tubeMap[l][c].visited = false;
            tubeMap[l][c].depth = 0;

            if(line[c] == 'S'){
                startI = l;
                startJ = c;
                tubeMap[l][c].tube = 'F';
            }

        }
        maxI = l + 1;
        maxJ = line.length();
    }

    explore(startI, startJ, 0);
    
    deleteTubes();
    deleteTubes();


    tubeMap[startI][startJ].depth = 1;

    for(int i = 0; i < maxI; i++){
        for(int j = 0; j < maxJ; j++){
            cout << " ";
            if(tubeMap[i][j].depth == 0){
                cout << 0;
                result++;
            }
            else if(tubeMap[i][j].depth == -1){
                cout << 1;
            }
            else cout << 2;
        }
        cout << endl;
    }
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}