#include "LibraryUtils.h"
#include <QTextStream>
#include <QDebug>

LibraryUtils::LibraryUtils(QObject* parent) : QObject(parent) {}

void LibraryUtils::saveToFile(const QString& filename, const Storage<LibraryItem>& storage) {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (const auto& item : storage.getItems()) {
            out << item->serialize() << "\n";
        }
        file.close();
    }
}

void LibraryUtils::loadFromFile(const QString& filename, Storage<LibraryItem>& storage) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split("|");
        if (parts.size() < 5) continue;

        QString type = parts[0];
        QString title = parts[1];
        QString author = parts[2];
        int id = parts[3].toInt();
        bool isBorrowed = parts[parts.size() - 1] == "1";

        if (type == "Book" && parts.size() == 6) {
            QString genre = parts[4];
            auto book = QSharedPointer<Book>::create(title, author, id, genre);
            book->setIsBorrowed(isBorrowed);
            storage.addItem(book);
        } else if (type == "Magazine" && parts.size() == 6) {
            int issue = parts[4].toInt();
            auto magazine = QSharedPointer<Magazine>::create(title, author, id, issue);
            magazine->setIsBorrowed(isBorrowed);
            storage.addItem(magazine);
        }
    }
    file.close();
}

void LibraryUtils::sortItems(Storage<LibraryItem>& storage, const QString& criterion) {
    auto& items = const_cast<QList<QSharedPointer<LibraryItem>>&>(storage.getItems());
    std::sort(items.begin(), items.end(), [criterion](const QSharedPointer<LibraryItem>& a, const QSharedPointer<LibraryItem>& b) {
        if (criterion == "title") return a->getTitle() < b->getTitle();
        if (criterion == "author") return a->getAuthor() < b->getAuthor();
        return a->getId() < b->getId();
    });
}
