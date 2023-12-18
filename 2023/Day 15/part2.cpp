#include <bits/stdc++.h>

using namespace std;

#define MAXN 256

struct Lens{
    string label;
    int focal;
};

vector<vector<Lens>> boxes(MAXN);

int decodeHASH(string line){
    int box = 0;

    for(int c : line){
        box += c;
        box *= 17;
        box %= 256;
    }

    return box;
}

int findLens(Lens lens, int box){
    for(int i = 0; i < boxes[box].size(); i++)
        if(boxes[box][i].label == lens.label)
            return i;
    return -1;
}

void removeLens(Lens lens, int box){
    for(int i = 0; i < boxes[box].size(); i++)
        if(boxes[box][i].label == lens.label)
            boxes[box].erase(boxes[box].begin() + i);
}

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;
    string stepString;
    string label;
    getline(inputFile, line);

    string delimiter = ",";
    int pos = 0;
    int box = 0;
    int index = 0;
    string focal;
    Lens lens;

    line += ",";

    while ((pos = line.find(delimiter)) != string::npos) {
        stepString = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());

        pos = stepString.find('-');
        if(pos == string::npos)
            pos = stepString.find('=');

        label = stepString.substr(0, pos);
        if(pos + 1 < stepString.length())
            focal = stepString.substr(pos + 1, stepString.length());
        else focal = "";

        box = decodeHASH(label);

        if(focal != "")
            lens.focal = stoi(focal);
        lens.label = label;

        if(stepString[pos] == '='){
            index = findLens(lens, box);
            if(index == -1)
                boxes[box].push_back(lens);
            else boxes[box][index] = lens;
        }
        else{
            removeLens(lens, box);
        }
    }
    /*
    for(int j = 0; j < 5; j++){
            cout << j << " ";
            for(int i = 0; i < boxes[j].size(); i++)
                cout << boxes[j][i].label << " " << boxes[j][i].focal << " ";
            cout << endl;
    }
    cout << endl;
    */
    int power = 1;
    for(int j = 0; j < MAXN; j++){
        for(int i = 0; i < boxes[j].size(); i++){
            power = j + 1;
            power *= i + 1 ;
            power *= boxes[j][i].focal;
            result += power;
        }
    }

    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}