#include <bits/stdc++.h>

using namespace std;

#define MAXN 999

ofstream outputFile("output.txt");

struct Workflow{
    string name;
    string work;
};

vector<Workflow> workflows;
int parts[MAXN][MAXN];

void printAll(int l){
    for(auto w : workflows ){
        cout << w.name << " ";
        cout << w.work << endl;
    }

    cout << endl;

    for(int i = 0; i < l; i++){
        cout << parts[i]['x'] << " ";
        cout << parts[i]['m'] << " ";
        cout << parts[i]['a'] << " ";
        cout << parts[i]['s'] << " " << endl;
    }
}

bool workPart(string workflowName, int i){

    //outputFile << workflowName << endl;

    if(workflowName == "A")
        return true;
    
    if(workflowName == "R")
        return false;

    Workflow currentWorkflow;
    for(auto w : workflows){
        if (w.name == workflowName){
            currentWorkflow = w;
            break;
        }
    }

    outputFile << currentWorkflow.work << endl;

    int commaPos = currentWorkflow.work.find(',');
    int currentPart;
    int currentThreshold;
    string whereToNextIfTrue;

    while(commaPos != string::npos){
        currentPart = currentWorkflow.work[0];
        currentThreshold = stoi(currentWorkflow.work.substr(2, currentWorkflow.work.find(':') - 2));

        if(currentWorkflow.work[1] == '<'){
            if(parts[i][currentPart] < currentThreshold)
                return workPart(currentWorkflow.work.substr(currentWorkflow.work.find(':') + 1, commaPos - 1 - currentWorkflow.work.find(':')), i);
        }
        else{
            if(parts[i][currentPart] > currentThreshold)
                return workPart(currentWorkflow.work.substr(currentWorkflow.work.find(':') + 1, commaPos - 1 - currentWorkflow.work.find(':')), i);
        }

        currentWorkflow.work = currentWorkflow.work.erase(0, commaPos + 1);
        commaPos = currentWorkflow.work.find(',');
    }

    return workPart(currentWorkflow.work, i);
}

int sumPart(int i){
    return parts[i]['x'] + parts[i]['m'] + parts[i]['a'] + parts[i]['s'];
}

int main(){
    long long int result = 0;

    ifstream inputFile;
    inputFile.open ("input.txt");
    string line;
    Workflow workflow;
    int l = 0;
    bool blankSpaceFound = 0;

    while (getline(inputFile, line)) {
        if(line.empty()){
            blankSpaceFound = true;
            continue;
        }

        if(!blankSpaceFound){
            workflow.name = line.substr(0,line.find('{'));
            line = line.erase(0,line.find('{') + 1);
            line = line.erase(line.length() - 1, 1);
            workflow.work = line;
            workflows.push_back(workflow);
        }
        else{
            line = line.erase(0,1);
            line = line.erase(line.length() - 1, 1);
            line += ',';
            int commaPos = line.find(',');
            while(commaPos != string::npos){
                parts[l][line[0]] = stoi(line.substr(line.find("=") + 1, commaPos - 2));
                line = line.erase(0, commaPos + 1);
                commaPos = line.find(',');
            }
            l++;
        } 
    }

    for(int i = 0; i < l; i++){
        if(workPart("in", i)){
            result += sumPart(i);
        }
    }
    //printAll(l);

    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}