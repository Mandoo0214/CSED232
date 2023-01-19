/* 객체지향 프로그래밍 Assignment 1 Prob2_20210479 이주현 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>

struct pic //사진 한 장의 정보를 담는 구조체
{
	int year = 0;
	std::string place;
};

int main()
{
	using namespace std;

	ifstream fi("input.txt"); //input 파일 읽기 전용으로 열기
	ofstream fo("output.txt"); //output 파일 쓰기 전용으로 열기 

	if (fi.fail()) //input 파일이 열리지 않았을 때 오류 문구 출력
	{
		cout << "Input file open error. Please try again.";
		return 100;
	}

	if (fo.fail()) //output 파일이 열리지 않았을 때 오류 문구 출력
	{
		cout << "Output file open error. Please try again.";
		return 100;
	}
	
	int line = 0;
	while (!fi.eof())
	{
		string buffer;
		getline(fi, buffer);
		line++;
	}
	
	pic* pics = new pic[line]; //줄 수만큼의 구조체 배열 선언
	fi.seekg(0);

	cout << "File Reading. Please wait...\n";
	for (int i = 0; i < line; i++)
	{
		char buffer = 'a';
		fi >> pics[i].year;
		fi >> pics[i].place;
		fi.get(buffer);
	}

	cout << "Information sorting. Please wait...\n";
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < line; j++)
		{
			pic buffer;
			
			if (i == j || i > j)
				continue;

			else if (pics[i].year > pics[j].year)
			{
				buffer = pics[i];
				pics[i] = pics[j];
				pics[j] = buffer;
			}

			else if (pics[i].year == pics[j].year)
			{
				for (int k = 0; k < 6; k++)
				{
					if (pics[i].place[k] == pics[j].place[k])
						continue;

					else if (pics[i].place[k] > pics[j].place[k])
					{
						buffer = pics[i];
						pics[i] = pics[j];
						pics[j] = buffer;
						break;
					}

					break;
				}
			}
		}
	}

	cout << "File exporting. Please wait...\n";
	for (int i = 0; i < line; i++)
	{
		fo << pics[i].year << " " << pics[i].place << endl;
	}

	cout << "File exporting finished.\n";

	return 0;
}