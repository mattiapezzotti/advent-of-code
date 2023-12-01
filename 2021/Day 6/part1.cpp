#include <bits/stdc++.h>

using namespace std;

#define MAXN 1001

long long int fish[MAXN];

long long int sum(){
    long long int ret = 0;
    for(int i=0; i<10; i++)
        ret+=fish[i];
    return ret;
}

int main(){
    long long int result = 42;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;

    if (inputFile.is_open()) {
        while(getline(inputFile,line,','))
            fish[stoi(line)]++;
      

        for(int j=80; j>0; j--){
                if(fish[0] > 0){
                    fish[9]+=fish[0];
                    fish[7]+=fish[0];
                    fish[0] = 0;
                }
            for(int i=1; i<11; i++){
                fish[i-1] = fish[i];
            }
        }
            result = sum();

    }
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}