/* 객체지향 프로그래밍 Assignment 3_20210479 이주현*/
#include "menu.h"

using namespace std;

Menu::Menu(WhiteBoard* board, AShapeList* shape_list) //private 변수에 입력받은 값 대입
{
	(*this).board = board;
	(*this).shape_list = shape_list;
}

Menu::~Menu() //소멸자
{
	shape_list = NULL;
	board = NULL;
}

void Menu::display() const
{
	board->display(); //whiteboard 출력

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
	int menu = 0; //사용자로부터 메뉴를 입력받을 변수 선언
	cin >> menu; //메뉴 입력받기

	if (menu == 1) //1번을 입력받았을 경우
		addAShape(); //도형 추가 함수 실행

	else if (menu == 2) //2번을 입력받았을 경우
		deleteAShape(); //도형 삭제 함수 실행

	else if (menu == 3) //3번을 입력받았을 경우
	{
		cout << "Exit program" << endl; //프로그램 종료 안내 문구 출력
		is_running = false; //프로그램 종료(getRunning의 리턴값이 false로 변하게 됨)
	}
		
	else //잘못된 메뉴를 입력받았을 경우 에러 처리
		cout << "Error: Invalid input. Type again." << endl << endl;
}

void Menu::addAShape() const
{
	char a; //알파벳을 입력받아 저장할 변수
	int xs = 0, xe = 0, ys = 0, ye = 0; //x, y 좌표를 입력받아 저장할 변수
	
	/* 정보를 입력받는 부분 */
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

	/* 입력받은 정보를 선별하여 에러를 처리하거나 혹은 도형을 추가하는 부분 */
	AShape* s; //polymorphism 이용을 위해 ashape 포인터 선언

	if (xs < 0 || xe < 0 || ys < 0 || ye < 0) //좌표값으로 음수가 입력된 경우 에러 처리
		cout << "Error: Coordinate cannot be a negative value." << endl << endl;

	if (xs > 14 || xe > 14 || ys > 14 || ye > 14) //좌표값이 whiteboard를 넘어간 경우 에러 처리
		cout << "Error: Your input exceed the whiteboard size." << endl << endl;

	if (xs == xe && ys == ye) //Point를 입력받은 경우
	{
		s = new APoint(xs, ys, a);
		cout << endl << "New APoint is added with size: 1" << endl << endl;

		shape_list->addNewAShape(s); //list에 도형 추가
	}
	
	else if (xs == xe && ys < ye) //VerticalLine을 입력받은 경우
	{
		s = new AVerticalLine(xs, ys, ye, a);
		cout << endl << "New AVerticalLine is added with size: " <<  s->size() << endl << endl;

		shape_list->addNewAShape(s); //list에 도형 추가
	}

	else if (xs < xe && ys == ye) //HorizontalLine을 입력받은 경우
	{
		s = new AHorizontalLine(ys, xs, xe, a);
		cout << endl << "New AHorizontalLine is added with size: " << s->size() << endl << endl;

		shape_list->addNewAShape(s); //list에 도형 추가
	}

	else if (xs < xe && ys < ye) //Rectangle을 입력받은 경우
	{
		s = new ARectangle(xs, xe, ys, ye, a);
		cout << endl << "New ARectangle is added with size: " << s->size() << endl << endl;

		shape_list->addNewAShape(s); //list에 도형 추가
	}

	else if (xs > xe) //x 시작 좌표가 x 끝 좌표보다 큰 경우 에러 처리
		cout << "Error: x_start exceed x_end." << endl << endl;

	else if (ys > ye) //y 시작 좌표가 y 끝 좌표보다 큰 경우 에러 처리
		cout << "Error: y_start exceed y_end." << endl << endl;
}

void Menu::deleteAShape() const
{
	if (shape_list->getSize() == 0) //list가 비어 있을 경우 에러 처리
		cout << "AShapeList is empty." << endl << endl;
	
	else //list에 원소가 들어 있을 경우
	{
		/* list의 정보를 출력하는 부분 */
		cout << endl << "Choose index of AShape that you want to remove." << endl;
		shape_list->displayAShapeList();

		/* 삭제할 원소의 인덱스를 입력받아 에러를 처리하거나 원소 삭제를 수행하는 부분 */
		int idx = 0; //입력받은 인덱스를 저장하는 변수
		int size = shape_list->getSize(); //list의 size를 저장하는 변수

		cin >> idx;
		if (idx < 0 || idx > size) //idx가 음수이거나 size를 초과할 경우 에러 처리
			cout << "Error: Index exceeds the size of AShapeList." << endl << endl;


		else //idx에 문제가 없는 경우
			shape_list->popNodeByIdx(idx);
	}
}