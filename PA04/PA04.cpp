#include <iostream>
#include <vector>
#include <Fraction.h>


using namespace std;

int main(int argc, char const *argv[]) {

    Fraction fraction1(3,4);
    Fraction fraction2(1,2);
    cout<<"Fraction 1: "<<fraction1<<endl;
    cout<<"Fraction 2: "<<fraction2<<endl;
    Fraction sum = fraction1+fraction2;
    cout<<fraction1<<" + " <<fraction2<<" = "<<sum<<endl;

    Fraction difference = fraction1-fraction2;
    cout<<fraction1<<" - " <<fraction2<<" = "<<difference<<endl;

    Fraction product = fraction1*fraction2;
    cout<<fraction1<<" * " <<fraction2<<" = "<<product<<endl;

    Fraction quotient = fraction1/fraction2;
    cout<<fraction1<<" divided by " <<fraction2<<" = "<<quotient<<endl;

    bool equivalent = fraction1==fraction2;
    cout<<"Is "<<fraction1<<" equivalent to " <<fraction2<<"? ";
    if (equivalent) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }

    Fraction fraction3(6,9);
    Fraction fraction4(4,6);
    equivalent = fraction3==fraction4;
    cout<<"Is "<<fraction3<<" equivalent to " <<fraction4<<"? ";
    if (equivalent) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }

}