#include "Bookmark.h"
#include <iostream>
#include <windows.h>  // Required for Windows to open the browser ( A Library that allows c++ to talk to the Windows Operating System)
#include <shellapi.h> // Required for ShellExecute command

using namespace std;

// Tells the compiler these functions belong to the bookmark class
Bookmark::Bookmark(string bookmarkName, string bookmarkUrl) {
    name = bookmarkName;

    // URL Validation and fix
    // Look for https:// at the start and add it to the start if it is missing
    if (bookmarkUrl.find("https://") != 0) {
        cout << "\nWARNING !! Incorrect URL syntax for the bookmark " << name << ". Fixing URL...." << endl;
        bookmarkUrl = "https://" + bookmarkUrl;
    }

    // Remove junk (unnecessary special characters) from the end
    while (!bookmarkUrl.empty() && !isalnum(bookmarkUrl.back())) { // isalnum() checks if the entered character is alphanumeric or not
        bookmarkUrl.pop_back(); // Removes junk characters from the back
    }

    // Look for .com in the end and add it if it is missing
    if (bookmarkUrl.size() < 4 || bookmarkUrl.substr(bookmarkUrl.size() - 4) != ".com") {
        bookmarkUrl += ".com";
    }

    url = bookmarkUrl;

    visitCount = 0; // Each new bookmark starts with 0 visits
}

// Renames the bookmark
void Bookmark::rename(string newName) {
    name = newName;
}

// Visits the bookmark and increments the visit counter by 1
void Bookmark::visit() {
    visitCount++;
}

// Prints the information to the console
void Bookmark::printInfo() {
    cout << "Name: " << name << " | URL: " << url
              << " | Visits: " << visitCount << endl;
}

// Opens the URl in your default browser
void Bookmark::openInBrowser() {
    cout << "\nOpening the bookmark,'" << name << "' in your browser..." << endl;
    ShellExecuteA(NULL , "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
    //NULL- For pop up, IpParameters- For extra info(opening a specific tab), IpDirectory-which folder to start in, nShowCmd- how to appear(shownormal - default size)
}