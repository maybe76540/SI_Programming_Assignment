#include <stdio.h>

void delete_data(void) {
	FILE* p_file = NULL;
	
	if (0 == fopen_s(&p_file, "data.csv", "rt+")) {
		//파일포인터를 파일 끝으로 이동시킴
		fseek(p_file, 0, SEEK_END);
		long pos = ftell(p_file);

		if (pos > 0) {
			short int cnt_for_del = 0;
			char ch_for_del;

			//파일포인터를 파일 뒤에서부터 이동
			while (pos > 0) {
				fseek(p_file, pos - 1, SEEK_SET);
				ch_for_del = fgetc(p_file);

				if (ch_for_del == '\n') {
					//\n 나오기 전까지 지나왔던 문자 \b로 지우고 break;
					//파일의 마지막줄에 위치한 데이터 지워짐
					fseek(p_file, pos - 1, SEEK_SET);
					for (int i = 0; i <= cnt_for_del; i++) {
						fputc('\b', p_file);
					}
					break;
				}
				cnt_for_del += 1;
				pos -= 1;
			}
			fseek(p_file, pos, SEEK_SET);
		}
		fclose(p_file);
	}
	else {
		printf("에러: data.csv 파일을 찾지 못했습니다. 파일을 확인해주세요.");
	}
}

//
//#include <unistd.h>
//
////파일 마지막에 위치한 데이터 삭제하는 기능 구현
//void delete_data(void) {
//	//
//	FILE* p_file = NULL;
//	char ch_for_del;
//	int file_descriptor;
//
//	if (0 == fopen_s(&p_file, "data.csv", "rt")) {
//
//		//파일포인터로 파일 마지막 문자로 이동
//		fseek(p_file, -1, SEEK_END);
//
//		//pos는 파일포인터 위치
//		long pos = ftell(p_file);
//
//		//파일의 끝에서 \n 나올때까지 반복문, 
//		//\n 나오면 뒤에서 한 줄 지났다는 뜻으로 파일 크기 줄여서 한 줄 삭제함
//		while (pos > 0) {
//			ch_for_del = fgetc(p_file);
//			if (ch_for_del == '\n') {
//				ftruncate(fileno(p_file), pos); // 파일 크기 수정
//				fclose(p_file);
//				return;
//			}
//			//\n문자는 두 byte로 구성되어 두 byte씩 건너 뛰어 찾음
//			fseek(p_file, -2, SEEK_CUR);
//			pos = ftell(p_file);
//		}
//		fclose(p_file);
//
//	}
//	else
//		printf("에러: data.csv 파일을 찾지 못했습니다. 파일을 확인해주세요.");
//}
//		/*fgetc(file) 함수로 현재 파일 포인터 위치의 문자(즉 마지막 문자)를 읽어서 ch 변수에 저장합니다.
//		그 후에 다시 fseek(file, -2, SEEK_CUR); 로 현재 위치에서 두 칸 앞으로 이동하여 바로 전 문자로 가게 됩니다.
//		이 과정을 개행문자(' ')를 만나거나 파일 시작점까지 반복합니다.
//		반복문을 나오면 현재 위치가 마지막 줄의 시작점이 됩니다(ftell(file)은 현재 파일 포인터 위치를 반환).*/
//		//do {
//		//	ch_for_del = fgetc(p_file);
//		//	fseek(p_file, -2, SEEK_CUR);
//		//} while (ch_for_del != '\n' && ftell(p_file) > 0);
//
//		//if (ftell(p_file) != 0) {
//		//	//POSIX 호환시스템에서 사용가능
//		//	//ftruncate(fileno(file), ftell(file) + 1);
//		//	// Windows시스템에서 사용가능하지만 #include <io.h> #include <fcntl.h> 불러와야함
//		//	//_chsize_s()
//		//	//따라서 동일한 기능을 하는 함수 직접 구현 필요함
//		//	
//		//}