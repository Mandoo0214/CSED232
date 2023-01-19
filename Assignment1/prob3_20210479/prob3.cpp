/* 객체지향 프로그래밍 Assignment 1 Prob3_20210479 이주현 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>

struct position //좌표를 유용하게 다루고 queue를 만들기 위한 구조체
{
	int x;
	int y;
};

struct node
{
	position p;
	node* next;
};

struct queue
{
	node *front;
	node *rear;
	int size;
};

void qInit(queue* q);
void push(queue* q, position temp);
void pop(queue* q);
void front(queue* q, int *x, int *y);
bool empty(queue* q);
void FindOpt(int xs, int ys, int xt, int yt, int map[][10], int *rslt); //출발 좌표와 목표 좌표를 받아 최단 거리를 계산해주는 함수

int main()
{
	using namespace std;

	ifstream fi("input.txt"); //입력받는 파일 열기
	ofstream fo("output.txt"); //출력할 파일 열기

	if (fi.fail()) //input 파일을 열지 못했을 경우 오류 문구 출력
	{
		cout << "Input file open error. Please try again.\n";
		return 100;
	}

	if (fo.fail()) //output 파일을 열지 못했을 경우 오류 문구 출력
	{
		cout << "Output file open error. Please try again.\n";
		return 101;
	}

	int map[10][10]; //지도 저장용 2차원 배열
	
	int xk = 0, yk = 0, xe = 0, ye = 0; //k와 e 위치 저장용 변수
	int kRslt = 200, eRslt = 200, rslt = 0; //(순서대로) k까지, e까지, 최종 최단 거리 저장용 변수

	cout << "File reading. Please wait...\n";
	int a = 0, b = 0; //map 배열 좌표 세기 위한 변수

	while (!fi.eof()) //파일에서 map 읽어들이기
	{
		char buffer = 'a'; //파일에서 읽어들이기 위한 변수

		fi >> buffer;

		if (b == 10) //while문을 사용했으므로 줄 바꿈을 위해 작성
		{
			a++;
			b = 0;
		}

		if (a == 10 && b == 0) //eof인데 정상적으로 while문이 종료되지 않는 경우를 위해 작성
			break;

		if (buffer == 'k') //k 위치를 찾으면 해당 좌표 기록 및 map에 2로 표시
		{
			map[a][b] = 2;
			xk = a;
			yk = b;
		}

		else if (buffer == 'e') //e 위치를 찾으면 해당 좌표 기록 및 map에 3으로 표시
		{
			map[a][b] = 3;
			xe = a;
			ye = b;
		}

		else //k, e 모두 아닌 경우 map에 숫자 표시
			map[a][b] = (int)buffer - 48; //int형으로 자료형 변형을 할 경우 0이 48로 들어가므로, 48을 빼줌

		b++; //map 내에서 x 좌표 이동 고려를 위해 작성
	}

	cout << "k distance calculating. Please wait...\n";
	FindOpt(0, 0, xk, yk, map, &kRslt);

	cout << "e distance calculating. Please wait...\n";
	FindOpt(xk, yk, xe, ye, map, &eRslt);

	rslt = kRslt + eRslt; //최종 최단 거리 계산
	fo << rslt; //output 파일로 출력

	cout << "File exporting finished.\n";

	fi.close();
	fo.close(); //input, output 파일 닫기

	return 0;
}

void FindOpt(int xs, int ys, int xt, int yt, int map[][10], int *rslt)
{
	using namespace std;

	int vstSts[10][10]; //방문 확인용 2차원 배열
	int distance[10][10]; //거리 저장용 2차원 배열

	int xd[4] = { 0, 0, -1, 1 }; //좌우 방향 지시용 배열
	int yd[4] = { 1, -1, 0, 0 }; //상하 방향 지시용 배열

	queue plist; //이동 가능 좌표 저장용 큐
	qInit(&plist); //큐 초기화
	position temp; //좌표 임시 기록용 구조체 선언

	for (int i = 0; i < 10; i++) //방문 확인용, 거리 저장용 배열 0으로 초기화
	{
		for (int j = 0; j < 10; j++)
		{
			vstSts[i][j] = 0;
			distance[i][j] = 0;
		}
	}

	vstSts[xs][ys] = 1; //출발 좌표 방문 기록
	distance[xs][ys] = 1; //거리 기록

	temp.x = xs, temp.y = ys; //출발 좌표 기록
	push(&plist, temp); //큐에 출발 좌표 넣기

	while (!empty(&plist)) //이동 가능 좌표를 모두 검토할 때까지 반복
	{
		int xCur = 0, yCur = 0; //현재 좌표를 표시할 변수 선언
		
		front(&plist, &xCur, &yCur); //xCur, yCur에 현재 좌표 저장 

		pop(&plist); //좌표를 xCur, yCur에 저장하고 첫 원소 삭제

		for (int i = 0; i < 4; i++)
		{
			int xNext = xCur + xd[i]; //상하좌우 움직임 반영한 다음 좌표의 x위치
			int yNext = yCur + yd[i]; //상하좌우 움직임 반영한 다음 좌표의 y위치

			if (xNext < 0 || yNext < 0 || xNext > 9 || yNext > 9) //map을 벗어난 좌표는 고려하지 않음
				continue;

			else if (map[xNext][yNext] == 0 && vstSts[xNext][yNext] != 1) //이동 가능하고 방문한 적 없는 좌표에 대해서
			{
				temp.x = xNext, temp.y = yNext; //큐에 기록하기 위해 구조체 변수에 좌표 기록
				push(&plist, temp); //이동 가능한 좌표 큐에 저장

				vstSts[xNext][yNext] = 1; //방문 기록
				distance[xNext][yNext] = distance[xCur][yCur] + 1; //거리 기록
			}
		}
	}

	for (int i = 0; i < 4; i++) //목표 좌표 주변의 거리 배열을 보고 최단 거리를 rslt에 저장
	{
		int xtemp = xt + xd[i]; //목표 좌표 주변 4개 좌표의 x좌표
		int ytemp = yt + yd[i]; //목표 좌표 주변 4개 좌표의 y좌표

		if (xtemp < 0 || xtemp > 9 || ytemp < 0 || ytemp > 9) //map을 벗어난 좌표는 고려하지 않음
			continue;

		else
		{
			if (*rslt > distance[xtemp][ytemp] && distance[xtemp][ytemp] > 0) //distance에 저장된 거리가 rslt보다 작으면 최단거리이므로 바꾸어 저장
			{
				*rslt = distance[xtemp][ytemp];
				continue;
			}
		}
	}
}

void qInit(queue* q) //큐 초기화 함수
{
	node* temp = new node;

	temp->p.x = NULL;
	temp->p.y = NULL;
	temp->next = NULL;

	q->front = temp;
	q->rear = temp;

	q->size = 0;
}

void push(queue* q, position temp) //enqueue 함수 (큐에 노드를 삽입하는 함수)
{
	node* buffer = new node;
	buffer->p = temp;
	buffer->next = NULL;
	
	if (q->size == 0) //큐가 비어있을 경우
	{
		q->front = buffer;
		q->rear = buffer;
	}

	else //큐에 기존에 들어있는 element가 있을 경우
	{
		q->rear->next = buffer;
		q->rear = buffer;
	}

	q->size++; //사이즈 업데이트
}

void pop(queue* q) //dequeue 함수 (큐에서 노드를 삭제하는 함수)
{
	node* temp = new node;
	temp->p.x = NULL;
	temp->p.y = NULL;
	temp->next = NULL;
	
	if (q->size == 1) //큐의 남은 element가 하나일 경우
	{
		q->front = temp;
		q->rear = temp;
	}

	else //큐에 두 개 이상의 element가 남아있을 경우
	{
		temp->p = q->front->p;
		temp = q->front;

		q->front = q->front->next;
		delete temp;
	}

	q->size--; //사이즈 업데이트
}

void front(queue* q, int *x, int *y) //큐의 front에 있는 element를 출력하는 함수
{
	if (q->size != 0)
	{
		*x = q->front->p.x;
		*y = q->front->p.y;
	}
}

bool empty(queue* q) //큐가 비었는지 (size == 0인지) 확인하는 함수
{
	return q->size == 0;
}