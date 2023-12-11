#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("dummyinput.txt");
    string line;

    while (getline(inputFile, line)) {
        cout << line << endl;
    }
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}