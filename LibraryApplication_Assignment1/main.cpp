#include "LibrarySystem.h"
#include <iostream>
using namespace std;

//Display menu to user
void showMenu() {
    cout << "\n===== Library Menu =====\n";
    cout << "1. Add Book\n";
    cout << "2. Add Magazine\n";
    cout << "3. Search Item\n";
    cout << "4. Borrow Item\n";
    cout << "5. Return Item\n";
    cout << "6. Display All Items\n";
    cout << "0. Exit\n";
    cout << "Select option: ";
}

int main() {
    LibrarySystem system;                   // Create an instance of the library system
    int choice;                             //Variable to store menu choice of user
    string filename = "Library_Data.txt";   // Filename for data

    // Loop to display menu and process user commands
    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: system.addBook(); break;
        case 2: system.addMagazine(); break;
        case 3: system.searchItem(); break;
        case 4: system.borrowItem(); break;
        case 5: system.returnItem(); break;
        case 6: system.displayAll(); break;
        case 0: cout << "Exiting...\n"; break;
        default: cout << "Invalid option.\n";
        }
    } while (choice != 0);                    //Command to exit (Keep loop until user chooses to exit)

    return 0;
}
