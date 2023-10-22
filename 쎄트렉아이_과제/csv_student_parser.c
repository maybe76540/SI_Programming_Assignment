//csv_student_parser.c
//csv의 데이터를 구조체에 저장해 정렬 등에 사용하기 위한 목적의 파일
#include<stdio.h>
#include "student.h"
#include "read_data.h"
#include "get_data_num.h"

void csv_student_parser() {
    FILE* p_file = NULL;
    Student* students = malloc(num_of_lines * sizeof(Student));
    int num_students = 0;

    if (0 == fopen_s(&p_file, "data.csv", "rt")) {
        char one_line_str[128], buffer[32], * p_pos;

        while (NULL != fgets(one_line_str, 128, p_file)) {
            p_pos = one_line_str;

            // 각 학생의 정보를 저장하기 위한 임시 Student 구조체 생성
            Student temp_student;

            for (int i = 0; *p_pos; i++) {
                p_pos = space_for_next_str(p_pos, ',', buffer);

                if (i == 0) {
                    strncpy(temp_student.name, buffer, sizeof(temp_student.name));
                    temp_student.name[sizeof(temp_student.name) - 1] = '\0'; // Null-terminate the string just in case
                }

                else if (i == 1) {
                    strncpy(temp_student.student_number, buffer, sizeof(temp_student.student_number));
                    temp_student.student_number[sizeof(temp_student.student_number) - 1] = '\0';
                }

                else if (i == 2) {
                    temp_student.subj_1 = atoi(buffer);
                }

                else if (i == 3) {
                    temp_student.subj_2 = atoi(buffer);
                }

                else if (i == 4) {
                    temp_student.average = atof(buffer);
                }
            }
            //아래 줄에서 예외 발생해 수정필요함
            //students[num_students++] = temp_student;
        }
    }
}