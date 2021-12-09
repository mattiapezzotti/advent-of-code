#include <bits/stdc++.h>

using namespace std;

#define MAXN 1001;

vector< vector<int> > mat(1000, vector<int>(1000,10));
vector<int> toSum;

int sum(vector<int> vet){
    int ret = 0;
    for(auto x: vet)
        ret+=x;
    return ret;
}

int main(){
    int result = 42;
    int i = 0, c = 0, curr = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;

    if (inputFile.is_open()) {
        for(i=1; !inputFile.eof(); i++){
            c = 0;
            inputFile >> line;
            for(int j=1; j<=line.length(); j++){
                mat[i][j] = line[c] - '0';
                c++;
            }
        }

        for(int x=1; x<i; x++)
            for(int j=1; j<=line.length(); j++){
                curr = mat[x][j];
                if(mat[x-1][j] > curr && mat[x+1][j] > curr && mat[x][j+1] > curr && mat[x][j-1] > curr)
                    toSum.push_back(curr+1);
            }

        result = sum(toSum);
    }
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}