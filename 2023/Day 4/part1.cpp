#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

long long int result = 0;
long long int cardPoints = 0;
int winningNumbers[MAXN];
string winningNumbersS, myNumbersS;
string numberS;
int number;

void clear(){
    cardPoints = 0;
    numberS = "";
    for(int i=0; i<MAXN; i++){
        winningNumbers[i] = 0;
    }
}

int main(){
    ifstream inputFile;
    inputFile.open ("input.txt");

    for (string line; getline(inputFile, line); ) {
        line = line.substr(line.find(":") + 2, line.length());

        clear();

        size_t pos = line.find("|");

        winningNumbersS = line.substr(0, pos);
        myNumbersS = line.substr(pos + 2, line.length());

        for(int i = 0; i < winningNumbersS.length(); i += 3){
            numberS = "";
            if(winningNumbersS[i] != ' '){
                numberS += winningNumbersS[i];
                numberS += winningNumbersS[i+1];
            }
            else numberS = winningNumbersS[i+1];

            number = stoi(numberS);
            winningNumbers[number] = 1;
        }

        for(int i = 0; i < myNumbersS.length(); i += 3){
            numberS = "";
            if(myNumbersS[i] != ' '){
                numberS += myNumbersS[i];
                numberS += myNumbersS[i+1];
            }
                
            else numberS = myNumbersS[i+1];

            number = stoi(numberS);

            if(winningNumbers[number] == 1){
                cardPoints++;
            }
        }
        cardPoints = pow(2, cardPoints-1);
        if(cardPoints > 0)
            result += cardPoints;
    }
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}