#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

using namespace std;

struct BinarySearch {
    BinarySearch();
    ~BinarySearch();

	string letter;
	int times;
	BinarySearch* left;
	BinarySearch* right;

    void insert(int data);
    void display() const;

    BinarySearch* head;
};

#endif