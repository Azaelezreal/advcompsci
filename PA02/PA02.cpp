#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    vector<int> count(10, 0);
    string file;
    if (argc > 1) {
        // Print the first argument
        file = argv[1];
    } else {
        cerr<< "No arguments provided." <<endl;
        return 2;
    }

    std::ifstream inputFile(file);

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1; // or some other error code
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        count[stoi(line)]++;
    }
    inputFile.close();
    
    for (unsigned int i = 0; i<10; i++) {
        cout<<i<<" "<<count.at(i)<<endl;
    }

    return 0;
}