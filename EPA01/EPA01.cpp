#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class FileProcessor {
public:
    void processFile(const std::string& filename) {
        // Open the file for reading
        std::ifstream inputFile(filename);

        // Check if the file was opened successfully
        if (!inputFile.is_open()) {
            std::cerr << "Could not open the file: " << filename << std::endl;
            return;
        }

        // Read and process data from the file
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << "Read from file: " << line << std::endl;
            // Process the data as needed
        }

        // Close the file
        inputFile.close();
    }
};

int main() {
    FileProcessor processor;
    std::string filename = "example.txt"; // Change this to your file's name
    processor.processFile(filename);

    return 0;
}

class MyClass {
public:
    // Member function declaration
    void add(const std::string& filename) {
        // Open the file for reading
        std::ifstream inputFile(filename);

        // Check if the file was opened successfully
        if (!inputFile.is_open()) {
            std::cerr << "Could not open the file: " << filename << std::endl;
            return;
        }

        // Read and process data from the file
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << "Read from file: " << line << std::endl;
            // Process the data as needed
        }

        // Close the file
        inputFile.close();
        
    }

    void find(const std::string& filename) {

    }

};

int main(int argc, char const *argv[]) {
    vector<string> firstname;
    vector<string> lastname;
    vector<int> age;
    vector<string> instagram;
    vector<string> twitter;
    vector<int> phone;
    vector<string> email;

    add(argv[1]);

}