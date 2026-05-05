#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

ifstream in;
ofstream out;
long long int result = 0, ingredient, bot, top;
vector<pair<long long int, long long int>> fresh;

int main(){
    //clock_t tStart = clock();

    in.open ("input.txt");
    out.open("output.txt");
    string line;

    while (getline(in, line)) {
        if (line.empty()) break;
        bot = stoll(line.substr(0, line.find('-')));
        top = stoll(line.substr(line.find('-') + 1));
        fresh.push_back({bot,top});
    }

    while (getline(in, line)) {
        ingredient = stoll(line);
        for(int i = 0; i < fresh.size(); i++){
            if(ingredient >= fresh[i].first && ingredient <= fresh[i].second){
                result++;
                break;
            }
        }
    }

    out << "Result: " << result << endl;
    // out << "Time taken: " <<  (double)(clock() - tStart)/CLOCKS_PER_SEC << "s";
    
    in.close();
    out.close();

    return 0;
}