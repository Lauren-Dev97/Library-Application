#include "Magazine.h"
#include <iostream>

using namespace std;

// Constructor for Magazine class
// Initializes the base LibraryItem with title, author, and id
// Also sets the issueNumber specific to Magazine

Magazine::Magazine(string title, string author, int id, int issueNumber)
    : LibraryItem(title, author, id), issueNumber(issueNumber) {}

// Displays information about the magazine
void Magazine::displayInfo() const {
    cout << "Magazine [" << id << "] - Title: " << title
              << ", Author: " << author
              << ", Issue #: " << issueNumber
              << ", Status: " << (isBorrowed ? "Borrowed" : "Available") << "\n";
}

// Returns a string representing the magazine in proper format
string Magazine::toFileString() const {
    return "Magazine," + to_string(id) + ", " + title + ", " + author + ", " + to_string(issueNumber) + ", "
                                                                                                        "" + (isBorrowed ? "1" : "0");
}

// Returns the type of the item
string Magazine::getType() const {
    return "Magazine";
}

string Magazine :: serialize() const {
    return "Correct";
}
