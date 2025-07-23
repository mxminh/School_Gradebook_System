#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>
#include <iostream>

struct Course {
    int course_units;
	int course_id;
	std::string course_name;
    double student_points;
    double assignment_points;

    void setPoints(double);
    void setAssignmentPoints(double);

    double getGrade(Course [], int);
};

class Student : public Person {
private:
    double gpa;
    Course* courses;
    int course_count;

public: 

    Student();
    virtual ~Student();

    int getCourseCount();
    Course* getCourses();
    void setCourses(Course*, int);

    void updateStudentCoursePoints(int, double);

    double calculateGPA(Course []);

    void changeCourses(Course*, int);
    void displayCourses(Course []);
    void displayCourseNameWithID();

	// Display all courses with their IDs and names
	void displayInfoA(Course []);

	void updateInfo() override;

	void updateID(int) override;
	void updateName(std::string) override;
	void updateEmail(std::string) override;
	void updatePhoneNumber(std::string) override;

	void saveToFile(const std::string&, Course []);

    void securityLevel() override;

};

#endif