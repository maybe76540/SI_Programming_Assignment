#include <stdio.h>
#include "read_data.h"
#include "student.h"
#include "get_data_num.h"

//strtok_s �Լ� ���Ұ� ��ǥ�� ���� ���� ���� ����
//str�� ��ü ���ڿ�, comma�� ���� ������ ����, next_str�� ���� ���� ���ڿ�
char* space_for_next_str(char* str, char comma, char* next_str) {

	//��ü ���ڿ����� ','�̳� NULL�� ������ ���������� ����
	while (*str && *str != comma) {
		*next_str++ = *str++;
	}
	//�������� ���๮�ڸ� NULL �߰�
	if (*(next_str - 1) == '\n')
		*(next_str - 1) = 0;
	else
		*next_str = 0;

	// ���� ���� ��ġ�� ��ǥ�ų� ���ڿ��� �������̶�� �� ĭ ������ �̵�
	if (*str == comma || *str == '\n')
		str++;

	return str;
}

void read_data(void) {
	//���������� csv ���Ϸ� ��ȯ�ؼ� �д� ���(���� p_pile)
	FILE* p_file = NULL;

	//data.csv ���� �б� ���� ����
	if (0 == fopen_s(&p_file, "data.csv", "rt")) {
		char one_line_str[128], buffer[32], *p_pos;

		//�迭 ����ؼ� ���� ���� ��������� ���� �������� ���� �ȵ�
		//�迭 ũ��� �׸� ������ �°Բ� �����ʿ�
		const char* title_format[5] =
		{ "   %s   ", "   %s   ", "   %s   ", "   %s   ", "   %s   \n" };
		const char* data_format[5] =
		{ "   %s   ", "   %s   ", "   %s   ", "   %s   ", "   %s   \n" };

		//���Ͽ��� �׸��� �̸� ������
		if (NULL != fgets(one_line_str, 128, p_file)) {
			printf("--------------------------------------------------------\n");
			p_pos = one_line_str;

			for (int i = 0; *p_pos; i++) {
				p_pos = space_for_next_str(p_pos, ',', buffer);
				printf(title_format[i], buffer);
			}
			printf("--------------------------------------------------------\n");
		}
		//������ ���������� �׸��� ������
		while (NULL != fgets(one_line_str, 128, p_file)) {
			p_pos = one_line_str;

			for (int i = 0; *p_pos; i++) {

				p_pos = space_for_next_str(p_pos, ',', buffer);
				printf(data_format[i], buffer);
			}
		}
		printf("--------------------------------------------------------\n");

		fclose(p_file);
	}
	else
		printf("����: data.csv ������ ã�� ���߽��ϴ�. ������ Ȯ�����ּ���.");
}