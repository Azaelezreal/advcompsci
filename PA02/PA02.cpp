#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    ifstream myfile; myfile.open("PA02SampleFile.txt");
    string mystring;
    if ( myfile.is_open() ) { // always check whether the file is open
        myfile >> mystring; // pipe file's content into stream
        std::cout << mystring; // pipe stream's content to standard output
    }
    return 0;
}