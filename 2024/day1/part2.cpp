#include <bits/stdc++.h>

using namespace std;

#define MAXN 99999

int main(){
    long long int result = 0;

    int leftList[MAXN];
    int rightList[MAXN];

     for(int i = 0; i < MAXN; i++){
        leftList[i] = 0;
        rightList[i] = 0;
    }

    ifstream inputFile;
    ofstream out;
    inputFile.open ("input.txt");
    out.open("output.txt");
    string line;

    string del = "   ";
    bool left = true;

    while (getline(inputFile, line)) {

        int delPos = line.find(del);

        int left = stoi(line.substr(0, delPos));
        int right = stoi(line.substr(delPos + del.size(), line.size()));

        leftList[left]++;
        rightList[right]++;
    }

    for(int i = 0; i <= MAXN; i++)
        result += i * rightList[i] * leftList[i];
    
    
    out << "Result: " << result << endl;
    inputFile.close();
    return 0;
}