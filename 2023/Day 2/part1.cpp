#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

//12 red cubes, 13 green cubes, and 14 blue cubes
int maxCubes[3] = {12,13,14};
string cubeNames[3] = {"red", "green", "blue"};
int foundCube[3];
int maxFoundCubes[3];
int gameNumber = 0;

int foundCubes(string word, string color){
    size_t pos = 0;
    string cubes = "0";
    size_t commaPos = 0;

    if((pos = word.find(color)) != std::string::npos){
        word = word.substr(0, pos);
        commaPos = word.find_last_of(",");
        cubes = word.substr(commaPos + 1, pos - 1);
    }

    return stoi(cubes);
}

string workLine(string line){

    line += ";";
    size_t pos = line.find(":");
    line = "," + line.substr(pos + 2, line.length());

    return line;
}

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");

    string line;
    string word;
    string delimiter = ";";
    size_t pos = 0;
    bool validGame;
    
    // Game
    for (string line; getline(inputFile, line); ) {
        line = workLine(line);

        gameNumber++;
        result+=gameNumber;
        validGame = true;

        for(int i = 0; i < 3; i++){
            maxFoundCubes[i] = 0;
        }

        // Estrazione cubi
        while (size_t pos = line.find(":")) {

            word = line.substr(0, pos);
            line.erase(0, pos + delimiter.length() + 1);
            
            for(int i = 0; i < 3; i++){
                foundCube[i] = 0;
            }

            for(int i = 0; i < 3; i++){
                foundCube[i] = foundCubes(word, cubeNames[i]);
                if(foundCube[i] > maxFoundCubes[i])
                    maxFoundCubes[i] = foundCube[i];
            }

            for(int i = 0; i < 3 && validGame; i++){
                if(maxFoundCubes[i] > maxCubes[i]){
                    result -= gameNumber;
                    validGame = false;
                }
            }

            if(!validGame){
                break;
            }
        }
    }
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}