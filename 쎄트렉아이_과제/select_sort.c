#include<stdio.h>
#include"quick_sort_by_name.h"

void select_sort() {
	short int sel_sort = -1;

	while (sel_sort != 0) {
		printf("���ϴ� ����� �����ϼ���: \n\
		0. �������� ���� \n\
		1. �̸� �� ���� \n\
		2. �й� �� ���� \n\
		3. ��� ���� �� ���� \n");

		printf("�Է�: ");
		scanf_s("%hd", &sel_sort);

		switch (sel_sort)
		{
		case 0:
			printf("�������� ���ϴ�. \n");
			break;
		case 1:
			quick_sort_by_name();
			break;
		case 2:
			
			break;
		case 3:

			break;
		default:
			printf("�߸��� �Է��Դϴ�.\n");
			break;
		}
	}
}