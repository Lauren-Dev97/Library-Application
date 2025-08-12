#ifndef LIBRARYUTILS_H
#define LIBRARYUTILS_H

#include <QObject>
#include <QFile>
#include "Storage.h"
#include "Book.h"
#include "Magazine.h"

class LibraryUtils : public QObject {
    Q_OBJECT
public:
    explicit LibraryUtils(QObject* parent = nullptr);

    void saveToFile(const QString& filename, const Storage<LibraryItem>& storage);
    void loadFromFile(const QString& filename, Storage<LibraryItem>& storage);
    void sortItems(Storage<LibraryItem>& storage, const QString& criterion);
};

#endif // LIBRARYUTILS_H
