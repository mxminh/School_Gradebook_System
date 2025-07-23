#include "Course.h"

double Course::getGrade() {
	if (assignmentPoints == 0) { 
		return 0.0;
	}
	return studentPoints / assignmentPoints;
}