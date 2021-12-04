#include <bits/stdc++.h>

using namespace std;

#define MAXN 1001

vector<int> extracted;
int board[MAXN][6][6];
int check[MAXN][6][6];
int won[MAXN];
int last;

void extractNumbers(vector<int> &vet, string line){
        stringstream stream(line);

        while(getline(stream, line, ',')) {   
            vet.push_back(stoi(line));
        }
}

bool checkBoard(int (&board)[6][6], int (&check)[6][6], int estratto){
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            if(board[i][j] == estratto && check[i][j] != 1){
                check[i][j] = 1;
                return 1;
            }     
    return 0;
}

bool checkWin(int (&check)[6][6]){
    int c;
    for(int i=0; i<5; i++){
        c = 0;
        for(int j=0; j<5; j++)
            if(check[i][j] == 1) 
                c++;
        if(c == 5)
            return 1;
    }

    for(int j=0; j<5; j++){
        c = 0;
        for(int i=0; i<5; i++)
            if(check[i][j] == 1) 
                c++;
        if(c == 5)
            return 1;
    }
    return 0;
}

int sum(int (&board)[6][6], int (&check)[6][6]){
    int summ = 0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++)
            if(check[i][j] == 0){
                summ += board[i][j];
            }
    }
    return summ;
}

int main(){
    int result = 42;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;

    if (inputFile.is_open()) {
        getline(inputFile, line);
        extractNumbers(extracted, line);
        int b;
        
        for(b=0; !inputFile.eof(); b++)
            for(int i=0; i<5; i++)
                for(int j=0; j<5; j++){
                    inputFile >> line;
                    board[b][i][j] = stoi(line);
                }

        int boardWin = 0;

        for(auto x: extracted)
            for(int i=0; i<b; i++){
                if(won[i] != 1) 
                    if(checkBoard(board[i], check[i], x)){
                        if(checkWin(check[i])){
                            won[i] = 1;
                            boardWin++;
                            if(boardWin == b){
                                cout << "Result: " << sum(board[i], check[i]) * x << endl;
                                return 0;
                            }
                        }
                    }
            }
    
    inputFile.close();
    }
    return 0;    
}   