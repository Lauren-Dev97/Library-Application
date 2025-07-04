#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include "LibraryItem.h"
#include "Book.h"
#include "Magazine.h"
#include <vector>
#include <string>

using namespace std;

class LibrarySystem {
private:
    vector<LibraryItem*> items;
    int nextId;
    string filename = "library_data.txt";

public:
    //Constructor
    LibrarySystem();
    //Destructor
    ~LibrarySystem();

    void loadFromFile(const string& filename);
    void saveToFile(const string& filename);

    void addBook();
    void addMagazine();
    void searchItem();
    void borrowItem();
    void returnItem();
    void displayAll();

};

#endif // LIBRARYSYSTEM_H

