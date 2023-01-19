/* 객체지향 프로그래밍 Assignment 3_20210479 이주현*/
#include "ashapelist.h"

using namespace std;

AShapeList::AShapeList() //size는 선언과 동시에 초기화됨
{
	/* head, tail 초기화를 위한 임시 노드 선언 */
	AShapeNode* temp = new AShapeNode;

	temp->next = NULL;
	temp->shape = NULL;

	/* 임시 노드를 이용해 head, tail 초기화 */
	head = temp;
	tail = temp;

	delete temp; //임시 노드는 바로 할당 해제
}

AShapeList::~AShapeList()
{
	if (size == 1) //size가 1인 경우 중복 할당 해제를 피하기 위해 head만 할당 해제
	{
		delete head;
	}

	else if (size > 1) //size가 1 초과인 경우
	{
		AShapeNode* temp = head;

		while (temp-> next != NULL) //head 뒤쪽의 모든 원소 할당 해제
		{
			delete temp->next;
		}

		delete head; //head 할당 해제
	}
}

void AShapeList::addNewAShape(AShape* new_shape)
{
	/* 입력받은 shape의 정보를 저장할 새로운 node 선언 */
	AShapeNode* buffer = new AShapeNode; //
	buffer->shape = new_shape;
	buffer->next = NULL;

	/* 새로운 node를 list에 삽입 */
	if (size == 0) //list가 비어있을 경우
	{
		head = buffer;
		tail = buffer;
	}

	else //기존에 list 내에 원소가 존재한 경우
	{
		tail->next = buffer;
		tail = buffer;
	}

	size++; //list 사이즈 업데이트
}

AShapeNode* AShapeList::popNodeByIdx(int idx)
{
	AShapeNode* temp = head; //list 내의 원소를 가리킬 임시 변수
	AShapeNode* rtemp = new AShapeNode; //반환용 임시 변수

	if (idx == 0) //맨 앞 노드를 지우는 경우
	{
		head = head->next;
		size--; //사이즈 업데이트

		return temp;
	}

	else //맨 앞이 아닌 노드를 지우는 경우
	{
		int cnt = 0; //인덱스 카운트용 임시 변수

		while (cnt != idx - 1) //삭제할 노드 바로 앞을 가리키도록 함
		{
			temp = temp->next;
			cnt++;
		}

		rtemp = temp;

		if (idx == size - 1) //삭제할 노드가 맨 뒤일 경우
		{
			temp->next = NULL;
			tail = temp;
			size--; //사이즈 업데이트

			return rtemp;
		}

		else //중간에 있는 노드를 삭제하는 경우
		{
			temp->next = temp->next->next; //삭제할 노드 이전 노드와, 삭제할 노드 다음 노드를 연결함
			size--; //사이즈 업데이트

			return rtemp;
		}
	}
}

const AShapeNode* AShapeList::getNodeByIdx(int idx) const
{
	int cnt = 0;
	AShapeNode* temp = head;

	while (cnt < idx) //idx에 해당하는 원소 가리킬 때까지 반복
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