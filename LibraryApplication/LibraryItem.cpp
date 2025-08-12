#include "LibraryItem.h"

LibraryItem::LibraryItem(const QString& t, const QString& a, int i, QObject* parent)
    : QObject(parent), title(t), author(a), id(i), isBorrowed(false) {}

int LibraryItem::getId() const { return id; }
bool LibraryItem::getIsBorrowed() const { return isBorrowed; }
void LibraryItem::setIsBorrowed(bool status) { isBorrowed = status; }
QString LibraryItem::getTitle() const { return title; }
QString LibraryItem::getAuthor() const { return author; }
