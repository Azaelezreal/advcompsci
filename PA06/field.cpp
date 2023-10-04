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
    if (valstr.substr(position, 1) == "0") {
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
    int mask = 1<<position;
    mask = ~mask;
    int ans = value & mask;
    return ans;
}

/** Extract the field (possibly signed) between bits hi and lo (inclusive).
 *  @param value  the source value or bit pattern
 *  @param hi the bit position of one end of the field
 *  @param lo the bit position of the other end of the field
 *  @param isSigned zero means the field is unsigned, non-zero means the field is signed
 *  @return The value of the field.  Sanity check example: 
 *   if the field is three bits wide and unsigned, the result
 *   will be a value between 0 and 7, regardless of the actual position of the
 *   bits in value. If the value is signed, the result will be between -4 and 3.
 *   Furthermore, if the value is signed, it will be negative only if
 *   the left most bit of the field is 1. In this case, the field must be
 *   sign extended (i.e. make all bits to the left 1).
 */
int getField (int value, int hi, int lo, int isSigned) {
    int field = value;
    field = field>>lo;
    if (isSigned==0 || getBit(field, hi-lo) == 0) {
        for (int i = hi-lo+1; i<32; i++) {
            field = clearBit(field, i);
        }
    } else {
        for (int i = hi-lo+1; i<32; i++) {
            field = setBit(field, i);
        }
    }
    return field;
}

/** Change the bits of oldValue between hi and lo to the newValue,
 * leaving the other bits unchanged.
 * @param oldValue the original value
 * @param hi the bit position of one end of the field
 * @param lo the bit position of the other end of the field
 * @param newValue the new value to put in the field (use lower bits)
 * @return the value after replacing only the hi to low bits 
 *         inclusive by newValue
 */
int setField (int oldValue, int hi, int lo, int newValue) {
    string newvalstr = to_string(newValue);
    int ans = oldValue;
    for (int i = 0; i<= hi-lo; i++) {
        if (newvalstr.substr(i, 1) == "0") {
            ans = clearBit(ans, i+lo);
        }
        else {
            ans = setBit(ans, i+lo);
        }
    }
    return ans;
}

/** Determine if a value will fit in a specified field
 *  @param value  the source value
 *  @param width the number of bits holding the value
 *  @param isSigned zero means the field is unsigned, non-zero means the field is signed
 *  @return zero if the field does NOT fit. Return 1 if the value fits.
 */
int fieldFits (int value, int width, int isSigned) {
    string valstr = to_string(value);
    if (isSigned == 0) {
        if (valstr.length()>width) {
            return 0;
        }
        return 1;
    }
    if (valstr.length()>width-1) {
        return 0;
    }
    return 1;
}
