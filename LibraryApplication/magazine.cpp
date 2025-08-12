#include "Magazine.h"
#include <QDebug>

Magazine::Magazine(const QString& t, const QString& a, int i, int issue, QObject* parent)
    : LibraryItem(t, a, i, parent), issueNumber(issue) {}

void Magazine::displayInfo() const {
    qDebug() << "[Magazine] ID:" << id << ", Title:" << title << ", Author:" << author
             << ", Issue #:" << issueNumber << ", Borrowed:" << (isBorrowed ? "Yes" : "No");
}

QString Magazine::getType() const { return "Magazine"; }

QString Magazine::serialize() const {
    return QString("Magazine|%1|%2|%3|%4|%5").arg(title, author, QString::number(id), QString::number(issueNumber), isBorrowed ? "1" : "0");
}
