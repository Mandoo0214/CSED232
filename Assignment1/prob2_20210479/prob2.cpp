/* ��ü���� ���α׷��� Assignment 1 Prob2_20210479 ������ */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>

struct pic //���� �� ���� ������ ��� ����ü
{
	int year = 0;
	std::string place;
};

int main()
{
	using namespace std;

	ifstream fi("input.txt"); //input ���� �б� �������� ����
	ofstream fo("output.txt"); //output ���� ���� �������� ���� 

	if (fi.fail()) //input ������ ������ �ʾ��� �� ���� ���� ���
	{
		cout << "Input file open error. Please try again.";
		return 100;
	}

	if (fo.fail()) //output ������ ������ �ʾ��� �� ���� ���� ���
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
	
	pic* pics = new pic[line]; //�� ����ŭ�� ����ü �迭 ����
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