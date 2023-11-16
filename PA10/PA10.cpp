#include <vector>
#include <string>
#include <iostream>

using namespace std;

void fizzBuzz(int n) {
    for (int i = 1; i<=n; i++) {
        if (i%3 == 0 && i%5 ==0) {
            cout<<"FizzBuzz"<<endl;
        }
        else if (i%3 == 0) {
            cout<<"Fizz"<<endl;
        }
        else if (i%5 == 0) {
            cout<<"Buzz"<<endl;
        }
        else {
            cout<<i<<endl;
        }
    }
}

int main(int argc, char const *argv[]) {
    if (argc > 1) {
        int n = (int)argv[1];
        fizzBuzz(n);
    } else {
        cerr<<"no argument"<<endl;
    }
    
    return 0;
}