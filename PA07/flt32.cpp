#include "field.h"
#include "flt32.h"

/** @file flt32.c
 *  @brief You will modify this file and implement nine functions
 *  @details Your implementation of the functions defined in flt32.h.
 *  You may add other function if you find it helpful. Added function
 *  should be declared <b>static</b> to indicate they are only used
 *  within this file.
 *  <p>
 *  @author <b>Your name</b> goes here
 */

/** Extract the sign of the argument
 *  @param x the integer containing a IEEE floating point value
 *  @return 0 if the value is 0 or positive, 1 if it is negative
 */
int flt32_get_sign(flt32 x)
{
    return getBit(x, 31);
}

/** Extract the exponent of the argument
 *  @param x the integer containing a IEEE floating point value
 *  @return the biased exponent of the argument
 */
int flt32_get_exp(flt32 x)
{
    return getField(x, 30, 23, 0);
}

/** Extract the digits of the argument
 *  @param x the integer containing a IEEE floating point value
 *  @return the <b>24</b> bits representing the value (includes the implicit 1)
 */
int flt32_get_val(flt32 x)
{
    return setBit(getField(x, 23, 0, 0), 23);
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
void flt32_get_all(flt32 x, int *sign, int *exp, int *val)
{
    // Assign each to a pointer given in the arguments.
    // This one is already done for you. No need to edit this.
    *sign = flt32_get_sign(x);
    *exp = flt32_get_exp(x);
    *val = flt32_get_val(x);
}

/** Extract the position of the left most 1 in the argument's bits
 *  @param value the integer
 *  @return -1 if the value is 0, otherwise the position (0 to 31) of the left
 *  most 1 bit.
 */
int flt32_left_most_1(int value)
{
    for (int i = 31; i >= 0; i--)
    {
        if (getBit(value, i) == 1)
        {
            return i;
        }
    }
    return -1;
}

/** Absolute value of the argument. This can be done with a simple bit
 *  manipulation operation or with your <code>field</code> functions. No
 *  conditionals are required.
 *  @param x some pattern of bits (may be a IEEE floating point value)
 *  @return the absolute value of the parameter
 */
flt32 flt32_abs(flt32 x)
{
    return clearBit(x, 31);
}

/** Negate the argument. This can be done with a simple bit manipulation
 *  function (think about the C <b>xor</b> operator (<code>^</code>) or with
 *  your <code>field</code> functions.
 *  @param x the integer containing a IEEE floating point value
 *  @return the negation of the value
 */
flt32 flt32_negate(flt32 x)
{
    if (flt32_get_sign(x) == 0)
    {
        return setBit(x, 31);
    }
    return clearBit(x, 31);
}

/** Add two floating point values
 *  @param x an integer containing a IEEE floating point value
 *  @param y an integer containing a IEEE floating point value
 *  @return x + y. Your code needs to account for a value of 0.0, but no other
 *  special cases (e.g. infinities)
 */
flt32 flt32_add(flt32 x, flt32 y)
{
    int xsign = flt32_get_sign(x);
    int ysign = flt32_get_sign(y);
    int xexp = flt32_get_exp(x) - 127;
    int yexp = flt32_get_exp(y) - 127;
    int xmant = flt32_get_val(x);
    int ymant = flt32_get_val(y);
    if (xsign != ysign && flt32_abs(x) == flt32_abs(y)) {
        return 0.0;
    }
    int ansexp = 0;
    if (xexp > yexp) {
        ymant = ymant >> xexp - yexp;
        ansexp = xexp;
    }
    else if (yexp > xexp) {
        xmant = xmant >> yexp - xexp;
        ansexp = yexp;
    }
    if (xsign == 1 && ysign != 1) {
        xmant = ~xmant + 1; //twos complement
    }
    if (ysign == 1 && xsign != 1) {
        ymant = ~ymant + 1; //twos complement
    }
    int ansmant = ymant + xmant;
    while (flt32_left_most_1(ansmant) > 24) {
        ansmant = ansmant<<1;
        ansexp ++;
    }
    return 0;
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
flt32 flt32_sub(flt32 x, flt32 y)
{
    return flt32_add(x, flt32_negate(y));
}
