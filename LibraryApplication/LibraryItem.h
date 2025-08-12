#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <QString>
#include <QObject>

class LibraryItem : public QObject {
    Q_OBJECT
protected:
    QString title;
    QString author;
    int id;
    bool isBorrowed;

public:
    LibraryItem(const QString& t, const QString& a, int i, QObject* parent = nullptr);
    virtual ~LibraryItem() = default;

    int getId() const;
    bool getIsBorrowed() const;
    void setIsBorrowed(bool status);
    QString getTitle() const;
    QString getAuthor() const;

    virtual void displayInfo() const = 0;
    virtual QString getType() const = 0;
    virtual QString serialize() const = 0;
};

#endif // LIBRARYITEM_H
