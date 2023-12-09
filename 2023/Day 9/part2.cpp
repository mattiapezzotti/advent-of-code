#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

vector<vector<int>> matrix;

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");

    string line;
    string word;
    vector<int> oasis;
    vector<int> difference;
    vector<int> currentLine;
    size_t pos;

    while (getline(inputFile, line)) {
        line += " ";     
        oasis.clear();
        matrix.clear();
        difference.clear();

        // GET NUMBERS
        while ((pos = line.find(" ")) != std::string::npos) {
            word = line.substr(0, pos);
            oasis.push_back(stoi(word));
            line.erase(0, pos + 1);
        }

        matrix.push_back(oasis);
        currentLine = oasis;
        do{
            for(int i = 0; i < currentLine.size() - 1; i++){
                difference.push_back(currentLine[i+1] - currentLine[i]);
            }

            matrix.push_back(difference);
            currentLine = difference;
            difference.clear();
        }while(!all_of(currentLine.begin(), currentLine.end(), [](int i) { return i==0; }));

        int sum = 0;
        for(int i = matrix.size() - 2; i >= 0; i--){
            sum = matrix[i][0] - sum;
        }
        result += sum;
    }
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}