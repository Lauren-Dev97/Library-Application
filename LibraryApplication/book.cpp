#include "Book.h"
#include <QDebug>

Book::Book(const QString& t, const QString& a, int i, const QString& g, QObject* parent)
    : LibraryItem(t, a, i, parent), genre(g) {}

void Book::displayInfo() const {
    qDebug() << "[Book] ID:" << id << ", Title:" << title << ", Author:" << author
             << ", Genre:" << genre << ", Borrowed:" << (isBorrowed ? "Yes" : "No");
}

QString Book::getType() const { return "Book"; }

QString Book::serialize() const {
    return QString("Book|%1|%2|%3|%4|%5").arg(title, author, QString::number(id), genre, isBorrowed ? "1" : "0");
}
