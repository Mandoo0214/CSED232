/* 객체지향 프로그래밍 Assignment 1 Prob1_20210479 이주현*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>

void fOperate(FILE* fi, FILE* fo); //내용 입력, 계산, 출력 작업을 하는 함수

int main()
{
	FILE* fi = fopen("input.txt", "r");
	FILE* fo = fopen("output.txt", "w"); //파일 입출력 변수 선언

	if (fi == NULL) //input 파일이 제대로 열리지 않았을 때 오류 문구 출력
	{
		printf("Input file open error. Please try again.");
		return 100;
	}

	if (fo == NULL) //output 파일이 제대로 열리지 않았을 때 오류 문구 출력
	{
		printf("Output file open error. Please try again.");
		return 101;
	}

	printf("File Reading. Please wait...\n"); //파일 열기에 문제가 없었을 시 계산 중임을 알리는 문구 출력

	fOperate(fi, fo); //계산용 함수 실행

	printf("Calculation Finished."); //계산 및 파일 출력 종료 후 정상 처리 안내 문구 출력

	fclose(fi);
	fclose(fo); //파일 닫기
	return 0;
}

void fOperate(FILE* fi, FILE* fo)
{
	char op = 'a', ent = 'a'; //연산자 받아들일 변수 1개, 줄 바꿈 문자 변수 1개
	float x = 0, y = 0, rslt = 0; //숫자 받아들일 변수 2개, 결과값 저장용 변수 1개

	while (ent != EOF)
	{
		op = fgetc(fi);
		fscanf(fi, "%f %f", &x, &y);
		ent = fgetc(fi);
		
		if (op == '+') //덧셈
		{
			rslt = x + y;
		}

		else if (op == '-') //뺄셈
		{
			rslt = x - y;
		}

		else if (op == '*') //곱셈
		{
			rslt = x * y;
		}

		else if (op == '/') //나눗셈
		{
			rslt = x / y;
		}

		fprintf(fo, "%.3f\n", rslt);
	}
}