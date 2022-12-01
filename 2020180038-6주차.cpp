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
			printf("�� �����Դϴ�.\n���� �� ��ǥ�� �Է����ּ���");
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
					printf("�̰����� ���� �� �� �����ϴ�. �ٽ� �Է����ּ���.");
				}
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
				x = -1;
				y = -1;
			}
		}
		else if (turn % 2 == 1)
		{

			printf("���� �� �����Դϴ�.\n���� ���� �� ��ǥ�� �Է����ּ���");
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
					printf("�̰����� ���� �� �� �����ϴ�. �ٽ� �Է����ּ���.");
				}
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
				x = -1;
				y = -1;
			}
		}
		printf("���� ������ : %d\n", whitenum);
		printf("�������� ������ : %d\n\n", blacknum);


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
			printf("%d��° �������� �� ����: %d, ������ ����: %d\n", i, line_w[i], line_b[i]);
		for (int i = 0; i < length; ++i)
			printf("%d��° �������� �� ����: %d, ������ ����: %d\n", i, length_w[i], length_b[i]);
		printf("\n");

		//����
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
				printf("%d��° �� �������� ���ӵ� ��ǥ��: ", i);
				for (int j = save_w[1]; j <= save_w[2]; ++j)
					printf("(%d, %d)", j, i);
				printf("\n");
				printf("%d��° �� �������� ���ӵ� ������: %d\n", i, save_w[0]);
			}
			if (save_w[0] <= save_b[0] && save_b[0] > 1)
			{
				printf("%d��° ������ �������� ���ӵ� ��ǥ��: ", i);
				for (int j = save_b[1]; j <= save_b[2]; ++j)
					printf("(%d, %d)", j, i);
				printf("\n");
				printf("%d��° ������ �������� ���ӵ� ������: %d\n", i, save_b[0]);
			}
			memset(save_w, NULL, sizeof(save_w));
			memset(save_b, NULL, sizeof(save_b));
			start_w = 0;	start_b = 0;
			finish_w = 0;	finish_b = 0;
		}
		printf("\n");
		//����
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
				printf("%d��° �� �������� ���ӵ� ������: %d\n", j, save_w[0]);
			}
			if (save_w[0] <= save_b[0] && save_b[0] > 1)
			{
				printf("%d��° ������ �������� ���ӵ� ������: %d\n", j, save_b[0]);
			}
			memset(save_w, NULL, sizeof(save_w));
			memset(save_b, NULL, sizeof(save_b));
			start_w = 0;	start_b = 0;
			finish_w = 0;	finish_b = 0;
		}

		printf("\n");
		//��->��
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
				printf("%d��° �� ��->�� �밢���� ���ӵ� ������: %d\n", size - k - 1, save_w[0]);
			}
			if (save_w[0] <= save_b[0] && save_b[0] > 1)
			{
				printf("%d��° ������ ��->�� �밢���� ���ӵ� ������: %d\n", size-k-1, save_b[0]);
			}
			memset(save_w, NULL, sizeof(save_w));
			memset(save_b, NULL, sizeof(save_b));
			start_w = 0;	start_b = 0;
			finish_w = 0;	finish_b = 0;
		}
		printf("\n");
		//��->��
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
				printf("%d��° �� ��->�� �밢���� ���ӵ� ������: %d\n", k, save_w[0]);
			}
			if (save_w[0] <= save_b[0] && save_b[0] > 1)
			{
				printf("%d��° ������ ��->�� �밢���� ���ӵ� ������: %d\n", k, save_b[0]);
			}
			memset(save_w, NULL, sizeof(save_w));
			memset(save_b, NULL, sizeof(save_b));
			start_w = 0;	start_b = 0;
			finish_w = 0;	finish_b = 0;
		}
		printf("\n");
		//��->�� �밢��
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
				printf("%d��° �� ��->�� �밢���� ���ӵ� ������: %d\n", k, save_w[0]);
			}
			if (save_w[0] <= save_b[0] && save_b[0] > 1)
			{
				printf("%d��° ������ ��->�� �밢���� ���ӵ� ������: %d\n", k, save_b[0]);
			}
			memset(save_w, NULL, sizeof(save_w));
			memset(save_b, NULL, sizeof(save_b));
			start_w = 0;	start_b = 0;
			finish_w = 0;	finish_b = 0;
		}
		printf("\n");
		//��->��
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
				printf("%d��° �� ��->�� �밢���� ���ӵ� ������: %d\n", k, save_w[0]);
			}
			if (save_w[0] <= save_b[0] && save_b[0] > 1)
			{
				printf("%d��° ������ ��->�� �밢���� ���ӵ� ������: %d\n", k, save_b[0]);
			}
			memset(save_w, NULL, sizeof(save_w));
			memset(save_b, NULL, sizeof(save_b));
			start_w = 0;	start_b = 0;
			finish_w = 0;	finish_b = 0;
		}
	}
}