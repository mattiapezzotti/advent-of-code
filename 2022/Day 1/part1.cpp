#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;
    long long int elfCalories = 0;
    long long int maxCalories = 0;

    while (getline(inputFile, line)) {
        if(line.empty()){
            if(elfCalories > maxCalories)
                maxCalories = elfCalories;
            elfCalories = 0;
        }
        else{
            elfCalories += stoi(line);
        }
    }
    
    result = maxCalories;

    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}