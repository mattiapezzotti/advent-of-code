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

    sort(fresh.begin(), fresh.end());

    for(int i = 1; i < fresh.size(); i++){
        if(fresh[i].first <= fresh[i - 1].second){
            fresh[i].first = min(fresh[i - 1].first, fresh[i].first);
            fresh[i].second = max(fresh[i - 1].second, fresh[i].second);
            fresh.erase(fresh.begin() + i - 1);
            i--;
        }
    }

    for(int i = 0; i < fresh.size(); i++){
        cout << fresh[i].first << "-" << fresh[i].second << ": " << (fresh[i].second - fresh[i].first) + 1 << endl;
        result += (fresh[i].second - fresh[i].first) + 1;
    }

    out << "Result: " << result << endl;
    // out << "Time taken: " <<  (double)(clock() - tStart)/CLOCKS_PER_SEC << "s";
    
    in.close();
    out.close();

    return 0;
}