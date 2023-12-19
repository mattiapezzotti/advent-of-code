#include <bits/stdc++.h>

using namespace std;

#define MAXN 999

ofstream outputFile("output.txt");

struct Workflow{
    string name;
    string work;
};

vector<Workflow> workflows;
vector<string> steps;

string trim(string line){
    int pos = line.find("  ");
    while(pos != string::npos){
        line = line.erase(pos, 1);
        pos = line.find("  ");
    }
    return line;
}

string invertStep(string step){
    int num;
    if(step.find('>') != string::npos){
        num = stoi(step.substr(step.find('>') + 1, step.length()));
        num++;
        step = step.substr(0, step.find('>') + 1) + to_string(num);
        replace(step.begin(), step.end(), '>', '<');
        
    }
    else{
        num = stoi(step.substr(step.find('<') + 1, step.length()));
        num--;
        step = step.substr(0, step.find('<') + 1) + to_string(num);
        replace(step.begin(), step.end(), '<', '>');
    }
    return step;
}

long long int getCombination(string step){
    //cout << step << endl;
    long long int comb = 1;
    int maggioreDi, minoreDi, maggioreDiPos, minoreDiPos;
    int currentPos, currentNum;
    string xmas = "xmas";

    for(auto c : xmas){
        maggioreDi = 0;
        minoreDi = 4001;
        //cout << c << " ";

        currentPos = step.find(c);
        while(currentPos != string::npos){
            currentNum = stoi(step.substr(currentPos + 2, step.find(" ", currentPos) - currentPos - 2));
            if (step[currentPos + 1] == '<'){
                minoreDiPos = currentPos;
                minoreDi = min(minoreDi, currentNum);
            }
            else{
                maggioreDiPos = currentPos;
                maggioreDi = max(maggioreDi, currentNum);
            }
            currentPos = step.find(c, currentPos + 1);
        }

        if(maggioreDi == 0 && minoreDi == 4000){
            cout << "4000" << endl;
            comb *= 4000;
        }
        else{
            //cout << max(maggioreDi, minoreDi) - min(maggioreDi, minoreDi) - 1 << endl;
            comb *= max(maggioreDi, minoreDi) - min(maggioreDi, minoreDi) - 1;
        }
    }
    return comb;
}

void workPart(string workflowName, string currentSteps){
    if(workflowName == "A"){
        steps.push_back(currentSteps);
        return;
    }
    
    if(workflowName == "R")
        return;

    Workflow currentWorkflow;
    for(auto w : workflows){
        if (w.name == workflowName){
            currentWorkflow = w;
            break;
        }
    }

    //outputFile << currentWorkflow.work << endl;

    int commaPos = currentWorkflow.work.find(',');
    string step;
    string nextWorkflow;

    while(commaPos != string::npos){
        step = currentWorkflow.work.substr(0, currentWorkflow.work.find(':'));
        nextWorkflow = currentWorkflow.work.substr(currentWorkflow.work.find(':') + 1, commaPos - currentWorkflow.work.find(':') - 1);
        workPart(nextWorkflow, currentSteps + step + " ");
        currentSteps += invertStep(step) + " ";
        
        currentWorkflow.work = currentWorkflow.work.erase(0, commaPos + 1);
        commaPos = currentWorkflow.work.find(',');
    }
    //cout << currentWorkflow.work << " " << currentSteps << endl;
    workPart(currentWorkflow.work, currentSteps + " ");
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
            break;
        }
        workflow.name = line.substr(0,line.find('{'));
        line = line.erase(0,line.find('{') + 1);
        line = line.erase(line.length() - 1, 1);
        workflow.work = line;
        workflows.push_back(workflow);
    }

    workPart("in", "");

    for(auto s : steps){
        s = trim(s);
        result += getCombination(s);
    }


    cout << "Result: " << result << endl;
    inputFile.close();
    return 0;
}