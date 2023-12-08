#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

int countFirst[MAXN];

void clear(){
    for(int i = 0; i < MAXN; i++)
        countFirst[i] = 0;
}

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;

    while(getline(inputFile, line)) {
        clear();
        for(int i = 0; i < (line.length() / 2); i++)
            countFirst[line[i]]++;
                
        for(int i = (line.length() / 2); i < line.length(); i++){
            if(countFirst[line[i]] > 0){
                if(line[i] >= 97)
                    result += (line[i] - 96);
                else result += (line[i] - 38);
                break;
            }
        }     
    }
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}