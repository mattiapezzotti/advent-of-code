#include <bits/stdc++.h>

using namespace std;

#define MAXN 100

ifstream in;
ofstream out;

vector<int> rules[MAXN];
int printed [MAXN];
vector<int> currentPrint;

char delimiter = '|';
int n1;
int n2;
bool correct = false;
string string_number;
int curr_number;

void printRules(){
    for(int i = 0; i < MAXN; i++){
        out << i << " -> ";
        for(auto v : rules[i])
            out << v << " ";
        out << endl;
    }
    
}

void clearPrinted(){
    for(int i = 0; i < MAXN; i++)
        printed[i] = 0;
}

int main(){
    clock_t tStart = clock();
    long long int result = 0;

    ifstream in;
    in.open("input.txt");
    out.open("output.txt");
    string line;

    while (getline(in, line)) {

        if(line.find(delimiter) == string::npos)
            break;
        
        n1 = stoi(line.substr(0, line.find(delimiter)));
        n2 = stoi(line.substr(line.find(delimiter) + 1));

        rules[n1].push_back(n2);
    }

    while (getline(in, line)) {

        correct = true;
        clearPrinted();
        currentPrint.clear();
        stringstream stream(line);

        while(getline(stream, string_number, ',')){
            curr_number = stoi(string_number);
            currentPrint.push_back(curr_number);

            printed[curr_number] = 1;

            for(auto v : rules[curr_number])
                if(printed[v] == 1)
                    correct = false;
            
            if(correct == false)
                break;
        }

        if(correct)
            result += currentPrint.at(currentPrint.size() / 2);
    }
    
    out << "Result: " << result << endl;
    
    in.close();
    out.close();

    return 0;
}