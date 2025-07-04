#include "LibraryItem.h"

// Constructor for LibraryItem
// Initializes the title, author, and ID of the item
// Sets isBorrowed to false by default
LibraryItem::LibraryItem(string title, string author, int id)
    : title(title), author(author), id(id), isBorrowed(false) {}

string LibraryItem::getTitle() const { return title; }   //returns title of library item
string LibraryItem::getAuthor() const { return author; } //returns author of library item
int LibraryItem::getId() const { return id; } //Returns unique id of item
bool LibraryItem::getIsBorrowed() const { return isBorrowed; } //Returns borrowed status
void LibraryItem::setIsBorrowed(bool status) { isBorrowed = status;} //sets borrowed status of library item
