#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

ifstream in;
ofstream out;
long long int result = 0, ingredient, bot, top;
vector<pair<long long int, long long int>> fresh;
bool is_new;

void appiattisci(){
    for(int i = 0; i < fresh.size(); i++){
        bool appiattito = false;
        if(
            (bot >= fresh[i].first && bot <= fresh[i].second)
            || (top >= fresh[i].first && top <= fresh[i].second)
        ){
            fresh[i].first = min(bot, fresh[i].first); 
            fresh[i].second = max(top, fresh[i].second); 
            appiattito = true;
        }
    }
    return appiattito;
}

int main(){
    //clock_t tStart = clock();

    in.open ("dummyinput.txt");
    out.open("output.txt");
    string line;

    while (getline(in, line)) {
        if (line.empty()) break;
        is_new = true;  

        bot = stoll(line.substr(0, line.find('-')));
        top = stoll(line.substr(line.find('-') + 1));

        fresh.push_back({bot,top});
    }

    for(int i = 0; i < fresh.size(); i++){
        result += fresh[i].second - fresh[i].first + 1;
    }

    out << "Result: " << result << endl;
    // out << "Time taken: " <<  (double)(clock() - tStart)/CLOCKS_PER_SEC << "s";
    
    in.close();
    out.close();

    return 0;
}