#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "student.h"

void str_copy(char* dest, const char* src);
int str_cmp(const char* str1, const char* str2);
void quick_sort(Student* student, int left, int right);
int partition(Student* student, int left, int right);
void swap(Student* a, Student* b);

#endif // !QUICK_SORT_H