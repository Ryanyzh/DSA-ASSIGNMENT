//  +------------------------------------------------------------+
//  |                      Team 02: AWOL                         |
//  +------------------------------------------------------------+
//  |        Student 1: Yong Zong Han Ryan, S10219317A           |
//  |                                                            |
//  |        Student 2: Tan Jin Daat, S10222867?                 |
//  +------------------------------------------------------------+


#include <iostream>
#include <string>
using namespace std;

void displayMenu();             // function to display main menu
void displayTopics();           // function to display topics

int main()
{
    int option = 1;

    while (option != 0)
    {
        displayMenu();
        option = 0;
    }

    return 0;
}

// function to display main menu
void displayMenu()
{
    cout << "+----------------------------------------------------------------------+" << endl;
    cout << "|                                                                      |" << endl;
    cout << "|                            Welcome to                                |" << endl;
    cout << "|                       Discussion Forum 2023                          |" << endl;
    cout << "|                                                                      |" << endl;
    cout << "+----------------------------------------------------------------------+" << endl;
}


void displayTopics()
{
    
    cout << "+----------------------------------------------------------------------+" << endl;
    cout << "|                                                                      |" << endl;
    cout << "|                            Welcome to                                |" << endl;
    cout << "|                       Discussion Forum 2023                          |" << endl;
    cout << "|                                                                      |" << endl;
    cout << "+----------------------------------------------------------------------+" << endl;
}

