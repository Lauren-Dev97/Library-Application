#pragma once //Ensures the header is only included once
#include "LibraryItem.h" //Includes base class 'LibraryItem'
#include <string>

class Book : public LibraryItem {
private:
    string genre; // Adds genre to derived class 'Book'

public:
    //Constructor
    Book(string t, string a, int i, string g);

    //Displays details of book
    void displayInfo() const override;
    //Returns the type
    string getType() const override;
    string serialize() const override;
    string toFileString() const override;

    //Getter for new added attribute
    string getGenre() const;
};
