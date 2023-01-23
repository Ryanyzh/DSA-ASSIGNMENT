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
#include <vector>
#include <algorithm>

#include "PLinkedList.h"
#include "Post.h"
#include "ReactionList.h"
#include "Reply.h"
#include "RStack.h"
#include "TDictionary.h"
#include "Topic.h"
#include "ULinkedList.h"
#include "User.h"


using namespace std;

User currentUser;
ULinkedList userList;
TDictionary topicDictionary;
vector<char> specialchar;
vector<int> mainOptions;
vector<int> postOptions;
int pageState;


void displayBanner();             // function to display banner
void displayTopics();             // function to display topics
bool displaySignInScreen();
bool displaySignUpScreen();
void displayMainMenu();
void displaySignInMenu();
void displayPostMenu();
void init();
int getOptionInput();
int hashing(string s);
bool validateUser(string username, string password);
bool validateUsernameInput(string username);
bool validatePasswordInput(string password);
bool checkSpecialCharacters(string p);



int main()
{
    init();
    int signInOption = -1;
    int mainOption = -1;
    int postOption = -1;
    bool signInStatus = false;
    bool signUpStatus = false;
    while ((currentUser.getUsername() == "" || currentUser.getPassword() == "") && signInOption != 0) {
        while (signInOption != 1 && signInOption != 2) {
            displaySignInMenu();
            signInOption = getOptionInput();
        }
        if (signInOption == 1) {
            while (!signInStatus) {
                signInStatus = displaySignInScreen();
            }
        }
        else {
            while (!signUpStatus) {
                signUpStatus = displaySignUpScreen();
            }
        }
    }

    // pageState 0 = not set
    // pageState 1 = main menu page
    // pageState 2 = post menu page
    pageState = 1;
    displayBanner();
    while ((currentUser.getUsername() != "" || currentUser.getPassword() != "") && mainOption != 0 && pageState == 1) {
        if (count(mainOptions.begin(), mainOptions.end(), mainOption)) {
            if (mainOption == 1) {
                displayTopics();
            }
            else if (mainOption == 2) {
                Topic newTopic = Topic();
                string topicName;
                cout << endl;
                cout << ">>  Enter new Topic name:  ";
                cin >> topicName;
                cout << endl;

                newTopic.setTopicName(topicName);
                topicDictionary.add(topicName, newTopic);
                mainOption = 999;
            }
            else if (mainOption == 3) {
                cout << "searching users" << endl;
                // Insert Codes Here
            }
            else if (mainOption == 4) {
                cout << "searching topics" << endl;
                // Insert Codes Here
            }
            else {
                pageState = 2;
                break;
            }
        }
        else {
            displayMainMenu();
            mainOption = getOptionInput();
        }
    }


    while ((currentUser.getUsername() != "" || currentUser.getPassword() != "") && postOption != 0 && pageState == 2) {
        while (!count(postOptions.begin(), postOptions.end(), postOption)) {
            displayPostMenu();
            postOption = getOptionInput();
        }
        if (postOption == 1) {
            // Insert Codes Here
        }
        else if (postOption == 2) {
            // Insert Codes Here
        }
        else if (postOption == 3) {
            // Insert Codes Here
        }
        else if (postOption == 4) {
            // Insert Codes Here
        }
        else if (postOption == 5) {
            // Insert Codes Here
        }
        else if (postOption == 6) {
            // Insert Codes Here
        }
        else if (postOption == 7) {
            // Insert Codes Here
        }
        else {
            pageState = 1;
        }
    }


    while (signInOption == 0 || mainOption == 0 || postOption == 0) {
        cout << "Exiting program. See you again!" << endl;
        exit(0);
    }
    
    
    
    
    /*
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


void init() {
    specialchar.push_back('!');
    specialchar.push_back('@');
    specialchar.push_back('#');
    specialchar.push_back('$');
    specialchar.push_back('%');
    specialchar.push_back('&');

    mainOptions.push_back(1);
    mainOptions.push_back(2);
    mainOptions.push_back(3);
    mainOptions.push_back(4);
    mainOptions.push_back(5);

    postOptions.push_back(1);
    postOptions.push_back(2);
    postOptions.push_back(3);
    postOptions.push_back(4);
    postOptions.push_back(5);
    postOptions.push_back(6);
    postOptions.push_back(7);
    postOptions.push_back(8);


    currentUser = User();
    currentUser.setUsername("");
    currentUser.setPassword("");
}

// function to display main menu
void displayBanner()
{
    cout << "\n\n" << endl;
    int nameCounter = 0;
    for (char c : currentUser.getUsername()) {
        nameCounter++;
    }
    cout << char(218);
    for (int i = 0; i < 72; i++) {
        char abc = 196;
        cout << abc;
    }
    cout << char(191) << endl;
    cout << "|                                                                        |" << endl;
    cout << "|";
    int spaces = (72 - 12 - nameCounter)/ 2;
    if (nameCounter % 2 == 0) { //even characters
        for (int space = 0; space < spaces; space++) {
            cout << " ";
        }
        cout << "Welcome " << currentUser.getUsername() << " to";
        for (int space = 0; space < spaces + 1; space++) {
            cout << " ";
        }
        cout << "|";
    }
    else {
        for (int space = 0; space < spaces; space++) {
            cout << " ";
        }
        cout << "Welcome " << currentUser.getUsername() << " to";
        for (int space = 0; space < spaces + 2; space++) {
            cout << " ";
        }
        cout << "|";
    }
    cout << endl;
    //cout << "|                             Welcome to                                 |" << endl;
    cout << "|                        Discussion Forum 2023                           |" << endl;
    cout << "|                                                                        |" << endl;
    cout << char(192);
    for (int i = 0; i < 72; i++) {
        char abc = 196;
        cout << abc;
    }
    cout << char(217) << endl;
};


void displayTopics()
{
    
};


void displayMainMenu() {
    cout << "\n\n" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|  Options                                                               |" << endl;
    cout << "+-----+-----------------+-----+-----------------+-----+------------------+" << endl;
    cout << "|  1  | View Topics     |  2  | Add Topics      |  3  | Search Users     |" << endl;
    cout << "+-----+-----------------+-----+-----------------+-----+------------------+" << endl;
    cout << "|  4  | Search Topics   |  5  | Display Post Menu For Selected Topic     |" << endl;
    cout << "+-----+-----------------+-----+------------------------------------------+" << endl;
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
    cout << "|  7  | Search Post     |  8  | Return Back To Main Menu                 |" << endl;
    cout << "+-----+-----------------+-----+------------------------------------------+" << endl;
    cout << "|  0  | Exit Program                                                     |" << endl;
    cout << "+-----+------------------------------------------------------------------+" << endl;
}


bool displaySignInScreen() {
    string username;
    string password;
    cout << endl;

    cout << char(218);
    for (int i = 0; i < 72; i++) {
        char abc = 196;
        cout << abc;
    }
    cout << char(191) << endl;

    cout << "|                                                                        |" << endl;
    cout << "|                      Please Sign In Below To Begin                     |" << endl;
    cout << "|                                                                        |" << endl;
    
    cout << char(192);
    for (int i = 0; i < 72; i++) {
        char abc = 196;
        cout << abc;
    }
    cout << char(217) << "\n" << endl;

    cout << ">>  Username:  ";
    cin >> username;
    cout << endl;
    cout << ">>  Password:  ";
    cin >> password;
    
    string correctname;
    string correctpassword;
    correctname = "abcdef";
    correctpassword = "123456";
    if (username == correctname && password == correctpassword) {
        currentUser.setUsername(username);
        currentUser.setPassword(password);
        return true;
    }
    else {
        cout << "\n[ERROR] You have entered invalid credentials. Please try again.\n\n\n" << endl;
        //cout << "__________________________________________________________________________" << endl;
        return false;
    }
    //return validateUser(username, password);
}



bool displaySignUpScreen() {
    string username;
    string password;
    bool usernameClear = false;
    bool passwordClear = false;
    cout << endl;
    cout << char(218);
    for (int i = 0; i < 72; i++) {
        char abc = 196;
        cout << abc;
    }
    cout << char(191) << endl;

    cout << "|                                                                        |" << endl;
    cout << "                  Please Sign Up Below For A New Account                  " << endl;
    cout << "|                                                                        |" << endl;

    cout << char(192);
    for (int i = 0; i < 72; i++) {
        char abc = 196;
        cout << abc;
    }
    cout << char(217) << "\n" << endl;

    while (usernameClear == false) {
        cout << ">>  New Username:  ";
        cin >> username;
        cout << endl;
        usernameClear = validateUsernameInput(username);
    }
    
    while (passwordClear == false) {
        cout << ">>  New Password:  ";
        cin >> password;
        cout << endl;
        passwordClear = validatePasswordInput(password);
    }
    currentUser.setUsername(username);
    currentUser.setPassword(password);

    return true;
}


bool validateUsernameInput(string u) {
    if (u.length() > 30 || u.length() < 5) {
        cout << "[ERROR] Your username needs to be between 5 to 30 characters. Please try again.\n" << endl;
        return false;
    }
    for (char c : u) {
        if (iswalnum(c) == false) {
            cout << "[ERROR] Your username can only consists of alphabets and numbers. Please try again.\n" << endl;
            return false;
        }
    }
    return true;
}

bool validatePasswordInput(string p) {
    if (p.length() > 20 || p.length() < 8) {
        cout << "[ERROR] Your password needs to be between 8 to 20 characters. Please try again.\n" << endl;
        return false;
    }
    if (checkSpecialCharacters(p) == false) {
        cout << "[ERROR] Your password need to include these special characters - !@#$%&. Please try again.\n" << endl;
        return false;
    }
    
    p.erase(remove(p.begin(), p.end(), '!'), p.end());
    p.erase(remove(p.begin(), p.end(), '@'), p.end());
    p.erase(remove(p.begin(), p.end(), '#'), p.end());
    p.erase(remove(p.begin(), p.end(), '$'), p.end());
    p.erase(remove(p.begin(), p.end(), '%'), p.end());
    p.erase(remove(p.begin(), p.end(), '&'), p.end());

    for (char c2 : p) {
        if (iswalnum(c2) == false) {
            cout << "[ERROR] Your password can only consists of alphabets, numbers and these special characters - !@#$%&. Please try again.\n" << endl;
            return false;
        }
    }
    return true;
}


bool checkSpecialCharacters(string p) {
    for (char character1 : p) {
        for (char character2 : specialchar) {
            //cout << character << " : " << typeid(character).name() << " and " << spc << " : " << typeid(spc).name() << endl;
            if (character1 == character2) {
                return true;
            }
        }
    }
    return false;
}





bool validateUser(string usernameInput, string passwordInput) {
    return userList.checkCredentials(usernameInput, passwordInput);
}


int getOptionInput() {
    int input;
    cout << endl;
    cout << ">>  Select an option to continue:  ";
    cin >> input;
    cout << endl;
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



void displaySignInMenu() {
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|  Options                                                               |" << endl;
    cout << "+-----+-----------------+-----+-----------------+-----+------------------+" << endl;
    cout << "|  1  | Sign In         |  2  | Sign Up         |  0  | Exit Program     |" << endl;
    cout << "+-----+-----------------+-----+-----------------+-----+------------------+" << endl;
};

