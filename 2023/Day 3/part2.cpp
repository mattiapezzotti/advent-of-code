#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

char mat[MAXN][MAXN];

string searchNumberLeft(string line, int x){
    if(x < 0 || !isdigit(line[x])){
        return "";
    }

    return searchNumberLeft(line, x-1) + line[x];
}

string searchNumberRight(string line, int x){
    if(x >= line.length() || !isdigit(line[x])){
        return "";
    }

    return line[x] + searchNumberRight(line, x+1);
}


long long int findNumbers(vector<string> searchBox, int x){
    long long int gearProd = 0;
    string leftNumber = "";
    string rightNumber = "";
    string foundNumber = "";
    vector<long int> gear;

    for(string line : searchBox){
        // Left
        leftNumber = searchNumberLeft(line, x-1);

        // Right
        rightNumber = searchNumberRight(line, x+1);

        if(isdigit(line[x])){
            foundNumber = leftNumber + line[x] + rightNumber;
            gear.push_back(stoi(foundNumber));
        }
        else{
            if(leftNumber != "")
                gear.push_back(stoi(leftNumber));
            if(rightNumber != "")
                gear.push_back(stoi(rightNumber));
        }

        leftNumber = "", rightNumber = "", foundNumber = "";
    }

    if(gear.size() == 2)
        gearProd = gear.at(0) * gear.at(1);

    return gearProd;
}

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;
    int i = 0, j = 0;
    int max_i = 0, max_j = 0;

    for (string line; getline(inputFile, line); ) {
        for(j = 0; j < line.length(); j++){
            mat[i][j] = line[j];
        }
        i++;
    }

    max_j = j;
    max_i = i;

    vector<string> searchBox;

    for(i = 0; i < max_i; i++){
        for(j = 0; j < max_j; j++){
            if(!isdigit(mat[i][j]) && mat[i][j] != '.'){
                if(i == max_i - 1){
                    // Last Line
                    searchBox.push_back(mat[i-1]);
                }
                else{
                    if(i == 0){
                        // First Line
                        searchBox.push_back(mat[i+1]);
                    }
                    else{
                        // Normal Line
                        searchBox.push_back(mat[i-1]);
                        searchBox.push_back(mat[i+1]);
                    }
                }
                searchBox.push_back(mat[i]);
                result += findNumbers(searchBox, j);
                searchBox.clear();
            }
        }
    }

    /*
    for(i = 0; i < max_i; i++){
        for(j = 0; j < max_j; j++){
            cout << mat[i][j];
        }
        cout << endl;
    }
    */

    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}