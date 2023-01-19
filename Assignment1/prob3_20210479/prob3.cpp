/* ��ü���� ���α׷��� Assignment 1 Prob3_20210479 ������ */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>

struct position //��ǥ�� �����ϰ� �ٷ�� queue�� ����� ���� ����ü
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
void FindOpt(int xs, int ys, int xt, int yt, int map[][10], int *rslt); //��� ��ǥ�� ��ǥ ��ǥ�� �޾� �ִ� �Ÿ��� ������ִ� �Լ�

int main()
{
	using namespace std;

	ifstream fi("input.txt"); //�Է¹޴� ���� ����
	ofstream fo("output.txt"); //����� ���� ����

	if (fi.fail()) //input ������ ���� ������ ��� ���� ���� ���
	{
		cout << "Input file open error. Please try again.\n";
		return 100;
	}

	if (fo.fail()) //output ������ ���� ������ ��� ���� ���� ���
	{
		cout << "Output file open error. Please try again.\n";
		return 101;
	}

	int map[10][10]; //���� ����� 2���� �迭
	
	int xk = 0, yk = 0, xe = 0, ye = 0; //k�� e ��ġ ����� ����
	int kRslt = 200, eRslt = 200, rslt = 0; //(�������) k����, e����, ���� �ִ� �Ÿ� ����� ����

	cout << "File reading. Please wait...\n";
	int a = 0, b = 0; //map �迭 ��ǥ ���� ���� ����

	while (!fi.eof()) //���Ͽ��� map �о���̱�
	{
		char buffer = 'a'; //���Ͽ��� �о���̱� ���� ����

		fi >> buffer;

		if (b == 10) //while���� ��������Ƿ� �� �ٲ��� ���� �ۼ�
		{
			a++;
			b = 0;
		}

		if (a == 10 && b == 0) //eof�ε� ���������� while���� ������� �ʴ� ��츦 ���� �ۼ�
			break;

		if (buffer == 'k') //k ��ġ�� ã���� �ش� ��ǥ ��� �� map�� 2�� ǥ��
		{
			map[a][b] = 2;
			xk = a;
			yk = b;
		}

		else if (buffer == 'e') //e ��ġ�� ã���� �ش� ��ǥ ��� �� map�� 3���� ǥ��
		{
			map[a][b] = 3;
			xe = a;
			ye = b;
		}

		else //k, e ��� �ƴ� ��� map�� ���� ǥ��
			map[a][b] = (int)buffer - 48; //int������ �ڷ��� ������ �� ��� 0�� 48�� ���Ƿ�, 48�� ����

		b++; //map ������ x ��ǥ �̵� ����� ���� �ۼ�
	}

	cout << "k distance calculating. Please wait...\n";
	FindOpt(0, 0, xk, yk, map, &kRslt);

	cout << "e distance calculating. Please wait...\n";
	FindOpt(xk, yk, xe, ye, map, &eRslt);

	rslt = kRslt + eRslt; //���� �ִ� �Ÿ� ���
	fo << rslt; //output ���Ϸ� ���

	cout << "File exporting finished.\n";

	fi.close();
	fo.close(); //input, output ���� �ݱ�

	return 0;
}

void FindOpt(int xs, int ys, int xt, int yt, int map[][10], int *rslt)
{
	using namespace std;

	int vstSts[10][10]; //�湮 Ȯ�ο� 2���� �迭
	int distance[10][10]; //�Ÿ� ����� 2���� �迭

	int xd[4] = { 0, 0, -1, 1 }; //�¿� ���� ���ÿ� �迭
	int yd[4] = { 1, -1, 0, 0 }; //���� ���� ���ÿ� �迭

	queue plist; //�̵� ���� ��ǥ ����� ť
	qInit(&plist); //ť �ʱ�ȭ
	position temp; //��ǥ �ӽ� ��Ͽ� ����ü ����

	for (int i = 0; i < 10; i++) //�湮 Ȯ�ο�, �Ÿ� ����� �迭 0���� �ʱ�ȭ
	{
		for (int j = 0; j < 10; j++)
		{
			vstSts[i][j] = 0;
			distance[i][j] = 0;
		}
	}

	vstSts[xs][ys] = 1; //��� ��ǥ �湮 ���
	distance[xs][ys] = 1; //�Ÿ� ���

	temp.x = xs, temp.y = ys; //��� ��ǥ ���
	push(&plist, temp); //ť�� ��� ��ǥ �ֱ�

	while (!empty(&plist)) //�̵� ���� ��ǥ�� ��� ������ ������ �ݺ�
	{
		int xCur = 0, yCur = 0; //���� ��ǥ�� ǥ���� ���� ����
		
		front(&plist, &xCur, &yCur); //xCur, yCur�� ���� ��ǥ ���� 

		pop(&plist); //��ǥ�� xCur, yCur�� �����ϰ� ù ���� ����

		for (int i = 0; i < 4; i++)
		{
			int xNext = xCur + xd[i]; //�����¿� ������ �ݿ��� ���� ��ǥ�� x��ġ
			int yNext = yCur + yd[i]; //�����¿� ������ �ݿ��� ���� ��ǥ�� y��ġ

			if (xNext < 0 || yNext < 0 || xNext > 9 || yNext > 9) //map�� ��� ��ǥ�� ������� ����
				continue;

			else if (map[xNext][yNext] == 0 && vstSts[xNext][yNext] != 1) //�̵� �����ϰ� �湮�� �� ���� ��ǥ�� ���ؼ�
			{
				temp.x = xNext, temp.y = yNext; //ť�� ����ϱ� ���� ����ü ������ ��ǥ ���
				push(&plist, temp); //�̵� ������ ��ǥ ť�� ����

				vstSts[xNext][yNext] = 1; //�湮 ���
				distance[xNext][yNext] = distance[xCur][yCur] + 1; //�Ÿ� ���
			}
		}
	}

	for (int i = 0; i < 4; i++) //��ǥ ��ǥ �ֺ��� �Ÿ� �迭�� ���� �ִ� �Ÿ��� rslt�� ����
	{
		int xtemp = xt + xd[i]; //��ǥ ��ǥ �ֺ� 4�� ��ǥ�� x��ǥ
		int ytemp = yt + yd[i]; //��ǥ ��ǥ �ֺ� 4�� ��ǥ�� y��ǥ

		if (xtemp < 0 || xtemp > 9 || ytemp < 0 || ytemp > 9) //map�� ��� ��ǥ�� ������� ����
			continue;

		else
		{
			if (*rslt > distance[xtemp][ytemp] && distance[xtemp][ytemp] > 0) //distance�� ����� �Ÿ��� rslt���� ������ �ִܰŸ��̹Ƿ� �ٲپ� ����
			{
				*rslt = distance[xtemp][ytemp];
				continue;
			}
		}
	}
}

void qInit(queue* q) //ť �ʱ�ȭ �Լ�
{
	node* temp = new node;

	temp->p.x = NULL;
	temp->p.y = NULL;
	temp->next = NULL;

	q->front = temp;
	q->rear = temp;

	q->size = 0;
}

void push(queue* q, position temp) //enqueue �Լ� (ť�� ��带 �����ϴ� �Լ�)
{
	node* buffer = new node;
	buffer->p = temp;
	buffer->next = NULL;
	
	if (q->size == 0) //ť�� ������� ���
	{
		q->front = buffer;
		q->rear = buffer;
	}

	else //ť�� ������ ����ִ� element�� ���� ���
	{
		q->rear->next = buffer;
		q->rear = buffer;
	}

	q->size++; //������ ������Ʈ
}

void pop(queue* q) //dequeue �Լ� (ť���� ��带 �����ϴ� �Լ�)
{
	node* temp = new node;
	temp->p.x = NULL;
	temp->p.y = NULL;
	temp->next = NULL;
	
	if (q->size == 1) //ť�� ���� element�� �ϳ��� ���
	{
		q->front = temp;
		q->rear = temp;
	}

	else //ť�� �� �� �̻��� element�� �������� ���
	{
		temp->p = q->front->p;
		temp = q->front;

		q->front = q->front->next;
		delete temp;
	}

	q->size--; //������ ������Ʈ
}

void front(queue* q, int *x, int *y) //ť�� front�� �ִ� element�� ����ϴ� �Լ�
{
	if (q->size != 0)
	{
		*x = q->front->p.x;
		*y = q->front->p.y;
	}
}

bool empty(queue* q) //ť�� ������� (size == 0����) Ȯ���ϴ� �Լ�
{
	return q->size == 0;
}