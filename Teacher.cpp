#include "Teacher.h"
#include "Student.h"
#include "StudentList.h"
#include "Course.h"

#include <iostream>
#include <string>
#include <fstream>
#include <thread> 
#include <chrono> 

Teacher::Teacher() {
	setSecurityAccess(2); // Default security access level for Teacher
}

Teacher::Teacher(int id, std::string name, std::string email, std::string phone_number) {
	setID(id);
	setName(name);
	setEmail(email);
	setPhoneNumber(phone_number);
	setSecurityAccess(2); // Default security access level for Teacher
}

// Adds a course ID to the list of courses taught by the teacher (as well as profile information)
void Teacher::displayInfo() {

    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    std::cout << "\n==============================================================================================" << std::endl;
    std::cout << "Teacher Information:" << std::endl;
    std::cout << "==============================================================================================" << std::endl;

    std::cout << "\tID: " << getID() << std::endl;
    std::cout << "\tName: " << getName() << std::endl;
    std::cout << "\tEmail: " << getEmail() << std::endl;
    std::cout << "\tPhone Number: " << getPhoneNumber() << std::endl;
	std::cout << "\tCourses Taught (ID): ";
    for (const auto& course_id : courses_taught) {
        std::cout << course_id << ", ";
        }
       
    std::cout << "\n==============================================================================================" << std::endl;
    }
// Allows the treacher to update their profile information
void Teacher::updateInfo() {
	int choice = -1;
	std::this_thread::sleep_for(std::chrono::milliseconds(750));
	std::cout << "\n==============================================================================================" << std::endl;
	std::cout << "Select the information you want to update:" << std::endl;
	std::cout << "==============================================================================================" << std::endl;
	std::cout << "\t1. ID" << std::endl;
	std::cout << "\t2. Name" << std::endl;
	std::cout << "\t3. Email" << std::endl;
	std::cout << "\t4. Phone Number" << std::endl;
	std::cout << "\t5. Courses Taught" << std::endl;
	std::cout << "\t6. Exit" << std::endl;
	std::cout << "==============================================================================================" << std::endl << "\tEnter Choice: ";
	std::cin >> choice;

	while (choice < 1 || choice > 5) {
		std::cout << "\n\nInvalid choice. Please select a valid option (1-5): ";
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
		std::string new_phone_number;
		std::cout << "\n--> Enter new Phone Number: ";
		std::cin.ignore(); // Clear the newline character from the input buffer
		std::getline(std::cin, new_phone_number);

		updatePhoneNumber(new_phone_number);
		break;
	}
	case 5: {
		int new_course_id = -1;

		std::cout << "\n--> Current Courses Taught: ";
		for (const auto& course_id : courses_taught) {
			std::cout << course_id << " ";
		}

		std::cout << "\n--> Select an option:" << std::endl;
		std::cout << "\t1. Remove Course ID" << std::endl;
		std::cout << "\t2. Add Course ID" << std::endl;

		int sub_choice;
		std::cout << "\n--> Enter your choice (1-2): ";
		std::cin >> sub_choice;
		while (sub_choice < 1 || sub_choice > 2) {
			std::cout << "\n\nInvalid choice. Please select a valid option (1-2): ";
			std::cin >> sub_choice;
		}

		if (sub_choice == 1) {
			int course_id_to_remove;
			std::cout << "\n--> Enter Course ID to remove: ";
			std::cin >> course_id_to_remove;
			removeCourseID(course_id_to_remove);
			std::cout << "\n--> Course ID " << course_id_to_remove << " removed successfully." << std::endl;
			return; // Exit the update menu after removing a course
		}
		else if (sub_choice == 2) {
			std::cout << "\n--> Adding a new Course ID." << std::endl;
			std::cout << "\n--> Enter new Course ID to add: ";
			std::cin >> new_course_id;
			addCourseID(new_course_id);
		}
		break;
	}

	case 6: {
		std::cout << "\n--> Exiting update menu." << std::endl;
		return; // Exit the update menu
	}
	default: {
		std::cout << "\n--> Invalid choice. Please select a valid option (1-5): ";
		break;
	}
	}
}

// Allows the teacher to edit a student's points in a specific course
void Teacher::editCourseStudentPoints(Student& student, Course masterListOfCourses[], int course_id, double new_points){
	std::this_thread::sleep_for(std::chrono::milliseconds(750));
	std::cout << "\n================================================================================================" << std::endl;
	std::cout << "Editing Student ID: " << student.getID() << std::endl;
	std::cout << "================================================================================================" << std::endl;
	student.displayCourseNameWithID();
	std::cout << "\n\t--> (1) Choose a course to update (Enter ID): ";
	std::cin >> course_id;
	std::cout << "\n\t--> Enter new points for " << masterListOfCourses[course_id - 101].course_name << " | Course ID " << course_id << ": " << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "\n\t--> New Score: ";
	std::cin >> new_points;

	student.updateStudentCoursePoints(course_id, new_points);
	std::cout << "\n--> Successfully updated points for Student ID: " << student.getID() << " in Course ID: " << course_id << std::endl;
	std::cout << "===============================================================================================" << std::endl;
	
}

// Allows the teacher to edit the assignment points for a specific course
void Teacher::editCourseAssignmentPoints(Course masterListOfCourses[], int course_id, double new_points) {
	std::this_thread::sleep_for(std::chrono::milliseconds(750));
	std::cout << "\n================================================================================================" << std::endl;
	std::cout << "Editing Assignment Points for Course ID: " << course_id << std::endl;
	std::cout << "================================================================================================" << std::endl;
	std::cout << "\n\t--> Enter new assignment points for Course ID " << course_id << ": " << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(750));
	std::cout << "\n\t--> New Assignment Points: ";
	std::cin >> new_points;
	for (int i = 0; i < 3; i++) { // Assuming there are 3 courses in the master list
		if (masterListOfCourses[i].course_id == course_id) {
			masterListOfCourses[i].setAssignmentPoints(new_points);
			std::cout << "\n--> Successfully updated assignment points for Course ID: " << course_id << std::endl;
			break;
		}
	}
}

// Add or Remove Course ID from Teacher's List: Allows theo manage the courses they teach and view students in those courses
void Teacher::addCourseID(int course_id) {
	courses_taught.push_back(course_id);
}
void Teacher::removeCourseID(int course_id) {
	courses_taught.erase(std::remove(courses_taught.begin(), courses_taught.end(), course_id), courses_taught.end());
}

// Write to .txt: Generate Report Card for All Students in Course or Specific Student
void Teacher::generateReportCard(Course masterListOfCourses[]) {
	//GENERATE REPORT CARD FOR ALL STUDENTS IN COURSE
	//OR SPECIFIC STUDENT
	std::this_thread::sleep_for(std::chrono::milliseconds(750));
	std::cout << "\n===============================================================================================" << std::endl;
	std::cout << "REPORT CARD GENERATOR " << std::endl;
	std::cout << "===============================================================================================" << std::endl;

	std::cout << "\nWould you like to generate a report card for all students in the course or a specific student?" << std::endl;
	std::cout << "\t1. All Students in Course" << std::endl;
	std::cout << "\t2. Specific Student" << std::endl;
	int choice;
	std::this_thread::sleep_for(std::chrono::milliseconds(750));
	std::cout << "--> Enter your choice (1-2): ";
	std::cin >> choice;
	while (choice < 1 || choice > 2) {
		std::cout << "\n\n--> Invalid choice. Please select a valid option (1-2): ";
		std::cin >> choice;
	}

    if (choice == 1) {
        int course_id;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
        std::cout << "\n--> Enter the Course ID for the report card: ";
        std::cin >> course_id;
        StudentList studentList;
        std::vector<Student*> students = studentList.getStudentsByCourseID(course_id);
        if (!students.empty()) {
            std::cout << "Generating report cards for all students in Course ID " << course_id << ":\n";
            for (const auto& student : students) {
                student->displayInfoA(masterListOfCourses);
                student->displayCourses(masterListOfCourses);
                std::string filename = "ReportCard_Student_" + std::to_string(student->getID()) + ".txt";
                student->saveToFile(filename, masterListOfCourses);
                std::cout << "--> Report card saved to " << filename << std::endl;
                system(("start " + filename).c_str());
            }
        } else {
            std::cout << "Error: No students found for Course ID " << course_id << "." << std::endl;
        }
    } else if (choice == 2) {
        int student_id;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
        std::cout << "\n--> Enter the Student ID for the report card: ";
        std::cin >> student_id;
        StudentList studentList;
        Student student = studentList.getStudentByID(student_id);
        if (student.getID() != 0) {
            student.displayInfoA(masterListOfCourses);
            student.displayCourses(masterListOfCourses);
            std::string filename = "ReportCard_Student_" + std::to_string(student.getID()) + ".txt";
            student.saveToFile(filename, masterListOfCourses);
            std::cout << "--> Report card saved to " << filename << std::endl;
            system(("start " + filename).c_str());
        } else {
            std::cout << "Error: Student with ID " << student_id << " not found." << std::endl;
        }
    }

	
}

// Future Implementation: Allow Access to Specific Methods Based on Security Level
void Teacher::securityLevel() {
    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    std::cout << "\n==============================================================================================" << std::endl;
    std::cout << "Security access level: Teacher Access" << std::endl;
    std::cout << "==============================================================================================" << std::endl;
}
