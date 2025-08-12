#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), utils(new LibraryUtils(this)) {
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);

    // Input fields
    titleEdit = new QLineEdit(this);
    authorEdit = new QLineEdit(this);
    genreEdit = new QLineEdit(this);
    issueEdit = new QLineEdit(this);

    mainLayout->addWidget(new QLabel("Title:", this));
    mainLayout->addWidget(titleEdit);
    mainLayout->addWidget(new QLabel("Author:", this));
    mainLayout->addWidget(authorEdit);
    mainLayout->addWidget(new QLabel("Genre (for Book):", this));
    mainLayout->addWidget(genreEdit);
    mainLayout->addWidget(new QLabel("Issue Number (for Magazine):", this));
    mainLayout->addWidget(issueEdit);

    // Buttons
    QHBoxLayout* buttonLayout = new QHBoxLayout;
    addBookButton = new QPushButton("Add Book", this);
    addMagazineButton = new QPushButton("Add Magazine", this);
    borrowButton = new QPushButton("Borrow", this);
    returnButton = new QPushButton("Return", this);
    buttonLayout->addWidget(addBookButton);
    buttonLayout->addWidget(addMagazineButton);
    buttonLayout->addWidget(borrowButton);
    buttonLayout->addWidget(returnButton);
    mainLayout->addLayout(buttonLayout);

    // Search
    searchEdit = new QLineEdit(this);
    searchButton = new QPushButton("Search", this);
    mainLayout->addWidget(new QLabel("Search by Title/Author:", this));
    mainLayout->addWidget(searchEdit);
    mainLayout->addWidget(searchButton);

    // Item list
    itemListWidget = new QListWidget(this);
    mainLayout->addWidget(itemListWidget);

    // Connect signals
    connect(addBookButton, &QPushButton::clicked, this, &MainWindow::addBook);
    connect(addMagazineButton, &QPushButton::clicked, this, &MainWindow::addMagazine);
    connect(borrowButton, &QPushButton::clicked, this, &MainWindow::borrowItem);
    connect(returnButton, &QPushButton::clicked, this, &MainWindow::returnItem);
    connect(searchButton, &QPushButton::clicked, this, &MainWindow::searchItems);

    // Load data
    utils->loadFromFile("library_data.txt", storage);
    updateItemList();
}

void MainWindow::addBook() {
    if (titleEdit->text().isEmpty() || authorEdit->text().isEmpty() || genreEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill in all fields for Book.");
        return;
    }
    auto book = QSharedPointer<Book>::create(titleEdit->text(), authorEdit->text(), storage.getNextId(), genreEdit->text());
    storage.addItem(book);
    utils->saveToFile("library_data.txt", storage);
    updateItemList();
    QMessageBox::information(this, "Success", "Book added successfully.");
}

void MainWindow::addMagazine() {
    if (titleEdit->text().isEmpty() || authorEdit->text().isEmpty() || issueEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill in all fields for Magazine.");
        return;
    }
    bool ok;
    int issue = issueEdit->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Error", "Invalid issue number.");
        return;
    }
    auto magazine = QSharedPointer<Magazine>::create(titleEdit->text(), authorEdit->text(), storage.getNextId(), issue);
    storage.addItem(magazine);
    utils->saveToFile("library_data.txt", storage);
    updateItemList();
    QMessageBox::information(this, "Success", "Magazine added successfully.");
}

void MainWindow::borrowItem() {
    if (!itemListWidget->currentItem()) {
        QMessageBox::warning(this, "Error", "Select an item to borrow.");
        return;
    }
    int id = itemListWidget->currentItem()->data(Qt::UserRole).toInt();
    auto item = storage.findItem(id);
    if (item && !item->getIsBorrowed()) {
        item->setIsBorrowed(true);
        utils->saveToFile("library_data.txt", storage);
        updateItemList();
        QMessageBox::information(this, "Success", "Item borrowed successfully.");
    } else {
        QMessageBox::warning(this, "Error", item ? "Item already borrowed." : "Item not found.");
    }
}

void MainWindow::returnItem() {
    if (!itemListWidget->currentItem()) {
        QMessageBox::warning(this, "Error", "Select an item to return.");
        return;
    }
    int id = itemListWidget->currentItem()->data(Qt::UserRole).toInt();
    auto item = storage.findItem(id);
    if (item && item->getIsBorrowed()) {
        item->setIsBorrowed(false);
        utils->saveToFile("library_data.txt", storage);
        updateItemList();
        QMessageBox::information(this, "Success", "Item returned successfully.");
    } else {
        QMessageBox::warning(this, "Error", item ? "Item not borrowed." : "Item not found.");
    }
}

void MainWindow::searchItems() {
    itemListWidget->clear();
    auto results = storage.searchByKeyword(searchEdit->text());
    for (const auto& item : results) {
        QString display = QString("%1: %2 by %3 (%4)").arg(item->getType(), item->getTitle(), item->getAuthor(), item->getIsBorrowed() ? "Borrowed" : "Available");
        QListWidgetItem* listItem = new QListWidgetItem(display, itemListWidget);
        listItem->setData(Qt::UserRole, item->getId());
    }
}

void MainWindow::updateItemList() {
    itemListWidget->clear();
    for (const auto& item : storage.getItems()) {
        QString display = QString("%1: %2 by %3 (%4)").arg(item->getType(), item->getTitle(), item->getAuthor(), item->getIsBorrowed() ? "Borrowed" : "Available");
        QListWidgetItem* listItem = new QListWidgetItem(display, itemListWidget);
        listItem->setData(Qt::UserRole, item->getId());
    }
}
