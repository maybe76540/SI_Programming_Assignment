#include<stdio.h>
#include"quick_sort_by_name.h"

void select_sort() {
	short int sel_sort = -1;

	while (sel_sort != 0) {
		printf("원하는 기능을 선택하세요: \n\
		0. 이전으로 가기 \n\
		1. 이름 순 정렬 \n\
		2. 학번 순 정렬 \n\
		3. 평균 점수 순 정렬 \n");

		printf("입력: ");
		scanf_s("%hd", &sel_sort);

		switch (sel_sort)
		{
		case 0:
			printf("이전으로 갑니다. \n");
			break;
		case 1:
			quick_sort_by_name();
			break;
		case 2:
			
			break;
		case 3:

			break;
		default:
			printf("잘못된 입력입니다.\n");
			break;
		}
	}
}