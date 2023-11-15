#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

void getData(ifstream &inputFile, vector<string> &lines){
    string line;

    while (getline(inputFile, line)) {
        lines.push_back(line);
    }
}

bool isValid(stack<string> &paras, string cpara) {
    if (paras.size() > 0 && paras.top() == "/*") {
        if (cpara == "*/") {
            paras.pop();
        }
        return true;
    }
    if (cpara == "{" || cpara == "(" || cpara == "[" || cpara == "/*") {
        paras.push(cpara);
        return true;
    }
    if (cpara == "}") {
        if (paras.size() > 0 && paras.top() == "{") {
            paras.pop();
            return true;
        }
        else {
            return false;
        }
    }
    if (cpara == ")") {
        if (paras.size() > 0 && paras.top() == "(") {
            paras.pop();
            return true;
        }
        else {
            return false;
        }
    }
    if (cpara == "]") {
        if (paras.size() > 0 && paras.top() == "[") {
            paras.pop();
            return true;
        }
        else {
            return false;
        }
    }
    if (cpara == "*/") {
            return false;
        }
    return true;
}

int main(int argc, char const *argv[]){
    string file;
    vector<string> lines;
    vector<string> parts;
    stack<string> paras;
    bool valid = true;
    bool inComment = false;
    if (argc > 1) {
        file = argv[1];
    }
    else {
        cerr << "No arguments provided." << endl;
        return 2;
    }

    ifstream inputFile(file);

    if (!inputFile.is_open()) {
        cerr << "Failed to open the file." << endl;
        return 1; // or some other error code
    }

    getData(inputFile, lines);
    for (unsigned int i = 0; i < lines.size(); i++) {
        string currentline = lines[i];
        if (currentline.size() > 0) {
            for (unsigned int j = 0; j < currentline.length(); j++) {
                string cchar = currentline.substr(j, 1);
                if (j < currentline.length()-1) {
                    if (currentline.substr(j, 2) == "/*") {
                        cchar = "/*";
                        inComment = true;
                    }
                    if (currentline.substr(j, 2) == "*/") {
                        cchar = "*/";
                        inComment = false;
                    }
                    if (!inComment && currentline.substr(j, 2) == "//") {
                        inComment = false;
                        break;
                    }
                }
                valid = isValid(paras, cchar);
                if (valid == false) {
                    cout<<"invalid"<<endl;
                    return 0;
                }
            }
        }
    }
    if (paras.size() != 0) {
        cout << "invalid" << endl;
        return 0;
    }
    cout << "valid" << endl;
    return 0;
}