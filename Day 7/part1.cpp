#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

long long int crab[MAXN];
long long int fuel[MAXN];


long long int sum(long long int arr[MAXN]){
    long long int ret = 0;
    for(int i=0; i<10; i++)
        ret+=arr[i];
    return ret;
}

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;
    int length = 0, min = INT_MAX, check = 0;

    if (inputFile.is_open()) {
        while(getline(inputFile,line,',')){
            crab[stoi(line)]++;
            if(stoi(line) > length)
                length = stoi(line);
        }

        for(int j=0; j<=length; j++){
            check = 0;
            for(int i=0; i<=length; i++){
                if(fuel[j] > min){
                    check = 1;
                    break;
                }
                fuel[j] += crab[i] * abs(i - j); 
            }

            if(check == 0){
                if(fuel[j] < min)
                    min = fuel[j]; 
            }
        }
    }

    for(int i=0; i<=length; i++){
        if(fuel[i] < min){
            min = fuel[i];
        }
    }

    result = min;
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}