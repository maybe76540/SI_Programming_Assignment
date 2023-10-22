#include <stdio.h>
#include "student.h"
num_of_lines;

int get_data_num(void) {
    FILE* p_file = NULL;

    if (0 == fopen_s(&p_file ,"data.csv", "rt")) {
        
        char ch;

        while ((ch = fgetc(p_file)) != EOF) {
            if (ch == '\n') {
                num_of_lines++;
            }
        }

        // 마지막 줄은 줄바꿈 문자가 없지만 title에서도 하나 빼야함
        //num_of_lines++;

        printf("CSV 파일의 데이터 수: %d\n", num_of_lines);

        fclose(p_file);

        Student* students = malloc(num_of_lines * sizeof(Student));
        if (students == NULL) {
            printf("메모리 할당 실패\n");
        }

        return num_of_lines;
    }
    else {
        printf("에러: data.csv 파일을 찾지 못했습니다. 파일을 확인해주세요.");
    }
}
