#include <json.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;



int main(int argc, char const *argv[]) {
    json::JSON obj;
    if (argc < 3) {
        cerr<<"not enough arguments"<<endl;
        return 1;
    }
    string filename = argv[1];
    
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Unable to open the file."<<endl;
        return 3;
    }
    string line;
    
    string stringOfAllData;
    //char* data = new char[10];

    while (getline(inputFile, line)) {
        stringOfAllData += line + "\n";
    }
    string output = argv[1];
    ofstream outputFile(output);
    string command = argv[2];
    if (command == "add") {
        string fname;
        if (argc > 5) {
            fname = argv[3];
        } else {
            cerr<<"not enough arguments"<<endl;
            return 1;
        }
        string lname = argv[4];
        string email = argv[5];
        //obj["firstName"] = fname;
        //obj["lastName"] = lname;
        json::JSON newp;
        newp["firstName"] = fname;
        newp["lastName"] = lname;
        newp["email"] = email;
        bool duplicate = false;
        for (unsigned int i = 0; i < obj.size(); i++) {
            if (obj[i]["email"].ToString() == email) {
                duplicate = true;
            }
        }
        if (duplicate) {
            cout<<"Person already in queue"<<endl;
        }
        else {
            obj.append(newp);
            outputFile<<obj;
        }
    }
    else if (command == "remove") {
        if (obj.size()==0) {
            outputFile<<"null";
        } else {
            json::JSON next = json::JSON(json::Array());
            for (unsigned int i = 1; i<obj.size(); i++) {
                next.append(obj[i]);
            }
            outputFile<<obj;
        }
        
    }
    else if (command == "clear") {
        stringOfAllData = "null";
        outputFile<<stringOfAllData;
    }
    else {
        cerr<<"not an acceptable command"<<endl;
        return 2;
    }
}
