#include <bits/stdc++.h>

using namespace std;

#define MAXN 11
#define DIM 9

int power[MAXN][MAXN];
int exploded[MAXN][MAXN];

void print(int step){
    cout << "Step: " << step << endl;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++)
            cout << power[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void explode(int i,int j){
    if(i==0 && j==0){
        power[i+1][j]++;
        power[i][j+1]++;
        power[i+1][j+1]++;
    }

    else if(i==0 && j==DIM){
        power[i+1][j-1]++;
        power[i+1][j]++;
        power[i][j-1]++;
    }

    else if(i==DIM && j==DIM){
        power[i-1][j-1]++;
        power[i-1][j]++;
        power[i][j-1]++;
    }

    else if(i==DIM && j==0){
        power[i-1][j+1]++;
        power[i-1][j]++;
        power[i][j+1]++;
    }

    else{
        power[i-1][j-1]++;
        power[i+1][j-1]++;
        power[i-1][j+1]++;
        power[i+1][j+1]++;

        power[i][j-1]++;
        power[i][j+1]++;
        power[i-1][j]++;
        power[i+1][j]++;
    }
}

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;

    if (inputFile.is_open()) {
        for(int i=0; !inputFile.eof(); i++){
            inputFile >> line;
            for(int j=0; j<line.length(); j++)
                power[i][j] = line.at(j) - '0';
        }
    }

    for(int step=0; step<100; step++){
        for(int i=0; i<10; i++)
            for(int j=0; j<10; j++)
                exploded[i][j] = 0;

        for(int i=0; i<10; i++)
            for(int j=0; j<10; j++)
                power[i][j]++;
        
        for(int i=0; i<10; i++)
            for(int j=0; j<10; j++)
                if(power[i][j] > 9){
                    if(exploded[i][j])
                        power[i][j] = 9;
                    else{
                        result++;
                        exploded[i][j] = 1;
                        explode(i,j);
                        i = 0;
                        j = -1;
                    }
                }

        for(int i=0; i<10; i++)
            for(int j=0; j<10; j++)
                if(exploded[i][j]){
                    power[i][j] = 0;
                }
    }
    //
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}