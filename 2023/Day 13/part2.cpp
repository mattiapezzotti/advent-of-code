#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define MAXN 9999

vector<string> horGrid;
vector<string> vertGrid;

ifstream inputFile("input.txt");
ofstream outputFile("output.txt");

void printGrid(const vector<string>& g) {
    outputFile << endl;
    for(auto l : g)
        outputFile << l << endl;
}

int hammingDist(const vector<string>& g, int l1, int l2) 
{ 
    int i = 0, count = 0;
    string str1 = g[l1];
    string str2 = g[l2];
    while (str1[i] != '\0') { 
        if (str1[i] != str2[i]) 
            count++; 
        i++; 
    } 
    return count; 
} 

bool checkMirror(const vector<string>& g, int start, int finish, bool hamming) {
    while (start <= finish) {
        if (g[start] != g[finish])
            if(hamming && hammingDist(g, start, finish) == 1) {
                hamming = false;
            }
            else return false;
        if(start == finish)
            return false;
        start++;
        finish--;
    }
    return !hamming;
}

bool checkRows(const vector<string>& g, int l1, int l2, int cols) {
    for (int j = 0; j < cols; j++)
        if (g[l1][j] != g[l2][j])
            return false;
    return true;
}

int findCenter(const vector<string>& g, int rows, int cols) {
    //printGrid(g);
    int j = rows - 1;
    for (int i = 0; i < rows - 1; i++) {
        if (hammingDist(g, i, j) == 1){
            if(checkMirror(g, i+1, j-1, false)){
            //outputFile << (j + i + 2) / 2 << endl;
            return ((j + i + 2) / 2);
            }
        }
        if (hammingDist(g, i, j) == 0){
            if(checkMirror(g, i+1, j-1, true)){
            //outputFile << (j + i + 2) / 2 << endl;
            return ((j + i + 2) / 2);
            }
        }
    }

    j = 0;
    for (int i = rows - 1; i > 0; i--) {
        if (hammingDist(g, i, j) == 1)
            if(checkMirror(g, j+1, i-1, false)){
            //outputFile << (j + i + 2) / 2 << endl;
            return ((j + i + 2) / 2);
        }

        if (hammingDist(g, i, j) == 0)
            if(checkMirror(g, j+1, i-1, true)){
            //outputFile << (j + i + 2) / 2 << endl;
            return ((j + i + 2) / 2);
        }
    }
    return 0;
}

int main() {
    long long int result = 0;

    string line;
    int rows = 0;
    int cols = 0;
    int val = 0;
    int count = 0;

    while (getline(inputFile, line)) {
        val = 0;
        if (!line.empty()) {
            horGrid.push_back(line);

            if(vertGrid.empty())
                for(auto c : line)
                    vertGrid.push_back("");

            for (int i = 0; i < line.length(); i++)
                vertGrid[i] += line[i];
            
            
            cols = line.length();

        } else {
            count++;
            rows = horGrid.size();

            val = 100 * findCenter(horGrid, rows, cols);
            if(val == 0)
                val = findCenter(vertGrid, cols, rows);
            result += val;

            horGrid.clear();
            vertGrid.clear();
        }
    }

    rows = horGrid.size();

    val = 100 * findCenter(horGrid, rows, cols);
    if(val == 0)
        val = findCenter(vertGrid, cols, rows);
    
    result += val;

    horGrid.clear();
    vertGrid.clear();

    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}
