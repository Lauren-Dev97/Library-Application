==============================
Library Management System
==============================

Author: Lauren Louw
Date: 22/05/2025
Course: COS2614
Assignment: Library Management System (Console-based C++ Application)

==============================
PROJECT DESCRIPTION
==============================
This is a console-based Library Management System developed using C++ and Qt Creator. 
The system demonstrates key Object-Oriented Programming (OOP) principles such as:
- Encapsulation
- Inheritance
- Polymorphism
- Abstraction

It allows users to:
- Add books and magazines
- Search for items
- Borrow and return items
- Save and load data from a file

==============================
FILE STRUCTURE
==============================
The project contains the following files:

Source Files:
- main.cpp
- book.cpp
- magazine.cpp
- libraryitem.cpp
- librarysystem.cpp

Header Files:
- book.h
- magazine.h
- libraryitem.h
- librarysystem.h

Other:
- Library_Data.txt (persistent storage of items)
- LibrarySystem.pro (Qt project file)
- README.txt (this file)

==============================
HOW TO BUILD AND RUN
==============================

1. Open Qt Creator.
2. Select "Open Project" and choose `LibrarySystem.pro`.
3. Once opened, click the "Run" button or press `Ctrl + R` to build and run.
4. Ensure the file `Library_Data.txt` is placed in the same folder as the compiled executable. 
   This is usually located in:
   - `build-LibrarySystem-Desktop_Qt_*_Debug/debug/`

====================================
DATA FILE FORMAT (Library_Data.txt)
====================================
Each line in the file represents either a Book or a Magazine in CSV format:

For Books:
Book,<id>,<title>,<author>,<genre>,<isBorrowed>

For Magazines:
Magazine,<id>,<title>,<author>,<issueNumber>,<isBorrowed>

Example:
Book,1,The Hobbit,J.R.R. Tolkien,Fantasy,0
Magazine,2,Time,Various,102,1

==============================
NOTES
==============================
- Borrowed status: 0 = Not Borrowed, 1 = Borrowed
- If the file does not exist or is empty, the program starts with no items.
- The file is automatically updated upon closing the program.

==============================
CONTACT
==============================
For questions or support, contact: [Your Email Here]

