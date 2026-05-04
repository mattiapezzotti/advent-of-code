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
    int firstDigit, secondDigit, firstPos, secondPos, foundDigit;

    while (getline(in, line)) {
        firstDigit = 9;
        secondDigit = 9;

        // FIRST
        firstPos = -1;
        do{
            foundDigit = line.find(to_string(firstDigit), firstPos + 1);

            if(foundDigit != string::npos && foundDigit != line.length() - 1){
                firstPos = foundDigit;
                result += 10 * firstDigit;
            }
            firstDigit--;
        }while(foundDigit == string::npos || foundDigit == line.length() - 1);

        // SECOND
        secondPos = firstPos;
        do{
            foundDigit = line.find(to_string(secondDigit), secondPos + 1);

            if(foundDigit != string::npos){
                secondPos = firstPos;
                result += secondDigit;
            }
            secondDigit--;
        }while(foundDigit == string::npos);
    }
    
    out << "Result: " << result << endl;
    // out << "Time taken: " <<  (double)(clock() - tStart)/CLOCKS_PER_SEC << "s";
    
    in.close();
    out.close();

    return 0;
}