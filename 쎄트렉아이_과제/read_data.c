#include <stdio.h>
#include "read_data.h"
#include "student.h"
#include "get_data_num.h"

//strtok_s 함수 사용불가 쉼표로 공백 구분 직접 구현
//str은 전체 문자열, comma는 공백 구분할 문자, next_str은 공백 다음 문자열
char* space_for_next_str(char* str, char comma, char* next_str) {

	//전체 문자열에서 ','이나 NULL이 나오지 않을때까지 복사
	while (*str && *str != comma) {
		*next_str++ = *str++;
	}
	//마지막이 개행문자면 NULL 추가
	if (*(next_str - 1) == '\n')
		*(next_str - 1) = 0;
	else
		*next_str = 0;

	// 만약 현재 위치가 쉼표거나 문자열의 마지막이라면 한 칸 앞으로 이동
	if (*str == comma || *str == '\n')
		str++;

	return str;
}

void read_data(void) {
	//엑셀파일을 csv 파일로 변환해서 읽는 기능(변수 p_pile)
	FILE* p_file = NULL;

	//data.csv 파일 읽기 모드로 열기
	if (0 == fopen_s(&p_file, "data.csv", "rt")) {
		char one_line_str[128], buffer[32], *p_pos;

		//배열 사용해서 보기 좋게 출력하지만 아직 보기좋게 정렬 안됨
		//배열 크기는 항목 개수에 맞게끔 수정필요
		const char* title_format[5] =
		{ "   %s   ", "   %s   ", "   %s   ", "   %s   ", "   %s   \n" };
		const char* data_format[5] =
		{ "   %s   ", "   %s   ", "   %s   ", "   %s   ", "   %s   \n" };

		//파일에서 항목의 이름 가져옴
		if (NULL != fgets(one_line_str, 128, p_file)) {
			printf("--------------------------------------------------------\n");
			p_pos = one_line_str;

			for (int i = 0; *p_pos; i++) {
				p_pos = space_for_next_str(p_pos, ',', buffer);
				printf(title_format[i], buffer);
			}
			printf("--------------------------------------------------------\n");
		}
		//파일의 마지막까지 항목을 가져옴
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
		printf("에러: data.csv 파일을 찾지 못했습니다. 파일을 확인해주세요.");
}