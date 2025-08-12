#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include <QObject>
#include <QSharedDataPointer>

class LibraryStystemData;

class LibraryStystem
{
public:
    LibraryStystem();
    LibraryStystem(const LibraryStystem &);
    LibraryStystem(LibraryStystem &&);
    LibraryStystem &operator=(const LibraryStystem &);
    LibraryStystem &operator=(LibraryStystem &&);
    ~LibraryStystem();

private:
    QSharedDataPointer<LibraryStystemData> data;
};

#endif // LIBRARYSYSTEM_H
