#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

long long int result = 0;
vector<long long int> input;
vector<long long int> mapping;
vector<long long int> results;

long long int findCorrisponding(long long int destination, long long int source, long long int range, long long int input){
    if(input < source || input >= source + range)
        return input;
    
    return destination + (input - source);

}

int main(){
    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;

    getline(inputFile, line);
    line = line.substr(line.find(":") + 2, line.length());

    stringstream iss(line);

    long long int number;
    while ( iss >> number ){
        results.push_back( number );
    }

    while(getline(inputFile, line)) {
        if(line.find(":") == std::string::npos && !line.empty()){
            mapping.clear();
            stringstream iss(line);
            while ( iss >> number ){
                mapping.push_back( number );
            }

            for(int i=0; i<input.size(); i++){
                number = findCorrisponding(mapping.at(0), mapping.at(1), mapping.at(2), input.at(i));
                if(number != input.at(i)){
                    results.at(i) = number; 
                }
            }
        }
        else{
            input = results;
        }
    }

    result = input.at(1);

    for(long long int n : results){
        if(n < result)
            result = n;
    }
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}