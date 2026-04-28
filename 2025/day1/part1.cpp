#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

int main(){
    long long int result = 0;

    vector<long long int> leftList;
    vector<long long int> rightList;

    ifstream inputFile;
    ofstream out;
    inputFile.open ("input.txt");
    out.open("output.txt");
    string line;

    string del = "   ";
    bool left = true;

    while (getline(inputFile, line)) {

        int delPos = line.find(del);

        string left = line.substr(0, delPos);
        string right = line.substr(delPos + del.size(), line.size());

        leftList.push_back(stoi(left));
        rightList.push_back(stoi(right));
    }

    sort(leftList.begin(), leftList.end());
    sort(rightList.begin(), rightList.end());

    for(int i = 0; i < leftList.size(); i++){
        result += abs(leftList[i] - rightList[i]);
    }
    
    out << "Result: " << result << endl;
    inputFile.close();
    return 0;
}