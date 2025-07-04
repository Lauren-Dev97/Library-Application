#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H // Include guard to prevent multiple inclusions

#include <string>
using namespace std;

//Base class

class LibraryItem {
protected:
    string title;
    string author;
    int id;
    bool isBorrowed;

public:
    // Constructor
    LibraryItem (string t, string a, int i);
    //Virtual destructor
    virtual ~LibraryItem() = default;

    //Getters
    string getTitle() const;
    string getAuthor() const;
    int getId() const;
    bool getIsBorrowed() const;
    void setIsBorrowed(bool status);

    //Setters
    virtual void displayInfo() const = 0;
    virtual string getType() const = 0;
    virtual string serialize() const = 0;
    virtual string toFileString() const = 0;
};


#endif // LIBRARYITEM_H
