#include <stdio.h>
#include "select_menu.h"
#include "get_data_num.h"
#include "csv_student_parser.h"


int main(){
	//�Էµ� �������� ���� �������� �Լ�
	get_data_num();
	
	//�̹� �ԷµǾ��ִ� �����͸� Student����ü�� �ҷ����� �Լ�
	csv_student_parser();
	
	//�������� ���α׷� ��� ���� �޴�
	select_menu();
	return 0;
}