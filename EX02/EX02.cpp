#include <iostream>
#include <vector>

using namespace std;

/*function declaration. these go at the top to make sure all the functions are usable
even when a function is implemented below where it is called in the function. */
int timesTwo(int num);

//this is called pass by reference
void changeThis(int &num) { //the & means passing by reference
    num *=2;
}

int main(int argc, char const *argv[]) {
    int x = 5;
    int y = timesTwo(x);
    cout<<"x is "<<x<<" and y is "<<y<<endl;

    changeThis(x);
    cout<<"x is "<<x<<" and y is "<<y<<endl;

}

//implementation of function (can be anywhere as long as declaration is before it)
//this is passing by value. it copies the variable so you can change it without
//changing the original
int timesTwo(int num) {
    return num*2;
}