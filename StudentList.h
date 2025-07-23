#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"

#include <vector>

class StudentList {
public:
	static std::vector<Student*> students;

	std::vector<Student*> getStudents();

	std::vector<Student*> getStudentsByCourseID(int course_id);
	Student getStudentByID(int student_id);

};

#endif