// Chapter7_GradeBook.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	// Program introduction
	cout << "Welcome to the Grade Book Program!" << endl;
	cout << "This program will calculate the average test scores for 5 students" << endl;
	cout << "and assign a letter grade based on their performanc." << endl;
	cout << "You will enter each student's name and their 4 test scores." << endl;
	cout << "Let's begin!\n" << endl;

	// Constants for number of students and tests
	const int NUM_STUDENTS = 5;
	const int NUM_TESTS = 4;

	// Arrays to store data 
	string studentNames[NUM_STUDENTS];     // Array for studnets names
	char letterGrades[NUM_STUDENTS];      // Array for letter grades
	double testScores[NUM_STUDENTS][NUM_TESTS];  // 2D array for test scores
	double averages[NUM_STUDENTS];        // Array for average scores

	// Loop to gather data for each student
	for (int i = 0; i < NUM_STUDENTS; i++) {
		// Input student name 
		cout << "Enter the name of student" << i + 1 << ":";
		cin >> studentNames[i];

		double sum = 0; // Variable to store the sum of scores for this student

		// Input test scores for the student 
		for (int j = 0; j < NUM_TESTS; j++) {
			double score;
			do {
				cout << "Enter test score" << j + 1 << "for" << studentNames[i] << "(0-100):";
				cin >> score;


				// Validate score input
				if (score < 0 || score > 100) {
					cout << "Invalid score. Please enter a vaule between 0 and 100." << endl;

				}
			} while (score < 0 || score > 100);

			// Store score and add to sum
			testScores[i][j] = score;
			sum += score;
		}

		// Calculate average score for the student
		averages[i] = sum / NUM_TESTS;


		// Assign letter grade based on average score 
		if (averages[i] >= 90) {
			letterGrades[i] = 'A';
		}
		else if (averages[i] >= 80) {
			letterGrades[i] = 'B';
		}
		else if (averages[i] >= 70) {
			letterGrades[i] = 'C';
		}
		else if (averages[i] >= 60) {
			letterGrades[i] = 'D';
		}
		else {
			letterGrades[i] = 'F';
		}
	}

	// Display the results in a formatted table 
	cout << "\nGrade Book:" << endl;
	cout << left << setw(15) << "Name" << setw(10) << "Average" << "Grade" << endl;
	cout << "-------------------------------------" << endl;

	for (int i = 0; i < NUM_STUDENTS; i++) {
		cout << left << setw(15) << studentNames[i]
			<< setw(10) << fixed << setprecision(2) << averages[i]
			<< letterGrades[i] << endl;
	}

	// Programc completion message
	cout << "\nThank you for using the Grade Book Program!" << endl;

	return 0;

}