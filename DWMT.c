#include <stdio.h>
#include <Windows.h>
#include <process.h>
#include <stdlib.h> // srand, rand

#define MAX_DOUBLE_DIGITS 99
#define MIN_DOUBLE_DIGITS 1

#define CALCULATOR_TOOL 2

#define EXIT_KEY -1

// initialization
int speed = 0;
int delay = 0;
int count = 0;
unsigned _stdcall Thread_A(void* arg) {

	while (1) {
		Beep(350, speed);
		count = count + 1;
		Sleep(delay);
	}
	printf("총 카운트 : %d \n",count);
}

int main(void) {

	FILE* fp;
	fopen_s(&fp, "test.txt", "w");

	// introduction
	int difficulty = 0;

	//main number tool
	int number_1 = 0;
	int number_2 = 0;

	// calculator tool
	char calculator[] = "+-";

	int answer = 0;  //사용자 정답

	srand(time(NULL));

	printf("Give me a Your Speed : \n");
	scanf_s("%d", &speed);
	printf("Give me a Your Delay : \n");
	scanf_s("%d", &delay);

	_beginthreadex(NULL, 0, Thread_A, 0, 0, NULL);


	// Main Loop
	while (1) {

		number_1 = rand() % MAX_DOUBLE_DIGITS + MIN_DOUBLE_DIGITS;// 1 ~ 99
		int Index = rand() % CALCULATOR_TOOL; // 0 ~ 3
		do {
			printf("de");
			number_2 = rand() % MAX_DOUBLE_DIGITS + MIN_DOUBLE_DIGITS;// 1 ~ 99
		} while ( Index == 1  && number_1 < number_2 );

		//	음수 제외(모든 결과 값)
		// 	앞 수가 뒷 수 보다 커야 함 (뺄셈)
		//	앞 수가 2자리면 뒷자리는 한자리(곱셈)
		//	나눗셈이면 앞자리가 뒷자리보다 커야함(나눗셈)

		// calculator result
		int result[] = {
			  number_1 + number_2
			, number_1 - number_2
		};

		system("cls");
		// main question
		printf("%d %c %d  = ", number_1, calculator[Index], number_2);
		scanf_s("%d", &answer);


		fprintf(fp, "%d %c %d  = %d // 내가 쓴 정답 : %d // 총 카운트 : %d \n"
			, number_1, calculator[Index], number_2, result[Index], answer,count); //문자열 입력

		if (answer == EXIT_KEY) break;



	}
	fclose(fp); //파일 포인터 닫기
	return 0;
}