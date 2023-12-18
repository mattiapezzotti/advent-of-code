#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

vector<int> spring;

int findIsolatedOnsen(string line, int length){
    int start = 0;
    int count = 0;
    int hashpos = line.find('#');

    while(hashpos != string::npos){
        count = 0;

        for(int i = hashpos; line[i] == '#'; i++){
            if(line[i] == '#')
                count++;
        }
        if(count == length)
            return hashpos;

        start = hashpos + 1 + count;

        hashpos = line.find('#', start);
    }

    return hashpos;
}

int checkOnsen(string line, vector<int> length){
    int start = 0;
    int count = 0;
    int hashpos = 0;
    int prec_hashpos = 0;
    int missingpos = line.find('?');


    if(missingpos == string::npos){
        //cout << line << " ";
        for(auto l : length){
            hashpos = findIsolatedOnsen(line, l);
            if(hashpos == string::npos || prec_hashpos > hashpos){
                //cout << "0" << endl;
                return 0;
            }
            prec_hashpos = hashpos;
            line.erase(hashpos, l);
        }
        if(line.find('#') == string::npos){
            //cout << "1" << endl;
            return 1;
        }
        return 0;
    }

    line[missingpos] = '.';
    count += checkOnsen(line, length);
    line[missingpos] = '#';
    count += checkOnsen(line, length);

    return count;
}

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;
    string onsen;
    string numbers;

    int commapos;
    int start;

    for (int i = 0; getline(inputFile, line); i++) {
        spring.clear();
        onsen = line.substr(0, line.find(' '));
        numbers = line.substr(line.find(' ') + 1, line.length());

        commapos = numbers.find(',');
        start = 0;

        while(commapos != string::npos){
            spring.push_back(stoi(numbers.substr(start, commapos)));
            start = commapos + 1;
            commapos = numbers.find(',', start);
        }

        spring.push_back(stoi(numbers.substr(start)));
        start = commapos + 1;
        commapos = numbers.find(',', start);

        result += checkOnsen(onsen, spring);
        //cout << endl;
    }
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}