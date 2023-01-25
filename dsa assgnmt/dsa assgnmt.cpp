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


// \x18\x19 
// only 5 reactions combined : upvote, downvote, happy, sad, shock, cry

using namespace std;

User currentUser;
ULinkedList userList;
TDictionary topicDictionary;
vector<char> specialchar;
vector<int> mainOptions;
vector<int> postOptions;
int pageState;
string currentTopicName;


void displayBanner();             // function to display banner
bool displaySignInScreen();
bool displaySignUpScreen();
void displayMainMenu();
void displaySignInMenu();
void displayPostMenu();
void displayReactionsMenu();
void init();
int getOptionInput();
int hashing(string s);
bool validateUser(string username, string password);
bool validateUsernameInput(string username);
bool validatePasswordInput(string password);
bool checkSpecialCharacters(string p);
bool checkInteger(string input);
bool validateTopicName(string nameOfTopic);
bool validateTopicNumber(int topicNum);



int main()
{
    init();
    int signInOption = -1;
    int mainOption = -1;
    int postOption = -1;
    bool signInStatus = false;
    bool signUpStatus = false;
    while (signInOption != 0 && mainOption != 0 && postOption != 0) {
        
        while (currentUser.getUsername() == "" || currentUser.getPassword() == "") {
            signInOption = -999;
            while (signInOption != 1 && signInOption != 2) {
                displaySignInMenu();
                signInOption = getOptionInput();
            }
            if (signInOption == 1) {
                while (!signInStatus) {
                    signInStatus = displaySignInScreen();
                }
                pageState = 1;
                displayBanner();
            }
            else {
                while (!signUpStatus) {
                    signUpStatus = displaySignUpScreen();
                }
                pageState = 1;
                displayBanner();
            }
        }

        // pageState 0 = not set
        // pageState 1 = main menu page
        // pageState 2 = post menu page
        
        while ((currentUser.getUsername() != "" || currentUser.getPassword() != "") && pageState == 1) {
            mainOption = -999;
            while (!count(mainOptions.begin(), mainOptions.end(), mainOption)) {
                displayMainMenu();
                mainOption = getOptionInput();
            }
            if (count(mainOptions.begin(), mainOptions.end(), mainOption)) {
                if (mainOption == 1) {
                    cout << "\n\n" << endl;
                    topicDictionary.displayTopics();
                    mainOption = -1;
                }
                else if (mainOption == 2) {
                    bool topicNameValid = false;
                    Topic newTopic = Topic();
                    string topicName = "";
                    while (topicNameValid == false) {
                        cout << endl;
                        cout << ">>  Enter new Topic name:  ";
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        getline(cin, topicName);
                        cout << endl;
                        topicNameValid = validateTopicName(topicName);
                    }
                    newTopic.setTopicName(topicName);
                    topicDictionary.add(topicName, newTopic);
                    mainOption = -1;
                }
                else if (mainOption == 3) {
                    cout << "searching users" << endl;
                    mainOption = -1;
                    // Insert Codes Here
                }
                else if (mainOption == 4) {
                    cout << "searching topics" << endl;
                    mainOption = -1;
                    // Insert Codes Here
                }
                else {
                    pageState = 2;
                    break;
                }
            }
        }


        while ((currentUser.getUsername() != "" || currentUser.getPassword() != "") && pageState == 2) {
            postOption = -999;
            while (!count(postOptions.begin(), postOptions.end(), postOption)) {
                displayPostMenu();
                postOption = getOptionInput();
            }
            if (postOption == 1) {
                int topicSelected = -1;
                bool topicSelectionSuccess = false;
                while (topicSelectionSuccess == false) {
                    cout << "\n\n" << endl;
                    cout << "+------------------------------------------------------------------------+" << endl;
                    cout << "|  Choose a topic                                                        |" << endl;
                    topicDictionary.displayTopics();
                    topicSelected = getOptionInput();
                    topicSelectionSuccess = validateTopicNumber(topicSelected);
                }
                cout << currentTopicName << endl;
                
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
                break;
            }
        }
    }
    


    while (signInOption == 0 || mainOption == 0 || postOption == 0) {
        cout << "Exiting program. See you again!" << endl;
        exit(0);
    }
    
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

    currentTopicName = "";
    pageState = 0;
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


bool validateTopicName(string nameOfTopic) {
    if (iswalnum(nameOfTopic[0]) && nameOfTopic.length() >= 1 && nameOfTopic.length() <= 50) {
        return true;
    }
    else {
        cout << "The first character needs to be an alphanumeric character and only 1 to 50 characters are allowed." << endl;
        return false;
    }
}



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
    cout << "+-----+-----------------------------------------+-----+------------------+" << endl;
    cout << "|  1  | View Post(s) And Reply(ies)             |  2  | Edit Post        |" << endl;
    cout << "+-----+-----------------+-----+-----------------+-----+------------------+" << endl;
    cout << "|  3  | Delete Post     |  4  | Add Reply       |  5  |  Add Reactions   |" << endl;
    cout << "+-----+-----------------+-----+-----------------+-----+------------------+" << endl;
    cout << "|  6  | Search Post     |  7  | Return Back To Main Menu                 |" << endl;
    cout << "+-----+-----------------+-----+------------------------------------------+" << endl;
    cout << "|  0  | Exit Program                                                     |" << endl;
    cout << "+-----+------------------------------------------------------------------+" << endl;
}


void displayReactionsMenu() {
    cout << "\n\n" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|  Options                                                               |" << endl;
    cout << "+-----+-----------------+-----+-----------------+-----+------------------+" << endl;
    cout << "|  1  | \x18 [Upvote]      |  2  | \x19 [Downvote]    |  3  | :) [Happy]       |" << endl;
    cout << "+-----+-----------------+-----+-----------------+-----+------------------+" << endl;
    cout << "|  4  | :( [Sad]        |  5  | :0 [Shock]      |  6  |  :'( [Cry]       |" << endl;
    cout << "+-----+-----------------+-----+-----------------+-----+------------------+" << endl;
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
    cout << "|                 Please Sign Up Below For A New Account                 |" << endl;
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
    bool isInteger = false;
    string input;
    while (!isInteger) {
        cout << endl;
        cout << ">>  Select an option to continue:  ";
        cin >> input;
        cout << endl;
        isInteger = checkInteger(input);
        if (checkInteger(input) == false) {
            cout << "[ERROR] Only (integer) numbers are accepted. Pls try again." << endl;
        }
        
    }
    
    return stoi(input);
}



bool checkInteger(string input)
{
    bool isNeg = false;
    int itr = 0;
    if (input.size() == 0)
        return false;
    if (input[0] == '-')
    {
        isNeg = true;
        itr = 1;
    }

    for (int i = itr; i < input.size(); i++)
    {
        if (!isdigit(input[i]))
            return false;
    }
    return true;
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




bool validateTopicNumber(int topicNum) {
    if (topicNum == 0) {
        return false;
    }
    currentTopicName = topicDictionary.returnTopicName(topicNum);
    if (currentTopicName != "") {
        return true;
    }
    else {
        cout << "[ERROR] Invalid number inputted. Pls try again." << endl;
        return false;
    }
};

