#include "ConsoleDisplay.h"
#include "Student.h"
#include "StudentList.h"
#include "Teacher.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <thread> 
#include <chrono> 

// Greetings and Farewells
void displayConsoleHeader() {
	std::cout << "================================================================================================" << std::endl;
	std::cout << "Welcome to the Course Management System!  |  By: Minh Le" << std::endl;
	std::cout << "================================================================================================" << std::endl;
}
void displayBye() {
	std::cout << "\n================================================================================================" << std::endl;
	std::cout << "Thank you for using the Course Management System!  |  By: Minh Le" << std::endl;
	std::cout << "================================================================================================" << std::endl;
}

void userMenu(Course masterListOfCourses[], StudentList& studentList) {

	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "\n================================================================================================" << std::endl;
	std::cout << "Select an option:" << std::endl;
	std::cout << "\n\t1. Create a Student" << std::endl;
	std::cout << "\t2. Create a Teacher" << std::endl;
	std::cout << "\t3. Exit\n" << std::endl; 
	std::cout << "================================================================================================\n" << std::endl;

	short int choice = -1;
	std::cout << "--> Enter Choice: ";
	std::cin >> choice;

	do{

	if (choice < 1 || choice > 3) {
		std::cout << "\n\n--> Invalid choice. Please select a valid option (1-3): ";
		std::cin >> choice;
	}

	if (choice == 1) {
		std::cout << "\n--> Creating a Student..." << std::endl;
		studentMenu(masterListOfCourses, studentList);

	}
	else if (choice == 2) {
		std::cout << "\n--> Creating a Teacher..." << std::endl;
		teacherMenu(masterListOfCourses, studentList);
	}
	else if (choice == 4) {
		std::cout << "\n--> Viewing a Student..." << std::endl;

		for (const auto& student : studentList.getStudents()) { // Iterates through each student in the vector
			std::cout << student->getName(); // Assuming displayInfo() is a method in the Student class
		}
		std::cout << "\n--> Please enter the Student ID: ";
		int student_id;
		std::cin >> student_id;

		Student copy = studentList.getStudentByID(student_id);
		copy.setID(studentList.getStudentByID(student_id).getID());
		copy.setName(studentList.getStudentByID(student_id).getName());
		copy.setEmail(studentList.getStudentByID(student_id).getEmail());
		copy.setPhoneNumber(studentList.getStudentByID(student_id).getPhoneNumber());
		copy.setCourses(studentList.getStudentByID(student_id).getCourses(), studentList.getStudentByID(student_id).getCourseCount());
		copy.displayInfoA(masterListOfCourses);
		
	}
	else if (choice == 3) {
		std::cout << "\n--> Exiting the program..." << std::endl;
		std::cout << "\n================================================================================================" << std::endl;
		
	}
	std::cout << "\n--> Would you like to continue viewing the User Menu? (1 for Yes, 0 for No): ";
	int continueChoice;
	std::cin >> continueChoice;
	if (continueChoice == 1) {
		userMenu(masterListOfCourses, studentList);
	}
	else {
		std::cout << "\n--> Exiting the User Menu..." << std::endl;
		return;
	}

	} while (choice != 4);

	exit(0);
}
void studentMenu(Course masterListOfCourses[], StudentList& studentList) {
	
	std::cout << "\n================================================================================================";
	std::cout << "\nPlease Enter Student Information: ";
	int student_id;
	std::string student_name;
	std::string student_email;
	std::string student_phone_number;
	std::cout << "\n\n\t--> Enter Student ID: ";
	std::cin >> student_id;
	std::cout << "\n\t--> Enter Student Name: ";
	std::cin.ignore(); 
	std::getline(std::cin, student_name);
	std::cout << "\n\t--> Enter Student Email: ";
	std::getline(std::cin, student_email);
	std::cout << "\n\t--> Enter Student Phone Number: ";
	std::getline(std::cin, student_phone_number);
	std::cout << "\n================================================================================================" << std::endl;

	Student student1;
	student1.updateID(student_id);
	student1.updateName(student_name);
	student1.updateEmail(student_email);
	student1.updatePhoneNumber(student_phone_number);
	std::cout << "\n--> Student created successfully!" << std::endl;
	
	short int choice = -1;
	do {
		short int choice = -1;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "\n================================================================================================" << std::endl;
	std::cout << "Select an option:" << std::endl;	
	std::cout << "\n\t1. Display Student Information" << std::endl;
	std::cout << "\t2. Update Student Information" << std::endl;
	std::cout << "\t3. Enroll in Courses" << std::endl;
	std::cout << "\t4. View Enrolled Courses" << std::endl;
	std::cout << "\t5. Generate Report Card" << std::endl;
	std::cout << "\t6. Edit Points in Enrolled Course" << std::endl; 
	std::cout << "\t7. Back to User Menu" << std::endl;
	std::cout << "\t8. Exit" << std::endl;
	std::cout << "================================================================================================\n" << std::endl;

	
	std::cout << "\tEnter Choice: ";
	std::cin >> choice;

	if (choice < 1 || choice > 8) {
		std::cout << "\n\n--> Invalid choice. Please select a valid option (1-8): ";
		std::cin >> choice;
	}

		if (choice == 1) {
			std::cout << "\n--> Displaying Student Information..." << std::endl;
			student1.displayInfoA(masterListOfCourses);
		}
		else if (choice == 2) {
			std::cout << "\n--> Updating Student Information..." << std::endl;
			student1.updateInfo();
		}
		else if (choice == 3) {
			std::cout << "\n--> Enrolling in Courses..." << std::endl;
			std::cout << "\n--> Please enter the number of courses you want to enroll in: ";
			std::cout << "\n--> Note: If you would like to view all courses, please enter 0." << std::endl;
			int numCourses;
			std::cin >> numCourses;

			if (numCourses < 0 || numCourses > 30) {
				std::cout << "\n--> Invalid number of courses. Please enter a number between 1 and 30." << std::endl;
				continue; // Restart the loop to ask for the number of courses again
			}

			if (numCourses == 0) {
				std::cout << "\n--> Displaying all available courses..." << std::endl;
				displayAllCourses(masterListOfCourses, 30);
				continue; // Restart the loop to allow the user to choose again
			}
			std::cout << "\n--> Please enter the Course IDs (between 101 and 130) for the courses you want to enroll in, separated by spaces: ";
			int courseIDs[30];
			for (int i = 0; i < numCourses; i++) {
				std::cin >> courseIDs[i];
				if (courseIDs[i] < 101 || courseIDs[i] > 130) {
					std::cout << "\n--> Invalid Course ID: " << courseIDs[i] << ". Please enter a valid Course ID between 101 and 130." << std::endl;
					i--; // Decrement i to re-enter the invalid course ID
				}
			}
			Course selectedCourses[30];
			int validCourseCount = 0;
			for (int i = 0; i < numCourses; i++) {
				int index = binary_search_Class(masterListOfCourses, 30, courseIDs[i]);
				if (index != -1) {
					selectedCourses[validCourseCount++] = masterListOfCourses[index];
				} else {
					std::cout << "\n--> Course ID " << courseIDs[i] << " not found. Please enter a valid Course ID." << std::endl;
				}
			}
			if (validCourseCount > 0) {
				student1.setCourses(selectedCourses, validCourseCount);
				std::cout << "\n--> Successfully enrolled in " << validCourseCount << " course(s)." << std::endl;
			} else {
				std::cout << "\n--> No valid courses were selected. Please try again." << std::endl;
			}

			// After enrolling, display the updated courses
			std::cout << "\n--> Your enrolled courses are now updated." << std::endl;
			student1.displayCourses(masterListOfCourses);


		}
		else if (choice == 4) {
			std::cout << "\n--> Displaying Enrolled Courses..." << std::endl;
			student1.displayCourses(masterListOfCourses);
		}
		else if (choice == 5) {
			std::cout << "\n--> Generating Report Card..." << std::endl;
			student1.displayInfoA(masterListOfCourses);
			student1.displayCourses(masterListOfCourses);
			std::string filename = "ReportCard_Student_" + std::to_string(student1.getID()) + ".txt";
			student1.saveToFile(filename, masterListOfCourses);
			std::cout << "--> Report card saved to " << filename << std::endl;
			system(("start " + filename).c_str());
		}

		else if (choice == 7) {
			std::cout << "\n--> Returning to User Menu..." << std::endl;
			return; // Return to the user menu
		}
		else if (choice == 8) {
			std::cout << "\n--> Exiting the program..." << std::endl;
			std::cout << "\n================================================================================================" << std::endl;
			exit(0);
			
		}
		else if (choice == 6) {
			std::cout << "\n--> Editing Course Student Points..." << std::endl;
			int course_id = 0;
			double new_points = 0.0;
			Teacher new_teacher;
			new_teacher.editCourseStudentPoints(student1, masterListOfCourses, course_id, new_points);
			student1.displayCourses(masterListOfCourses);
			std::cout << "\n--> Student points updated." << std::endl;
		}

		std::cout << "\n--> Would you like to continue viewing the Student Menu? (1 for Yes, 0 for No): ";
		int continueChoice;
		std::cin >> continueChoice;

		if (continueChoice == 1) {
			continue;
		}
		else {
			std::cout << "\n--> Exiting the Student Menu..." << std::endl;
			return;
		}

	} while (choice != 5);

	exit(0);
}
void teacherMenu(Course masterListOfCourses[], StudentList& studentList) {
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "\n================================================================================================" << std::endl;
	std::cout << "Please Enter Teacher Information: ";
	int teacher_id;
	std::string teacher_name;
	std::string teacher_email;
	std::string teacher_phone_number;
	std::cout << "\n\n\t--> Enter Teacher ID: ";
	std::cin >> teacher_id;
	std::cout << "\n\t--> Enter Teacher Name: ";
	std::cin.ignore();
	std::getline(std::cin, teacher_name);
	std::cout << "\n\t--> Enter Teacher Email: ";
	std::getline(std::cin, teacher_email);
	std::cout << "\n\t--> Enter Teacher Phone Number: ";
	std::getline(std::cin, teacher_phone_number);
	std::cout << "\n================================================================================================" << std::endl;

	Teacher teacher1; 
	teacher1.updateID(teacher_id);
	teacher1.updateName(teacher_name);
	teacher1.updateEmail(teacher_email);
	teacher1.updatePhoneNumber(teacher_phone_number);
	std::cout << "\n--> Teacher created successfully!" << std::endl;

	short int choice = -1;
	do {
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cout << "\n================================================================================================" << std::endl;
		std::cout << "Select an option:" << std::endl;
		std::cout << "\n\t1. Display Teacher Information" << std::endl;
		std::cout << "\t2. Update Teacher Information" << std::endl;
		std::cout << "\t3. Edit Course Assignment Points" << std::endl;
		std::cout << "\t4. **FEATURE STILL IN DEVELOPMENT**" << std::endl;
		std::cout << "\t5. **FEATURE STILL IN DEVELOPMENT**" << std::endl;
		std::cout << "\t6. Back to User Menu" << std::endl;
		std::cout << "\t7. Exit\n" << std::endl;
		std::cout << "================================================================================================\n" << std::endl;

		std::cout << "\tEnter Choice: ";
		std::cin >> choice;

		if (choice < 1 || choice > 7) {
			std::cout << "\n\n--> Invalid choice. Please select a valid option (1-7): ";
			std::cin >> choice;
		}

		if (choice == 1) {
			std::cout << "\n--> Displaying Teacher Information..." << std::endl;
			teacher1.displayInfo(); 
		}
		else if (choice == 2) {
			std::cout << "\n--> Updating Teacher Information..." << std::endl;
			teacher1.updateInfo();
		}
		else if (choice == 3) {
			std::cout << "\n--> Editing Course Assignment Points..." << std::endl;
			std::cout << "\n--> Enter Course ID: ";
			int course_id;
			std::cin >> course_id;
			double new_points = 0.0;
			teacher1.editCourseAssignmentPoints(masterListOfCourses, course_id, new_points);
			std::cout << "\n--> Assignment points updated." << std::endl;
		}
		else if (choice == 4) {
			std::cout << "\n--> Editing Student Points in Course..." << std::endl;
			std::cout << "\n--> Enter Student ID: ";
			int student_id;
			std::cin >> student_id;
			int course_id = 0;
			double new_points = 0.0;
			Student student = studentList.getStudentByID(student_id);
			student.displayCourses(masterListOfCourses);
			if (student.getID() == -1) {
				std::cout << "\n--> Student with ID " << student_id << " not found." << std::endl;
			} else {
				student.updateStudentCoursePoints(course_id, new_points);
				std::cout << "\n--> Student points updated." << std::endl;
			}
		}
		else if (choice == 5) {
			std::cout << "\n--> Generating Report Card..." << std::endl;
			teacher1.generateReportCard(masterListOfCourses);
		}
		else if (choice == 6) {
			std::cout << "\n--> Returning to User Menu..." << std::endl;
			return;
		}
		else if (choice == 7) {
			std::cout << "\n--> Exiting the program..." << std::endl;
			std::cout << "\n================================================================================================" << std::endl;
			exit(0);
		}

		std::cout << "\n--> Would you like to continue viewing the Teacher Menu? (1 for Yes, 0 for No): ";
		int continueChoice;
		std::cin >> continueChoice;

		if (continueChoice == 1) {
			continue;
		}
		else {
			std::cout << "\n--> Exiting the Teacher Menu..." << std::endl;
			return;
		}

	} while (choice != 6);

	exit(0);
}

void displayAllCourses(const Course courses[], int size) {
	std::cout << "\n"
		<< std::string(96, '=') << std::endl;

	std::cout << std::left
		<< std::setw(12) << "COURSE ID"
		<< std::setw(50) << "COURSE NAME"
		<< std::setw(12) << "UNITS"
		<< std::setw(15) << "MAX POINTS"
		<< std::endl;

	std::cout << std::string(96, '=') << std::endl;

	for (int i = 0; i < size; i++) {
		std::cout << std::left
			<< std::setw(12) << courses[i].course_id
			<< std::setw(50) << courses[i].course_name
			<< std::fixed << std::setprecision(1)
			<< std::setw(12) << courses[i].course_units
			<< std::setw(15) << courses[i].assignment_points
			<< std::endl;

		std::cout << std::string(96, '.') << std::endl;
	}

	std::cout << std::string(96, '=') << std::endl;
}

int binary_search_Class(Course masterListOfCourses[], int size, int target) {

	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (masterListOfCourses[mid].course_id == target) {
			return mid; // Found the course
		}
		if (masterListOfCourses[mid].course_id < target) {
			left = mid + 1; // Search in the right half
		}
		else {
			right = mid - 1; // Search in the left half
		}
	}
	return -1; // Target not found; DNE
}
