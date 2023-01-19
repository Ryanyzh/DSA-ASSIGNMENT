//  +------------------------------------------------------------+
//  |                      Team 02: AWOL                         |
//  +------------------------------------------------------------+
//  |        Student 1: Yong Zong Han Ryan, S10219317A           |
//  |                                                            |
//  |        Student 2: Tan Jin Daat, S10222867?                 |
//  +------------------------------------------------------------+


#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void displayBanner();             // function to display banner
void displayTopics();             // function to display topics
void displayMainMenu();
void displayPostMenu();
int getOptionInput();
int hashing(string s);

int main()
{
    int mainOption = -1;
    displayBanner();
    for (int abc = 0; abc < 10; abc++) {
        string s = "";
        cout << "Enter string: ";
        cin >> s;
        cout << "hash: " << hashing(s) << endl;
    }

    //displayTopics();
    //displayPostMenu();

    /*
    while (mainOption == -1) {
        displayPostMenu();
        mainOption = getOptionInput();
    }
    

    switch (mainOption) {
    case 1:
        cout << "1" << endl;
        mainOption = 1;
        //enter code here
    case 2:
        cout << "2" << endl;
        mainOption = 2;
        //enter code here
    case 3:
        cout << "3" << endl;
        mainOption = 3;
        //enter code here
    case 4:
        cout << "4" << endl;
        mainOption = 4;
        //enter code here
    case 5:
        cout << "5" << endl;
        mainOption = 5;
        //enter code here
    case 6:
        cout << "6" << endl;
        mainOption = 6;
        //enter code here
    case 7:
        cout << "7" << endl;
        mainOption = 7;
        //enter code here
    case 8:
        cout << "8" << endl;
        mainOption = 8;
        //enter code here
    case 9:
        cout << "9" << endl;
        mainOption = 9;
        //enter code here
    default:
        cout << "Exiting Programme" << endl;
        break;
    }
    */


    return 0;
}

// function to display main menu
void displayBanner()
{
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|                             Welcome to                                 |" << endl;
    cout << "|                        Discussion Forum 2023                           |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
};


void displayTopics()
{
    cout << "\n\n" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "| Topic |                            Name                                |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "|   " << i << "   |                            Name                                | " << endl;
        cout << "+------------------------------------------------------------------------+" << endl;
    }
};


void displayMainMenu() {
    cout << "\n\n" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|  Options                                                               |" << endl;
    cout << "+-----+-----------------+-----+-----------------+-----+------------------+" << endl;
    cout << "|  1  | View Topics     |  2  | Search Users    |  3  | Search Topics    |" << endl;
    cout << "+-----+-----------------+-----+-----------------+-----+------------------+" << endl;
    cout << "|  0  | Exit Program                                                     |" << endl;
    cout << "+-----+------------------------------------------------------------------+" << endl;
};


void displayPostMenu() {
    cout << "\n\n" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|  Options                                                               |" << endl;
    cout << "+-----+-----------------+-----+-----------------+-----+------------------+" << endl;
    cout << "|  1  | View Post(s)    |  2  | Edit Post       |  3  | Delete Post      |" << endl;
    cout << "+-----+-----------------+-----+-----------------+-----+------------------+" << endl;
    cout << "|  4  | Like Post       |  5  | Add Reply       |  6  | Add Reaction(s)  |" << endl;
    cout << "+-----+-----------------+-----+-----------------+-----+------------------+" << endl;
    cout << "|  7  | Search Post     |  0  | Exit Program                             |" << endl;
    //cout << "+-----+-----------------+-----+-----------------+-----+------------------+" << endl;
    //cout << "+-----+------------------------------------------------------------------+" << endl;
}


int getOptionInput() {
    int input;
    //cout << "\n\n" << endl;
    cout << "__________________________________________________________________________\n" << endl;
    cout << ">>  Select an option to continue:  ";
    cin >> input;
    cout << "__________________________________________________________________________" << endl;
    return input;
}

int hashing(string str) {
    size_t hashCode = 0;
    for (int i = 0; i < str.length(); i++) {
        hashCode += (str[i] * (int)pow(31, i))%31;
    }
    cout << "hello: " << hashCode << endl;;
    return hashCode % 31;
}

