#include "menu.h"

int main()
{
	WhiteBoard board;
	AShapeList shape_list;
	Menu menu(&board, &shape_list); //constructor�� �̿��Ͽ� menu object ����

	while (menu.getRunning()) //menu�� private ���� is_running�� true�� ���� ���� (i.e., �޴� 3���� �Է¹ޱ� ������ ����)
	{
		/* board�� ���� �׷��� ��� �� menu ��� */
		board.reset();
		shape_list.drawAll(&board);
		menu.display();

		/* ������ �޴� �Է¹ޱ� */
		menu.getUserInput();
	}

	return 0;
}