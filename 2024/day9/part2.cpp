#include <bits/stdc++.h>

using namespace std;

#define MAXN 99999

ifstream in;
ofstream out;
long long int result = 0;

vector<int> newLine;

int currentId = 0;
int currentNumber;
int spaces = false;
int nextPoint;

struct section{
    int id;
    int length;
    int startIndex;
    bool isPoint;
};

vector<section> sections;

int main(){
    clock_t tStart = clock();

    ifstream in;
    in.open ("input.txt");
    out.open("output.txt");
    string line;
    int indexSum = 0;
    

    while (getline(in, line)) {
        section dummy;
        for(int i = 0; i < line.length(); i++){
            currentNumber = line[i] - '0';
            dummy.startIndex = indexSum;
            dummy.id = currentId;
            indexSum += currentNumber;

            if(!spaces){
                for(int j = 0; j < currentNumber; j++)
                    newLine.push_back(currentId);
                currentId++;
            }
            else{
                for(int i = 0; i < currentNumber; i++)
                    newLine.push_back(-1);
            }

            dummy.length = currentNumber;
            dummy.isPoint = spaces; 
            sections.push_back(dummy); 
            spaces = !spaces;
    
        }
    }
    
    for(int i = 0; i < sections.size() - 1; i++){
        if(sections[i].isPoint){
            for(int j = sections.size() - 1; j > i; j--){
                if(!sections[j].isPoint){
                    if(sections[j].length <= sections[i].length){
                       for(int x = 0; x < sections[j].length; x++){
                            newLine[sections[i].startIndex + x] = sections[j].id;
                            newLine[sections[j].startIndex + x] = -1;
                       }
                       sections[i].length -= sections[j].length;
                       sections[j].isPoint = true;
                       sections[i].startIndex += sections[j].length;
                       i--; 
                       break;
                    }
                }
            }
        }
    }

    for(int i = 0; i < newLine.size(); i++){
        if(newLine[i] > 0)
            result += (newLine[i] * i);
    }

    out << "Result: " << result << endl;
    out << "Time taken: " <<  (double)(clock() - tStart)/CLOCKS_PER_SEC << "s";
    
    in.close();
    out.close();

    return 0;
}