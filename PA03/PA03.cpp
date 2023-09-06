#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void getData(ifstream& inputFile, vector<string>& lines) {
    string line;
    
    while (getline(inputFile, line)) {
        lines.push_back(line);
    }
}

void split(const string& str, const string& delim, vector<string>& parts) {
  size_t start, end = 0;
  while (end < str.size()) {
    start = end;
    while (start < str.size() && (delim.find(str[start]) != string::npos)) {
      start++;  // skip initial whitespace
    }
    end = start;
    while (end < str.size() && (delim.find(str[end]) == string::npos)) {
      end++; // skip to end of word
    }
    if (end-start != 0) {  // just ignore zero-length strings.
      parts.push_back(string(str, start, end-start));
    }
  }
}

string calculateGrade (int x) {
    if (x >= 90) {
        return "A";
    }
    if (x >= 80) {
        return "B";
    }
    if (x>= 70) {
        return "C";
    }
    if (x>=60) {
        return "D";
    }
    return "F";
}

void writeData(vector<string> lines, vector<string> grades, ofstream& outputFile) {
    for (unsigned int i = 0; i< lines.size(); i++) {
        outputFile<<lines[i]<<" "<<grades[i]<<endl;
    }
}

void highestScore (vector<int> scores) {
    int high = scores[0];
    for (unsigned int i = 0; i< scores.size(); i++) {
        if (scores[i]>high) {
            high = scores[i];
        }
    }
    cout<<high<<endl;
}

int main(int argc, char const *argv[]) {
    string input;
    string output;
    vector<string> lines;
    vector<string> parts;
    vector<int> scores;
    vector<string> grades;
    if (argc >2 ) {
        input = argv[1];
        output = argv[2];
    } else {
        cerr<< "Arguments not provided." <<endl;
        return 1;
    }
    ifstream inputFile(input);

    if (!inputFile.is_open()) {
        cerr << "Failed to open input file." << endl;
        return 2; // or some other error code
    }

    ofstream outputFile(output);
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open output file." << std::endl;
        return 3; // or some other error code
    }

    getData(inputFile, lines);
    for (unsigned int i = 0; i<lines.size(); i++) {
        split (lines[i], " ", parts);
    }

    for (unsigned int i = 2; i< parts.size(); i = i+3) {
        string s = parts[i];
        int j = stoi(s);
        scores.push_back(j);
    }
    for (unsigned int i = 0; i< scores.size(); i++) {
        string g = calculateGrade(scores[i]);
        grades.push_back(g);
    }
    
    writeData(lines, grades, outputFile);
    highestScore(scores);

}