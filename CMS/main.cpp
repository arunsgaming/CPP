// CMS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

# include <iostream>
# include "cms.h"

using namespace std;


int main()
{
    system("cls");
    system("Color 3F");
    cout << "WELCOME TO CONTACT MANAGEMENT SYSTEM"<<endl;
    cin.get();

    while (1)
    {
        cms c1;
        int choice;

        system("cls");
        system("Color 03");

        cout << "\nCONTACT MANAGEMENT SYSTEM";
        cout << "\n\nMAIN MENU";
        cout << "=============================\n";
        cout << "[1] Add a new Contact\n";
        cout << "[2] List all Contacts\n";
        cout << "[3] Search for Contact\n";
        cout << "[4] Delete a Contact\n";
        cout << "[5] Edit a Contact\n";
        cout << "[0] Exit\n";
        cout << "=============================\n";

        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            c1.writeOnFile();
            break;

        case 2:
            system("cls");
            c1.readFromFile();
            cin.get();
            cin.get();
            break;

        case 3:
            system("cls");
            c1.searchOnFile();
            cin.get();
            cin.get();
            break;

        case 4:
            system("cls");
            c1.deleteOnFile();
            cin.get();
            cin.get();
            break;

        case 5:
            system("cls");
            c1.editContact();
            cin.get();
            cin.get();
            break;

        case 0:
            system("cls");
            cout << "Thank you for using Contact Management System \n\n";
            exit(0);
        }
    }
}