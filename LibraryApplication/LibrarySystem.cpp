#include "LibrarySystem.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

void LibrarySystem::loadFromFile(const string& filename) {
    ifstream fin(filename);
    if (!fin) return;

    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        string type, title, author, genre;
        int id, issue;
        string status;
        getline(ss, type, '|');
        getline(ss, title, '|');
        getline(ss, author, '|');
        ss >> id;
        ss.ignore();

        if (type == "Book") {
            getline(ss, genre, '|');
            getline(ss, status);
            auto book = make_shared<Book>(title, author, id, genre);
            book->setIsBorrowed(status == "1");
            items.push_back(book);
        } else if (type == "Magazine") {
            ss >> issue;
            ss.ignore();
            getline(ss, status);
            auto mag = make_shared<Magazine>(title, author, id, issue);
            mag->setIsBorrowed(status == "1");
            items.push_back(mag);
        }

        nextId = max(nextId, id + 1);
    }

    fin.close();
}

void LibrarySystem::saveToFile(const string& filename) {
    ofstream fout(filename);
    for (auto& item : items)
        fout << item->serialize() << endl;
    fout.close();
}

void LibrarySystem::addBook() {
    string title, author, genre;
    cout << "Enter title: "; cin.ignore(); getline(cin, title);
    cout << "Enter author: "; getline(cin, author);
    cout << "Enter genre: "; getline(cin, genre);

    items.push_back(make_shared<Book>(title, author, nextId++, genre));
    cout << "Book added.\n";
}

void LibrarySystem::addMagazine() {
    string title, author;
    int issue;
    cout << "Enter title: "; cin.ignore(); getline(cin, title);
    cout << "Enter author: "; getline(cin, author);
    cout << "Enter issue number: "; cin >> issue;

    items.push_back(make_shared<Magazine>(title, author, nextId++, issue));
    cout << "Magazine added.\n";
}

void LibrarySystem::displayItems() {
    for (auto& item : items)
        item->displayInfo();
}

void LibrarySystem::borrowItem() {
    int id;
    cout << "Enter ID to borrow: "; cin >> id;
    for (auto& item : items) {
        if (item->getId() == id) {
            if (item->getIsBorrowed()) {
                cout << "Item already borrowed.\n";
                return;
            }
            item->setIsBorrowed(true);
            cout << "Borrowed successfully.\n";
            return;
        }
    }
    cout << "Item not found.\n";
}

void LibrarySystem::returnItem() {
    int id;
    cout << "Enter ID to return: "; cin >> id;
    for (auto& item : items) {
        if (item->getId() == id) {
            if (!item->getIsBorrowed()) {
                cout << "Item wasn't borrowed.\n";
                return;
            }
            item->setIsBorrowed(false);
            cout << "Returned successfully.\n";
            return;
        }
    }
    cout << "Item not found.\n";
}

void LibrarySystem::searchItem() {
    string keyword;
    cout << "Enter title/author keyword: ";
    cin.ignore(); getline(cin, keyword);
    for (auto& item : items) {
        if (item->getType() == "Book" || item->getType() == "Magazine") {
            string info = item->serialize();
            if (info.find(keyword) != string::npos)
                item->displayInfo();
        }
    }
}

void LibrarySystem::menu() {
    int choice;
    do {
        cout << "\nLibrary Menu:\n";
        cout << "1. Add Book\n";
        cout << "2. Add Magazine\n";
        cout << "3. Display Items\n";
        cout << "4. Borrow Item\n";
        cout << "5. Return Item\n";
        cout << "6. Search Item\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addBook(); break;
        case 2: addMagazine(); break;
        case 3: displayItems(); break;
        case 4: borrowItem(); break;
        case 5: returnItem(); break;
        case 6: searchItem(); break;
        case 0: saveToFile("library_data.txt"); break;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}
