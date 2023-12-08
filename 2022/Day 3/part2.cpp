#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

int countFirst[MAXN];
int countSecond[MAXN];

void clear(){
    for(int i = 0; i < MAXN; i++){
        countFirst[i] = 0;
        countSecond[i] = 0;
    }
}

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;

    for(int j = 0; getline(inputFile, line); j++) {
        if(j == 0)
            for(int i = 0; i < line.length(); i++)
                countFirst[line[i]] = 1;
        

        if(j == 1)
            for(int i = 0; i < line.length(); i++)
                countSecond[line[i]] = 1;

        if(j == 2){
            for(int i = 0; i < line.length(); i++){
                if(countFirst[line[i]] == 1 && countSecond[line[i]] == 1){
                    if(line[i] >= 97)
                        result += (line[i] - 96);
                    else result += (line[i] - 38);
                    break;
                }
            }    
            j = -1;
            clear();
        }
    }
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}