#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

ifstream in;
ofstream out;
long long int result = 0;

int main(){
    //clock_t tStart = clock();

    ifstream in;
    in.open ("input.txt");
    out.open("output.txt");
    string line;
    string resultS = "";
    int currentDigit, currentPos, precPos = -1, foundPos;

    while (getline(in, line)) {
        cout << endl;
        for(int i = 11; i >= 0; i--){
            currentDigit = 9;
            currentPos = precPos;

            do{
                foundPos = line.find(to_string(currentDigit), currentPos + 1);

                if(foundPos != string::npos && foundPos < line.length() - i){
                    precPos = foundPos;
                    resultS += to_string(currentDigit);
                    cout << currentDigit;
                    break;
                }

                if(currentDigit > 1)
                    currentDigit--;

            }while(true);
        }
        result += stoll(resultS);
        resultS = "";
        precPos = -1;
    }
    
    out << "Result: " << result << endl;
    // out << "Time taken: " <<  (double)(clock() - tStart)/CLOCKS_PER_SEC << "s";
    
    in.close();
    out.close();

    return 0;
}