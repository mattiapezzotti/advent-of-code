#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

long long int word[MAXN];

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;
    int length = 0, min = INT_MAX, check = 0;

    if (inputFile.is_open()) {
        while(!inputFile.eof()){
            for(int i=0; i<10; i++)
                inputFile >> line;

            inputFile >> line;

            for(int i=0; i<4; i++){
                inputFile >> line;
                word[line.length()]++;
            }
        }
    }

    result = word[2] + word[3] + word[7] + word[4];
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}