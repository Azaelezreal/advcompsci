#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    string file;
    if (argc > 1) {
        file = argv[1];
    } else {
        cerr<< "No arguments provided." <<endl;
        return 2;
    }

    ifstream inputFile(file);

    if (!inputFile.is_open()) {
        cerr << "Failed to open the file." <<endl;
        return 1; // or some other error code
    }
    string line;
    while (getline(inputFile, line)) {
        
    }
    inputFile.close();
}