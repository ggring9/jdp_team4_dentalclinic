// 전역 변수
unsigned int G_x_position = 1;
unsigned int G_y_position = 1;

// 함수 원형
void moveCursor();
void dirCursor(char inputKey);
void moveCursorPosition(int x, int y);
int isCursorMovable(int x, int y, int dir);



// 방향키를 통해서 커서를 원하는 위치로 움직이는 함수
void moveCursor()
{
	char user_input;
	while (1)
	{
		user_input = getch();
		if (user_input>0)
		{
			dirCursor(user_input);
			moveCursorPosition(G_x_position, G_y_position);
		}
//		else if (user_input == '?') return;	// 커서이동 종료조건
	}
}



// 커서가 움직일 수 있는 위치인지 확인
int isCursorMovable(int x, int y)
{
	if ((x > 0) && (y > 0))
		return 1;
	else
		return 0;
}

// 커서를 X,Y로 이동
void moveCursorPosition(int x, int y)
{
	COORD Pos = { x-1, y-1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// 사용자로부터 방향키를 입력받음
void dirCursor(char inputKey)
{
	switch (inputKey)
	{
	case 72:	// ↑
		if (isCursorMovable(G_x_position, G_y_position - 1))
		{
			G_y_position--;
			moveCursorPosition(G_x_position, G_y_position);
		}
		break;

	case 75:	// ←
		if (isCursorMovable(G_x_position - 1, G_y_position))
		{
			G_x_position--;
			moveCursorPosition(G_x_position, G_y_position);
		}
		break;

	case 77:	// →
		if (isCursorMovable(G_x_position + 1, G_y_position))
		{
			G_x_position++;
			moveCursorPosition(G_x_position, G_y_position);
		}
		break;

	case 80:	// ↓
		if (isCursorMovable(G_x_position, G_y_position + 1))
		{
			G_y_position++;
			moveCursorPosition(G_x_position, G_y_position);
		}
		break;

	default:
		return;
	}
}
