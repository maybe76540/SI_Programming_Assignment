#include <stdio.h>
#include "student.h"
#include "write_data.h"

void write_data(void) {
	//csv 파일에 쓰는 기능(변수 p_pile)
	FILE* p_file = NULL;

	Student student;

	if (0 == fopen_s(&p_file, "data.csv", "at")) {

		printf("새로운 자료를 입력해주세요. \n");
		printf("이름: ");
		scanf_s("%s, \n", student.name, sizeof(student.name));

		printf("학번: ");
		scanf_s("%s, \n", student.student_number, sizeof(student.student_number));

		printf("C언어기초 과목 점수: ");
		scanf_s("%hd, \n", &student.subj_1);

		printf("C++언어기초 과목 점수: ");
		scanf_s("%hd, \n", &student.subj_2);

		printf("전체 과목 평균 점수: ");
		scanf_s("%f, \n", &student.average);


		//사용자가 입력한 자료를 파일에 추가
		//앞, 뒤 개행문자로 한줄씩 쓰게함
		fprintf(p_file, "\n%s,%s,%hd,%hd,%.1f",
			student.name,
			student.student_number,
			student.subj_1,
			student.subj_2,
			student.average);
		//fputs("한줄, 내려와서, 글자, 추가, 예제", p_file);
		/*fputs(Data_Struct.name + ',' + Data_Struct.student_num + ',' +
			Data_Struct.subj_1 + ',' + Data_Struct.subj_2 + ',' +
			Data_Struct.everage_subj, p_file);*/
		//printf("추가된 자료 보여주기")
		fclose(p_file);
	}
	else {
		printf("에러: data.csv 파일을 찾지 못했습니다. 파일을 확인해주세요.");
	}
}