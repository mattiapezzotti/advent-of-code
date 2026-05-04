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
    string line, bottomS, topS, iS, halfS;
    char delimiter = '-';
    long long int bottom, top, half, mirror;

    while (getline(in, line, ',')) {
        
        bottomS = line.substr(0, line.find(delimiter));
        topS = line.substr(line.find(delimiter) + 1);

        bottom = stoll(bottomS);
        top = stoll(topS);

        if(bottomS.size() % 2 != 0) continue;

        halfS = (bottomS.substr(0, bottomS.size() / 2));
        half = stoll(halfS);
        
        do{
            mirror = stoll(to_string(half) + to_string(half));

            if (mirror >= bottom && mirror <= top)
                result += mirror;

            half++;
        }while(mirror <= top);
    }
    
    out << "Result: " << result << endl;
    // out << "Time taken: " <<  (double)(clock() - tStart)/CLOCKS_PER_SEC << "s";
    
    in.close();
    out.close();

    return 0;
}