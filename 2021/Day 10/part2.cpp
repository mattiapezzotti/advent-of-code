#include <bits/stdc++.h>

using namespace std;

#define MAXN 1001

stack<char> expected;
vector<long long int> points;
long long int error = 0, score = 0;

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;

    if (inputFile.is_open()) {
        while(!inputFile.eof()){
            inputFile >> line;
            error = 0;
            score = 0;
            for(int i = 0; i < line.length(); i++){
                switch (line.at(i))
                {
                case '(':
                    expected.push(')');
                    break;
                case '[':
                    expected.push(']');
                    break;
                case '{':
                    expected.push('}');
                    break;
                case '<':
                    expected.push('>');
                    break;
                ////////////
                case ')':
                    if(expected.top() == ')')
                        expected.pop();
                    else error = 1;
                    break;
                case ']':
                    if(expected.top() == ']')
                        expected.pop();
                    else error = 1;
                    break;
                case '}':
                    if(expected.top() == '}')
                        expected.pop();
                    else error = 1;
                    break;
                case '>':
                    if(expected.top() == '>')
                        expected.pop();
                    else error = 1;
                    break;
                
                default:
                    break;
                }
            }

            if(error != 1){
                while(!expected.empty()){
                    score*=5;
                    switch(expected.top()){
                        case ')':
                            score += 1;
                            break;
                        case ']':
                            score += 2;
                            break;
                        case '}':
                            score += 3;
                            break;
                        case '>':
                            score += 4;
                            break;
                    }
                    expected.pop();
                }
                points.push_back(score);
            }
            else{
                while(!expected.empty()){
                    expected.pop();
                }
            }
        }
        sort(points.begin(), points.end());

        result = points.at(points.size()/2);
    }
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}