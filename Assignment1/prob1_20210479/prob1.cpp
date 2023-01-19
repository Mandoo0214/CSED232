/* ��ü���� ���α׷��� Assignment 1 Prob1_20210479 ������*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>

void fOperate(FILE* fi, FILE* fo); //���� �Է�, ���, ��� �۾��� �ϴ� �Լ�

int main()
{
	FILE* fi = fopen("input.txt", "r");
	FILE* fo = fopen("output.txt", "w"); //���� ����� ���� ����

	if (fi == NULL) //input ������ ����� ������ �ʾ��� �� ���� ���� ���
	{
		printf("Input file open error. Please try again.");
		return 100;
	}

	if (fo == NULL) //output ������ ����� ������ �ʾ��� �� ���� ���� ���
	{
		printf("Output file open error. Please try again.");
		return 101;
	}

	printf("File Reading. Please wait...\n"); //���� ���⿡ ������ ������ �� ��� ������ �˸��� ���� ���

	fOperate(fi, fo); //���� �Լ� ����

	printf("Calculation Finished."); //��� �� ���� ��� ���� �� ���� ó�� �ȳ� ���� ���

	fclose(fi);
	fclose(fo); //���� �ݱ�
	return 0;
}

void fOperate(FILE* fi, FILE* fo)
{
	char op = 'a', ent = 'a'; //������ �޾Ƶ��� ���� 1��, �� �ٲ� ���� ���� 1��
	float x = 0, y = 0, rslt = 0; //���� �޾Ƶ��� ���� 2��, ����� ����� ���� 1��

	while (ent != EOF)
	{
		op = fgetc(fi);
		fscanf(fi, "%f %f", &x, &y);
		ent = fgetc(fi);
		
		if (op == '+') //����
		{
			rslt = x + y;
		}

		else if (op == '-') //����
		{
			rslt = x - y;
		}

		else if (op == '*') //����
		{
			rslt = x * y;
		}

		else if (op == '/') //������
		{
			rslt = x / y;
		}

		fprintf(fo, "%.3f\n", rslt);
	}
}