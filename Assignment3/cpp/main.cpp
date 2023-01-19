#include "menu.h"

int main()
{
	WhiteBoard board;
	AShapeList shape_list;
	Menu menu(&board, &shape_list); //constructor를 이용하여 menu object 생성

	while (menu.getRunning()) //menu의 private 변수 is_running이 true인 동안 수행 (i.e., 메뉴 3번을 입력받기 전까지 수행)
	{
		/* board에 도형 그려서 출력 후 menu 출력 */
		board.reset();
		shape_list.drawAll(&board);
		menu.display();

		/* 실행할 메뉴 입력받기 */
		menu.getUserInput();
	}

	return 0;
}