#include <stdio.h>
#include "select_menu.h"
#include "get_data_num.h"
#include "csv_student_parser.h"

//���α׷��� �Է� ������ ����(�̸�, �й�, ����1, ����2, ���)
//short int title_num = 5;

int main(){
	get_data_num();
	
	csv_student_parser();
	
	select_menu();
	return 0;
}