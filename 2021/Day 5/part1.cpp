#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

vector< vector<int> > mat(1000, vector<int>(1000,0));
int dimX, dimY;

int getX(string line){
    return stoi(line.substr(0, line.find(',')));
}

int getY(string line){
    return stoi(line.substr(line.find(',')+1, line.length()-1));
}

long long int count(vector< vector<int> > mat){
    long long int count = 0;
    for(int i=0; i<=dimX; i++)
        for(int j=0; j<=dimY; j++)
            if(mat[i][j] > 1)
                count++;
    return count;
}

int main(){
    long long int result = 42;
    int x1,x2,y1,y2;
    int max = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;

    if (inputFile.is_open()) {
        while(!inputFile.eof()){
            inputFile >> line;
            x1 = getX(line);
            y1 = getY(line);

            if(x1 > dimX)
                dimX = x1;

            if(y1 > dimY)
                dimY = y1;

            inputFile >> line; // ->

            inputFile >> line;
            x2 = getX(line);
            y2 = getY(line);

            if(x1 != x2 && y2 != y1)
                continue;

            if(x2 > dimX)
                dimX = x2;

            if(y2 > dimY)
                dimY = y2;

            for(int i=min(x2,x1); i<=std::max(x1,x2); i++)
                for(int j=min(y1,y2); j<=std::max(y1,y2); j++){
                    mat[i][j]++;
                }
        }
        result = count(mat);
    }
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}