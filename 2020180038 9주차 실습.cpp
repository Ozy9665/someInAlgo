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

			case 3:
				printf("★");
				break;

			case 4:
				printf("♣");
				break;
			}
		}
		printf("\n");
	}
}

char Board[line][length] = {};

struct last {
	int x;
	int y;
	int color;
};

struct check
{
	int lc;
	int tc;
	int lrd;
	int rld;
	int c;
};

void savefile(last st[300], int count, int cancel)
{
	FILE* fp = fopen("save.txt", "w+");
	if (fp == NULL)
	{
		printf("파일 열기 실패\n");
		return;
	}
	fprintf(fp, "%d\n", count);
	fprintf(fp, "%d\n", cancel);
	for (int i = 0; i < count + cancel; ++i)
		fprintf(fp, "%d %d %d\n", st[i].x, st[i].y, st[i].color);
	fclose(fp);
}

void openfile(char Board[line][length], last st[300], int* count, int* cancel)
{
	FILE* fp = fopen("save.txt", "r");
	if (fp == NULL)
	{
		printf("파일 열기 실패\n");
		return;
	}
	for (int i = 0; i < line; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			Board[i][j] = 0;
		}
	}
	*count = 0;
	*cancel = 0;
	fscanf(fp, "%d", count);
	fscanf(fp, "%d", cancel);

	for (int i = 0; i < *count + *cancel; ++i)
		fscanf(fp, "%d %d %d", &st[i].x, &st[i].y, &st[i].color);

	for (int i = 0; i < *count; ++i)
		Board[st[i].x][st[i].y] = st[i].color;
	PrintBoard(Board);
	fclose(fp);
}

int main()
{
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

	int state = 0; int wcount = 0; int bcount = 0;
	last st[300]{};	int count = 0; int cancel = 0;
	int savew = 0;	int saveb = 0;	int max = 0; char select;
	check ch[size][size]{};	int space = 0;	int before = 0;	int spc = 0;

	while (true)
	{
		printf("돌 두기: K  무르기: U  무르기 취소하기: R  저장하기: S  불러오기: P\n");
		printf("Input Command: ");
		scanf(" %c", &select);
		switch (select)
		{
		case 'K':
		case 'k':
		{
			cancel = 0;

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
					else if (Board[x][y] == 1 || Board[x][y] == 2 || Board[x][y] == 3)
						printf("이곳에는 이미 돌이 놓여 있습니다. 다시 입력해주세요.");
					else
					{
						Board[x][y] = 1;
						st[count].x = x;
						st[count].y = y;
						st[count].color = 1;
						++count;
						system("cls");
						PrintBoard(Board);
						++turn;
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
					else if (Board[x][y] == 1 || Board[x][y] == 2 || Board[x][y] == 3)
						printf("이곳에는 이미 돌이 놓여 있습니다. 다시 입력해주세요.");
					else
					{
						Board[x][y] = 2;
						st[count].x = x;
						st[count].y = y;
						st[count].color = 2;
						++count;
						system("cls");
						PrintBoard(Board);
						++turn;
						break;
					}
					x = -1;
					y = -1;
				}
			}

			for (int i = 0; i < size; ++i)
			{
				for (int j = 0; j < size; ++j)
				{
					if (Board[i][j] == 3)
						Board[i][j] = ch[i][j].c;
					if (Board[i][j] == 4)
						Board[i][j] = 0;
				}
			}

			system("cls");
			//PrintBoard(Board);

			for (int j = 0; j < line; ++j)
			{
				for (int i = 0; i < length; ++i)
				{
					if (Board[i][j] == 1)
						++whitenum;
					else if (Board[i][j] == 2)
						++blacknum;
				}
			}

			printf("흰돌의 개수는 : %d\n", whitenum);
			printf("검은돌의 개수는 : %d\n\n", blacknum);

			whitenum = 0;
			blacknum = 0;

			for (int j = 0; j < line; ++j)
			{
				for (int i = 0; i < length; ++i)
				{
					if (Board[i][j] == 1)
						++line_w[j];
					else if (Board[i][j] == 2)
						++line_b[j];
					if (i == length - 1)
						printf("%d번째 세로줄의 흰돌개수: %d, 검은돌 개수: %d\n", j, line_w[j], line_b[j]);
				}
			}	//세로줄 개수
			memset(line_w, NULL, sizeof(line_w));
			memset(line_b, NULL, sizeof(line_b));
			printf("\n");

			for (int i = 0; i < length; ++i)
			{
				for (int j = 0; j < line; ++j)
				{
					if (Board[i][j] == 1)
						++length_w[i];
					else if (Board[i][j] == 2)
						++length_b[i];

					if (j == line - 1)
						printf("%d번째 가로줄의 흰돌개수: %d, 검은돌 개수: %d\n", i, length_w[i], length_b[i]);
				}
			}
			memset(length_w, NULL, sizeof(length_w));
			memset(length_b, NULL, sizeof(length_b));

			int max = 0;

			//가로
			for (int i = 0; i < line; ++i)
			{
				for (int j = 0; j < length; ++j)
				{
					if (Board[i][j] == 1)
					{
						spc = 0;
						bcount = 0;
						++wcount;
						ch[i][j].lc = wcount;
						ch[i][j].c = 1;
						if (savew <= wcount)
							savew = wcount;
					}
					else if (Board[i][j] == 2)
					{
						spc = 0;
						wcount = 0;
						++bcount;
						ch[i][j].lc = bcount;
						ch[i][j].c = 2;
						if (saveb <= bcount)
							saveb = bcount;
					}
					else
					{
						++space;	++spc;
						if ((wcount == 0 && bcount == 0) || spc == 2)
						{
							space = 0;	spc = 0;
							wcount = 0; bcount = 0;
						}
						if (space == 1)
						{
							if (wcount > 0)
							{
								before = wcount;
								state = 1;
							}
							if (bcount > 0)
							{
								before = bcount;
								state = 2;
							}
						}
						if (space == 2)
						{
							if (wcount > 0 && state == 1)
							{
								wcount -= before;
								before = wcount;
							}
							if (bcount > 0 && state == 2)
							{
								bcount -= before;
								before = bcount;
							}
							space -= 1;
						}
					}
					if (max <= savew)
						max = savew;
					if (max <= saveb)
						max = saveb;
				}
				savew = 0;	saveb = 0; bcount = 0; wcount = 0;	space = 0;	before = 0;	state = 0;	spc = 0;
			}
			//세로
			for (int j = 0; j < length; ++j)
			{
				for (int i = 0; i < line; ++i)
				{
					if (Board[i][j] == 1)
					{
						spc = 0;
						bcount = 0;
						++wcount;
						ch[i][j].tc = wcount;
						ch[i][j].c = 1;
						if (savew <= wcount)
							savew = wcount;
					}
					else if (Board[i][j] == 2)
					{
						spc = 0;
						wcount = 0;
						++bcount;
						ch[i][j].tc = bcount;
						ch[i][j].c = 2;
						if (saveb <= bcount)
							saveb = bcount;
					}
					else
					{
						++space;	++spc;
						if ((wcount == 0 && bcount == 0) || spc == 2)
						{
							space = 0;	spc = 0;
							wcount = 0; bcount = 0;
						}
						if (space == 1)
						{
							if (wcount > 0)
							{
								before = wcount;
								state = 1;
							}
							if (bcount > 0)
							{
								before = bcount;
								state = 2;
							}
						}
						if (space == 2)
						{
							if (wcount > 0 && state == 1)
							{
								wcount -= before;
								before = wcount;
							}
							if (bcount > 0 && state == 2)
							{
								bcount -= before;
								before = bcount;
							}
							space -= 1;
						}
					}
					if (max <= savew)
						max = savew;
					if (max <= saveb)
						max = saveb;
				}
				savew = 0;	saveb = 0; bcount = 0; wcount = 0;	space = 0;	before = 0;	state = 0;	spc = 0;
			}
			//왼->오 대각선
			for (int k = 0; k < size; ++k)
			{
				int j = 0;
				for (int i = k; i < line; ++i)
				{
					if (Board[i][j] == 1)
					{
						spc = 0;
						bcount = 0;
						++wcount;
						ch[i][j].lrd = wcount;
						ch[i][j].c = 1;
						if (savew <= wcount)
							savew = wcount;
					}
					else if (Board[i][j] == 2)
					{
						spc = 0;
						wcount = 0;
						++bcount;
						ch[i][j].lrd = bcount;
						ch[i][j].c = 2;
						if (saveb <= bcount)
							saveb = bcount;
					}
					else
					{
						++space;	++spc;
						if ((wcount == 0 && bcount == 0) || spc == 2)
						{
							space = 0;	spc = 0;
							wcount = 0; bcount = 0;
						}
						if (space == 1)
						{
							if (wcount > 0)
							{
								before = wcount;
								state = 1;
							}
							if (bcount > 0)
							{
								before = bcount;
								state = 2;
							}
						}
						if (space == 2)
						{
							if (wcount > 0 && state == 1)
							{
								wcount -= before;
								before = wcount;
							}
							if (bcount > 0 && state == 2)
							{
								bcount -= before;
								before = bcount;
							}
							space -= 1;
						}
					}
					if (max <= savew)
						max = savew;
					if (max <= saveb)
						max = saveb;
					++j;
				}
				savew = 0;	saveb = 0; bcount = 0; wcount = 0;	space = 0;	before = 0;	state = 0;	spc = 0;
			}
			//왼->오 대각선
			for (int k = size; k < size * 2; ++k)
			{
				int j = 0;
				for (int i = k - size + 1; i < line; ++i)
				{
					if (Board[j][i] == 1)
					{
						spc = 0;
						bcount = 0;
						++wcount;
						ch[j][i].lrd = wcount;
						ch[j][i].c = 1;
						if (savew <= wcount)
							savew = wcount;
					}
					else if (Board[j][i] == 2)
					{
						spc = 0;
						wcount = 0;
						++bcount;
						ch[j][i].lrd = bcount;
						ch[j][i].c = 2;
						if (saveb <= bcount)
							saveb = bcount;
					}
					else
					{
						++space;	++spc;
						if ((wcount == 0 && bcount == 0) || spc == 2)
						{
							space = 0;	spc = 0;
							wcount = 0; bcount = 0;
						}
						if (space == 1)
						{
							if (wcount > 0)
							{
								before = wcount;
								state = 1;
							}
							if (bcount > 0)
							{
								before = bcount;
								state = 2;
							}
						}
						if (space == 2)
						{
							if (wcount > 0 && state == 1)
							{
								wcount -= before;
								before = wcount;
							}
							if (bcount > 0 && state == 2)
							{
								bcount -= before;
								before = bcount;
							}
							space -= 1;
						}
					}
					if (max <= savew)
						max = savew;
					if (max <= saveb)
						max = saveb;
					++j;
				}
				savew = 0;	saveb = 0; bcount = 0; wcount = 0;	space = 0;	before = 0;	state = 0;	spc = 0;
			}
			//오->왼 대각선
			for (int k = 0; k < size; ++k)
			{
				int i = 0;
				for (int j = k; j >= 0; --j)
				{
					if (Board[i][j] == 1)
					{
						spc = 0;
						bcount = 0;
						++wcount;
						ch[i][j].rld = wcount;
						ch[i][j].c = 1;
						if (savew <= wcount)
							savew = wcount;
					}
					else if (Board[i][j] == 2)
					{
						spc = 0;
						wcount = 0;
						++bcount;
						ch[i][j].rld = bcount;
						ch[i][j].c = 2;
						if (saveb <= bcount)
							saveb = bcount;
					}
					else
					{
						++space;	++spc;
						if ((wcount == 0 && bcount == 0) || spc == 2)
						{
							space = 0;	spc = 0;
							wcount = 0; bcount = 0;
						}
						if (space == 1)
						{
							if (wcount > 0)
							{
								before = wcount;
								state = 1;
							}
							if (bcount > 0)
							{
								before = bcount;
								state = 2;
							}
						}
						if (space == 2)
						{
							if (wcount > 0 && state == 1)
							{
								wcount -= before;
								before = wcount;
							}
							if (bcount > 0 && state == 2)
							{
								bcount -= before;
								before = bcount;
							}
							space -= 1;
						}
					}
					if (max <= savew)
						max = savew;
					if (max <= saveb)
						max = saveb;
					++i;
				}
				savew = 0;	saveb = 0; bcount = 0; wcount = 0;	space = 0;	before = 0;	state = 0;	spc = 0;
			}
			//오->왼 대각선
			for (int k = size; k < size * 2; ++k)
			{
				int j = 18;
				for (int i = k - size + 1; i < line; ++i)
				{
					if (Board[i][j] == 1)
					{
						spc = 0;
						bcount = 0;
						++wcount;
						ch[i][j].rld = wcount;
						ch[i][j].c = 1;
						if (savew <= wcount)
							savew = wcount;
					}
					else if (Board[i][j] == 2)
					{
						spc = 0;
						wcount = 0;
						++bcount;
						ch[i][j].rld = bcount;
						ch[i][j].c = 2;
						if (saveb <= bcount)
							saveb = bcount;
					}
					else
					{
						++space;	++spc;
						if ((wcount == 0 && bcount == 0) || spc == 2)
						{
							space = 0;	spc = 0;
							wcount = 0; bcount = 0;
						}
						if (space == 1)
						{
							if (wcount > 0)
							{
								before = wcount;
								state = 1;
							}
							if (bcount > 0)
							{
								before = bcount;
								state = 2;
							}
						}
						if (space == 2)
						{
							if (wcount > 0 && state == 1)
							{
								wcount -= before;
								before = wcount;
							}
							if (bcount > 0 && state == 2)
							{
								bcount -= before;
								before = bcount;
							}
							space -= 1;
						}
					}
					if (max <= savew)
						max = savew;
					if (max <= saveb)
						max = saveb;
					--j;
				}	
				savew = 0;	saveb = 0; bcount = 0; wcount = 0;	space = 0;	before = 0;	state = 0;	spc = 0;
			}
			printf("최대 연속인 개수는: %d\n", max);
			printf("최대 연속된 좌표는: ");
			for (int i = 0; i < size; ++i)
			{
				for (int j = 0; j < size; ++j)
				{
					if (max == ch[i][j].lc && max > 1)
					{
						printf("\n");
						int sp = 0;
						for (int k = 0; k < max + sp; ++k)
						{
							if (Board[i][j - k] != 0)
							{
								Board[i][j - k] = 3;
								printf("(%d, %d) ", j - k, i);
							}
							else
							{
								sp = 1;
								if (max == 3)
								{
									if (Board[i][j - max - sp] == 0 && Board[i][j + 1] == 0 && j - max - sp >= 0 && j + 1 <= 18)
										Board[i][j - k] = 4;
								}
								if (max == 4)
									Board[i][j - k] = 4;
							}
							if (k == max + sp - 1 && sp == 0 && max == 3)
							{
								if (Board[i][j - max - sp] == 0 && Board[i][j + 1] == 0 && j - max - sp >= 0 && j + 1 <= 18)
								{
									Board[i][j - max - sp] = 4;
									Board[i][j + 1] = 4;
								}
							}
							if (k == max + sp - 1 && sp == 0 && max == 4)
							{
								if (Board[i][j - max - sp] == 0 && i>=0 &&j-max-sp>=0)
									Board[i][j - max - sp] = 4;
								if (Board[i][j + 1] == 0 && i<=18 && j+1 <=18)
									Board[i][j + 1] = 4;
							}
						}
					}
					//가로 연속 좌표

					if (max == ch[i][j].tc && max > 1)
					{
						printf("\n");
						int sp = 0;
						for (int k = 0; k < max + sp; ++k)
						{
							if (Board[i - k][j] != 0)
							{
								Board[i - k][j] = 3;
								printf("(%d, %d) ", j, i - k);
							}
							else
							{
								sp = 1;
								if (max == 3)
								{
									if (Board[i - max - sp][j] == 0 && Board[i + 1][j] == 0 && i - max - sp >= 0 && i + 1 <= 18)
										Board[i - k][j] = 4;
								}
								if (max == 4)
									Board[i - k][j] = 4;
							}
							if (k == max + sp - 1 && sp == 0 && max == 3)
							{
								if (Board[i - max - sp][j] == 0 && Board[i + 1][j] == 0 && i - max - sp >= 0 && i + 1 <= 18)
								{
									Board[i - max - sp][j] = 4;
									Board[i + 1][j] = 4;
								}
							}
							if (k == max + sp - 1 && sp == 0 && max == 4)
							{
								if (Board[i - max - sp][j] == 0 && i-max-sp>=0 && j>=0)
									Board[i - max - sp][j] = 4;
								if (Board[i + 1][j] == 0 && i+1<=18 && j<=18)
									Board[i + 1][j] = 4;
							}
						}
					}
					//세로
					if (max == ch[i][j].lrd && max > 1)
					{
						printf("\n");
						int sp = 0;
						for (int k = 0; k < max + sp; ++k)
						{
							if (Board[i - k][j - k] != 0)
							{
								Board[i - k][j - k] = 3;
								printf("(%d, %d) ", j - k, i - k);
							}
							else
							{
								sp = 1;
								if (max == 3)
								{
									if (Board[i - max - sp][j - max - sp] == 0 && Board[i + 1][j + 1] == 0 && i - max - sp >= 0 && j - max - sp >= 0 && j + 1 <= 18 && i + 1 <= 18)
										Board[i - k][j - k] = 4;
								}
								if (max == 4)
									Board[i - k][j - k] = 4;
							}
							if (k == max + sp - 1 && sp == 0 && max == 3)
							{
								if (Board[i - max - sp][j - max - sp] == 0 && Board[i + 1][j + 1] == 0 && i - max - sp >= 0 && i + 1 <= 18 && j - max - sp >= 0 && j + 1 <= 18)
								{
									Board[i - max - sp][j - max - sp] = 4;
									Board[i + 1][j + 1] = 4;
								}
							}
							if (k == max + sp - 1 && sp == 0 && max == 4)
							{
								if (Board[i - max - sp][j - max - sp] == 0 && i-max-sp>=0&& j-max-sp>=0)
									Board[i - max - sp][j - max - sp] = 4;
								if (Board[i + 1][j + 1] == 0 && i+1 <=18 && j+1<=18)
									Board[i + 1][j + 1] = 4;
							}
						}
					}//왼->오
					if (max == ch[i][j].rld && max > 1)
					{
						printf("\n");
						int sp = 0;
						for (int k = 0; k < max + sp; ++k)
						{
							if (Board[i - k][j + k] != 0)
							{
								Board[i - k][j + k] = 3;
								printf("(%d, %d) ", j + k, i - k);
							}
							else
							{
								sp = 1;
								if (max == 3)
								{
									if (Board[i - max - sp][j + max + sp] == 0 && Board[i + 1][j - 1] == 0 && i - max - sp >= 0 && j + max + sp >= 0 && j - 1 <= 18 && i + 1 <= 18)
										Board[i - k][j + k] = 4;
								}
								if (max == 4)
									Board[i - k][j + k] = 4;
							}
							if (k == max + sp - 1 && sp == 0 && max == 3)
							{
								if (Board[i - max - sp][j + max + sp] == 0 && Board[i + 1][j - 1] == 0 && i - max - sp >= 0 && i + 1 <= 18 && j + max + sp >= 0 && j - 1 <= 18)
								{
									Board[i - max - sp][j + max + sp] = 4;
									Board[i + 1][j - 1] = 4;
								}
							}
							if (k == max + sp - 1 && sp == 0 && max == 4)
							{
								if (Board[i - max - sp][j + max + sp] == 0 && i-max-sp>=0 && j+max+sp>=0)
									Board[i - max - sp][j + max + sp] = 4;
								if (Board[i + 1][j - 1] == 0 && i+1 <=18 && j-1<=18)
									Board[i + 1][j - 1] = 4;
							}
						}
					}//왼->오
				}
			}
			printf("\n");
			PrintBoard(Board);
		}
		break;
		case  'U':
		case 'u':
			if (count > 0)
			{
				Board[st[count - 1].x][st[count - 1].y] = 0;
				--count;
				++cancel;
				++turn;
				system("cls");
				PrintBoard(Board);
			}
			else
				printf("무르기를 할 수 있는 돌이 없습니다.\n");
			break;
		case 'R':
		case 'r':
			if (cancel > 0)
			{
				Board[st[count].x][st[count].y] = st[count].color;
				++count;
				--cancel;
				++turn;
				system("cls");
				PrintBoard(Board);
			}
			else
				printf("무르기를 취소 할 수 있는 돌이 없습니다.\n");
			break;
		case 'S':
		case 's':
			savefile(st, count, cancel);
			break;
		case 'P':
		case 'p':
			openfile(Board, st, &count, &cancel);
			break;
		}
	}
}