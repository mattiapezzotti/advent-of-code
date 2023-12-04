#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

long long int result = 0;
long long int cardPoints = 0;
int winningNumbers[MAXN], copies[MAXN];
string winningNumbersS, myNumbersS;
string numberS;
int number, cardNumber = 0;

void clear(){
    cardPoints = 0;
    numberS = "";
    for(int i=0; i<MAXN; i++){
        winningNumbers[i] = 0;
    }
}

void initCopies(){
    for(int i=0; i<MAXN; i++){
        copies[i] = 0;
    }
    
}

int main(){
    cardNumber = 0;
    ifstream inputFile;
    inputFile.open ("input.txt");

    initCopies();

    for (string line; getline(inputFile, line); ) {
        cardNumber++;
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

        for(int i = cardNumber + 1; i <= (cardNumber + cardPoints); i++){
            copies[i]++;
            if(copies[i-1] != 0)
                copies[i] += copies[cardNumber];
        }
    }

    for(int i=1; i<cardNumber; i++){
        result += copies[i];
    }

    result += cardNumber;
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}