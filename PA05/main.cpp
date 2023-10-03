//You can edit this file to run your program and make more test cases.

#include <iostream>
#include "convert.h"

using namespace std;

int main() {
    char abc = '0';
    cout<<char2int(abc)<<" ";
    cout<<char2int('1')<<" ";
    cout<<char2int('2')<<" ";
    cout<<char2int('3')<<" ";
    cout<<char2int('4')<<" ";
    cout<<char2int('5')<<" ";
    cout<<char2int('6')<<" ";
    cout<<char2int('7')<<" ";
    cout<<char2int('8')<<" ";
    cout<<char2int('9')<<" ";
    cout<<char2int('A')<<" ";
    cout<<char2int('B')<<" ";
    cout<<char2int('C')<<" ";
    cout<<char2int('D')<<" ";
    cout<<char2int('E')<<" ";
    cout<<char2int('F')<<" "<<endl;

    
    // Base 16 (hexadecimal)
    int value = 1234;
    cout << value << " (base 10) = ";
    int2ascii(value, 16);
    cout << " (base 16)" << endl;

    string hexString = "ABCD";
    cout << hexString << " (base 16) = ";
    ascii2int(hexString.c_str(), 16);
    cout << " (base 10)" << endl;

    
    // Base 8 (octal)
    value = 1234;
    cout << value << " (base 10) = ";
    int2ascii(value, 8);
    cout << " (base 8)" << endl;

    

    string octalString = "4567";
    cout << octalString << " (base 8) = ";
    ascii2int(octalString.c_str(), 8);
    cout << " (base 10)" << endl;
    

    // Base 2 (binary)
    value = 1234;
    cout << value << " (base 10) = ";
    int2ascii(value, 2);
    cout << " (base 2)" << endl;

    

    string binaryString = "10011011";
    cout << binaryString << " (base 2) = ";
    ascii2int(binaryString.c_str(), 2);
    cout << " (base 10)" << endl;
    

    // Base 6 (unusual!)
    value = 1234;
    cout << value << " (base 10) = ";
    int2ascii(value, 6);
    cout << " (base 6)" << endl;

    
    string base6String = "4532";
    cout << base6String << " (base 6) = ";
    ascii2int(base6String.c_str(), 6);
    cout << " (base 10)" << endl;
    

    
    return 0;
}
