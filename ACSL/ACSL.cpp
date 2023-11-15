#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'findHandSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER originalRows
 *  2. STRING handTiles
 *  3. STRING drawPile
 */

void split(const string& str, const string& delim, vector<string>& parts) {
    size_t start, end = 0;
    while (end < str.size()) {
        start = end;
        while (start < str.size() && (delim.find(str[start]) != string::npos)) {
            start++;  // skip initial whitespace
        }
        end = start;
        while (end < str.size() && (delim.find(str[end]) == string::npos)) {
            end++; // skip to end of word
        }
        if (end-start != 0) {  // just ignore zero-length strings.
            parts.push_back(string(str, start, end-start));
        }
    }
}

int findHandSum(int originalRows, string handTiles, string drawPile) {
    vector<string> handParts;
    vector<string> drawParts;
    vector<string> rows; //string so I can compare two strings
    rows.push_back(to_string((int)(originalRows/1000)));
    rows.push_back(to_string((int)(originalRows/100)%10));
    rows.push_back(to_string((int)(originalRows/10)%10));
    rows.push_back(to_string(originalRows%10));
    //now rows has all the initial values in order
    bool currentDoub = false; //variable to see if there is a double piece
    int doubLocation = -1; //variable to see where a double piece was placed
    split(handTiles, " ", handParts);
    split(drawPile, " ", drawParts);
    //now individual tiles from the hand and draw pile are in vectors
    string currentTile = "";
    string num1 = "";
    string num2 = "";
    int i = 0; //i for iterating through hand
    int r = 0; //r for current row
    int lastr = 3;
    int rcount = 0;
    while (true) {
        if (handParts.size() == 0) {
            return 0;
        }
        currentTile = handParts[i];
        if(currentTile.length() == 1) {
            num1 = "0";
            num2 = currentTile.substr(0,1);
        } else {
            num1 = currentTile.substr(0, 1);
            num2 = currentTile.substr(1, 1);
        }
        //cout<<"rows are "<<rows[0]<<rows[1]<<rows[2]<<rows[3]<<endl;
        //cout<<"current hand size: "<<handParts.size()<<endl;
        //cout<<"looking at "<<num1<<" and "<<num2<<" tile"<<endl;
        if (currentDoub) { //if a double was placed last turn
            r = doubLocation;
            //cout<<"double placed at row "<<r<<" last turn"<<endl;
            if (num1 == rows[r]) {
                rows[r] = num2;
                handParts.erase(handParts.begin() + i);
                //cout<<"placed tile at row "<<r<<endl;
                //cout<<"row "<<r<<" now "<<rows[r]<<endl;
                i = 0;
                lastr = r;
                r++;
                if (r == 4) {
                    r = 0;
                }
                //cout<<"now looking at row "<<r<<endl;
                currentDoub = false;
                doubLocation = -1;
                if (num1 == num2) { //check if tile placed was a double
                    currentDoub = true;
                    doubLocation = lastr;
                }
            }
            else if (num2 == rows[r]) {
                rows[r] = num1;
                handParts.erase(handParts.begin() + i);
                cout<<"placed tile at row "<<r<<endl;
                cout<<"row "<<r<<" now "<<rows[r]<<endl;
                i = 0;
                lastr = r;
                r++;
                if (r == 4) {
                    r = 0;
                }
                cout<<"now looking at row "<<r<<endl;
                currentDoub = false;
                doubLocation = -1;
                if (num1 == num2) { //check if tile placed was a double
                    currentDoub = true;
                    doubLocation = lastr;
                }
            }
            else { //if no tile placed
                cout<<"no tile placed at the row with double"<<endl;
                i++;
                if (i == handParts.size()) { //last tile in hand
                    cout<<"last tile in hand"<<endl;
                    if (drawParts.size() >0) { //there are tiles in draw
                        handParts.push_back(drawParts[0]);
                        drawParts.erase(drawParts.begin());
                        i = handParts.size() -1;
                        cout<<"drew tile from draw pile"<<endl;
                    }
                    else { //there are no tiles in draw
                        int sum = 0; //add up remaining tile numbers
                        for (int t = 0; t < handParts.size(); t++) { 
                            currentTile = handParts[t];
                            if(currentTile.length() == 1) {
                                num1 = "0";
                                num2 = currentTile.substr(0,1);
                            } else {
                                num1 = currentTile.substr(0, 1);
                                num2 = currentTile.substr(1, 1);
                            }
                            sum += stoi(num1);
                            sum += stoi(num2);
                        }
                        return sum; //game end
                    }
                }
            }
            
        }
        else { //if a double was not placed last turn
            cout<<"double not placed last turn"<<endl;
            if (num1 == rows[r]) { //tile i placed at r
                cout<<"put tile at row "<<r<<endl;
                rows[r] = num2;
                handParts.erase(handParts.begin() + i);
                i = 0;
                lastr = r;
                r++;
                if (r == 4) {
                    r = 0;
                }
                if (num1 == num2) { //check if tile placed was a double
                    currentDoub = true;
                    doubLocation = lastr;
                }
            }
            else if (num2 == rows[r]) { //tile i placed at r
                cout<<"put tile at row "<<r<<endl;
                rows[r] = num1;
                handParts.erase(handParts.begin() + i);
                currentDoub = false;
                doubLocation = -1;
                i = 0;
                lastr = r;
                r++;
                if (r == 4) {
                    r = 0;
                }
                if (num1 == num2) { //check if tile placed was a double
                    currentDoub = true;
                    doubLocation = lastr;
                }
            }
            else { //tile not placed
                cout<<"tile not placed in row "<<r<<endl;
                if (lastr == r) { //if all rows been looked through
                    i++;
                    if (i == handParts.size()) { //last tile in hand
                        cout<<"last tile in hand"<<endl;
                        if (drawParts.size() >0) { //there are tiles in draw
                            handParts.push_back(drawParts[0]);
                            drawParts.erase(drawParts.begin());
                            i = handParts.size() -1;
                            cout<<"drew tile from draw pile"<<endl;
                        }
                        else { //there are no tiles in draw
                            int sum = 0; //add up remaining tile numbers
                            for (int t = 0; t < handParts.size(); t++) { 
                                currentTile = handParts[t];
                                if(currentTile.length() == 1) {
                                    num1 = "0";
                                    num2 = currentTile.substr(0,1);
                                } else {
                                    num1 = currentTile.substr(0, 1);
                                    num2 = currentTile.substr(1, 1);
                                }
                                sum += stoi(num1);
                                sum += stoi(num2);
                            }
                        return sum; //game end
                        }
                    }
                }
                r++; //look at next row
                rcount++;
                if (r == 4) {
                    r = 0;
                }
            }
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string originalRows_temp;
    getline(cin, originalRows_temp);

    int originalRows = stoi(ltrim(rtrim(originalRows_temp)));

    string handTiles;
    getline(cin, handTiles);

    string drawPile;
    getline(cin, drawPile);

    int result = findHandSum(originalRows, handTiles, drawPile);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
