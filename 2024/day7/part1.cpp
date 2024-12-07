#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

ifstream in;
ofstream out;
long long int result = 0;
vector<int> eq_numbers;

// 0 = + ; 1 = *
int operations[MAXN];

long long int tryOperations(){
    long long int result = eq_numbers.at(0);

    for(int i = 1; i < eq_numbers.size(); i++)
        if(!operations[i - 1])
            result += eq_numbers.at(i);
        else
            result *= eq_numbers.at(i);
    return result;
}

void initOperations(){
    for(int i = 0; i < eq_numbers.size(); i++)
        operations[i] = 0;
}

void newOperations(int n)
{
    for (int i = eq_numbers.size() - 1; i >= 0; i--) {
        int k = n >> i;
        if (k & 1){
            operations[i] = 1;
        }
        else{
            operations[i] = 0;
        }
    }
}

int main(){
    clock_t tStart = clock();

    ifstream in;
    in.open ("input.txt");
    out.open("output.txt");
    string line;

    char delimiter = ':';
    long long int eq_result;
    long long int op_result;
    string eq_numbers_string;
    string eq_number_string;

    while (getline(in, line)) {
        eq_result = stoll(line.substr(0, line.find(delimiter)));
        eq_numbers_string = line.substr(line.find(delimiter) + 2);

        stringstream stream(eq_numbers_string);
        eq_numbers.clear();

        while (getline(stream, eq_number_string, ' ')){
            eq_numbers.push_back(stoi(eq_number_string));
        }
            
        initOperations();
        
        for(int i = 0; i < pow(2, (eq_numbers.size() - 1)); i++){

            op_result = tryOperations();
            
            if(op_result == eq_result){
                result += eq_result;
                break;
            }

            newOperations(i + 1);
            
        }
    }
    
    out << "Result: " << result << endl;
    out << "Time taken: " <<  (double)(clock() - tStart)/CLOCKS_PER_SEC << "s";
    
    in.close();
    out.close();

    return 0;
}