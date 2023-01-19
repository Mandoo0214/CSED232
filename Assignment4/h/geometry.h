/* ��ü���� ���α׷��� Assignment 4_20210479 ������ */
#pragma once

#include <iostream>
#include <vector>

class geometry
{
	public:
		geometry() {} //default ������
		virtual ~geometry() {} //default �Ҹ���
		virtual void draw2canvas(char** arr, int w, int h, char init) = 0;
};

template <typename T>
class rectangle : public geometry
{
	public:
		/* ���� �߰��� ��� ���� & �Լ� */
		T x1; //�� x��ǥ �� ���� ��
		T y1; //�� y��ǥ �� ���� ��
		T x2; //�� x��ǥ �� ū ��
		T y2; //�� y��ǥ �� ū ��

		/* pdf�� �־��� ��� �Լ� */
		rectangle(T a, T b, T c, T d)
		{
			if (!(a == c || b == d))
			{
				/* x��ǥ�� ũ�� ������� ���� */
				if (a < c)
				{
					x1 = a;
					x2 = c;
				}

				else if (a > c)
				{
					x1 = c;
					x2 = a;
				}

				/* y��ǥ�� ũ�� ������� ���� */
				if (b < d)
				{
					y1 = b;
					y2 = d;
				}

				else if (b > d)
				{
					y1 = d;
					y2 = b;
				}
			}

			else throw;
		}

		~rectangle() {} //default �Ҹ���

		void draw2canvas(char** arr, int w, int h, char init)
		{
			if (int(x2) >= w || int(y2) >= h) //������ canvas�� �Ѿ�� ��� �׸��� �ʰ� ����
				return;

			int x = int(x2) - int(x1) + 1;
			int y = int(y2) - int(y1) + 1;

			int cntX = int(x1) + x;
			int cntY = int(y1) + y;

			for (int i = int(x1); i < cntX; i++)
			{
				for (int j = int(y1); j < cntY; j++)
				{
					if (arr[j][i] == init)
						arr[j][i] = 49;

					else
					{
						arr[j][i]++;

						if (arr[j][i] >= 58)
							arr[j][i] -= 10;
					}
				}
			}
		}

		bool is_equal(const rectangle<T>& other)
		{
			if (x1 == other.x1 && x2 == other.x2 && y1 == other.y1 && y2 == other.y2)
				return true;

			else
				return false;
		}

		bool is_intersect(const rectangle<T>& other)
		{		
			if (x1 < other.x1 && other.x1 < x2) //other�� this���� ���������� ��ġ�ؼ� ���� �ִ� ���
			{
				if (other.y1 >= y1 && other.y1 <= y2) //������ ���� ��ģ ���
					return true;

				else if (other.y2 >= y1 && other.y2 <= y2) //������ �Ʒ��� ��ģ ���
					return true;

				else if (other.y1 == y1 && other.y2 == y2) //y�� ũ�Ⱑ ������ ���
					return true;

				else if (other.y1 < y1 && other.y2 > y2) //other�� ���� ���̰� this���� ū ���
					return true;
			}

			else if (x1 < other.x2 && other.x2 < x2) //other�� this���� �������� ��ġ�ؼ� ���� �ִ� ���
			{
				if (other.y1 >= y1 && other.y1 <= y2) //���� ���� ��ģ ���
					return true;

				else if (other.y2 >= y1 && other.y2 <= y2) //���� �Ʒ��� ��ģ ���
					return true;

				else if (other.y1 == y1 && other.y2 == y2) //y�� ũ�Ⱑ ������ ���
					return true;

				else if (other.y1 < y1 && other.y2 > y2) //other�� ���� ���̰� this���� ū ���
					return true;
			}

			else if (!is_equal(other) && ((other.x1 <= x1 && other.x2 >= x2) || (other.x1 >= x1 && other.x2 <= x2))) //��� �� ���� ���� ���̰� �� ���� �����ϴ� ���
			{
				if (other.y1 >= y1 && other.y1 <= y2) //�������� ��ģ ���
					return true;

				else if (other.y2 >= y1 && other.y2 <= y2) //�Ʒ������� ��ģ ���
					return true;

				else if (other.y1 == y1 && other.y2 == y2) //y�� ũ�Ⱑ ������ ���
					return true;

				else if (other.y1 < y1 && other.y2 > y2) //other�� ���� ���̰� this���� ū ���
					return true;
			}

			else
				return false;
		}

		bool is_line_overlap(const rectangle<T>& other)
		{			
			if (x1 == other.x2) //other�� this�� ���ʿ� �پ� �ִ� ���
			{
				if (other.y1 == y2) //point match�� ���� ���
					return false;

				else if (other.y2 == y1) //point match�� ���� ���
					return false;

				else if (other.y1 >= y1 && other.y1 < y2) //�������� ��ģ ���
					return true;

				else if (other.y2 > y1 && other.y2 <= y2) //�Ʒ������� ��ģ ���
					return true;

				else if (other.y1 == y1 && other.y2 == y2) //y�� ũ�Ⱑ ������ ���
					return true;

				else if (other.y1 < y1 && other.y2 > y2) //this���� other�� ���ΰ� �� ���
					return true;
			}

			else if (x2 == other.x1) //other�� this�� �����ʿ� �پ� �ִ� ���
			{
				if (other.y1 == y2) //point match�� ���� ���
					return false;

				else if (other.y2 == y1) //point match�� ���� ���
					return false;

				else if (other.y1 >= y1 && other.y1 < y2) //�������� ��ģ ���
					return true;

				else if (other.y2 > y1 && other.y2 <= y2) //�Ʒ������� ��ģ ���
					return true;

				else if (other.y1 == y1 && other.y2 == y2) //y�� ũ�Ⱑ ������ ���
					return true;

				else if (other.y1 <  y1 && other.y2 > y2) //this���� other�� ���ΰ� �� ���
					return true;
			}

			else if (other.y1 == y2) //other�� this�� ���ʿ� �پ� �ִ� ���
			{
				if (other.x2 == x1) //point match�� ���� ���
					return false;

				else if (other.x1 == x2) //point match�� ���� ���
					return false;

				else if (x1 < other.x2 && other.x2 <= x2) //�������� ��ġ�� ���
					return true;

				else if (x1 <= other.x1 && other.x1 < x2) //���������� ��ġ�� ���
					return true;

				else if (x1 == other.x1 && x2 == other.x2) //y�� ũ�Ⱑ ������ ���
					return true;

				else if (other.x1 < x1 && other.x2 > x2) //this���� other�� ���ΰ� �� ���
					return true;
			}

			else if (other.y2 == y1) //other�� this�� �Ʒ��ʿ� �پ� �ִ� ���
			{
				if (other.x2 == x1) //point match�� ���� ���
					return false;

				else if (other.x1 == x2) //point match�� ���� ���
					return false;

				else if (x1 < other.x2 && other.x2 <= x2) //�������� ��ġ�� ���
					return true;

				else if (x1 <= other.x1 && other.x1 < x2) //���������� ��ġ�� ���
					return true;

				else if (x1 == other.x1 && x2 == other.x2) //y�� ũ�Ⱑ ������ ���
					return true;

				else if (other.x1 < x1 && other.x2 > x2) //this���� other�� ���ΰ� �� ���
					return true;
			}

			else
				return false;
		}

		bool is_point_match(const rectangle<T>& other)
		{			
			if (x1 == other.x2) //other�� this�� ���ʿ� ��ġ�ϴ� ���
			{
				if (other.y1 == y2) //other�� this�� ���� ���� ��ġ�ϴ� ���
					return true;

				else if (other.y2 == y1) //other�� this�� ���� �Ʒ��� ��ġ�ϴ� ���
					return true;

				else
					return false;
			}

			else if (x2 == other.x1) //other�� this�� �����ʿ� ��ġ�ϴ� ���
			{
				if (other.y1 == y2) //other�� this�� ������ ���� ��ġ�ϴ� ���
					return true;

				else if (other.y2 == y1) //other�� this�� ������ �Ʒ��� ��ġ�ϴ� ���
					return true;

				else
					return false;
			}

			else
				return false;
		}

		bool is_disjoint(const rectangle<T>& other)
		{
			if (!is_equal(other) && !is_intersect(other) && !is_line_overlap(other) && !is_point_match(other)) //�ٸ� �Լ����� ��� false�� ���� true
				return true;

			else
				return false;
		}

};

template <typename T, int N>
class point : public geometry
{
	public:
		/* ���� �߰��� ��� ���� & �Լ� */
		T* coord; //��ǥ ����� �迭

		/* pdf�� �־��� ��� �Լ� */
		point(const T* coords)
		{
			coord = new T[N]; //��ǥ ����� �迭 ���� �Ҵ�

			/* ��ǥ ����� �迭�� ��ǥ�� ���� */
			for (int i = 0; i < N; i++)
				coord[i] = coords[i];
		}

		~point()
		{
			delete[] coord;
		}

		void draw2canvas(char** arr, int w, int h, char init)
		{
			int x = int(coord[0]);
			int y = int(coord[1]);
			
			if (y >= h || x >= w) //������ canvas�� �Ѿ�� ��� �׸��� �ʰ� ����
				return;

			if (N == 2)
			{
				if (arr[y][x] == init) //�ش� ��ġ�� �׷��� geometry�� �̰� �ϳ��� ��� or ���ʷ� �׷����� ���
					arr[y][x] = 49;

				else //�̹� �׷��� geometry�� �ִ� ���
				{
					arr[y][x]++;

					if (arr[y][x] >= 58) //10�� ���� ��� 0���� ���ư��� ��
						arr[y][x] -= 10;
				}
			}

			else if (N == 3)
			{
				int z = int(coord[2]);
				
				if (arr[y][x] == init) //�ش� ��ġ�� �׷��� geometry�� �̰� �ϳ��� ��� or ���ʷ� �׷����� ���
				{
					arr[y][x] = z + 48;

					if (arr[y][x] >= 58) //10�� ���� ��� 0���� ���ư��� ��
						arr[y][x] -= 10;
				}
					

				else //�̹� �׷��� geometry�� �ִ� ���
				{
					arr[y][x] += z;

					if (arr[y][x] >= 58) //10�� ���� ��� 0���� ���ư��� ��
						arr[y][x] -= 10;
				}
			}

			else //N�� 3 �ʰ��� ���
			{
				/* �� ��° �������� �� ���������� ���� ��� ���Ͽ� ������ ���� ���� �� ���� ���� ���� */
				int sum = 0;

				for (int i = 2; i < N; i++)
					sum += int(coord[i]);

				if (sum >= 10) //sum�� 10�� �Ѿ ��� BCD �� �ϳ��� �ǵ��� ��ġ
					sum %= 10;

				if (arr[y][x] == init) //�ش� ��ġ�� �׷��� geometry�� �̰� �ϳ��� ��� or ���ʷ� �׷����� ���
				{
					arr[y][x] = sum + 48;

					if (arr[y][x] >= 58) //10�� ���� ��� 0���� ���ư��� ��
						arr[y][x] -= 10;
				}
					

				else //�̹� �׷��� geometry�� �ִ� ���
				{
					arr[y][x] += sum;

					if (arr[y][x] >= 58) //10�� ���� ��� 0���� ���ư��� ��
						arr[y][x] -= 10;
				}
			}
		}
};

class canvas2d : public std::vector<geometry*>
{
	public:
		/* ���� �߰��� ��� ���� & �Լ� */
		char init = 'a'; //�ʱ�ȭ ������ �Է¹��� ����

		int w = 0; //canvas�� �ʺ�
		int h = 0; //canvas�� ����

		char** canvas; //canvas�� ����	

		/* pdf�� �־��� ��� �Լ� */
		canvas2d(int width, int height, char c_empty)
		{
			w = width; //canvas�� �ʺ� ������Ʈ
			h = height; //canvas�� ���� ������Ʈ
			init = c_empty; //canvas�� �ʱ�ȭ�ϴ� ���� ����

			/* canvas �����Ҵ� */
			canvas = new char* [h];
			for (int i = 0; i < h; i++)
			{
				canvas[i] = new char[w];
			}

			/* �־��� char�� canvas �ʱ�ȭ */
			for (int j = 0; j < h; j++)
			{
				for (int k = 0; k < w; k++)
				{
					canvas[j][k] = c_empty;
				}
			}
		}

		~canvas2d() {} //default �Ҹ���

		void draw2stdout()
		{
			/* vector�� �����ϴ� geometry���� canvas�� �׸��� */
			int cnt = 0;

			while (cnt < (*this).size())
			{
				(*this)[cnt]->draw2canvas(this->canvas, this->w, this->h, this->init);
				cnt++;
			}

			/* stdout���� ����ϴ� �κ� */
			for (int i = 0; i < h; i++)
			{
				for (int j = 0; j < w; j++)
				{
					if (canvas[i][j] >= 48 && canvas[i][j] <= 58)
						std::cout << int(canvas[i][j]) - 48;

					else
						std::cout << canvas[i][j];
				}

				std::cout << std::endl;
			}
		}

		canvas2d operator= (const canvas2d& c)
		{
			w = c.w;
			h = c.h;
			init = c.init;

			/* canvas ���� �Ҵ� */
			canvas = new char* [h];
			for (int i = 0; i < h; i++)
			{
				canvas[i] = new char[w];
			}

			/* �־��� char�� canvas �ʱ�ȭ */
			for (int j = 0; j < h; j++)
			{
				for (int k = 0; k < w; k++)
				{
					canvas[j][k] = c.canvas[j][k];
				}
			}
		}
};