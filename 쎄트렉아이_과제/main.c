#include <stdio.h>
#include "select_menu.h"
#include "get_data_num.h"
#include "csv_student_parser.h"


int main(){
	//입력된 데이터의 개수 가져오는 함수
	get_data_num();
	
	//이미 입력되어있는 데이터를 Student구조체로 불러오는 함수
	csv_student_parser();
	
	//성적관리 프로그램 기능 선택 메뉴
	select_menu();
	return 0;
}