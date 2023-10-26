#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void getData(ifstream &inputFile, vector<string> &lines)
{
    string line;

    while (getline(inputFile, line))
    {
        lines.push_back(line);
    }
}

bool checkparas(vector<string> &paras, string cpara)
{
    if (paras[paras.size() - 1] == "/*") {
        if (cpara == "*/") {
            paras.pop_back();
        }
        return true;
    }
    if (cpara == "{" || cpara == "(" || cpara == "[")
    {
        paras.push_back(cpara);
        return true;
    }
    if (cpara == "}")
    {
        if (paras[paras.size() - 1] == "{")
        {
            paras.pop_back();
            return true;
        }
        else
        {
            return false;
        }
    }
    if (cpara == ")")
    {
        if (paras[paras.size() - 1] == "(")
        {
            paras.pop_back();
            return true;
        }
        else
        {
            return false;
        }
    }
    if (cpara == "]")
    {
        if (paras[paras.size() - 1] == "{")
        {
            paras.pop_back();
            return true;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    string file;
    vector<string> lines;
    vector<string> parts;
    vector<string> paras;
    bool valid = true;
    if (argc > 1)
    {
        file = argv[1];
    }
    else
    {
        cerr << "No arguments provided." << endl;
        return 2;
    }

    ifstream inputFile(file);

    if (!inputFile.is_open())
    {
        cerr << "Failed to open the file." << endl;
        return 1; // or some other error code
    }

    getData(inputFile, lines);
    for (unsigned int i = 0; i < lines.size(); i++)
    {
        string currentline = lines[i];
        if (currentline.substr(0, 2) != "//")
        {
            for (unsigned int j = 0; j < currentline.length(); j++)
            {
                string cchar = "";
                if (j < currentline.length()-1 && currentline.substr(j, 2) == "/*") {
                    cchar = "/*";
                } else {
                    cchar = currentline.substr(j, 1);
                    valid = checkparas(paras, cchar);
                    if (valid == false) {
                        cout<<"invalid"<<endl;
                        return 0;
                    }
                    
                }
            }
        }
    }
    if (paras.size() != 0)
    {
        cout << "invalid" << endl;
        return 0;
    }
    cout << "valid" << endl;
    return 0;
}