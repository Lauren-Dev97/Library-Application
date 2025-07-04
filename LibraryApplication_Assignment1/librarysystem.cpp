#include "LibrarySystem.h"  // Include the header file for LibrarySystem
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//Constructor
LibrarySystem::LibrarySystem() : nextId (1),filename("Library_Data.txt") {
    loadFromFile(filename);
}

//Destructor
// Saves all data to file and deallocates dynamic memor
LibrarySystem::~LibrarySystem() {
    saveToFile(filename);
    for (auto item : items) {
        delete item;
    }
}

//Load LIbrary items (data) from .txt file
void LibrarySystem::loadFromFile(const string& filename) {

    //Show error message if file cannot be opened
    string line;
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Could not open file: " << filename << endl;
        return;
    }

    // Read each line and parse the item's data

    while (getline(inFile, line)) {
        stringstream ss(line);
        string type, idStr, title, author, extra, borrowedStr;
        getline(ss, type, ',');
        getline(ss, idStr, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, extra, ',');
        getline(ss, borrowedStr);

        int id = stoi(idStr);                   //Convert id to int
        bool borrowed = (borrowedStr == "1");   // Convert borrowed status

        //Create and store item type
        if (type == "Book") {
            Book* book = new Book(title, author, id, extra);
            book->setIsBorrowed(borrowed);
            items.push_back(book);
        } else if (type == "Magazine") {
            Magazine* mag = new Magazine(title, author, id, stoi(extra));
            mag->setIsBorrowed(borrowed);
            items.push_back(mag);
        }
        if (id >= nextId) nextId = id + 1;
    }
}

//Saves new library items to file
void LibrarySystem::saveToFile(const string& filename) {
    ofstream inFile(filename);
    for (auto item : items) {
        inFile << item->toFileString() << "\n";
    }
}

//Add new library items to file
//Add books
void LibrarySystem::addBook() {
    string title, author, genre;
    cout << "Enter Title: "; getline(cin, title);
    cout << "Enter Author: "; getline(cin, author);
    cout << "Enter Genre: "; getline(cin, genre);
    items.push_back(new Book(title, author, nextId++, genre));
    cout << "Book added.\n";
}

//Add magazines
void LibrarySystem::addMagazine() {
    string title, author;
    int issue;
    cout << "Enter Title: "; getline(cin, title);
    cout << "Enter Author: "; getline(cin, author);
    cout << "Enter Issue Number: "; cin >> issue; cin.ignore();
    items.push_back(new Magazine(title, author, nextId++, issue));
    cout << "Magazine added.\n";
}

// Searches for items by title or author keyword
void LibrarySystem::searchItem() {
    string keyword;
    cout << "Enter title or author to search: ";
    getline(cin, keyword);
    // Search each item and display if there's a match
    for (auto item : items) {
        if (item->getTitle().find(keyword) != string::npos ||
            item->getAuthor().find(keyword) != string::npos) {
            item->displayInfo();
        }
    }
}

//Borrow item by ID if available
void LibrarySystem::borrowItem() {
    int id;
    cout << "Enter ID to borrow: ";
    cin >> id; cin.ignore();
    for (auto item : items) {
        if (item->getId() == id) {
            if (!item->getIsBorrowed()) {
                item->setIsBorrowed(true);
                cout << "Item borrowed.\n";
            } else {
                cout << "Already borrowed.\n";
            }
            return;
        }
    }
    cout << "Item not found.\n";
}

// Returns an item by ID if it was borrowed
void LibrarySystem::returnItem() {
    int id;
    cout << "Enter ID to return: ";
    cin >> id; cin.ignore();
    for (auto item : items) {
        if (item->getId() == id) {
            if (item->getIsBorrowed()) {
                item->setIsBorrowed(false);
                cout << "Item returned.\n";
            } else {
                cout << "Item was not borrowed.\n";
            }
            return;
        }
    }
    cout << "Item not found.\n";
}

// Displays information for all items in the library
void LibrarySystem::displayAll() {
    for (auto item : items) {
        item->displayInfo();
    }
}
