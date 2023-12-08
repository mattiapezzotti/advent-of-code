#include <bits/stdc++.h>

using namespace std;

#define MAXN 9999

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string val){
        name = val;
        left = NULL;
        right = NULL;
    }

    Node(){ }
};

vector<Node*> graph;

int findNode(string name){

    for(int i = 0 ; i < graph.size(); i++)
        if(graph[i]->name == name)
            return i;

    return -1;
}

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;
    Node* node = new Node();

    string movements;
    getline(inputFile, movements);

    //emptyLine
    getline(inputFile, line);

    int i = 0;
    int charSize = 3;
    int startPos = 0;

    int nodePosition = 0;
    int leftNodePosition = 0;
    int rightNodePosition = 0;
    string leftNodeName;
    string rightNodeName;
    string nodeName;


    while (getline(inputFile, line)) {
        // ROOT
        nodeName = line.substr(0, charSize);

        nodePosition = findNode(nodeName);

        if(nodePosition == -1){
            node = new Node(nodeName);
            graph.push_back(node);
        }
        else{
            node = graph[nodePosition];
        }

        // LEFT

        leftNodeName = line.substr(line.find('(') + 1, charSize);
        leftNodePosition = findNode(leftNodeName);

        if(leftNodePosition == -1){
            node->left = new Node(leftNodeName);
            graph.push_back(node->left);
        }
        else{
            node->left = graph[leftNodePosition];
        }

        // RIGHT

        rightNodeName = line.substr(line.find(',') + 2, charSize);
        rightNodePosition = findNode(rightNodeName);

        if(rightNodePosition == -1){
            node->right = new Node(rightNodeName);
            graph.push_back(node->right);
        }
        else{
            node->right = graph[rightNodePosition];
        }
    }
    
    Node* currentNode = graph[findNode("AAA")];
    bool found = false;

    do{
        for(i = 0; i < movements.length(); i++){
            //cout << currentNode->name << " - ";
            result++;
                
            if(movements[i] == 'L'){
                if(currentNode->left->name == "ZZZ"){
                    found = true;
                    break;
                }
                //cout << "L " << currentNode->left->name << endl;
                currentNode = currentNode->left;
            }
            if(movements[i] == 'R'){
                if(currentNode->right->name == "ZZZ"){
                    found = true;
                    break;
                }
                //cout << "R " << currentNode->right->name << endl;
                currentNode = currentNode->right;
            }
        }
    }while(!found);
    
    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}