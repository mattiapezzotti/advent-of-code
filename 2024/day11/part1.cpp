#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

ifstream in;
ofstream out;
long long int result = 0;
vector<long long int> stones;
vector<long long int> newStones;

int digits(long long int n){
    return to_string(n).length();
}

void split(long long int n){
    string sn = to_string(n);
    long long int n1 = stoll(sn.substr(0, sn.length() / 2));
    long long int n2 = stoll(sn.substr(sn.length() / 2));

    newStones.push_back(n1);
    newStones.push_back(n2);
}

void printStones(){
    for(auto s : stones)
        cout << s << " ";

    cout << endl;
}

void blink(){
    long long int n;
    for(int i = 0; i < stones.size(); i++){
        n = stones.at(i);
        if(n == 0){
            newStones.push_back(1);
            continue;
        }
        if(digits(n) % 2 == 0){
            split(n);
            continue;
        }
        newStones.push_back(n *= 2024);
    }
    stones = newStones;
    newStones.clear();
}

int main(){
    clock_t tStart = clock();

    ifstream in;
    in.open ("input.txt");
    out.open("output.txt");
    string line;

    while (getline(in, line)) {
        stringstream ss(line);
        string number;

        while(getline(ss, number, ' ')){
            stones.push_back(stoi(number));
            for(int i = 0; i < 75; i++){
                blink();
            }
            result += stones.size();
            stones.clear();
        }
    }
    
    out << "Result: " << result << endl;
    out << "Time taken: " <<  (double)(clock() - tStart)/CLOCKS_PER_SEC << "s";
    
    in.close();
    out.close();

    return 0;
}