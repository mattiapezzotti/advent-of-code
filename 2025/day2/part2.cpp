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
    string line, bottomS, topS, iS, partS;
    char delimiter = '-';
    long long int bottom, top, current, part, size;

    while (getline(in, line, ',')) {
        
        bottomS = line.substr(0, line.find(delimiter));
        topS = line.substr(line.find(delimiter) + 1);

        bottom = stoll(bottomS);
        top = stoll(topS);
        
        for(int size = 1; size <= botS  .size(); size++){
            partS = (bottomS.substr(0, size));
            part = stoll(partS);
            
            do{
            for(int size = 1; size <= topS.size(); size++){
                currentS += to_string(part);

                if (mirror >= bottom && mirror <= top)
                    result += mirror;

                half++;
            }while(mirror <= top);
        }
    }
    
    out << "Result: " << result << endl;
    // out << "Time taken: " <<  (double)(clock() - tStart)/CLOCKS_PER_SEC << "s";
    
    in.close();
    out.close();

    return 0;
}