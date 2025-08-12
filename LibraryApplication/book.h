#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"

class Book : public LibraryItem {
    Q_OBJECT
private:
    QString genre;

public:
    Book(const QString& t, const QString& a, int i, const QString& g, QObject* parent = nullptr);
    void displayInfo() const override;
    QString getType() const override;
    QString serialize() const override;
};

#endif // BOOK_H
