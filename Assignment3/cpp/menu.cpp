/* ��ü���� ���α׷��� Assignment 3_20210479 ������*/
#include "menu.h"

using namespace std;

Menu::Menu(WhiteBoard* board, AShapeList* shape_list) //private ������ �Է¹��� �� ����
{
	(*this).board = board;
	(*this).shape_list = shape_list;
}

Menu::~Menu() //�Ҹ���
{
	shape_list = NULL;
	board = NULL;
}

void Menu::display() const
{
	board->display(); //whiteboard ���

	cout << "[===========]" << endl << "[Select Menu]" << endl << "[===========]" << endl;
	cout << "1. add new shape" << endl << "2. delete existing shape" << endl << "3. exit" << endl;
	cout << ">> ";
}

bool Menu::getRunning() const
{
	return is_running;
}

void Menu::getUserInput()
{
	int menu = 0; //����ڷκ��� �޴��� �Է¹��� ���� ����
	cin >> menu; //�޴� �Է¹ޱ�

	if (menu == 1) //1���� �Է¹޾��� ���
		addAShape(); //���� �߰� �Լ� ����

	else if (menu == 2) //2���� �Է¹޾��� ���
		deleteAShape(); //���� ���� �Լ� ����

	else if (menu == 3) //3���� �Է¹޾��� ���
	{
		cout << "Exit program" << endl; //���α׷� ���� �ȳ� ���� ���
		is_running = false; //���α׷� ����(getRunning�� ���ϰ��� false�� ���ϰ� ��)
	}
		
	else //�߸��� �޴��� �Է¹޾��� ��� ���� ó��
		cout << "Error: Invalid input. Type again." << endl << endl;
}

void Menu::addAShape() const
{
	char a; //���ĺ��� �Է¹޾� ������ ����
	int xs = 0, xe = 0, ys = 0, ye = 0; //x, y ��ǥ�� �Է¹޾� ������ ����
	
	/* ������ �Է¹޴� �κ� */
	cout << endl << "[Add New AShape]" << endl;

	cout << "Enter Alphabet >> ";
	cin >> a;

	cout << "Enter x_start >> ";
	cin >> xs;

	cout << "Enter x_end >> ";
	cin >> xe;

	cout << "Enter y_start >> ";
	cin >> ys;

	cout << "Enter y_end >> ";
	cin >> ye;

	/* �Է¹��� ������ �����Ͽ� ������ ó���ϰų� Ȥ�� ������ �߰��ϴ� �κ� */
	AShape* s; //polymorphism �̿��� ���� ashape ������ ����

	if (xs < 0 || xe < 0 || ys < 0 || ye < 0) //��ǥ������ ������ �Էµ� ��� ���� ó��
		cout << "Error: Coordinate cannot be a negative value." << endl << endl;

	if (xs > 14 || xe > 14 || ys > 14 || ye > 14) //��ǥ���� whiteboard�� �Ѿ ��� ���� ó��
		cout << "Error: Your input exceed the whiteboard size." << endl << endl;

	if (xs == xe && ys == ye) //Point�� �Է¹��� ���
	{
		s = new APoint(xs, ys, a);
		cout << endl << "New APoint is added with size: 1" << endl << endl;

		shape_list->addNewAShape(s); //list�� ���� �߰�
	}
	
	else if (xs == xe && ys < ye) //VerticalLine�� �Է¹��� ���
	{
		s = new AVerticalLine(xs, ys, ye, a);
		cout << endl << "New AVerticalLine is added with size: " <<  s->size() << endl << endl;

		shape_list->addNewAShape(s); //list�� ���� �߰�
	}

	else if (xs < xe && ys == ye) //HorizontalLine�� �Է¹��� ���
	{
		s = new AHorizontalLine(ys, xs, xe, a);
		cout << endl << "New AHorizontalLine is added with size: " << s->size() << endl << endl;

		shape_list->addNewAShape(s); //list�� ���� �߰�
	}

	else if (xs < xe && ys < ye) //Rectangle�� �Է¹��� ���
	{
		s = new ARectangle(xs, xe, ys, ye, a);
		cout << endl << "New ARectangle is added with size: " << s->size() << endl << endl;

		shape_list->addNewAShape(s); //list�� ���� �߰�
	}

	else if (xs > xe) //x ���� ��ǥ�� x �� ��ǥ���� ū ��� ���� ó��
		cout << "Error: x_start exceed x_end." << endl << endl;

	else if (ys > ye) //y ���� ��ǥ�� y �� ��ǥ���� ū ��� ���� ó��
		cout << "Error: y_start exceed y_end." << endl << endl;
}

void Menu::deleteAShape() const
{
	if (shape_list->getSize() == 0) //list�� ��� ���� ��� ���� ó��
		cout << "AShapeList is empty." << endl << endl;
	
	else //list�� ���Ұ� ��� ���� ���
	{
		/* list�� ������ ����ϴ� �κ� */
		cout << endl << "Choose index of AShape that you want to remove." << endl;
		shape_list->displayAShapeList();

		/* ������ ������ �ε����� �Է¹޾� ������ ó���ϰų� ���� ������ �����ϴ� �κ� */
		int idx = 0; //�Է¹��� �ε����� �����ϴ� ����
		int size = shape_list->getSize(); //list�� size�� �����ϴ� ����

		cin >> idx;
		if (idx < 0 || idx > size) //idx�� �����̰ų� size�� �ʰ��� ��� ���� ó��
			cout << "Error: Index exceeds the size of AShapeList." << endl << endl;


		else //idx�� ������ ���� ���
			shape_list->popNodeByIdx(idx);
	}
}