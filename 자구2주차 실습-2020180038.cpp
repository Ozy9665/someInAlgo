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
				printf("┼ ");
				break;

			case 1:
				printf("○");
				break;
				
			case 2:
				printf("●");
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
			printf("흰돌 차례입니다.\n흰돌을 둘 좌표를 입력해주세요");
			
			while (true)
			{
				scanf("%d %d", &y, &x);
				if (x < 0 || y < 0 || x>18 || y>18)
					printf("이곳에는 돌을 둘 수 없습니다. 다시 입력해주세요.");
				else if (Board[x][y] == 1 || Board[x][y] == 2)
					printf("이곳에는 이미 돌이 놓여 있습니다. 다시 입력해주세요.");
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

			printf("검은 돌 차례입니다.\n검은 돌을 둘 좌표를 입력해주세요");

			while (true)
			{
				scanf("%d %d", &y, &x);
				if (x < 0 || y < 0 || x>18 || y>18)
					printf("이곳에는 돌을 둘 수 없습니다. 다시 입력해주세요.");
				else if (Board[x][y] == 1 || Board[x][y] == 2)
					printf("이곳에는 이미 돌이 놓여 있습니다. 다시 입력해주세요.");
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
		printf("흰돌의 개수는 : %d\n", whitenum);
		printf("검은돌의 개수는 : %d\n\n", blacknum);
	}
}