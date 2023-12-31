#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    //argc is the number of strings given to this program
    //argv is the array of strings
    cout<<"Hello, World!"<<endl;
    /*
    this is a
    multiline
    comment
    */
    int x = 3;
    cout<<"The number x is: "<<x<<endl;
    int y;
    cout<<"Please insert a number for y: ";
    cin>>y;
    cout<<"y is: "<<y<<endl;
    /* Data types are:
    int, float, double, bool, and char
    */
    bool blah = true; //can also be a number. Note booleans are actually ints
    //0 is false, everything else is true
    if (blah) {
        //if statements are the same as Java
        cout<<"It is true"<<endl;
    }
    else {
        cout<<"It is false"<<endl;
    }

    int a = 0; //sometimes C++ does not treat "int a" as "int a = 0." You should initialize everything
    cout<<"a is: "<<a<<endl;
    
    //you can convert a double to an int without casting
    double b = 5.3;
    int c = b; //this works in C++
    cout<<"b is: "<<b<<"\n"<<"c is "<<c<<endl; //\n is the same as endl and \t does a tab

    //Strings do not work as you think they do. Look up functions such as substring
    /*substring is s.substring(start, length of substring) in C++ rather than 
    s.substring(start, end) so name.substring(1,3) would be "zae" in C++ instead of
    "za" like in Java*/
    string name = "Azael Mayer"; //strings start with a lowercase
    cout<<"My name is "<<name<<endl;

    /*C++ programs all have arguments. Don't worry about the syntax, but know this is how you
    use it*/
    cout<<"You gave "<<argc<<" arguments and they are: "<<endl;
    for(int i = 0; i<argc; i++) {
        cout<<argv[i]<<endl;
    }
    //most of the time you will take command line arguments instead of cin
    //the thing above is an array. Never use arrays, use Vectors.
    //Here's why
    int daArray[] = {2,4,6,8};
    //cout<<"Number at position 4 is: "<<daArray[4]<<endl; this will print any random thing
    //daArray[4] = 5; you are allowed to go past the array's bounds. very dangerous!
    //C++ does not do error checking, nor can you check for size.

    //Instead, you should use Vectors which are like ArrayLists
    vector<int> lol; //vector called lol
    lol.push_back(53); //adds 53 to the vector
    lol.push_back(5); //adds 5 to the vector, it now holds 53, 5
    lol.push_back(8); //adds 8 to the vector, it now holds 53, 5, 8
    cout<<lol.at(0)<<endl; //access the item at 0. Will error check if out of bounds.
    //cout<<lol[3]<<endl; another way to access an item. Will NOT error check
    cout<<lol.size()<<endl; //size of the vector
    lol.pop_back(); //get rid of the last item
    lol[1] = 28; //changes position 2 to 28
    //lol.erase(lol.begin()+1); //removes the item at position 1
    cout<<"the vector currently has: "<<endl;
    for(unsigned int i = 0; i<=lol.size(); i++) {
        cout<<lol[i]<<endl;
    }
}

//in order to submit, use "zip EX01.zip Makefile EX01.cpp"
//the first file is what the new zip file will be called
//the next files are what will be contained in the new zip file

//wget is the command to download a website