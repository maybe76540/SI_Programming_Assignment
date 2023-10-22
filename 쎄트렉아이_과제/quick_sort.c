#include <stdio.h>
#include "student.h"
#include "quick_sort.h"

void str_copy(char* dest, const char* src) {
    while ((*dest++ = *src++));
}

int str_cmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }

    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

void quick_sort(Student* student, int left, int right) {
    if (left < right) {
        int pivot = partition(student, left, right);
        quick_sort(student, left, pivot - 1);
        quick_sort(student, pivot + 1, right);
    }
}

int partition(Student* student, int left, int right) {
    Student pivot = student[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (str_cmp(student[j].name, pivot.name) < 0) {
            i++;
            swap(&student[i], &student[j]);
        }
    }

    swap(&student[i + 1], &student[right]);
    return i + 1;
}

void swap(Student* a, Student* b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}
