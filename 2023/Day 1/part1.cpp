#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;
    string newLine = "";

    for (string line; getline(inputFile, line); ) {
        for (char c : line){
            if(isdigit(c)){
                newLine += (c - '0');
            }
        }
        result += newLine[0] * 10 + newLine[newLine.length() - 1];
        newLine = "";
    }
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}