#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

string spelledDigit[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

string findSpelledDigit(string line){
    size_t foundPos = 0;
    char charDigit;
    for (int i = 0 ; i < 9; i++){
        charDigit = (i + 1 + '0');
        foundPos = line.find(spelledDigit[i]);
        if (foundPos != std::string::npos){
            line.insert(foundPos + 1, 1, charDigit);
            i--;
        }
    }
    return line;
}

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;
    string newLine = "";

    for (string line; getline(inputFile, line); ) {
        line = findSpelledDigit(line);
        for (char c : line)
            if(isdigit(c))
                newLine += (c - '0');
        
        result += newLine[0] * 10 + newLine[newLine.length() - 1];
        newLine = "";
    }
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}