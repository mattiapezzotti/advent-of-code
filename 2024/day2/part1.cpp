#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

int main(){
    long long int result = 0;

    ifstream inputFile;
    ofstream out;
    inputFile.open ("input.txt");
    out.open("output.txt");

    string line;
    string string_number;
    int curr_number;
    int prec_number;

    char del = ' ';
    bool decr = false;
    bool incr = false;
    bool safe = true;
    bool firstNumber = true;

    while (getline(inputFile, line)) {
        decr = false;
        incr = false;
        safe = true;
        firstNumber = true;
        stringstream stream(line);

        while(getline(stream, string_number, del)){

            curr_number = stoi(string_number);

            if(firstNumber){
                prec_number = curr_number;
                firstNumber = false;
                continue;
            }

            if(curr_number < prec_number)
                decr = true;
            else
                incr = true;

            if(abs(curr_number - prec_number) < 1 || abs(curr_number - prec_number) > 3)
                safe = false;

            prec_number = curr_number;
        }

        if(decr && incr || !decr && !incr)
            safe = false;

        if(safe)
            result++;
    }
    
    out << "Result: " << result << endl;
    inputFile.close();
    return 0;
}