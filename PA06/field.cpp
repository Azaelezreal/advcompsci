#include "field.h"
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/** @file field.c
 *  @brief You will modify this file and implement six functions
 *  @details Your implementation of the functions defined in field.h.
 *  You may add other function if you find it helpful. Added function
 *  should be declared <b>static</b> to indicate they are only used
 *  within this file. For example, methods you write may need a mask value.
 *  You might write a method to compute mask for you and use it wherever
 *  it is needed as oposed to just puting the code in line.
 * <p>
 * @author <b>Your name</b> goes here
 */

/** Get the specified bit from a value.
 *  @param value the source value or bit pattern
 *  @param position the bit position to get (0..31)
 *  @return 1 when the bit is set, and 0 otherwise.
 */
//0 is the LEAST significant bit
int getBit (int value, int position) {
    string valstr = to_string(value);
    if (valstr.substr(31 - position, 1) == "0") {
        return 0;
    }
    return 1;
}

/** Set the specified bit in a value to 1.
 *  @param value the source value or bit pattern
 *  @param position the bit position to be set (0..31)
 *  @return An integer value that is the original value with the bit set to 1.
 */
int setBit (int value, int position) {
    int mask = 1<<position;
    int ans = value | mask;
    return ans;
}

/** Set the specified bit in a value to 0.
 *  @param value the source value or bit pattern
 *  @param position the bit position to be set (0..31)
 *  @return An integer value that is the original value with the bit set to 0.
 */
int clearBit (int value, int position) {
    string maskstr = "";
    for (int i = 31; i >=0; i--) {
        if (i== position) {
            maskstr += "0";
        } else {
            maskstr += "1";
        }
    }
    int mask = stoi(maskstr);
    return value & mask;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int getField (int value, int hi, int lo, int isSigned) {
    return 0;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int setField (int oldValue, int hi, int lo, int newValue) {
    return 0;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int fieldFits (int value, int width, int isSigned) {
    return 0;
}
