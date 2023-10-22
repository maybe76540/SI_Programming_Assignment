#include <stdio.h>
#include "read_data.h"
#include "write_data.h"
#include "delete_data.h"
#include "select_sort.h"
#include "get_data_num.h"

void select_menu() {
	short int sel_func = -1;

	while (sel_func != 0) {
		printf("���ϴ� ����� �����ϼ���: \n\
		0. ���α׷� ���� \n\
		1. ������ ���� \n\
		2. ������ ���� \n\
		3. ������ ���� \n\
		4. ������ ���� \n\
		5. �غ� ��\n\
		6. ������ ���� ���� \n");

		printf("�Է�: ");
		scanf_s("%hd", &sel_func);

		switch (sel_func)
		{
		case 0:
			printf("���α׷��� �������ϴ�. \n");
			break;
		case 1:
			read_data();
			break;
		case 2:
			write_data();
			break;
		case 3:
			delete_data();
			break;
		case 4:
			select_sort();
			break;
		case 5:

			break;
		case 6:
			get_data_num();
			break;
		default:
			printf("�߸��� �Է��Դϴ�.\n");
			break;
		}
	}
}
