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

        // ������ ���� �ٹٲ� ���ڰ� ������ title������ �ϳ� ������
        //num_of_lines++;

        printf("CSV ������ ������ ��: %d\n", num_of_lines);

        fclose(p_file);

        Student* students = malloc(num_of_lines * sizeof(Student));
        if (students == NULL) {
            printf("�޸� �Ҵ� ����\n");
        }

        return num_of_lines;
    }
    else {
        printf("����: data.csv ������ ã�� ���߽��ϴ�. ������ Ȯ�����ּ���.");
    }
}
