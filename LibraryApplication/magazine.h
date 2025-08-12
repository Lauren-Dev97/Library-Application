#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "LibraryItem.h"

class Magazine : public LibraryItem {
    Q_OBJECT
private:
    int issueNumber;

public:
    Magazine(const QString& t, const QString& a, int i, int issue, QObject* parent = nullptr);
    void displayInfo() const override;
    QString getType() const override;
    QString serialize() const override;
};

#endif // MAGAZINE_H
