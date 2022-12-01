#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define line 19
#define length 19
#define size 19

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
	int x = -1; int y = -1;
	int blacknum = 0; int whitenum = 0;
	int line_w[size]{};	int length_w[size]{};
	int line_b[size]{};	int length_b[size]{};
	int start_w = 0;	int finish_w = 0;	int save_w[3]{};
	int start_b = 0;	int finish_b = 0;	int save_b[3]{};
	while (true)
	{
		if (turn % 2 == 0)
		{
			printf("흰돌 차례입니다.\n흰돌을 둘 좌표를 입력해주세요");
			while (true)
			{
				scanf("%d %d", &y, &x);
				if (x == -1 && y == -1)
				{
					getchar();
					getchar();
				}
				else if (x < 0 || y < 0 || x>18 || y>18)
				{
					printf("이곳에는 돌을 둘 수 없습니다. 다시 입력해주세요.");
				}
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
				x = -1;
				y = -1;
			}
		}
		else if (turn % 2 == 1)
		{

			printf("검은 돌 차례입니다.\n검은 돌을 둘 좌표를 입력해주세요");
			while (true)
			{
				scanf("%d %d", &y, &x);
				if (x == -1 && y == -1)
				{
					getchar();
					getchar();
				}
				else if (x < 0 || y < 0 || x>18 || y>18)
				{
					printf("이곳에는 돌을 둘 수 없습니다. 다시 입력해주세요.");
				}
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
				x = -1;
				y = -1;
			}
		}
		printf("흰돌의 개수는 : %d\n", whitenum);
		printf("검은돌의 개수는 : %d\n\n", blacknum);


		if (Board[x][y] == 1)
		{
			++length_w[x];
			++line_w[y];
		}
		if (Board[x][y] == 2)
		{
			++length_b[x];
			++line_b[y];
		}

		for (int i = 0; i < line; ++i)
			printf("%d번째 세로줄의 흰돌 개수: %d, 검은돌 개수: %d\n", i, line_w[i], line_b[i]);
		for (int i = 0; i < length; ++i)
			printf("%d번째 가로줄의 흰돌 개수: %d, 검은돌 개수: %d\n", i, length_w[i], length_b[i]);
		printf("\n");

		//가로
		for (int i = 0; i < line; ++i)
		{
			for (int j = 0; j < length; ++j)
			{
				if (Board[i][j] == 1)
				{
					if (Board[i][j - 1] != 1 || j == 0)
						start_w = j;
					finish_w = j;
				}
				else if (Board[i][j] == 2)
				{
					if (Board[i][j - 1] != 2 || j == 0)
						start_b = j;
					finish_b = j;
				}
				if (finish_w - start_w + 1 >= save_w[0])
				{
					save_w[0] = finish_w - start_w + 1;
					save_w[1] = start_w;
					save_w[2] = finish_w;
				}
				if (finish_b - start_b + 1 >= save_b[0])
				{
					save_b[0] = finish_b - start_b + 1;
					save_b[1] = start_b;
					save_b[2] = finish_b;
				}
			}
			if (save_w[0] >= save_b[0] && save_w[0] > 1)
			{
				printf("%d번째 흰돌 가로줄의 연속된 좌표는: ", i);
				for (int j = save_w[1]; j <= save_w[2]; ++j)
					printf("(%d, %d)", j, i);
				printf("\n");
				printf("%d번째 흰돌 가로줄의 연속된 개수는: %d\n", i, save_w[0]);
			}
			if (save_w[0] <= save_b[0] && save_b[0] > 1)
			{
				printf("%d번째 검은돌 가로줄의 연속된 좌표는: ", i);
				for (int j = save_b[1]; j <= save_b[2]; ++j)
					printf("(%d, %d)", j, i);
				printf("\n");
				printf("%d번째 검은돌 가로줄의 연속된 개수는: %d\n", i, save_b[0]);
			}
			memset(save_w, NULL, sizeof(save_w));
			memset(save_b, NULL, sizeof(save_b));
			start_w = 0;	start_b = 0;
			finish_w = 0;	finish_b = 0;
		}
		printf("\n");
		//세로
		for (int j = 0; j < length; ++j)
		{
			for (int i = 0; i < line; ++i)
			{
				if (Board[i][j] == 1)
				{
					if (Board[i-1][j] != 1 || i == 0)
						start_w = i;
					finish_w = i;
				}
				else if (Board[i][j] == 2)
				{
					if (Board[i-1][j] != 2 || i == 0)
						start_b = i;
					finish_b = i;
				}
				if (finish_w - start_w + 1 >= save_w[0])
				{
					save_w[0] = finish_w - start_w + 1;
					save_w[1] = start_w;
					save_w[2] = finish_w;
				}
				if (finish_b - start_b + 1 >= save_b[0])
				{
					save_b[0] = finish_b - start_b + 1;
					save_b[1] = start_b;
					save_b[2] = finish_b;
				}
			}
			if (save_w[0] >= save_b[0] && save_w[0] > 1)
			{
				printf("%d번째 흰돌 세로줄의 연속된 개수는: %d\n", j, save_w[0]);
			}
			if (save_w[0] <= save_b[0] && save_b[0] > 1)
			{
				printf("%d번째 검은돌 세로줄의 연속된 개수는: %d\n", j, save_b[0]);
			}
			memset(save_w, NULL, sizeof(save_w));
			memset(save_b, NULL, sizeof(save_b));
			start_w = 0;	start_b = 0;
			finish_w = 0;	finish_b = 0;
		}

		printf("\n");
		//왼->오
		for (int k = 0; k < size; ++k)
		{
			int j = 0;
			for (int i = k; i < line; ++i)
			{
				if (Board[i][j] == 1)
				{
					if (Board[i - 1][j-1] != 1 || j == 0)
						start_w = j;
					finish_w = j;
				}
				else if (Board[i][j] == 2)
				{
					if (Board[i - 1][j-1] != 2 || j == 0)
						start_b = j;
					finish_b = j;
				}
				if (finish_w - start_w + 1 >= save_w[0])
				{
					save_w[0] = finish_w - start_w + 1;
					save_w[1] = start_w;
					save_w[2] = finish_w;
				}
				if (finish_b - start_b + 1 >= save_b[0])
				{
					save_b[0] = finish_b - start_b + 1;
					save_b[1] = start_b;
					save_b[2] = finish_b;
				}
				++j;
			}
			if (save_w[0] >= save_b[0] && save_w[0] > 1)
			{
				printf("%d번째 흰돌 왼->오 대각선의 연속된 개수는: %d\n", size - k - 1, save_w[0]);
			}
			if (save_w[0] <= save_b[0] && save_b[0] > 1)
			{
				printf("%d번째 검은돌 왼->오 대각선의 연속된 개수는: %d\n", size-k-1, save_b[0]);
			}
			memset(save_w, NULL, sizeof(save_w));
			memset(save_b, NULL, sizeof(save_b));
			start_w = 0;	start_b = 0;
			finish_w = 0;	finish_b = 0;
		}
		printf("\n");
		//왼->오
		for (int k = size; k < size*2; ++k)
		{
			int j = 0;
			for (int i = k-size+1; i < line; ++i)
			{
				if (Board[j][i] == 1)
				{
					if (Board[j - 1][i - 1] != 1 || j == 0)
						start_w = j;
					finish_w = j;
				}
				else if (Board[j][i] == 2)
				{
					if (Board[j - 1][i - 1] != 2 || j == 0)
						start_b = j;
					finish_b = j;
				}
				if (finish_w - start_w + 1 >= save_w[0])
				{
					save_w[0] = finish_w - start_w + 1;
					save_w[1] = start_w;
					save_w[2] = finish_w;
				}
				if (finish_b - start_b + 1 >= save_b[0])
				{
					save_b[0] = finish_b - start_b + 1;
					save_b[1] = start_b;
					save_b[2] = finish_b;
				}
				++j;
			}
			if (save_w[0] >= save_b[0] && save_w[0] > 1)
			{
				printf("%d번째 흰돌 왼->오 대각선의 연속된 개수는: %d\n", k, save_w[0]);
			}
			if (save_w[0] <= save_b[0] && save_b[0] > 1)
			{
				printf("%d번째 검은돌 왼->오 대각선의 연속된 개수는: %d\n", k, save_b[0]);
			}
			memset(save_w, NULL, sizeof(save_w));
			memset(save_b, NULL, sizeof(save_b));
			start_w = 0;	start_b = 0;
			finish_w = 0;	finish_b = 0;
		}
		printf("\n");
		//오->왼 대각선
		for (int k = 0; k< size; ++k)
		{
			int i = 0;
			for (int j = k; j >=0; --j)
			{
				if (Board[i][j] == 1)
				{
					if (Board[i-1][j+1] != 1 || i == 0)
						start_w = i;
					finish_w = i;
				}
				else if (Board[i][j] == 2)
				{
					if (Board[i-1][j + 1] != 2 || i == 0)
						start_b = i;
					finish_b = i;
				}
				if (finish_w - start_w + 1 >= save_w[0])
				{
					save_w[0] = finish_w - start_w + 1;
					save_w[1] = start_w;
					save_w[2] = finish_w;
				}
				if (finish_b - start_b + 1 >= save_b[0])
				{
					save_b[0] = finish_b - start_b + 1;
					save_b[1] = start_b;
					save_b[2] = finish_b;
				}
				++i;
			}
			if (save_w[0] >= save_b[0] && save_w[0] > 1)
			{
				printf("%d번째 흰돌 오->왼 대각선의 연속된 개수는: %d\n", k, save_w[0]);
			}
			if (save_w[0] <= save_b[0] && save_b[0] > 1)
			{
				printf("%d번째 검은돌 오->왼 대각선의 연속된 개수는: %d\n", k, save_b[0]);
			}
			memset(save_w, NULL, sizeof(save_w));
			memset(save_b, NULL, sizeof(save_b));
			start_w = 0;	start_b = 0;
			finish_w = 0;	finish_b = 0;
		}
		printf("\n");
		//오->왼
		for (int k = size; k < size * 2; ++k)
		{
			int j = 18;
			for (int i = k-size + 1; i < line; ++i)
			{
				if (Board[i][j] == 1)
				{
					if (Board[i - 1][j + 1] != 1 || j == 18)
						start_w = j;
					finish_w = j;
				}
				else if (Board[i][j] == 2)
				{
					if (Board[i - 1][j + 1] != 2 || j == 18)
						start_b = j;
					finish_b = j;
				}
				if (start_w - finish_w + 1 >= save_w[0])
				{
					save_w[0] = start_w - finish_w + 1;
					save_w[1] = start_w;
					save_w[2] = finish_w;
				}
				if (start_b - finish_b + 1 >= save_b[0])
				{
					save_b[0] = start_b - finish_b + 1;
					save_b[1] = start_b;
					save_b[2] = finish_b;
				}
				--j;
			}
			if (save_w[0] >= save_b[0] && save_w[0] > 1)
			{
				printf("%d번째 흰돌 오->왼 대각선의 연속된 개수는: %d\n", k, save_w[0]);
			}
			if (save_w[0] <= save_b[0] && save_b[0] > 1)
			{
				printf("%d번째 검은돌 오->왼 대각선의 연속된 개수는: %d\n", k, save_b[0]);
			}
			memset(save_w, NULL, sizeof(save_w));
			memset(save_b, NULL, sizeof(save_b));
			start_w = 0;	start_b = 0;
			finish_w = 0;	finish_b = 0;
		}
	}
}