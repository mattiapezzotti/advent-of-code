#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;
    long long int elfCalories = 0;
    vector<long long int> allCalories;

    while (getline(inputFile, line)) {
        if(line.empty()){
            allCalories.push_back(elfCalories);
            elfCalories = 0;
        }
        else{
            elfCalories += stoi(line);
        }
    }

    allCalories.push_back(elfCalories);
    
    sort(allCalories.begin(), allCalories.end());

    int sizeC = allCalories.size();
    result += allCalories[sizeC - 1] + allCalories[sizeC - 2] + allCalories[sizeC - 3];

    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}