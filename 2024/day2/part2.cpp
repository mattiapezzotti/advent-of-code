#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

ifstream inputFile;
ofstream out;

bool isSafe(vector<int> level){
    bool decr = false;
    bool incr = false;

    for(int i = 1; i < level.size(); i++){
        if(level[i] < level[i - 1])
            decr = true;
        else
            incr = true;

        if(abs(level[i] - level[i - 1]) < 1 || abs(level[i] - level[i - 1]) > 3){
            return false;
        }
    }

    if(decr && incr || !decr && !incr)
        return false;

    return true;
}


int main(){
    long long int result = 0;

    inputFile.open ("input.txt");
    out.open("output.txt");
    
    string line;
    string string_number;

    int curr_number;
    int prec_number;

    char del = ' ';

    bool safe;

    bool firstNumber = true;

    vector<int> originalLevel;
    vector<int> currentLevel;

    for (int i = 0; getline(inputFile, line); i++) {

        bool safe = true;

        stringstream stream(line);
        originalLevel.clear();

        while(getline(stream, string_number, del)){
            curr_number = stoi(string_number);
            originalLevel.push_back(curr_number);
        }

        for(int j = 0; j < originalLevel.size(); j++){

            if(j == 0){
                currentLevel = originalLevel;
                safe = isSafe(currentLevel);
            }

            if(safe)
                break;

            currentLevel = originalLevel;
            currentLevel.erase(currentLevel.begin() + j);

            safe = isSafe(currentLevel);
        }

        if(safe)
            result++;

    }
    
    out << "Result: " << result << endl;
    inputFile.close();
    return 0;
}