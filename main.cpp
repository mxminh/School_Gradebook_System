#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "StudentList.h"
#include "ConsoleDisplay.h"

#include <iostream>
#include <string>
#include <vector>


int main() {

	// Initialize the student list
	StudentList studentList;

	// Creates the master list of courses
	Course masterListOfCourses[30] = {
        {5, 101, "Calculus I", 0.0, 100.0},
        {5, 102, "Calculus II", 0.0, 100.0},
        {3, 103, "Algebra", 0.0, 100.0},
        {3, 104, "Geometry", 0.0, 100.0},
        {4, 105, "Trigonometry", 0.0, 100.0},
        {4, 106, "Linear Algebra", 0.0, 100.0},
        {5, 107, "Diff EQs", 0.0, 100.0},
        {3, 108, "Statistics", 0.0, 100.0},
        {3, 109, "Discrete Math", 0.0, 100.0},
        {5, 110, "Physics I", 0.0, 100.0},
        {5, 111, "Physics II", 0.0, 100.0},
        {4, 112, "Chemistry I", 0.0, 100.0},
        {4, 113, "Chemistry II", 0.0, 100.0},
        {3, 114, "Biology I", 0.0, 100.0},
        {3, 115, "Biology II", 0.0, 100.0},
        {3, 116, "Env. Science", 0.0, 100.0},
        {4, 117, "COMPSCI I", 0.0, 100.0},
        {4, 118, "COMPSCI II", 0.0, 100.0},
        {3, 119, "Entry to CS", 0.0, 100.0},
        {4, 120, "Data Structures", 0.0, 100.0},
        {3, 121, "World History", 0.0, 100.0},
        {3, 122, "U.S. History", 0.0, 100.0},
        {3, 123, "Government", 0.0, 100.0},
        {3, 124, "Economics", 0.0, 100.0},
        {3, 125, "Psychology", 0.0, 100.0},
        {3, 126, "Sociology", 0.0, 100.0},
        {3, 127, "Philosophy", 0.0, 100.0},
        {3, 128, "English Lit.", 0.0, 100.0},
        {3, 129, "Creative Writing", 0.0, 100.0},
        {3, 130, "Art History", 0.0, 100.0}
        };

	// Start the console application
	displayConsoleHeader();

	// Display the user menu (user menu allows the user to create a student or teacher)
    userMenu(masterListOfCourses, studentList);

	// Display a goodbye message before exiting
    displayBye();
    
    return 0;
}