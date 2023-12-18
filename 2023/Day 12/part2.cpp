#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

vector<int> spring;
vector<string> groups;

long long int findIsolatedOnsen(string line, int length){
    long long int start = 0;
    long long int count = 0;
    long long int hashpos = line.find('#');

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

long long int countHash(string line){
    long long int hash = 0;
    for(auto c : line)
        if(c == '#')
            hash++;
    return hash;
}

long long int countQuestion(string line){
    long long int q = 0;
    for(auto c : line)
        if(c == '?')
            q++;
    return q;
}

long long int sumVet(vector<int> length){
    long long int sum = 0;
    for(auto n : length)
        sum += n;
    return sum;
}

void cutDots(string &line){
    long long int dotStreak = 0;
    for(int i = 0; i < line.length(); i++){
        if(line[i] == '.')
            dotStreak++;
        else dotStreak = 0;
        if(dotStreak > 2)
            line.erase(i, 1);
    }
}

void getGroups(string &line){
    int dotStreak = 0;
    int start = 0;
    for(int i = 0; i < line.length(); i++){
        if(line[i] == '.')
            dotStreak++;
        else dotStreak = 0;
        if(dotStreak >= 2){
            groups.push_back(line.substr(start,i));
            start = i;
        }
    }
}



long long int checkOnsen(string line, vector<int> length){
    long long int start = 0;
    long long int count = 0;
    long long int hashpos = 0;
    long long int prec_hashpos = 0;
    long long int missingpos = line.find('?');
    
    long long int hashCount = countHash(line);
    long long int qCount = countQuestion(line);
    long long int vetSum = sumVet(length);

    if(qCount + hashCount < vetSum)
        return 0;

    if(hashCount > vetSum)
        return 0;

    if(missingpos == string::npos){

        if(vetSum != hashCount)
            return 0;

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
    inputFile.open ("dummyinput.txt");
    string line;
    string onsen;
    string numbers;

    string firstOnsen;
    string firstNumbers;

    int commapos;
    int start;

    for (int i = 0; getline(inputFile, line); i++) {
        spring.clear();
        firstOnsen = line.substr(0, line.find(' '));
        firstNumbers = line.substr(line.find(' ') + 1, line.length());

        onsen = firstOnsen;
        numbers = firstNumbers;

        for(int j = 0; j < 4; j++){
            onsen += '?' + firstOnsen;
            numbers += ',' + firstNumbers;

            cout << onsen << endl;
            cout << numbers << endl;
        }
        

        commapos = numbers.find(',');
        start = 0;
        cutDots(onsen);

        getGroups(onsen);

        for(auto g : groups)
            while(commapos != string::npos){
                spring.push_back(stoi(numbers.substr(start, commapos)));
                start = commapos + 1;
                commapos = numbers.find(',', start);
            }

        spring.push_back(stoi(numbers.substr(start)));
        start = commapos + 1;
        commapos = numbers.find(',', start);

        result += checkOnsen(onsen, spring);
        cout << result << endl;
        //cout << endl;
    }
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}