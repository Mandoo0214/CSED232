/* 객체지향 프로그래밍 Assignment 4_20210479 이주현 */
#pragma once

#include <iostream>
#include <vector>

class geometry
{
	public:
		geometry() {} //default 생성자
		virtual ~geometry() {} //default 소멸자
		virtual void draw2canvas(char** arr, int w, int h, char init) = 0;
};

template <typename T>
class rectangle : public geometry
{
	public:
		/* 새로 추가한 멤버 변수 & 함수 */
		T x1; //두 x좌표 중 작은 것
		T y1; //두 y좌표 중 작은 것
		T x2; //두 x좌표 중 큰 것
		T y2; //두 y좌표 중 큰 것

		/* pdf에 주어진 멤버 함수 */
		rectangle(T a, T b, T c, T d)
		{
			if (!(a == c || b == d))
			{
				/* x좌표를 크기 순서대로 대입 */
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

				/* y좌표를 크기 순서대로 대입 */
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

		~rectangle() {} //default 소멸자

		void draw2canvas(char** arr, int w, int h, char init)
		{
			if (int(x2) >= w || int(y2) >= h) //도형이 canvas를 넘어가는 경우 그리지 않고 무시
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
			if (x1 < other.x1 && other.x1 < x2) //other이 this보다 오른쪽으로 위치해서 겹쳐 있는 경우
			{
				if (other.y1 >= y1 && other.y1 <= y2) //오른쪽 위로 겹친 경우
					return true;

				else if (other.y2 >= y1 && other.y2 <= y2) //오른쪽 아래로 겹친 경우
					return true;

				else if (other.y1 == y1 && other.y2 == y2) //y축 크기가 동일한 경우
					return true;

				else if (other.y1 < y1 && other.y2 > y2) //other의 세로 길이가 this보다 큰 경우
					return true;
			}

			else if (x1 < other.x2 && other.x2 < x2) //other이 this보다 왼쪽으로 위치해서 겹쳐 있는 경우
			{
				if (other.y1 >= y1 && other.y1 <= y2) //왼쪽 위로 겹친 경우
					return true;

				else if (other.y2 >= y1 && other.y2 <= y2) //왼쪽 아래로 겹친 경우
					return true;

				else if (other.y1 == y1 && other.y2 == y2) //y축 크기가 동일한 경우
					return true;

				else if (other.y1 < y1 && other.y2 > y2) //other의 세로 길이가 this보다 큰 경우
					return true;
			}

			else if (!is_equal(other) && ((other.x1 <= x1 && other.x2 >= x2) || (other.x1 >= x1 && other.x2 <= x2))) //어느 한 쪽의 가로 길이가 한 쪽을 포함하는 경우
			{
				if (other.y1 >= y1 && other.y1 <= y2) //위쪽으로 겹친 경우
					return true;

				else if (other.y2 >= y1 && other.y2 <= y2) //아래쪽으로 겹친 경우
					return true;

				else if (other.y1 == y1 && other.y2 == y2) //y축 크기가 동일한 경우
					return true;

				else if (other.y1 < y1 && other.y2 > y2) //other의 세로 길이가 this보다 큰 경우
					return true;
			}

			else
				return false;
		}

		bool is_line_overlap(const rectangle<T>& other)
		{			
			if (x1 == other.x2) //other이 this의 왼쪽에 붙어 있는 경우
			{
				if (other.y1 == y2) //point match와 같은 경우
					return false;

				else if (other.y2 == y1) //point match와 같은 경우
					return false;

				else if (other.y1 >= y1 && other.y1 < y2) //위쪽으로 겹친 경우
					return true;

				else if (other.y2 > y1 && other.y2 <= y2) //아래쪽으로 겹친 경우
					return true;

				else if (other.y1 == y1 && other.y2 == y2) //y축 크기가 동일한 경우
					return true;

				else if (other.y1 < y1 && other.y2 > y2) //this보다 other의 세로가 긴 경우
					return true;
			}

			else if (x2 == other.x1) //other이 this의 오른쪽에 붙어 있는 경우
			{
				if (other.y1 == y2) //point match와 같은 경우
					return false;

				else if (other.y2 == y1) //point match와 같은 경우
					return false;

				else if (other.y1 >= y1 && other.y1 < y2) //위쪽으로 겹친 경우
					return true;

				else if (other.y2 > y1 && other.y2 <= y2) //아래쪽으로 겹친 경우
					return true;

				else if (other.y1 == y1 && other.y2 == y2) //y축 크기가 동일한 경우
					return true;

				else if (other.y1 <  y1 && other.y2 > y2) //this보다 other의 세로가 긴 경우
					return true;
			}

			else if (other.y1 == y2) //other이 this의 위쪽에 붙어 있는 경우
			{
				if (other.x2 == x1) //point match와 같은 경우
					return false;

				else if (other.x1 == x2) //point match와 같은 경우
					return false;

				else if (x1 < other.x2 && other.x2 <= x2) //왼쪽으로 겹치는 경우
					return true;

				else if (x1 <= other.x1 && other.x1 < x2) //오른쪽으로 겹치는 경우
					return true;

				else if (x1 == other.x1 && x2 == other.x2) //y축 크기가 동일한 경우
					return true;

				else if (other.x1 < x1 && other.x2 > x2) //this보다 other의 가로가 긴 경우
					return true;
			}

			else if (other.y2 == y1) //other이 this의 아래쪽에 붙어 있는 경우
			{
				if (other.x2 == x1) //point match와 같은 경우
					return false;

				else if (other.x1 == x2) //point match와 같은 경우
					return false;

				else if (x1 < other.x2 && other.x2 <= x2) //왼쪽으로 겹치는 경우
					return true;

				else if (x1 <= other.x1 && other.x1 < x2) //오른쪽으로 겹치는 경우
					return true;

				else if (x1 == other.x1 && x2 == other.x2) //y축 크기가 동일한 경우
					return true;

				else if (other.x1 < x1 && other.x2 > x2) //this보다 other의 가로가 긴 경우
					return true;
			}

			else
				return false;
		}

		bool is_point_match(const rectangle<T>& other)
		{			
			if (x1 == other.x2) //other이 this의 왼쪽에 위치하는 경우
			{
				if (other.y1 == y2) //other이 this의 왼쪽 위에 위치하는 경우
					return true;

				else if (other.y2 == y1) //other이 this의 왼쪽 아래에 위치하는 경우
					return true;

				else
					return false;
			}

			else if (x2 == other.x1) //other이 this의 오른쪽에 위치하는 경우
			{
				if (other.y1 == y2) //other이 this의 오른쪽 위에 위치하는 경우
					return true;

				else if (other.y2 == y1) //other이 this의 오른쪽 아래에 위치하는 경우
					return true;

				else
					return false;
			}

			else
				return false;
		}

		bool is_disjoint(const rectangle<T>& other)
		{
			if (!is_equal(other) && !is_intersect(other) && !is_line_overlap(other) && !is_point_match(other)) //다른 함수들이 모두 false일 때만 true
				return true;

			else
				return false;
		}

};

template <typename T, int N>
class point : public geometry
{
	public:
		/* 새로 추가한 멤버 변수 & 함수 */
		T* coord; //좌표 저장용 배열

		/* pdf에 주어진 멤버 함수 */
		point(const T* coords)
		{
			coord = new T[N]; //좌표 저장용 배열 동적 할당

			/* 좌표 저장용 배열에 좌표들 저장 */
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
			
			if (y >= h || x >= w) //도형이 canvas를 넘어가는 경우 그리지 않고 무시
				return;

			if (N == 2)
			{
				if (arr[y][x] == init) //해당 위치에 그려질 geometry가 이것 하나인 경우 or 최초로 그려지는 경우
					arr[y][x] = 49;

				else //이미 그려진 geometry가 있는 경우
				{
					arr[y][x]++;

					if (arr[y][x] >= 58) //10을 넘을 경우 0으로 돌아가게 함
						arr[y][x] -= 10;
				}
			}

			else if (N == 3)
			{
				int z = int(coord[2]);
				
				if (arr[y][x] == init) //해당 위치에 그려질 geometry가 이것 하나인 경우 or 최초로 그려지는 경우
				{
					arr[y][x] = z + 48;

					if (arr[y][x] >= 58) //10을 넘을 경우 0으로 돌아가게 함
						arr[y][x] -= 10;
				}
					

				else //이미 그려진 geometry가 있는 경우
				{
					arr[y][x] += z;

					if (arr[y][x] >= 58) //10을 넘을 경우 0으로 돌아가게 함
						arr[y][x] -= 10;
				}
			}

			else //N이 3 초과인 경우
			{
				/* 세 번째 차원부터 끝 차원까지의 값을 모두 더하여 저장할 변수 선언 및 저장 동작 실행 */
				int sum = 0;

				for (int i = 2; i < N; i++)
					sum += int(coord[i]);

				if (sum >= 10) //sum이 10을 넘어간 경우 BCD 중 하나가 되도록 조치
					sum %= 10;

				if (arr[y][x] == init) //해당 위치에 그려질 geometry가 이것 하나인 경우 or 최초로 그려지는 경우
				{
					arr[y][x] = sum + 48;

					if (arr[y][x] >= 58) //10을 넘을 경우 0으로 돌아가게 함
						arr[y][x] -= 10;
				}
					

				else //이미 그려진 geometry가 있는 경우
				{
					arr[y][x] += sum;

					if (arr[y][x] >= 58) //10을 넘을 경우 0으로 돌아가게 함
						arr[y][x] -= 10;
				}
			}
		}
};

class canvas2d : public std::vector<geometry*>
{
	public:
		/* 새로 추가한 멤버 변수 & 함수 */
		char init = 'a'; //초기화 값으로 입력받은 문자

		int w = 0; //canvas의 너비
		int h = 0; //canvas의 높이

		char** canvas; //canvas의 내용	

		/* pdf에 주어진 멤버 함수 */
		canvas2d(int width, int height, char c_empty)
		{
			w = width; //canvas의 너비 업데이트
			h = height; //canvas의 높이 업데이트
			init = c_empty; //canvas를 초기화하는 문자 저장

			/* canvas 동적할당 */
			canvas = new char* [h];
			for (int i = 0; i < h; i++)
			{
				canvas[i] = new char[w];
			}

			/* 주어진 char로 canvas 초기화 */
			for (int j = 0; j < h; j++)
			{
				for (int k = 0; k < w; k++)
				{
					canvas[j][k] = c_empty;
				}
			}
		}

		~canvas2d() {} //default 소멸자

		void draw2stdout()
		{
			/* vector에 존재하는 geometry들을 canvas에 그리기 */
			int cnt = 0;

			while (cnt < (*this).size())
			{
				(*this)[cnt]->draw2canvas(this->canvas, this->w, this->h, this->init);
				cnt++;
			}

			/* stdout으로 출력하는 부분 */
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

			/* canvas 동적 할당 */
			canvas = new char* [h];
			for (int i = 0; i < h; i++)
			{
				canvas[i] = new char[w];
			}

			/* 주어진 char로 canvas 초기화 */
			for (int j = 0; j < h; j++)
			{
				for (int k = 0; k < w; k++)
				{
					canvas[j][k] = c.canvas[j][k];
				}
			}
		}
};