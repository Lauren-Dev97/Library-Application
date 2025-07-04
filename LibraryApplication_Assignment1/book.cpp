#include "Book.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor for Book class
// Initializes the Book with title, author, id
Book::Book(string title, string author, int id, string genre)
    : LibraryItem(title, author, id), genre(genre) {}

// Displays information about the book, including title, author, genre, and status
void Book::displayInfo() const {
    cout << "Book [" << id << "] - Title: " << title
              << ", Author: " << author
              << ", Genre: " << genre
              << ", Status: " << (isBorrowed ? "Borrowed" : "Available") << "\n";
}

// Returns the type of library item
string Book::getType() const {
    return "Book";
}

string Book :: serialize() const {
    return "Correct";
}

//Converts book's data into suitable format for data storage
string Book::toFileString() const {
    return "Book," + to_string(id) + "," + title + "," + author + "," + genre + "," + (isBorrowed ? "1" : "0");
}
