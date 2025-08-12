#ifndef STORAGE_H
#define STORAGE_H

#include <QList>
#include <QSharedPointer>
#include "LibraryItem.h"

template<typename T>
class Storage {
private:
    QList<QSharedPointer<T>> items;
    int nextId;

public:
    Storage() : nextId(1) {}

    void addItem(QSharedPointer<T> item) {
        items.append(item);
        nextId = qMax(nextId, item->getId() + 1);
    }

    void removeItem(int id) {
        items.erase(std::remove_if(items.begin(), items.end(),
                                   [id](const QSharedPointer<T>& item) { return item->getId() == id; }), items.end());
    }

    QSharedPointer<T> findItem(int id) const {
        for (const auto& item : items) {
            if (item->getId() == id) return item;
        }
        return nullptr;
    }

    QList<QSharedPointer<T>> searchByKeyword(const QString& keyword) const {
        QList<QSharedPointer<T>> results;
        for (const auto& item : items) {
            if (item->serialize().contains(keyword, Qt::CaseInsensitive)) {
                results.append(item);
            }
        }
        return results;
    }

    const QList<QSharedPointer<T>>& getItems() const { return items; }
    int getNextId() const { return nextId; }
};

#endif // STORAGE_H
