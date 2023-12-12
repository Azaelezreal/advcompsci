#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>


using namespace std;

struct Node {
	std::string word;
	int times;
	Node* left;
	Node* right;

    Node(std::string data) : word(data), left(nullptr), right(nullptr) {}
};

struct BinarySearch {
    BinarySearch();
    ~BinarySearch();

	std::string letter;
	int times;
	BinarySearch* left;
	BinarySearch* right;

    void insert(std::string data, Node* currNode);
    void remove(Node* currNode);
    void display(Node* currNode);
    int getDepth(std::string data, Node* currNode, int depth);

    BinarySearch* head;
};

#endif