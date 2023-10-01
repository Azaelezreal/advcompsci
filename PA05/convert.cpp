// You will need to edit this file and turn this one in.

#include <iostream>
#include <string>

// char2int
// Converts from a character to an integer digit
// if character '0'..'9' convert to 0..9
// else if character 'A'..'F' convert to 10..15
// else convert to -1
int char2int(char digit) {
    if (digit<71 && digit>64){ //A to F
        return digit-55;
    }
    if (digit>96 && digit<103) { //a to f
        return digit-87;
    }
    if (digit>='0' && digit<58) { //0 to 9
        return digit-48;
    }
    return -1;
}

// int2char
// Converts from an integer digit to a character
// if integer 0..9 convert to '0'..'9'
// else if integer 10..15 convert to 'A'..'F'
// else convert to 'X'
char int2char(int digit){
    char a = 'X';
    if (digit<=9 && digit>=0) {
        a = digit + '0';
        return a;
    }
    if (digit<=15 && digit>=10) {
        a = digit -10 + 'A';
        return a;
    }
    return a;
}

// Convert integer to string in specified base and print
// 2 <= base <= 16
void int2ascii(int value, int base)
{
    return;
}

// Convert string in specified base to integer and print
// 2 <= base <= 16
void ascii2int(const std::string &ascii, int base)
{
    return;
}