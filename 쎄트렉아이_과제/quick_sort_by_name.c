#include <stdio.h>
#include "student.h"
#include "quick_sort.h"
#include "get_data_num.h"
#include "read_data.h"

void quick_sort_by_name() {
    FILE* p_file = NULL;
    FILE* sorted_file = NULL;
    Student* students = malloc(num_of_lines * sizeof(Student));
    int count = 0;

    //printf("%s", students[right]);
    printf("%d \n", num_of_lines); 

    if (students == NULL) {
        printf("students pointer is NULL.");
    }
    else {
        printf("students pointer is not NULL.");
    }


    if (0 == fopen_s(&p_file, "data.csv", "rt")) {
        //char* line = malloc(num_of_lines * sizeof(char));
        char one_line_str[128];
        
        while (fgets(one_line_str, 128, p_file)) {
            sscanf_s(one_line_str, "%[^,],%[^,],%hd,%hd,%f", students[count].name,
                students[count].student_number, &students[count].subj_1,
                &students[count].subj_2, &students[count].average);
            count++;
        }
        //free(line);
        fclose(p_file);
    }
    else {
        printf("에러: data.csv 파일을 찾지 못했습니다. 파일을 확인해주세요.");
    }
    
    quick_sort(students, 0, num_of_lines - 1);

    if (0== fopen_s(&sorted_file, "sorted_by_name.csv", "w")) {

        for (int i = 0; i < num_of_lines; i++) {
            fprintf(sorted_file, "%s,%s,%hd,%hd,%.1f\n", students[i].name,
                students[i].student_number, students[i].subj_1,
                students[i].subj_2, students[i].average);
        }
        fclose(sorted_file);
    }
    else {
        printf("파일을 열 수 없습니다.\n");
    }
    free(students);
}