/* 
CS-210
Project 1: ChadaTech Clock
Dan Randolph
05/25/2025
*/

#include <iostream>
#include <string>
#include <stdexcept> // Include for throwing exceptions for invalid time
#include <limits> // Include for numeric limits, input validation and clearing bad input

using namespace std;

// ------------------ Utility Functions ------------------

// Converts a single-digit number to a two-digit string with leading 0 (4 -> "04")
string twoDigitString(unsigned int n) {
    return (n < 10 ? "0" : "") + to_string(n); // Conditional operator for n < 10
}
// Returns a string with character 'c' repeated 'n' times

string nCharString(size_t n, char c) {
    return string(n, c); // Uses the std:string constructor
}

// ------------------ Clock Class ------------------

// Manage the time and supported operations of the clock display
class Clock {
private:
    unsigned int hour;
    unsigned int minute;
    unsigned int second;

public:
    // Initialize the clock to 00:00:00
    Clock() : hour(0), minute(0), second(0) {}

    // Update the hour, minute & second to a valid, desired time
    void setTime(unsigned int h, unsigned int m, unsigned int s) {
        if (h < 24 && m < 60 && s < 60) { // Confirms user input is a supported value
            hour = h;
            minute = m;
            second = s;
        }
        else {
            throw invalid_argument("Invalid time input.");
        }
    }

    // Increments hour by 1, wraps back to 0 after 23
    void addOneHour() {
        hour = (hour + 1) % 24;
    }

    // Increments minute by 1, after 60 adds 1 hour and wraps back to 0
    void addOneMinute() {
        minute++;
        if (minute >= 60) {
            minute = 0;
            addOneHour();
        }
    }

    // Increments second by 1, after 60 adds 1 minute and wraps back to 0
    void addOneSecond() {
        second++;
        if (second >= 60) {
            second = 0;
            addOneMinute();
        }
    }

    // format time output in 24-hour format as hh:mm:ss
    string formatTime24() const {
        return twoDigitString(hour) + ":" + twoDigitString(minute) + ":" + twoDigitString(second);
    }

    // format time output in 12-hour format as hh:mm:ss AM/PM
    string formatTime12() const {
        string period = (hour >= 12) ? "P M" : "A M";
        unsigned int h = hour % 12;
        if (h == 0) {
            h = 12;
        }
        return twoDigitString(h) + ":" + twoDigitString(minute) + ":" + twoDigitString(second) + " " + period;
    }
};

// ------------------ Clock Display Class ------------------

// Handles display output for both 12-hour and 12-hour clocks
class ClockDisplay {
public:
    static void show(const Clock& clock) {
        cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl; // Top * border

        cout << "*      12-HOUR CLOCK      *   *      24-HOUR CLOCK      *" << endl; // 12 & 24 hour clock labels

        cout << "*      " << clock.formatTime12() << "       *   *        "
            << clock.formatTime24() << "         *" << endl; // Formatted display of the respective time

        cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl; // Bottom * border
    }
};

// ------------------ Clock Menu Class ------------------

// Control the user input and menu operations
class ClockMenu {
private:
    Clock clock; // Clock instance

public:
    // Entry point for the menu loop
    void run() {
        cout << "Welcome to your ChadaTech Clock Program!" << endl;
        setInitialTime(); // Clock requires the initial time to be set here

        while (true) {
            cout << endl;
            ClockDisplay::show(clock); // This shows the current time
            showMenu(); // This shows the menu options

            int choice = getChoice(); // Get the user choice from menu

            // Handle the menu selection using a switch statement
            switch (choice) {
                case 1:
                    clock.addOneHour(); // Menu option 1 to add 1 hour
                    break;
                case 2:
                    clock.addOneMinute(); // Menu option 2 to add 1 minute
                    break;
                case 3:
                    clock.addOneSecond(); // Menu option 3 to add 1 second
                    break;
                case 4:
                    cout << "Goodbye for now!" << endl; // Option 4 to Exit program 
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl; // Unsupported menu option 
            }
        }
    }

private:
    // Request time for initial display of clock
    void setInitialTime() {
        unsigned int h, m, s;

        while (true) {
            cout << "\nSet the current time (24-hour):" << endl;

            // Designate hour
            cout << "Hour (0-23): ";
            cin >> h; // set hour to user input

            // Designate minute
            cout << "Minute (0-59): ";
            cin >> m; // set minute to user input

            // Designate second
            cout << "Second (0-59): ";
            cin >> s; // set second to user input

            // Sanity check user input is a valid numeric value
            if (cin.fail()) {
                cin.clear(); // clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
                cout << "ERROR" << endl
                     << "Time input required. Please enter a supported numeric value.\n";
                continue;
            }

            // Sanity check user inputs are in the correct respective range
            if (h < 24 && m < 60 && s < 60) {
                clock.setTime(h, m, s);
                break; // exit loop if time is correct
            }
            // Retry user input if input is outside respective range
            else {
                cout << "Invalid time entered. Please try again.\n" << endl;
            }
        }
    }
    // Display the user menu with 4 supported options
    void showMenu() {
        const string options[] = { // store options in array for easy access
            "Add One Hour",
            "Add One Minute",
            "Add One Second",
            "Exit Program"
        };
        const int menuWidth = 30;

        // Output top border for menu
        cout << endl << nCharString(menuWidth, '*') << endl;
        // Loop through Menu choices 1-3
        for (int i = 0; i < 4; ++i) {
            int padding = menuWidth - (int(options[i].length()) + 7);
            cout << "* " << i + 1 << " - " << options[i]
                << nCharString(padding, ' ') << "*" << endl;
        }
        // Output bottom border for menu
        cout << nCharString(menuWidth, '*') << endl;

        cout << endl; // Added a new line to clean up output display
    }
    
    // Captures user choice and takes necessary action
    int getChoice() {
        int choice;
        
        /*Adding a while loop here to handle incorrect user input
        * Found that entering 'a' resulted in unexpected behavior
        */
        while (true) {
            cout << "Enter your choice (1-4): ";
            cin >> choice;

            if (cin.fail()) {
                cin.clear(); // `clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
                cout << "Invalid input detected, use 1-4 to navigate program.\n";
            }
            else if (choice < 1 || choice > 4) {
                cout << "Unsupported Menu option, use 1-4 to navigate program.\n";
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Removes the trailing newline
                return choice; // Confirms user choice is valid
            }
        }
    }
};

// ------------------ Main Entry Point ------------------

/* Main function to start program
 * As minimal code as possible
*/
int main() {
    ClockMenu menu;
    menu.run(); // Launches the menu system
    return 0;
}