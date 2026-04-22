#ifndef BOOKMARK_H // Header Guard : Prevents the file from being included more than once
#define BOOKMARK_H
#include <string>

// Encapsulation: We group data and methods together.
class Bookmark {
private: // Private Class: Only accessible by functions inside this class
    std::string name;
    std::string url;
    int visitCount;

public: // Public Class: This can be called from the main.cpp
    Bookmark(std::string bookmarkName, std::string bookmarkUrl); // Constructor (Initializes the object when it is created.)
    void rename(std::string newName); // Renames the bookmark
    void visit(); // Increments the visit count by 1
    void printInfo(); // Prints the bookmark list to the console
    void openInBrowser(); // Launches the bookmark in the default browser
};
#endif