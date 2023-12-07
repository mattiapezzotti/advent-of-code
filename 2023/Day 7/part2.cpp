#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000

int cardValue[MAXN]; 
int handCards[MAXN];

struct Hand
{
    string cards;
    int bid;
    int power;
};

struct SortCards
{
    inline bool operator() (const Hand& hand1, const Hand& hand2)
    {
        if(hand1.power != hand2.power)
            return (hand1.power < hand2.power);

        for(int i = 0; i < 5; i++){
            if(hand1.cards[i] != hand2.cards[i])
                return cardValue[hand1.cards[i]] < cardValue[hand2.cards[i]];
        }
    }
};

vector<Hand> hands;

void printHand(Hand h){
    cout << h.cards << " " << h.bid << " " << h.power << endl;
}

void initCardValue(){
    cardValue['A'] = 13;
    cardValue['K'] = 12;
    cardValue['Q'] = 11;
    cardValue['T'] = 10;
    cardValue['9'] = 9;
    cardValue['8'] = 8;
    cardValue['7'] = 7;
    cardValue['6'] = 6;
    cardValue['5'] = 5;
    cardValue['4'] = 4;
    cardValue['3'] = 3;
    cardValue['2'] = 2;
    cardValue['J'] = 1;
}

int handPower(string hand){
    bool three = false;
    bool two = false;
    bool doubleTwo = false;
    bool four = false;

    for(int i = 0; i < MAXN; i++){
        handCards[i] = 0;
    }

    int maxCardI = 2;
    int maxCardValue = 0;

    for(int i = 0; i < 5; i++){
        handCards[cardValue[hand[i]]]++;
    }
    
    for(int i = 2; i < 14; i++)
        if(handCards[i] > maxCardValue){
            maxCardValue = handCards[i];
            maxCardI = i;
        }

    handCards[maxCardI] += handCards[1];

    for(int i = 2; i < 14; i++){
        if(handCards[i] == 5)
            return 7;

        if(handCards[i] == 4)
            return 6;

        if(handCards[i] == 3)
            three = true;

        if(handCards[i] == 2 && two)
            doubleTwo = true;

        if(handCards[i] == 2)
            two = true;
    }

    if(three && two)
        return 5;

    if(three)
        return 4;

    if(doubleTwo)
        return 3;

    if(two)
        return 2;

    return 1;
}

int main(){
    long long int result = 0;

    initCardValue();

    string cards;
    int bid;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;
    size_t whitespace;
    Hand hand;

    for (string line; getline(inputFile, line); ) {
        whitespace = line.find(" ");
        cards = line.substr(0, whitespace);
        bid = stoi(line.substr(whitespace + 1, line.length()));
    
        hand.bid = bid;
        hand.cards = cards;
        hand.power = handPower(cards);

        hands.push_back(hand);
    }

    sort(hands.begin(), hands.end(), SortCards());

    int rank = 1;

    for(Hand h : hands){
        result += h.bid * rank;
        rank++;
    }

    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}