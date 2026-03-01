#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Course {
    string courseNumber;              // e.g., "CSCI300"
    string title;                     // e.g., "Introduction to Algorithms"
    vector<string> prerequisites;     // e.g., {"CSCI200", "MATH201"}
};

// ---------- Utility helpers ----------
static inline string trim(const string& s) {
    size_t start = 0;
    while (start < s.size() && isspace(static_cast<unsigned char>(s[start]))) {
        start++;
    }
    size_t end = s.size();
    while (end > start && isspace(static_cast<unsigned char>(s[end - 1]))) {
        end--;
    }
    return s.substr(start, end - start);
}

static inline string toUpper(string s) {
    for (char& ch : s) {
        ch = static_cast<char>(toupper(static_cast<unsigned char>(ch)));
    }
    return s;
}

static vector<string> splitCSVLine(const string& line) {
    // Simple CSV split (works for this project’s input; titles have no quoted commas)
    vector<string> tokens;
    string token;
    stringstream ss(line);

    while (getline(ss, token, ',')) {
        tokens.push_back(trim(token));
    }
    return tokens;
}

// ---------- Core program functions ----------
static bool loadCoursesFromFile(const string& fileName, map<string, Course>& courses) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Error: Could not open file \"" << fileName << "\"." << endl;
        return false;
    }

    courses.clear();

    string line;
    unsigned int lineNumber = 0;

    while (getline(file, line)) {
        lineNumber++;
        line = trim(line);

        if (line.empty()) {
            continue; // skip blank lines
        }

        vector<string> parts = splitCSVLine(line);

        // Expect at least: courseNumber, title
        if (parts.size() < 2 || parts[0].empty() || parts[1].empty()) {
            cout << "Warning: Skipping malformed line " << lineNumber << "." << endl;
            continue;
        }

        Course c;
        c.courseNumber = toUpper(parts[0]);
        c.title = parts[1];

        // Any additional tokens are prerequisites (may be empty in some files)
        for (size_t i = 2; i < parts.size(); i++) {
            if (!parts[i].empty()) {
                c.prerequisites.push_back(toUpper(parts[i]));
            }
        }

        courses[c.courseNumber] = c;
    }

    // warn about prerequisites that aren't present in the loaded data
    for (const auto& kv : courses) {
        const Course& c = kv.second;
        for (const string& prereq : c.prerequisites) {
            if (courses.find(prereq) == courses.end()) {
                cout << "Warning: " << c.courseNumber
                     << " lists prerequisite " << prereq
                     << " which was not found in the file." << endl;
            }
        }
    }

    return true;
}

static void printMenu() {
    cout << "1. Load Data Structure." << endl;
    cout << "2. Print Course List." << endl;
    cout << "3. Print Course." << endl;
    cout << "9. Exit" << endl;
}

static void printCourseList(const map<string, Course>& courses) {
    cout << "Here is a sample schedule:" << endl;

    for (const auto& kv : courses) {
        const Course& c = kv.second;
        cout << c.courseNumber << ", " << c.title << endl;
    }
}

static void printCourseInformation(const map<string, Course>& courses) {
    cout << "What course do you want to know about? ";
    string input;
    getline(cin, input);
    input = toUpper(trim(input));

    auto it = courses.find(input);
    if (it == courses.end()) {
        cout << "Course not found: " << input << endl;
        return;
    }

    const Course& c = it->second;
    cout << c.courseNumber << ", " << c.title << endl;

    if (c.prerequisites.empty()) {
        cout << "Prerequisites: None" << endl;
        return;
    }

    cout << "Prerequisites: ";
    for (size_t i = 0; i < c.prerequisites.size(); i++) {
        cout << c.prerequisites[i];
        if (i + 1 < c.prerequisites.size()) {
            cout << ", ";
        }
    }
    cout << endl;
}

static int readMenuChoice() {
    cout << "What would you like to do? ";
    string line;
    getline(cin, line);
    line = trim(line);

    // Handles non-numeric input
    if (line.empty()) {
        return -1;
    }
    for (char ch : line) {
        if (!isdigit(static_cast<unsigned char>(ch))) {
            return -1;
        }
    }
    return stoi(line);
}

int main() {
    cout << "Welcome to the course planner." << endl;

    map<string, Course> courses;
    bool isLoaded = false;

    while (true) {
        printMenu();

        int choice = readMenuChoice();

        if (choice == 1) {
            cout << "Enter file name: ";
            string fileName;
            getline(cin, fileName);
            fileName = trim(fileName);

            if (fileName.empty()) {
                cout << "Error: File name cannot be empty." << endl;
                continue;
            }

            isLoaded = loadCoursesFromFile(fileName, courses);
            if (isLoaded) {
                // No extra success text in the sample output
            }
        }
        else if (choice == 2) {
            if (!isLoaded) {
                cout << "Please load the data structure first (Option 1)." << endl;
                continue;
            }
            printCourseList(courses);
        }
        else if (choice == 3) {
            if (!isLoaded) {
                cout << "Please load the data structure first (Option 1)." << endl;
                continue;
            }
            printCourseInformation(courses);
        }
        else if (choice == 9) {
            cout << "Thank you for using the course planner!" << endl;
            break;
        }
        else {
            // Match sample behavior: "<x> is not a valid option."
            if (choice == -1) {
                cout << "That is not a valid option." << endl;
            } else {
                cout << choice << " is not a valid option." << endl;
            }
        }
    }

    return 0;
}