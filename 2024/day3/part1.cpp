#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

ifstream in;
ofstream out;

int molt(int a, int b){
    return a * b;
}

int main(){
    long long int result = 0;

    ifstream in;
    in.open ("input.txt");
    out.open("output.txt");
    string line;

    while (getline(in, line)) {
        string pattern("mul\\([1-9]\\d{0,2},[1-9]\\d{0,2}\\)");
        regex rx(pattern);

        auto begin = sregex_iterator(line.begin(), line.end(), rx);
        auto end = sregex_iterator();

        for (auto it = begin; it != end; ++it) {
            smatch match = *it;
            string s = match.str();

            s = s.substr(4, s.length() - 1);

            string delimiter = ",";
            int n1 = stoi(s.substr(0, s.find(delimiter)));
            int n2 = stoi(s.substr(s.find(delimiter) + 1)); 

            out << n1 << " " << n2 << endl;

            result += molt(n1, n2);
        }
    }

    out << "Result: " << result << endl;
    
    in.close();
    out.close();

    return 0;

}