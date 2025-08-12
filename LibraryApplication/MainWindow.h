#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include "Storage.h"
#include "LibraryUtils.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);

private slots:
    void addBook();
    void addMagazine();
    void borrowItem();
    void returnItem();
    void searchItems();
    void updateItemList();

private:
    Storage<LibraryItem> storage;
    LibraryUtils* utils;
    QListWidget* itemListWidget;
    QLineEdit* searchEdit;
    QLineEdit* titleEdit;
    QLineEdit* authorEdit;
    QLineEdit* genreEdit;
    QLineEdit* issueEdit;
    QPushButton* addBookButton;
    QPushButton* addMagazineButton;
    QPushButton* borrowButton;
    QPushButton* returnButton;
    QPushButton* searchButton;
};

#endif // MAINWINDOW_H
