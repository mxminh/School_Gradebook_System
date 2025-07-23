#ifndef TEACHER_H
#define TEACHER_H

#include "Student.h"
#include "Person.h"
#include "Course.h"

#include <vector>
#include <string>

class Teacher : public Person {
	std::vector<int> courses_taught;

public:
    Teacher();
    Teacher(int id, std::string name, std::string email, std::string phone_number);

    void displayInfo() override;
    void updateInfo() override;

    void editCourseStudentPoints(Student&, Course[], int course_id, double new_points);
	void editCourseAssignmentPoints(Course [], int course_id, double new_points);
    
    void addCourseID(int course_id);
    void removeCourseID(int course_id);

    void generateReportCard(Course[]);

    void securityLevel() override;
};

#endif