// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// Function to compute the sum of numbers
int compute_sum(int numbers[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += numbers[i];
    }
    return total;
}

// Function to compute the average of numbers
double compute_average(int numbers[], int n) {
    int total = compute_sum(numbers, n);
    return (double)total / n;
}

// Function to find the maximum number
int compute_max(int numbers[], int n) {
    int maximum = numbers[0];
    for (int i = 1; i < n; i++) {
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
    }
    return maximum;
}

// Function to find the minimum number
int compute_min(int numbers[], int n) {
    int minimum = numbers[0];
    for (int i = 1; i < n; i++) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
    }
    return minimum;
}

int main() {
    int n;
    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: Number of items must be a positive integer.";
        return 0;
    }

    int nums[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> nums[i];
    }

    cout << "\nResults:\n";
    cout << "Sum:     " << compute_sum(nums, n) << endl;
    cout << "Average: " << compute_average(nums, n) << endl;
    cout << "Maximum: " << compute_max(nums, n) << endl;
    cout << "Minimum: " << compute_min(nums, n) << endl;

    return 0;
}


