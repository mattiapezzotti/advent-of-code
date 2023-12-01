#include <bits/stdc++.h>

using namespace std;

#define MAXN 1001

int point[4] = {3, 57, 1197, 25137};
stack<char> expected;
int error = -1;

int main(){
    int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;

    if (inputFile.is_open()) {
        while(!inputFile.eof()){
            inputFile >> line;
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
                    else error = 0;
                    break;
                case ']':
                    if(expected.top() == ']')
                        expected.pop();
                    else error = 1;
                    break;
                case '}':
                    if(expected.top() == '}')
                        expected.pop();
                    else error = 2;
                    break;
                case '>':
                    if(expected.top() == '>')
                        expected.pop();
                    else error = 3;
                    break;
                
                default:
                    break;
                }

                if(error != -1){
                    result += point[error];
                    error = -1;
                    break;
                }
            }
        }
    }
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}