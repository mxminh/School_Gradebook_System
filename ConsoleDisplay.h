#ifndef CONSOLE_DISPLAY_H
#define CONSOLE_DISPLAY_H

#include "Course.h"
#include "Student.h"
#include "StudentList.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <thread> 
#include <chrono> 

void displayConsoleHeader();
void displayBye();

void userMenu(Course[], StudentList&);

void studentMenu(Course[], StudentList&);

void teacherMenu(Course[], StudentList&);

void displayAllCourses(const Course courses[], int size);

int binary_search_Class(Course masterListOfCourses[], int size, int target);

#endif