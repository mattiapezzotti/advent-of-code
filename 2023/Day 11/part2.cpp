#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

struct Galaxy{
    int i, j;
};

vector<Galaxy> galaxy;
char space[MAXN][MAXN];
vector<int> emptyRow;
vector<int> emptyCol;

int galaxyDistance(Galaxy g1, Galaxy g2){
    int distanceHor = abs(g1.j - g2.j);
    int distanceVert = abs(g1.i - g2.i);
    return distanceHor + distanceVert;
}

int galaxyExpansion(Galaxy g1, Galaxy g2){
    long long int exp = 0;
    for(int i = min(g1.i, g2.i); i < max(g1.i, g2.i); i++){
        if(find(emptyRow.begin(), emptyRow.end(), i) != emptyRow.end()){
            exp+=999999;
        }
    }   

    for(int j = min(g1.j, g2.j); j < max(g1.j, g2.j); j++){
        if(find(emptyCol.begin(), emptyCol.end(), j) != emptyCol.end()){
                exp+=999999;
            }
    }
            
    return exp;

}

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;
    vector<char> spaceLine;

    int maxI;
    int maxJ;

    for(int l = 0; getline(inputFile, line); l++) {
        strcpy(space[l], line.c_str()); 
        if(line.find('#') == string::npos){
            emptyRow.push_back(l);
        }
        maxI = l + 1;
        maxJ = line.length();
    }

    bool empty;
    Galaxy g;
    int n = 0;

    for(int j = 0; j < maxJ; j++){
        empty = true;
        for(int i = 0; i < maxI; i++){
            if(space[i][j] == '#'){
                g.i = i;
                g.j = j;
                galaxy.push_back(g);
                empty = false;
            }
        }
        if(empty)
            emptyCol.push_back(j);
    }

    for(int i = 0; i < galaxy.size() - 1; i++ ){
        for(int j = i; j < galaxy.size(); j++)
            result += galaxyDistance(galaxy[i], galaxy[j]) + galaxyExpansion(galaxy[i], galaxy[j]);
    }
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}