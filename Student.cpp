#include <iostream>
#include "Student.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <thread> 
#include <chrono> 
#include "StudentList.h"

// All methods to help Teachers adjust points and retrieve student information
double Course::getGrade(Course masterListOfCourses[], int i) {
    if (assignment_points == 0) {
        std::cout << "--> No assignments for this course. Grade defaults to 0.0" << std::endl;
	    return 0.0;
    }
    return student_points / masterListOfCourses[i - 101].assignment_points;
}
void Course::setPoints(double points) {
    student_points = points;
}
void Course::setAssignmentPoints(double points) {
    assignment_points = points;
}

// Allows Teachers to changee Student Points
void Student::updateStudentCoursePoints(int course_id, double points) {
    for (int i = 0; i < course_count; i++) {
        if (courses[i].course_id == course_id) {
            courses[i].setPoints(points);
            return;
        }
    }
    std::cout << "--> Course ID " << course_id << " not found." << std::endl;
}
void Student::changeCourses(Course* courseList, int count) {
    delete[] courses; // Free existing memory
    courses = new Course[count]; // Allocate new memory
    for (int i = 0; i < count; i++) {
        courses[i] = courseList[i];
    }
    course_count = count;
}

// GPA Calculations Based on Points + Unit Count
double Student::calculateGPA(Course masterListOfCourses[]) {
    if (courses == nullptr || course_count == 0) {
        std::cout << "--> No courses found. GPA defaults to 0.0" << std::endl;
        return 0.0;
    }
    double totalWeightedGrades = 0.0;
    int totalUnits = 0;
    for (int i = 0; i < course_count; i++) {
        
        double grade = courses[i].getGrade(masterListOfCourses, courses[i].course_id); // 0.0 to 1.0
        totalWeightedGrades += grade * courses[i].course_units;
        totalUnits += courses[i].course_units;
    }
    if (totalUnits == 0) {
        std::cout << "--> No course units found. GPA defaults to 0.0" << std::endl;
        return 0.0;
    }
    gpa = totalWeightedGrades / totalUnits * 4.0; // GPA on 4.0 scale
    return gpa;
}

// Constructors
Student::Student() {
    gpa = 0.0;
    courses = nullptr;
    course_count = 0;
	StudentList::students.push_back(this); // Add this student to the global list of students
    setID(-1); // Default ID for Student
    setName("Unknown"); // Default Name for Student
    setEmail("Unknown");
	setPhoneNumber("Unknown");
	setSecurityAccess(1); // Default security access level for Student
}

Student::~Student() {
    delete[] courses;
}

// Regular Get and Set Methods
int Student::getCourseCount() {
    return course_count;
}
Course* Student::getCourses() {
    return courses;
}
void Student::setCourses(Course* courseList, int count) {

    course_count = count;
    courses = new Course[count];
    for (int i = 0; i < count; i++) {
        courses[i] = courseList[i];
    }
}

// Displays Student Courses in a Structured Manner
void Student::displayCourses(Course masterList[]) {
    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    std::cout << "\n==============================================================================================\n";
    std::cout << std::left
        << std::setw(12) << "UNITS"
        << std::setw(20) << "COURSE NAME"
        << std::setw(18) << "EARNED POINTS"
        << std::setw(18) << "MAX POINTS"
        << std::setw(10) << "GRADE" << std::endl;
    std::cout << "==============================================================================================\n";

    for (int i = 0; i < course_count; i++) {
        std::cout << std::left
            << std::setw(12) << std::fixed << std::setprecision(1) << static_cast<double>(courses[i].course_units)
            << std::setw(20) << courses[i].course_name
            << std::setw(18) << courses[i].student_points
            << std::setw(18) << masterList[(courses[i].course_id) - 101].assignment_points
			<< std::setw(10) << std::fixed << std::setprecision(2) << courses[i].getGrade(masterList, courses[i].course_id) * 100 << " %"
            << std::endl;
    }
    std::cout << "==============================================================================================\n";
}

// Related to Editing Course Points 
void Student::displayCourseNameWithID() {
    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    std::cout << "\n==============================================================================================" << std::endl;
    std::cout << "Courses Enrolled:" << std::endl;
    std::cout << "==============================================================================================" << std::endl;
    for (int i = 0; i < course_count; i++) {
        std::cout << "\tCourse ID: " << courses[i].course_id << " | Course Name: " << courses[i].course_name << std::endl;
    }

};

// Displays Student Info in a Structured Manner
void Student::displayInfoA(Course masterList[]) {
    std::this_thread::sleep_for(std::chrono::milliseconds(750));
	gpa = calculateGPA(masterList);
    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    std::cout << "\n==============================================================================================" << std::endl;
    std::cout << "Student Information: " << getID() << std::endl;
    std::cout << "==============================================================================================" << std::endl;

    std::cout << "\tID: " << getID() << std::endl;
    std::cout << "\tName: " << getName() << std::endl;
    std::cout << "\tEmail: " << getEmail() << std::endl;
    std::cout << "\tPhone Number: " << getPhoneNumber() << std::endl;
    std::cout << "\tGPA: " << std::fixed << std::setprecision(2) << gpa << std::endl;
    std::cout << "==============================================================================================" << std::endl;
}

// Updating Info Related Methods
void Student::updateInfo() {
    int choice = -1;
    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    std::cout << "\n==============================================================================================" << std::endl;
    std::cout << "Select the information you want to update:" << std::endl;
    std::cout << "==============================================================================================" << std::endl;
    std::cout << "\t1. ID" << std::endl;
    std::cout << "\t2. Name" << std::endl;
    std::cout << "\t3. Email" << std::endl;
    std::cout << "\t4. Phone Number" << std::endl;
    std::cout << "\t5. Courses" << std::endl;
    std::cout << "\t6. Exit" << std::endl;
    std::cout << "==============================================================================================" << std::endl << "\tEnter Choice: ";
    std::cin >> choice;
    while (choice < 1 || choice > 6) {
        std::cout << "\n\nInvalid choice. Please select a valid option (1-6): ";
        std::cin >> choice;
    }
    switch (choice) {
    case 1: {
        int new_id = -1;
        std::cout << "\n--> Enter new ID: ";
        std::cin >> new_id;
        updateID(new_id);
        break;
    }
    case 2: {
        std::string new_name = "";
        std::cout << "\n--> Enter new Name: ";
        std::cin.ignore(); // Clear the newline character from the input buffer
        std::getline(std::cin, new_name);
        updateName(new_name);
        break;
    }
    case 3: {
        std::string new_email = "";
        std::cout << "\n--> Enter new Email: ";
        std::cin.ignore(); // Clear the newline character from the input buffer
        std::getline(std::cin, new_email);
        updateEmail(new_email);
        break;
    }
    case 4: {
        std::string new_phone_number = "";
        std::cout << "\n--> Enter new Phone Number: ";
        std::cin.ignore(); // Clear the newline character from the input buffer
        std::getline(std::cin, new_phone_number);
        updatePhoneNumber(new_phone_number);
        break;
    }
    case 5: {

    }
    }
}

void Student::updateID(int new_id) {
    setID(new_id);
}
void Student::updateName(std::string new_name) {
    setName(new_name);
}
void Student::updateEmail(std::string new_email) {
    setEmail(new_email);
}
void Student::updatePhoneNumber(std::string new_phone_number) {
    setPhoneNumber(new_phone_number);
}

// Helps Teacher::generateReport to Write to .txt files instead of console
void Student::saveToFile(const std::string& filename, Course masterList[]) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    // Write student info (as in displayInfo)
    file << "==============================================================================================" << std::endl;
    file << "Student Information: " << getID() << std::endl;
    file << "==============================================================================================" << std::endl;
    file << "\tID: " << getID() << std::endl;
    file << "\tName: " << getName() << std::endl;
    file << "\tEmail: " << getEmail() << std::endl;
    file << "\tPhone Number: " << getPhoneNumber() << std::endl;
    file << "\tGPA: " << std::fixed << std::setprecision(2) << gpa << std::endl;
    file << "==============================================================================================" << std::endl;

    // Write course info (as in displayCourses)
    file << "==============================================================================================" << std::endl;
    file << std::left
        << std::setw(12) << "UNITS"
        << std::setw(20) << "COURSE NAME"
        << std::setw(18) << "EARNED POINTS"
        << std::setw(18) << "MAX POINTS"
        << std::setw(10) << "GRADE" << std::endl;
    file << "==============================================================================================" << std::endl;

    for (int i = 0; i < course_count; i++) {
        file << std::left
            << std::setw(12) << std::fixed << std::setprecision(1) << static_cast<double>(courses[i].course_units)
            << std::setw(20) << courses[i].course_name
            << std::setw(18) << courses[i].student_points
            << std::setw(18) << masterList[(courses[i].course_id) - 101].assignment_points
            << std::setw(10) << std::fixed << std::setprecision(2) << courses[i].getGrade(masterList, courses[i].course_id) * 100 << " %"
            << std::endl;
    }
    file << "==============================================================================================" << std::endl;

    file.close();
}

// Student Security Level Info
void Student::securityLevel() {
    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    std::cout << "\n==============================================================================================" << std::endl;
    std::cout << "Security access level: Student Access" << std::endl;
    std::cout << "==============================================================================================" << std::endl;
}
