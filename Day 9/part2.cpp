#include <bits/stdc++.h>

using namespace std;

#define MAXN 1001;

vector< vector<int> > mat(1000, vector<int>(1000,10));
vector< vector<int> > seen(1000, vector<int>(1000,0));
vector<int> toSum;

int sum(vector<int> vet){
    sort(vet.begin(), vet.end());
    long long int ret = 1;
    for(int i=vet.size()-1; i>vet.size()-4; i--){
        ret*=vet.at(i);   
    }
    return ret;
}

int checkNode(int i, int j, int basin){

    if(seen[i-1][j] == 0 && mat[i-1][j] < 9){
        seen[i-1][j] = 1;
        basin++;
        basin += checkNode(i-1,j,0);
    }

    if(seen[i+1][j] == 0 && mat[i+1][j] < 9){
        seen[i+1][j] = 1;
        basin++;
        basin += checkNode(i+1,j,0);
    }

    if(seen[i][j-1] == 0 && mat[i][j-1] < 9){
        seen[i][j-1] = 1;
        basin++;
        basin += checkNode(i,j-1,0);
    }

    if(seen[i][j+1] == 0 && mat[i][j+1] < 9){
        seen[i][j+1] = 1;
        basin++;
        basin += checkNode(i,j+1,0);
    }
    return basin;
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
                if(mat[x-1][j] > curr && mat[x+1][j] > curr && mat[x][j+1] > curr && mat[x][j-1] > curr){
                    toSum.push_back(checkNode(x,j,0));
                }
            }

        result = sum(toSum);
    }
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}