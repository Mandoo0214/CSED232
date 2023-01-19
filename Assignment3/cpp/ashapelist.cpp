/* ��ü���� ���α׷��� Assignment 3_20210479 ������*/
#include "ashapelist.h"

using namespace std;

AShapeList::AShapeList() //size�� ����� ���ÿ� �ʱ�ȭ��
{
	/* head, tail �ʱ�ȭ�� ���� �ӽ� ��� ���� */
	AShapeNode* temp = new AShapeNode;

	temp->next = NULL;
	temp->shape = NULL;

	/* �ӽ� ��带 �̿��� head, tail �ʱ�ȭ */
	head = temp;
	tail = temp;

	delete temp; //�ӽ� ���� �ٷ� �Ҵ� ����
}

AShapeList::~AShapeList()
{
	if (size == 1) //size�� 1�� ��� �ߺ� �Ҵ� ������ ���ϱ� ���� head�� �Ҵ� ����
	{
		delete head;
	}

	else if (size > 1) //size�� 1 �ʰ��� ���
	{
		AShapeNode* temp = head;

		while (temp-> next != NULL) //head ������ ��� ���� �Ҵ� ����
		{
			delete temp->next;
		}

		delete head; //head �Ҵ� ����
	}
}

void AShapeList::addNewAShape(AShape* new_shape)
{
	/* �Է¹��� shape�� ������ ������ ���ο� node ���� */
	AShapeNode* buffer = new AShapeNode; //
	buffer->shape = new_shape;
	buffer->next = NULL;

	/* ���ο� node�� list�� ���� */
	if (size == 0) //list�� ������� ���
	{
		head = buffer;
		tail = buffer;
	}

	else //������ list ���� ���Ұ� ������ ���
	{
		tail->next = buffer;
		tail = buffer;
	}

	size++; //list ������ ������Ʈ
}

AShapeNode* AShapeList::popNodeByIdx(int idx)
{
	AShapeNode* temp = head; //list ���� ���Ҹ� ����ų �ӽ� ����
	AShapeNode* rtemp = new AShapeNode; //��ȯ�� �ӽ� ����

	if (idx == 0) //�� �� ��带 ����� ���
	{
		head = head->next;
		size--; //������ ������Ʈ

		return temp;
	}

	else //�� ���� �ƴ� ��带 ����� ���
	{
		int cnt = 0; //�ε��� ī��Ʈ�� �ӽ� ����

		while (cnt != idx - 1) //������ ��� �ٷ� ���� ����Ű���� ��
		{
			temp = temp->next;
			cnt++;
		}

		rtemp = temp;

		if (idx == size - 1) //������ ��尡 �� ���� ���
		{
			temp->next = NULL;
			tail = temp;
			size--; //������ ������Ʈ

			return rtemp;
		}

		else //�߰��� �ִ� ��带 �����ϴ� ���
		{
			temp->next = temp->next->next; //������ ��� ���� ����, ������ ��� ���� ��带 ������
			size--; //������ ������Ʈ

			return rtemp;
		}
	}
}

const AShapeNode* AShapeList::getNodeByIdx(int idx) const
{
	int cnt = 0;
	AShapeNode* temp = head;

	while (cnt < idx) //idx�� �ش��ϴ� ���� ����ų ������ �ݺ�
	{
		temp = temp->next;
		cnt++;
	}

	return temp;
}

void AShapeList::displayAShapeList() const
{
	cout << "[========List of AShape========]" << endl;
	cout << "Current size: " << size << endl;

	AShapeNode* temp = head;

	for (int i = 0; i < size; i++)
	{
		cout << i << ") ";
		temp->shape->print();
		cout << endl;

		temp = temp->next;
	}

	cout << ">> ";
}

void AShapeList::drawAll(WhiteBoard* board) const
{
	AShapeNode* temp = head;
	
	for (int i = 0; i < size; i++)
	{
		temp->shape->draw(board);

		temp = temp->next;
	}
}

int AShapeList::getSize() const
{
	return size;
}