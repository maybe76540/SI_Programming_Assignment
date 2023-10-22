#include <stdio.h>
#include "select_menu.h"
#include "get_data_num.h"
#include "csv_student_parser.h"

//프로그램의 입력 데이터 개수(이름, 학번, 과목1, 과목2, 평균)
//short int title_num = 5;

int main(){
	get_data_num();
	
	csv_student_parser();
	
	select_menu();
	return 0;
}