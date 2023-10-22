#include <stdio.h>

void delete_data(void) {
	FILE* p_file = NULL;
	
	if (0 == fopen_s(&p_file, "data.csv", "rt+")) {
		//���������͸� ���� ������ �̵���Ŵ
		fseek(p_file, 0, SEEK_END);
		long pos = ftell(p_file);

		if (pos > 0) {
			short int cnt_for_del = 0;
			char ch_for_del;

			//���������͸� ���� �ڿ������� �̵�
			while (pos > 0) {
				fseek(p_file, pos - 1, SEEK_SET);
				ch_for_del = fgetc(p_file);

				if (ch_for_del == '\n') {
					//\n ������ ������ �����Դ� ���� \b�� ����� break;
					//������ �������ٿ� ��ġ�� ������ ������
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
		printf("����: data.csv ������ ã�� ���߽��ϴ�. ������ Ȯ�����ּ���.");
	}
}

//
//#include <unistd.h>
//
////���� �������� ��ġ�� ������ �����ϴ� ��� ����
//void delete_data(void) {
//	//
//	FILE* p_file = NULL;
//	char ch_for_del;
//	int file_descriptor;
//
//	if (0 == fopen_s(&p_file, "data.csv", "rt")) {
//
//		//���������ͷ� ���� ������ ���ڷ� �̵�
//		fseek(p_file, -1, SEEK_END);
//
//		//pos�� ���������� ��ġ
//		long pos = ftell(p_file);
//
//		//������ ������ \n ���ö����� �ݺ���, 
//		//\n ������ �ڿ��� �� �� �����ٴ� ������ ���� ũ�� �ٿ��� �� �� ������
//		while (pos > 0) {
//			ch_for_del = fgetc(p_file);
//			if (ch_for_del == '\n') {
//				ftruncate(fileno(p_file), pos); // ���� ũ�� ����
//				fclose(p_file);
//				return;
//			}
//			//\n���ڴ� �� byte�� �����Ǿ� �� byte�� �ǳ� �پ� ã��
//			fseek(p_file, -2, SEEK_CUR);
//			pos = ftell(p_file);
//		}
//		fclose(p_file);
//
//	}
//	else
//		printf("����: data.csv ������ ã�� ���߽��ϴ�. ������ Ȯ�����ּ���.");
//}
//		/*fgetc(file) �Լ��� ���� ���� ������ ��ġ�� ����(�� ������ ����)�� �о ch ������ �����մϴ�.
//		�� �Ŀ� �ٽ� fseek(file, -2, SEEK_CUR); �� ���� ��ġ���� �� ĭ ������ �̵��Ͽ� �ٷ� �� ���ڷ� ���� �˴ϴ�.
//		�� ������ ���๮��(' ')�� �����ų� ���� ���������� �ݺ��մϴ�.
//		�ݺ����� ������ ���� ��ġ�� ������ ���� �������� �˴ϴ�(ftell(file)�� ���� ���� ������ ��ġ�� ��ȯ).*/
//		//do {
//		//	ch_for_del = fgetc(p_file);
//		//	fseek(p_file, -2, SEEK_CUR);
//		//} while (ch_for_del != '\n' && ftell(p_file) > 0);
//
//		//if (ftell(p_file) != 0) {
//		//	//POSIX ȣȯ�ý��ۿ��� ��밡��
//		//	//ftruncate(fileno(file), ftell(file) + 1);
//		//	// Windows�ý��ۿ��� ��밡�������� #include <io.h> #include <fcntl.h> �ҷ��;���
//		//	//_chsize_s()
//		//	//���� ������ ����� �ϴ� �Լ� ���� ���� �ʿ���
//		//	
//		//}