#include <stdio.h>
#include "student.h"
#include "write_data.h"

void write_data(void) {
	//csv ���Ͽ� ���� ���(���� p_pile)
	FILE* p_file = NULL;

	Student student;
	
	//������ �������� ���� ����
	if (0 == fopen_s(&p_file, "data.csv", "at")) {

		printf("���ο� �ڷḦ �Է����ּ���. \n");
		printf("�̸�: ");
		scanf_s("%s, \n", student.name, sizeof(student.name));

		printf("�й�: ");
		scanf_s("%s, \n", student.student_number, sizeof(student.student_number));

		printf("C������ ���� ����: ");
		scanf_s("%hd, \n", &student.subj_1);

		printf("C++������ ���� ����: ");
		scanf_s("%hd, \n", &student.subj_2);

		printf("��ü ���� ��� ����: ");
		scanf_s("%f, \n", &student.average);


		//����ڰ� �Է��� �ڷḦ ���Ͽ� �߰�
		//��, �� ���๮�ڷ� ���پ� ������
		fprintf(p_file, "\n%s,%s,%hd,%hd,%.1f",
			student.name,
			student.student_number,
			student.subj_1,
			student.subj_2,
			student.average);

		fclose(p_file);
	}
	else {
		printf("����: data.csv ������ ã�� ���߽��ϴ�. ������ Ȯ�����ּ���.");
	}
}