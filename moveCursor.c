// ���� ����
unsigned int G_x_position = 1;
unsigned int G_y_position = 1;

// �Լ� ����
void moveCursor();
void dirCursor(char inputKey);
void moveCursorPosition(int x, int y);
int isCursorMovable(int x, int y, int dir);



// ����Ű�� ���ؼ� Ŀ���� ���ϴ� ��ġ�� �����̴� �Լ�
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
//		else if (user_input == '?') return;	// Ŀ���̵� ��������
	}
}



// Ŀ���� ������ �� �ִ� ��ġ���� Ȯ��
int isCursorMovable(int x, int y)
{
	if ((x > 0) && (y > 0))
		return 1;
	else
		return 0;
}

// Ŀ���� X,Y�� �̵�
void moveCursorPosition(int x, int y)
{
	COORD Pos = { x-1, y-1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// ����ڷκ��� ����Ű�� �Է¹���
void dirCursor(char inputKey)
{
	switch (inputKey)
	{
	case 72:	// ��
		if (isCursorMovable(G_x_position, G_y_position - 1))
		{
			G_y_position--;
			moveCursorPosition(G_x_position, G_y_position);
		}
		break;

	case 75:	// ��
		if (isCursorMovable(G_x_position - 1, G_y_position))
		{
			G_x_position--;
			moveCursorPosition(G_x_position, G_y_position);
		}
		break;

	case 77:	// ��
		if (isCursorMovable(G_x_position + 1, G_y_position))
		{
			G_x_position++;
			moveCursorPosition(G_x_position, G_y_position);
		}
		break;

	case 80:	// ��
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
