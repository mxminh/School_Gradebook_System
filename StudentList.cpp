#include "StudentList.h"  
#include <iostream>  
#include <vector>  

std::vector<Student*> StudentList::getStudents() {  
    return students;  
}  

// Initialize the static member variable to store Student pointers
std::vector<Student*> StudentList::students;  

// Function to get search for students by course ID and return a vector of Students
std::vector<Student*> StudentList::getStudentsByCourseID(int course_id) {  
    for (Student* student : students) {  
        for (int i = 0; i < student->getCourseCount(); i++) {  
            if (student->getCourses()[i].course_id == course_id) {  
                return {student}; // Return a vector containing the student with the matching course ID  
            }  
        }  
	}
    return {};  
}  

// Function to get a student by ID and return the Student object
Student StudentList::getStudentByID(int student_id) {  
    for (Student* student : students) {  
        if (student->getID() == student_id) {  
            return *student;  
        }  
    }  
	std::cout << "\n--> Student with ID " << student_id << " not found." << std::endl;

	return Student(); 
}
