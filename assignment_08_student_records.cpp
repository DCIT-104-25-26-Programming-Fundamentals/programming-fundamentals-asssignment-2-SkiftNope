// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Defining the struct
struct Student {
    string name;
    int id;
    vector<double> scores;
};

// FUNCTION 1: Add a Student
void addStudent(vector<Student>& students) {
    Student s;

    cout << "Student name: ";
    getline(cin, s.name);

    cout << "Student ID: ";
    cin >> s.id;

    int count;
    cout << "How many scores? ";
    cin >> count;

    s.scores.resize(count);
    for (int i = 0; i < count; i++) {
        cout << "Enter score " << i + 1 << ": ";
        cin >> s.scores[i];
    }

    cin.ignore(); 

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully.\n\n";
}

// FUNCTION 2: Display All Students
void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet.\n\n";
        return;
    }

    cout << "--------------------------------------------------\n";
    cout << "Name           ID          Scores         Average\n";
    cout << "--------------------------------------------------\n";

    for (const auto& s : students) {
        cout << left << setw(15) << s.name
             << setw(12) << s.id;

        // Print scores
        string scoreList = "";
        for (double sc : s.scores) {
            scoreList += to_string((int)sc) + ", ";
        }
        if (!scoreList.empty()) scoreList.pop_back(), scoreList.pop_back();

        cout << setw(15) << scoreList;

        // Average
        double avg = 0;
        for (double sc : s.scores) avg += sc;
        avg /= s.scores.size();

        cout << fixed << setprecision(2) << avg << "\n";
    }

    cout << "--------------------------------------------------\n\n";
}

// FUNCTION 3: Calculate Average Score for a Student
void calculateAverage(const vector<Student>& students) {
    int searchID;
    cout << "Enter student ID: ";
    cin >> searchID;

    for (const auto& s : students) {
        if (s.id == searchID) {
            double avg = 0;
            for (double sc : s.scores) avg += sc;
            avg /= s.scores.size();

            cout << s.name << "'s average score: "
                 << fixed << setprecision(2) << avg << "\n\n";
            return;
        }
    }

    cout << "Error: Student ID not found.\n\n";
}

// The program
int main() {
    vector<Student> students;

    while (true) {
        cout << "===============================\n";
        cout << "   STUDENT RECORD SYSTEM MENU\n";
        cout << "===============================\n";
        cout << "1. Add student\n";
        cout << "2. Display all students\n";
        cout << "3. Calculate average score\n";
        cout << "4. Quit\n";
        cout << "Enter your choice (1-4): ";

        int choice;
        cin >> choice;
        cin.ignore(); 

        if (choice == 1) {
            addStudent(students);
        }
        else if (choice == 2) {
            displayStudents(students);
        }
        else if (choice == 3) {
            calculateAverage(students);
        }
        else if (choice == 4) {
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid choice. Please enter a number between 1 and 4.\n\n";
        }
    }

    return 0;
}

