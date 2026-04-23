#include <iostream>
#include <vector>
#include "Bookmark.h"

using namespace std;

int main() {
    // Vector to store the 5 Bookmarks
    vector<Bookmark>myBookmarks;

    // Creating the 5 bookmarks
    myBookmarks.push_back(Bookmark("Google", "google...,,,,"));
    myBookmarks.push_back(Bookmark("Youtube", "www.youtube//:::"));
    myBookmarks.push_back(Bookmark("Outlook", "https://outlook.office.com"));
    myBookmarks.push_back(Bookmark("Github", "https://www.github.com"));
    myBookmarks.push_back(Bookmark("ESPNCricinfo", "https://www.espncricinfo"));

    // Print the Initial bookmark list to the console
    cout << "\nBookmark List: " << endl;
    for (int i = 0; i < myBookmarks.size(); i++) {
        myBookmarks[i].printInfo();
    }

    // Modify and Visit the bookmarks
    // Rename ESPNCricinfo and visit it a few times
    myBookmarks[4].rename("Cricket Updates");
    myBookmarks[4].visit();
    myBookmarks[4].visit();
    myBookmarks[4].visit();
    myBookmarks[4].visit();
    myBookmarks[4].visit();

    // Rename Outlook and visit it a few times
    myBookmarks[2].rename("Mail");
    myBookmarks[2].visit();
    myBookmarks[2].visit();
    myBookmarks[2].visit();
    myBookmarks[2].visit();

    // Visit YouTube a
    myBookmarks[1].visit();

    // Visit Google a few times
    myBookmarks[0].visit();
    myBookmarks[0].visit();
    myBookmarks[0].visit();

    // Visit GitHub a few times
    myBookmarks[3].visit();
    myBookmarks[3].visit();

    // Opening the URls in the default browser
    /*myBookmarks[0].openInBrowser();
    myBookmarks[1].openInBrowser();
    myBookmarks[2].openInBrowser();
    myBookmarks[3].openInBrowser();
    myBookmarks[4].openInBrowser();*/


    // Print the Updated Bookmark List to the console
    cout << "\nUpdated Bookmark List: " << endl;
    for (int i = 0; i < myBookmarks.size(); i++) {
        myBookmarks[i].printInfo();
    }

    return 0;
}
