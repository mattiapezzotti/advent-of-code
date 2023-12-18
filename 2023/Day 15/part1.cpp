#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;
    string stepString;
    getline(inputFile, line);

    string delimiter = ",";
    int pos = 0;
    int ascii = 0;

    line += ",";

    while ((pos = line.find(delimiter)) != string::npos) {
        stepString = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());

        ascii = 0;

        for(int c : stepString){
            ascii += c;
            ascii *= 17;
            ascii %= 256;
        }
        result += ascii;
    }
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}