#include <iostream>
#include "BinarySearch.h"
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

BinarySearch::BinarySearch() : head(nullptr) {}

void BinarySearch::insert (std::string data, Node* currNode) {
	if (currNode == nullptr) {
		currNode = new Node(data);
	} else if (data == currNode->word) {
		currNode->times++;
    } else if (data<currNode->word) {
		insert(data, currNode->left);
	} else if (data>currNode->word) {
		insert(data, currNode->right);
	}
	
};

void BinarySearch::remove (Node* currNode) {
	if (currNode == nullptr) {
		delete currNode;
	}
	else if (currNode->left != nullptr) {
		remove(currNode->left);
	}
	else if (currNode->right != nullptr) {
		remove(currNode->right);
	}
};

void BinarySearch::display(Node* currNode) {
    if (currNode != nullptr) {

    }
    cout << head->word << " ";
}

std::string toLowerCase(const std::string& input) {
    std::string result = input;
    for (char& c : result) {
        c = std::tolower(c);
    }
    return result;
}

string removeCharacters(const std::string& input) {
    std::string result;
    for (char c : input) {
        // Check if the character is not in the set of specified characters
        if (c != '.' && c != ',' && c != ';' && c != '!' && c != '?' && c != '(' && c != ')' && c != '[' && c != ']') {
            result += c;
        }
    }
    return result;
}

int BinarySearch::getDepth(std::string data, Node* currNode, int depth) {
    if (currNode == nullptr) {
        return -1;
    } else if (currNode->word == data) {
        currNode->times++;
    }
    else if (currNode->word > data) {
        return getDepth(data, currNode->left, depth+1);
    }
    else {
        return getDepth(data, currNode->right, depth+1);
    }
}

int main(int argc, char const *argv[]) {
    string file;
    string input;
    string target;
    if (argc >2 ) {
        input = argv[1];
        target = argv[2];
    } else {
        cerr<< "Arguments not provided." <<endl;
        exit(1);
    }
    ifstream inputFile(input);

    if (!inputFile.good()) {
        cerr << "Failed to open input file." << endl;
        exit(1);
    }

    
    std::string line;
    while (std::getline(inputFile, line)) {
        line = removeCharacters(line);
    }
    inputFile.close();

}