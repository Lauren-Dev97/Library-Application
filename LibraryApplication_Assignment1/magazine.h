#pragma once
#include "LibraryItem.h"
#include <string>

// Magazine class derived from LibraryItem
// Represents a magazine with an issue number
class Magazine : public LibraryItem {
private:
    int issueNumber;            // Stores the issue number specific to the magazine

public:
    Magazine(string t, string a, int i, int issue);

    void displayInfo() const override;
    string getType() const override;
    string serialize() const override;
    string toFileString() const override;

    //Getter for issue number
    int getIssueNumber() const;
};
