#include <stdio.h>
#include "read_data.h"
#include "write_data.h"
#include "delete_data.h"
#include "select_sort.h"
#include "get_data_num.h"

void select_menu() {
	short int sel_func = -1;

	while (sel_func != 0) {
		printf("원하는 기능을 선택하세요: \n\
		0. 프로그램 종료 \n\
		1. 데이터 보기 \n\
		2. 데이터 쓰기 \n\
		3. 데이터 삭제 \n\
		4. 데이터 정렬 \n\
		5. 준비 중\n\
		6. 데이터 개수 보기 \n");

		printf("입력: ");
		scanf_s("%hd", &sel_func);

		switch (sel_func)
		{
		case 0:
			printf("프로그램을 종료힙니다. \n");
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
			printf("잘못된 입력입니다.\n");
			break;
		}
	}
}
