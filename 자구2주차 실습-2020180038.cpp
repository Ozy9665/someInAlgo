#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define line 19
#define length 19

void PrintBoard(char Board[line][length])
{
	for (int x = 0; x < line; ++x)
	{
		for (int y = 0; y < length; ++y)
		{
			switch (Board[x][y])
			{
			case 0:
				printf("�� ");
				break;

			case 1:
				printf("��");
				break;
				
			case 2:
				printf("��");
				break;
			}
		}
		printf("\n");
	}
}


int main()
{
	char Board[line][length] = {};

	for (int i = 0; i < line; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			Board[i][j] = 0;
		}
	}

	PrintBoard(Board);

	srand((unsigned)time(NULL));

	int turn = rand() % 2;
	int x = 0; int y = 0; 
	int blacknum = 0; int whitenum = 0;

	while (true)
	{
		if (turn % 2 == 0)
		{
			printf("�� �����Դϴ�.\n���� �� ��ǥ�� �Է����ּ���");
			
			while (true)
			{
				scanf("%d %d", &y, &x);
				if (x < 0 || y < 0 || x>18 || y>18)
					printf("�̰����� ���� �� �� �����ϴ�. �ٽ� �Է����ּ���.");
				else if (Board[x][y] == 1 || Board[x][y] == 2)
					printf("�̰����� �̹� ���� ���� �ֽ��ϴ�. �ٽ� �Է����ּ���.");
				else
				{
					Board[x][y] = 1;
					system("cls");
					PrintBoard(Board);
					++turn; ++whitenum;
					break;
				}
			}
		}
		else if (turn % 2 == 1)
		{

			printf("���� �� �����Դϴ�.\n���� ���� �� ��ǥ�� �Է����ּ���");

			while (true)
			{
				scanf("%d %d", &y, &x);
				if (x < 0 || y < 0 || x>18 || y>18)
					printf("�̰����� ���� �� �� �����ϴ�. �ٽ� �Է����ּ���.");
				else if (Board[x][y] == 1 || Board[x][y] == 2)
					printf("�̰����� �̹� ���� ���� �ֽ��ϴ�. �ٽ� �Է����ּ���.");
				else
				{
					Board[x][y] = 2;
					system("cls");
					PrintBoard(Board);
					++turn; ++blacknum;
					break;
				}
			}
		}
		printf("���� ������ : %d\n", whitenum);
		printf("�������� ������ : %d\n\n", blacknum);
	}
}