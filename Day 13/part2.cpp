#include <bits/stdc++.h>

using namespace std;

#define MAXN 3000

int fold;
int dimX, dimY;
int dots[MAXN][MAXN];

void print(){
    for(int i=0; i<=dimY; i++){
        for(int j=0; j<=dimX; j++)
            if(dots[i][j] == 0)
                cout << " ";
            else cout << "#";
        cout << endl;
    }
    cout << endl;
}

long long int count(){
    long long int ret = 0;
    for(int i=0; i<=dimY; i++){
        for(int j=0; j<=dimX; j++)
            if(dots[i][j] == 1)
                ret++;
    }
    return ret;
}

int main(){
    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;

    if (inputFile.is_open()) {
        while(getline(inputFile,line) && !line.empty()){
            int x = stoi(line.substr(0, line.find(',')));
            int y = stoi(line.substr(line.find(',') + 1, line.length() - 1));

            dots[y][x] = 1;

            if(x > dimX)
                dimX = x;
            if(y > dimY)
                dimY = y;
        }

        while(getline(inputFile,line)){
            fold = stoi(line.substr(line.find('=') + 1, line.length() - 1));

            if(line.find('x') != std::string::npos){
                for(int i = 0 ; i <= dimY; i++)
                    for(int j = 1 ; fold+j <= dimX ; j++)
                        if(dots[i][fold+j] == 1)
                            dots[i][fold-j] = 1;

               dimX = fold-1;            
            }

            else{
               for(int j = 0 ; j <= dimX; j++)
                    for(int i = 1 ; fold + i <= dimY ; i++)
                        if(dots[fold + i][j] == 1)
                            dots[fold - i][j] = 1;

                dimY = fold-1;
            } 
        }
        
    }
    
    cout << "Result: " << endl;
        print();

    inputFile.close();
    return 0;
}