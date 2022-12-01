#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define line_2020180038 19
#define length_2020180038 19
#define size_2020180038 19

char Board_2020180038[line_2020180038][length_2020180038] = {};

struct check_2020180038
{
	int lc;
	int tc;
	int lrd;
	int rld;
	int c;
};

struct blackstone_2020180038
{
	int x;
	int y;
};

struct Stone_2020180038
{
	int rank;
	int color;
	blackstone_2020180038 place{};
};

blackstone_2020180038 putblack_2020180038(blackstone_2020180038 stone, Stone_2020180038 rk[size_2020180038][size_2020180038], int bmax, check_2020180038 ch[size_2020180038][size_2020180038], char Board[size_2020180038][size_2020180038]);
blackstone_2020180038 putwhite_2020180038(blackstone_2020180038 stone, Stone_2020180038 rk[size_2020180038][size_2020180038], int wmax, check_2020180038 ch[size_2020180038][size_2020180038], char Board[size_2020180038][size_2020180038]);
void placecheck_2020180038(int x, int y, Stone_2020180038 rk[size_2020180038][size_2020180038]);

void WhiteAttack_2020180038(int* x, int* y);
void WhiteDefence_2020180038(int x, int y);
void BlackAttack_2020180038(int* x, int* y);
void BlackDefence_2020180038(int x, int y);

void BlackAttack_2020180038(int* x, int* y)
{
	srand((unsigned)time(NULL));
	int blacknum = 0; int whitenum = 0;

	int state = 0; int wcount = 0; int bcount = 0;
	int savew = 0;	int saveb = 0;	int max = 0; char select;
	check_2020180038 ch[size_2020180038][size_2020180038]{};	int space = 0;	int before = 0;	int spc = 0;
	int wmax = 0;	int bmax = 0;	Stone_2020180038 rk[size_2020180038][size_2020180038]{};	int mainrank = 1;
	blackstone_2020180038 black{ -1,-1 };	bool check = false;	bool wrankstate = false;		bool brankstate = false;
	mainrank = 1;
	max = 0;
	//°¡·Î
	for (int i = 0; i < line_2020180038; ++i)
	{
		for (int j = 0; j < length_2020180038; ++j)
		{
			if (Board_2020180038[i][j] == 1)
			{
				spc = 0;
				wcount = 0;
				++bcount;
				ch[i][j].lc = bcount;
				ch[i][j].c = 2;
				if (saveb <= bcount)
					saveb = bcount;
			}
			else if (Board_2020180038[i][j] == 2)
			{
				spc = 0;
				bcount = 0;
				++wcount;
				ch[i][j].lc = wcount;
				ch[i][j].c = 1;
				if (savew <= wcount)
					savew = wcount;
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
			if (wmax <= savew)
				wmax = savew;
			if (bmax <= saveb)
				bmax = saveb;
		}
		savew = 0;	saveb = 0; bcount = 0; wcount = 0;	space = 0;	before = 0;	state = 0;	spc = 0;
	}
	//¼¼·Î
	for (int j = 0; j < length_2020180038; ++j)
	{
		for (int i = 0; i < line_2020180038; ++i)
		{
			if (Board_2020180038[i][j] == 1)
			{
				spc = 0;
				wcount = 0;
				++bcount;
				ch[i][j].tc = bcount;
				ch[i][j].c = 2;
				if (saveb <= bcount)
					saveb = bcount;
			}
			else if (Board_2020180038[i][j] == 2)
			{
				spc = 0;
				bcount = 0;
				++wcount;
				ch[i][j].tc = wcount;
				ch[i][j].c = 1;
				if (savew <= wcount)
					savew = wcount;
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
			if (wmax <= savew)
				wmax = savew;
			if (bmax <= saveb)
				bmax = saveb;
		}
		savew = 0;	saveb = 0; bcount = 0; wcount = 0;	space = 0;	before = 0;	state = 0;	spc = 0;
	}
	//¿Þ->¿À ´ë°¢¼±
	for (int k = 0; k < size_2020180038; ++k)
	{
		int j = 0;
		for (int i = k; i < line_2020180038; ++i)
		{
			if (Board_2020180038[i][j] == 1)
			{
				spc = 0;
				wcount = 0;
				++bcount;
				ch[i][j].lrd = bcount;
				ch[i][j].c = 2;
				if (saveb <= bcount)
					saveb = bcount;
			}
			else if (Board_2020180038[i][j] == 2)
			{
				spc = 0;
				bcount = 0;
				++wcount;
				ch[i][j].lrd = wcount;
				ch[i][j].c = 1;
				if (savew <= wcount)
					savew = wcount;
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
			if (wmax <= savew)
				wmax = savew;
			if (bmax <= saveb)
				bmax = saveb;
			++j;
		}
		savew = 0;	saveb = 0; bcount = 0; wcount = 0;	space = 0;	before = 0;	state = 0;	spc = 0;
	}
	//¿Þ->¿À ´ë°¢¼±
	for (int k = size_2020180038; k < size_2020180038 * 2; ++k)
	{
		int j = 0;
		for (int i = k - size_2020180038 + 1; i < line_2020180038; ++i)
		{
			if (Board_2020180038[j][i] == 1)
			{
				spc = 0;
				wcount = 0;
				++bcount;
				ch[j][i].lrd = bcount;
				ch[j][i].c = 2;
				if (saveb <= bcount)
					saveb = bcount;
			}
			else if (Board_2020180038[j][i] == 2)
			{
				spc = 0;
				bcount = 0;
				++wcount;
				ch[j][i].lrd = wcount;
				ch[j][i].c = 1;
				if (savew <= wcount)
					savew = wcount;
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
			if (wmax <= savew)
				wmax = savew;
			if (bmax <= saveb)
				bmax = saveb;
			++j;
		}
		savew = 0;	saveb = 0; bcount = 0; wcount = 0;	space = 0;	before = 0;	state = 0;	spc = 0;
	}
	//¿À->¿Þ ´ë°¢¼±
	for (int k = 0; k < size_2020180038; ++k)
	{
		int i = 0;
		for (int j = k; j >= 0; --j)
		{
			if (Board_2020180038[i][j] == 1)
			{
				spc = 0;
				wcount = 0;
				++bcount;
				ch[i][j].rld = bcount;
				ch[i][j].c = 2;
				if (saveb <= bcount)
					saveb = bcount;
			}
			else if (Board_2020180038[i][j] == 2)
			{
				spc = 0;
				bcount = 0;
				++wcount;
				ch[i][j].rld = wcount;
				ch[i][j].c = 1;
				if (savew <= wcount)
					savew = wcount;
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
			if (wmax <= savew)
				wmax = savew;
			if (bmax <= saveb)
				bmax = saveb;
			++i;
		}
		savew = 0;	saveb = 0; bcount = 0; wcount = 0;	space = 0;	before = 0;	state = 0;	spc = 0;
	}
	//¿À->¿Þ ´ë°¢¼±
	for (int k = size_2020180038; k < size_2020180038 * 2; ++k)
	{
		int j = 18;
		for (int i = k - size_2020180038 + 1; i < line_2020180038; ++i)
		{
			if (Board_2020180038[i][j] == 1)
			{
				spc = 0;
				wcount = 0;
				++bcount;
				ch[i][j].rld = bcount;
				ch[i][j].c = 2;
				if (saveb <= bcount)
					saveb = bcount;
			}
			else if (Board_2020180038[i][j] == 2)
			{
				spc = 0;
				bcount = 0;
				++wcount;
				ch[i][j].rld = wcount;
				ch[i][j].c = 1;
				if (savew <= wcount)
					savew = wcount;
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
			if (wmax <= savew)
				wmax = savew;
			if (bmax <= saveb)
				bmax = saveb;
			--j;
		}
		savew = 0;	saveb = 0; bcount = 0; wcount = 0;	space = 0;	before = 0;	state = 0;	spc = 0;
	}
BACK:
	for (int i = 0; i < size_2020180038; ++i)
	{
		for (int j = 0; j < size_2020180038; ++j)
		{
			if (wmax == ch[i][j].lc && wmax > 1 && ch[i][j].c == 1)
			{
				int sp = 0;
				for (int k = 0; k < wmax + sp; ++k)
				{
					if (Board_2020180038[i][j - k] == 0)
					{
						sp = 1;
						if (wmax == 3)
						{
							if (Board_2020180038[i][j - wmax - sp] == 0 && Board_2020180038[i][j + 1] == 0 && j - wmax - sp >= 0 && j + 1 <= 18)
							{
								rk[i][j - k].rank = 3;
								placecheck_2020180038(i, j - k, rk);
								rk[i][j - k].color = 1;
								rk[i][j - wmax - sp].rank = 3;
								placecheck_2020180038(i, j - wmax - sp, rk);
								rk[i][j - wmax - sp].color = 1;
								rk[i][j + 1].rank = 3;
								placecheck_2020180038(i, j + 1, rk);
								rk[i][j + 1].color = 1;
							}
						}
						if (wmax == 4)
						{
							rk[i][j - k].rank = 1;
							placecheck_2020180038(i, j - k, rk);
							rk[i][j - k].color = 1;
							//--wmaxcount;
							wrankstate = true;
						}
					}
					if (k == wmax + sp - 1 && sp == 0 && wmax == 3)
					{
						if (Board_2020180038[i][j - wmax - sp] == 0 && Board_2020180038[i][j + 1] == 0 && j - wmax - sp >= 0 && j + 1 <= 18)
						{
							rk[i][j - wmax - sp].rank = 3;
							placecheck_2020180038(i, j - wmax - sp, rk);
							rk[i][j - wmax - sp].color = 1;
							rk[i][j + 1].rank = 3;
							placecheck_2020180038(i, j + 1, rk);
							rk[i][j + 1].color = 1;
						}
					}
					if (k == wmax + sp - 1 && sp == 0 && wmax == 4)
					{
						if (Board_2020180038[i][j - wmax - sp] == 0 && i >= 0 && j - wmax - sp >= 0)
						{
							rk[i][j - wmax - sp].rank = 2;
							placecheck_2020180038(i, j - wmax - sp, rk);
							rk[i][j - wmax - sp].color = 1;
							wrankstate = true;
						}
						if (Board_2020180038[i][j + 1] == 0 && i <= 18 && j + 1 <= 18)
						{
							rk[i][j + 1].rank = 2;
							placecheck_2020180038(i, j + 1, rk);
							rk[i][j + 1].color = 1;
							wrankstate = true;
						}
					}
				}
			}

			if (bmax == ch[i][j].lc && bmax > 1 && ch[i][j].c == 2)
			{
				int sp = 0;
				for (int k = 0; k < bmax + sp; ++k)
				{
					if (Board_2020180038[i][j - k] == 0)
					{
						sp = 1;
						if (bmax == 3)
						{
							if (Board_2020180038[i][j - bmax - sp] == 0 && Board_2020180038[i][j + 1] == 0 && j - bmax - sp >= 0 && j + 1 <= 18)
							{
								rk[i][j - k].rank = 3;
								placecheck_2020180038(i, j - k, rk);
								rk[i][j - k].color = 2;
								rk[i][j - bmax - sp].rank = 3;
								placecheck_2020180038(i, j - bmax - sp, rk);
								rk[i][j - bmax - sp].color = 2;
								rk[i][j + 1].rank = 3;
								placecheck_2020180038(i, j + 1, rk);
								rk[i][j + 1].color = 2;
							}
						}
						if (bmax == 4)
						{
							rk[i][j - k].rank = 1;
							placecheck_2020180038(i, j - k, rk);
							rk[i][j - k].color = 2;
							//--bmaxcount;
							brankstate = true;
						}
					}
					if (k == bmax + sp - 1 && sp == 0 && bmax == 3)
					{
						if (Board_2020180038[i][j - bmax - sp] == 0 && Board_2020180038[i][j + 1] == 0 && j - bmax - sp >= 0 && j + 1 <= 18)
						{
							rk[i][j - bmax - sp].rank = 3;
							placecheck_2020180038(i, j - bmax - sp, rk);
							rk[i][j - bmax - sp].color = 2;
							rk[i][j + 1].rank = 3;
							placecheck_2020180038(i, j + 1, rk);
							rk[i][j + 1].color = 2;
						}
					}
					if (k == bmax + sp - 1 && sp == 0 && bmax == 4)
					{
						if (Board_2020180038[i][j - bmax - sp] == 0 && i >= 0 && j - bmax - sp >= 0)
						{
							rk[i][j - bmax - sp].rank = 2;
							placecheck_2020180038(i, j - bmax - sp, rk);
							rk[i][j - bmax - sp].color = 2;
							brankstate = true;
						}
						if (Board_2020180038[i][j + 1] == 0 && i <= 18 && j + 1 <= 18)
						{
							rk[i][j + 1].rank = 2;
							placecheck_2020180038(i, j + 1, rk);
							rk[i][j + 1].color = 2;
							brankstate = true;
						}
					}
				}
			}
			//°¡·Î ¿¬¼Ó ÁÂÇ¥
			if (wmax == ch[i][j].tc && wmax > 1 && ch[i][j].c == 1)
			{
				int sp = 0;
				for (int k = 0; k < wmax + sp; ++k)
				{
					if (Board_2020180038[i - k][j] == 0)
					{
						sp = 1;
						if (wmax == 3)
						{
							if (Board_2020180038[i - wmax - sp][j] == 0 && Board_2020180038[i + 1][j] == 0 && i - wmax - sp >= 0 && i + 1 <= 18)
							{
								rk[i - k][j].rank = 3;
								placecheck_2020180038(i - k, j, rk);
								rk[i - k][j].color = 1;
								rk[i - wmax - sp][j].rank = 3;
								placecheck_2020180038(i - wmax - sp, j, rk);
								rk[i - wmax - sp][j].color = 1;
								rk[i + 1][j].rank = 3;
								placecheck_2020180038(i + 1, j, rk);
								rk[i + 1][j].color = 1;
							}
						}
						if (wmax == 4)
						{
							rk[i - k][j].rank = 1;
							placecheck_2020180038(i - k, j, rk);
							rk[i - k][j].color = 1;
							wrankstate = true;
							//--wmaxcount;
						}
					}
					if (k == wmax + sp - 1 && sp == 0 && wmax == 3)
					{
						if (Board_2020180038[i - wmax - sp][j] == 0 && Board_2020180038[i + 1][j] == 0 && i - wmax - sp >= 0 && i + 1 <= 18)
						{
							rk[i - wmax - sp][j].rank = 3;
							placecheck_2020180038(i - wmax - sp, j, rk);
							rk[i - wmax - sp][j].color = 1;
							rk[i + 1][j].rank = 3;
							placecheck_2020180038(i + 1, j, rk);
							rk[i + 1][j].color = 1;
						}
					}
					if (k == wmax + sp - 1 && sp == 0 && wmax == 4)
					{
						if (Board_2020180038[i - wmax - sp][j] == 0 && i - wmax - sp >= 0 && j >= 0)
						{
							rk[i - wmax - sp][j].rank = 2;
							placecheck_2020180038(i - wmax - sp, j, rk);
							rk[i - wmax - sp][j].color = 1;
							wrankstate = true;
						}
						if (Board_2020180038[i + 1][j] == 0 && i + 1 <= 18 && j <= 18)
						{
							rk[i + 1][j].rank = 2;
							placecheck_2020180038(i + 1, j, rk);
							rk[i + 1][j].color = 1;
							wrankstate = true;
						}
					}
				}
			}
			if (bmax == ch[i][j].tc && bmax > 1 && ch[i][j].c == 2)
			{
				int sp = 0;
				for (int k = 0; k < bmax + sp; ++k)
				{
					if (Board_2020180038[i - k][j] == 0)
					{
						sp = 1;
						if (bmax == 3)
						{
							if (Board_2020180038[i - bmax - sp][j] == 0 && Board_2020180038[i + 1][j] == 0 && i - bmax - sp >= 0 && i + 1 <= 18)
							{
								rk[i - k][j].rank = 3;
								placecheck_2020180038(i - k, j, rk);
								rk[i - k][j].color = 2;
								rk[i - bmax - sp][j].rank = 3;
								placecheck_2020180038(i - bmax - sp, j, rk);
								rk[i - bmax - sp][j].color = 2;
								rk[i + 1][j].rank = 3;
								placecheck_2020180038(i + 1, j, rk);
								rk[i + 1][j].color = 2;
							}
						}
						if (bmax == 4)
						{
							rk[i - k][j].rank = 1;
							placecheck_2020180038(i - k, j, rk);
							rk[i - k][j].color = 2;
							brankstate = true;
							//--bmaxcount;
						}
					}
					if (k == bmax + sp - 1 && sp == 0 && bmax == 3)
					{
						if (Board_2020180038[i - bmax - sp][j] == 0 && Board_2020180038[i + 1][j] == 0 && i - bmax - sp >= 0 && i + 1 <= 18)
						{
							rk[i - bmax - sp][j].rank = 3;
							placecheck_2020180038(i - bmax - sp, j, rk);
							rk[i - bmax - sp][j].color = 2;
							rk[i + 1][j].rank = 3;
							placecheck_2020180038(i + 1, j, rk);
							rk[i + 1][j].color = 2;
						}
					}
					if (k == bmax + sp - 1 && sp == 0 && bmax == 4)
					{
						if (Board_2020180038[i - bmax - sp][j] == 0 && i - bmax - sp >= 0 && j >= 0)
						{
							rk[i - bmax - sp][j].rank = 2;
							placecheck_2020180038(i - bmax - sp, j, rk);
							rk[i - bmax - sp][j].color = 2;
							brankstate = true;
						}
						if (Board_2020180038[i + 1][j] == 0 && i + 1 <= 18 && j <= 18)
						{
							rk[i + 1][j].rank = 2;
							placecheck_2020180038(i + 1, j, rk);
							rk[i + 1][j].color = 2;
							brankstate = true;
						}
					}
				}
			}
			//¼¼·Î
			if (wmax == ch[i][j].lrd && wmax > 1 && ch[i][j].c == 1)
			{
				int sp = 0;
				for (int k = 0; k < wmax + sp; ++k)
				{
					if (Board_2020180038[i - k][j - k] == 0)
					{
						sp = 1;
						if (wmax == 3)
						{
							if (Board_2020180038[i - wmax - sp][j - wmax - sp] == 0 && Board_2020180038[i + 1][j + 1] == 0 && i - wmax - sp >= 0 && j - wmax - sp >= 0 && j + 1 <= 18 && i + 1 <= 18)
							{
								rk[i - k][j - k].rank = 3;
								placecheck_2020180038(i - k, j - k, rk);
								rk[i - k][j - k].color = 1;
								rk[i - wmax - sp][j - wmax - sp].rank = 3;
								placecheck_2020180038(i - wmax - sp, j - wmax - sp, rk);
								rk[i - wmax - sp][j - wmax - sp].color = 1;
								rk[i + 1][j + 1].rank = 3;
								placecheck_2020180038(i + 1, j + 1, rk);
								rk[i + 1][j + 1].color = 1;
							}
						}
						if (wmax == 4)
						{
							rk[i - k][j - k].rank = 1;
							placecheck_2020180038(i - k, j - k, rk);
							rk[i - k][j - k].color = 1;
							wrankstate = true;
							//--wmaxcount;
						}
					}
					if (k == wmax + sp - 1 && sp == 0 && wmax == 3)
					{
						if (Board_2020180038[i - wmax - sp][j - wmax - sp] == 0 && Board_2020180038[i + 1][j + 1] == 0 && i - wmax - sp >= 0 && i + 1 <= 18 && j - wmax - sp >= 0 && j + 1 <= 18)
						{
							rk[i - wmax - sp][j - wmax - sp].rank = 3;
							placecheck_2020180038(i - wmax - sp, j - wmax - sp, rk);
							rk[i - wmax - sp][j - wmax - sp].color = 1;
							rk[i + 1][j + 1].rank = 3;
							placecheck_2020180038(i + 1, j + 1, rk);
							rk[i + 1][j + 1].color = 1;
						}
					}
					if (k == wmax + sp - 1 && sp == 0 && wmax == 4)
					{
						if (Board_2020180038[i - wmax - sp][j - wmax - sp] == 0 && i - wmax - sp >= 0 && j - wmax - sp >= 0)
						{
							rk[i - wmax - sp][j - wmax - sp].rank = 2;
							placecheck_2020180038(i - wmax - sp, j - wmax - sp, rk);
							rk[i - wmax - sp][j - wmax - sp].color = 1;
							wrankstate = true;
						}
						if (Board_2020180038[i + 1][j + 1] == 0 && i + 1 <= 18 && j + 1 <= 18)
						{
							rk[i + 1][j + 1].rank = 2;
							placecheck_2020180038(i + 1, j + 1, rk);
							rk[i + 1][j + 1].color = 1;
							wrankstate = true;
						}
					}
				}
			}//¿Þ->¿À
			if (bmax == ch[i][j].lrd && bmax > 1 && ch[i][j].c == 2)
			{
				int sp = 0;
				for (int k = 0; k < bmax + sp; ++k)
				{
					if (Board_2020180038[i - k][j - k] == 0)
					{
						sp = 1;
						if (bmax == 3)
						{
							if (Board_2020180038[i - bmax - sp][j - bmax - sp] == 0 && Board_2020180038[i + 1][j + 1] == 0 && i - bmax - sp >= 0 && j - bmax - sp >= 0 && j + 1 <= 18 && i + 1 <= 18)
							{
								rk[i - k][j - k].rank = 3;
								placecheck_2020180038(i - k, j - k, rk);
								rk[i - k][j - k].color = 2;
								rk[i - bmax - sp][j - bmax - sp].rank = 3;
								placecheck_2020180038(i - bmax - sp, j - bmax - sp, rk);
								rk[i - bmax - sp][j - bmax - sp].color = 2;
								rk[i + 1][j + 1].rank = 3;
								placecheck_2020180038(i + 1, j + 1, rk);
								rk[i + 1][j + 1].color = 2;
							}
						}
						if (bmax == 4)
						{
							rk[i - k][j - k].rank = 1;
							placecheck_2020180038(i - k, j - k, rk);
							rk[i - k][j - k].color = 2;
							//--bmaxcount;
						}
					}
					if (k == bmax + sp - 1 && sp == 0 && bmax == 3)
					{
						if (Board_2020180038[i - bmax - sp][j - bmax - sp] == 0 && Board_2020180038[i + 1][j + 1] == 0 && i - bmax - sp >= 0 && i + 1 <= 18 && j - bmax - sp >= 0 && j + 1 <= 18)
						{
							rk[i - bmax - sp][j - bmax - sp].rank = 3;
							placecheck_2020180038(i - bmax - sp, j - bmax - sp, rk);
							rk[i - bmax - sp][j - bmax - sp].color = 2;
							rk[i + 1][j + 1].rank = 3;
							placecheck_2020180038(i + 1, j + 1, rk);
							rk[i + 1][j + 1].color = 2;
						}
					}
					if (k == bmax + sp - 1 && sp == 0 && bmax == 4)
					{
						if (Board_2020180038[i - bmax - sp][j - bmax - sp] == 0 && i - bmax - sp >= 0 && j - bmax - sp >= 0)
						{
							rk[i - bmax - sp][j - bmax - sp].rank = 2;
							placecheck_2020180038(i - bmax - sp, j - bmax - sp, rk);
							rk[i - bmax - sp][j - bmax - sp].color = 2;
							brankstate = true;
						}
						if (Board_2020180038[i + 1][j + 1] == 0 && i + 1 <= 18 && j + 1 <= 18)
						{
							rk[i + 1][j + 1].rank = 2;
							placecheck_2020180038(i + 1, j + 1, rk);
							rk[i + 1][j + 1].color = 2;
							brankstate = true;
						}
					}
				}
			}//¿Þ->¿À
			if (wmax == ch[i][j].rld && wmax > 1 && ch[i][j].c == 1)
			{
				int sp = 0;
				for (int k = 0; k < wmax + sp; ++k)
				{
					if (Board_2020180038[i - k][j + k] == 0)
					{
						sp = 1;
						if (wmax == 3)
						{
							if (Board_2020180038[i - wmax - sp][j + wmax + sp] == 0 && Board_2020180038[i + 1][j - 1] == 0 && i - wmax - sp >= 0 && j + wmax + sp >= 0 && j - 1 <= 18 && i + 1 <= 18)
							{
								rk[i - k][j + k].rank = 3;
								placecheck_2020180038(i - k, j + k, rk);
								rk[i - k][j + k].color = 1;
								rk[i - wmax - sp][j + wmax + sp].rank = 3;
								placecheck_2020180038(i - wmax - sp, j + wmax + sp, rk);
								rk[i - wmax - sp][j + wmax + sp].color = 1;
								rk[i + 1][j - 1].rank = 3;
								placecheck_2020180038(i + 1, j - 1, rk);
								rk[i + 1][j - 1].color = 1;
							}
						}
						if (wmax == 4)
						{
							rk[i - k][j + k].rank = 1;
							placecheck_2020180038(i - k, j + k, rk);
							rk[i - k][j + k].color = 1;
							wrankstate = true;
							//--wmaxcount;
						}
					}
					if (k == wmax + sp - 1 && sp == 0 && wmax == 3)
					{
						if (Board_2020180038[i - wmax - sp][j + wmax + sp] == 0 && Board_2020180038[i + 1][j - 1] == 0 && i - wmax - sp >= 0 && i + 1 <= 18 && j + wmax + sp <= 18 && j - 1 <= 18)
						{
							rk[i - wmax - sp][j + wmax + sp].rank = 3;
							placecheck_2020180038(i - wmax - sp, j + wmax + sp, rk);
							rk[i - wmax - sp][j + wmax + sp].color = 1;
							rk[i + 1][j - 1].rank = 3;
							placecheck_2020180038(i + 1, j - 1, rk);
							rk[i + 1][j - 1].color = 1;
						}
					}
					if (k == wmax + sp - 1 && sp == 0 && wmax == 4)
					{
						if (Board_2020180038[i - wmax - sp][j + wmax + sp] == 0 && i - wmax - sp >= 0 && j + wmax + sp <= 18)
						{
							rk[i - wmax - sp][j + wmax + sp].rank = 2;
							placecheck_2020180038(i - wmax - sp, j + wmax + sp, rk);
							rk[i - wmax - sp][j + wmax + sp].color = 1;
							wrankstate = true;
						}
						if (Board_2020180038[i + 1][j - 1] == 0 && i + 1 <= 18 && j - 1 <= 18)
						{
							rk[i + 1][j - 1].rank = 2;
							placecheck_2020180038(i + 1, j - 1, rk);
							rk[i + 1][j - 1].color = 1;
							wrankstate = true;
						}
					}
				}
			}//¿Þ->¿À
			if (bmax == ch[i][j].rld && bmax > 1 && ch[i][j].c == 2)
			{
				int sp = 0;
				for (int k = 0; k < bmax + sp; ++k)
				{
					if (Board_2020180038[i - k][j + k] == 0)
					{
						sp = 1;
						if (bmax == 3)
						{
							if (Board_2020180038[i - bmax - sp][j + bmax + sp] == 0 && Board_2020180038[i + 1][j - 1] == 0 && i - bmax - sp >= 0 && j + bmax + sp >= 0 && j - 1 <= 18 && i + 1 <= 18)
							{
								rk[i - k][j + k].rank = 3;
								placecheck_2020180038(i - k, j + k, rk);
								rk[i - k][j + k].color = 2;
								rk[i - bmax - sp][j + bmax + sp].rank = 3;
								placecheck_2020180038(i - bmax - sp, j + bmax + sp, rk);
								rk[i - bmax - sp][j + bmax + sp].color = 2;
								rk[i + 1][j - 1].rank = 3;
								placecheck_2020180038(i + 1, j - 1, rk);
								rk[i + 1][j - 1].color = 2;
							}
						}
						if (bmax == 4)
						{
							rk[i - k][j + k].rank = 1;
							placecheck_2020180038(i - k, j + k, rk);
							rk[i - k][j + k].color = 2;
							brankstate = true;
						}
					}
					if (k == bmax + sp - 1 && sp == 0 && bmax == 3)
					{
						if (Board_2020180038[i - bmax - sp][j + bmax + sp] == 0 && Board_2020180038[i + 1][j - 1] == 0 && i - bmax - sp >= 0 && i + 1 <= 18 && j + bmax + sp <= 18 && j - 1 <= 18)
						{
							rk[i - bmax - sp][j + bmax + sp].rank = 3;
							placecheck_2020180038(i - bmax - sp, j + bmax + sp, rk);
							rk[i - bmax - sp][j + bmax + sp].color = 2;
							rk[i + 1][j - 1].rank = 3;
							placecheck_2020180038(i + 1, j - 1, rk);
							rk[i + 1][j - 1].color = 2;
						}
					}
					if (k == bmax + sp - 1 && sp == 0 && bmax == 4)
					{
						if (Board_2020180038[i - bmax - sp][j + bmax + sp] == 0 && i - bmax - sp >= 0 && j + bmax + sp <= 18)
						{
							rk[i - bmax - sp][j + bmax + sp].rank = 2;
							placecheck_2020180038(i - bmax - sp, j + bmax + sp, rk);
							rk[i - bmax - sp][j + bmax + sp].color = 2;
							brankstate = true;
						}
						if (Board_2020180038[i + 1][j - 1] == 0 && i + 1 <= 18 && j - 1 <= 18)
						{
							rk[i + 1][j - 1].rank = 2;
							placecheck_2020180038(i + 1, j - 1, rk);
							rk[i + 1][j - 1].color = 2;
							brankstate = true;
						}
					}
				}
			}//¿Þ->¿À
		}
	}

	if (wmax == 4 &&wrankstate == false)
	{
		wmax = 3;
		goto BACK;
	}
	if (bmax == 4 && brankstate == false)
	{
		bmax = 3;
		goto BACK;
	}

	while (true)
	{
		black = putblack_2020180038(black, rk, bmax, ch, Board_2020180038);
		if (black.x < 0 || black.y < 0 || black.x>18 || black.y>18)
		{
			continue;
		}
		else if (Board_2020180038[black.x][black.y] == 1 || Board_2020180038[black.x][black.y] == 2 || Board_2020180038[black.x][black.y] == 3)
		{
			continue;
		}
		else
		{
			*y = black.x;
			*x = black.y;
			Board_2020180038[black.x][black.y] = 1;
			break;
		}
	}
}

void BlackDefence_2020180038(int x, int y)
{
	Board_2020180038[y][x] = 2;
}

blackstone_2020180038 putblack_2020180038(blackstone_2020180038 stone, Stone_2020180038 rk[size_2020180038][size_2020180038], int bmax, check_2020180038 ch[size_2020180038][size_2020180038], char Board[size_2020180038][size_2020180038])
{
	int putrank = 1;
	while (putrank != 4)
	{
		for (int i = 0; i < size_2020180038; ++i)
		{
			for (int j = 0; j < size_2020180038; ++j)
			{
				if (rk[i][j].rank == putrank && rk[i][j].color == 1)
				{
					stone.x = i;
					stone.y = j;
					if (Board[i][j] == 0)
						return stone;
				}
			}
		}
		++putrank;
	}

	putrank = 1;
	while (putrank != 4)
	{
		for (int i = 0; i < size_2020180038; ++i)
		{
			for (int j = 0; j < size_2020180038; ++j)
			{
				if (rk[i][j].rank == putrank && rk[i][j].color == 2)
				{
					stone.x = i;
					stone.y = j;
					if (Board[i][j] == 0)
						return stone;
				}
			}
		}
		++putrank;
	}

	while (bmax != 0)
	{
		for (int i = 0; i < size_2020180038; ++i)
		{
			for (int j = 0; j < size_2020180038; ++j)
			{
				//if (bmax == ch[i][j].lrd && ch[i][j].c == 2)
				//{
				//	stone.x = i + 1;
				//	stone.y = j + 1;
				//	if (Board[i + 1][j + 1] == 0 && i + 1 <= 18 && j + 1 <= 18)
				//		return stone;
				//	stone.x = i - bmax;
				//	stone.y = j - bmax;
				//	if (Board[i - bmax][j - bmax] == 0 && i - bmax >= 0 && j - bmax >= 0)
				//		return stone;
				//}
				if (bmax == ch[i][j].lc && ch[i][j].c == 2)
				{
					stone.x = i;
					stone.y = j + 1;
					if (Board[i][j + 1] == 0 && j + 1 <= 18)
						return stone;
					stone.x = i;
					stone.y = j - bmax;
					if (Board[i][j - bmax] == 0 && j - bmax >= 0)
						return stone;
				}
				/*	if (bmax == ch[i][j].rld && ch[i][j].c == 2)
					{
						stone.x = i + 1;
						stone.y = j - 1;
						if (Board[i + 1][j - 1] == 0 && i + 1 <= 18 && j - 1 >= 0)
							return stone;
						stone.x = i - bmax;
						stone.y = j + bmax;
						if (Board[i - bmax][j + bmax] == 0 && i - bmax >= 0 && j + bmax <= 18)
							return stone;
					}
					if (bmax == ch[i][j].tc && ch[i][j].c == 2)
					{
						stone.x = i + 1;
						stone.y = j;
						if (Board[i + 1][j] == 0 && i + 1 <= 18)
							return stone;
						stone.x = i - bmax;
						stone.y = j;
						if (Board[i - bmax][j] == 0 && i - bmax >= 0)
							return stone;
					}*/
			}
		}
		--bmax;
	}
	stone.x = rand() % size_2020180038;
	stone.y = rand() % size_2020180038;

	return stone;
}

void placecheck_2020180038(int x, int y, Stone_2020180038 rk[size_2020180038][size_2020180038])
{
	rk[x][y].place.x = x;
	rk[x][y].place.y = y;
}

void WhiteAttack_2020180038(int* x, int* y)
{
	srand((unsigned)time(NULL));
	int blacknum = 0; int whitenum = 0;

	int state = 0; int wcount = 0; int bcount = 0;
	int savew = 0;	int saveb = 0;	int max = 0; char select;
	check_2020180038 ch[size_2020180038][size_2020180038]{};	int space = 0;	int before = 0;	int spc = 0;
	int wmax = 0;	int bmax = 0;	Stone_2020180038 rk[size_2020180038][size_2020180038]{};	int mainrank = 1;
	blackstone_2020180038 black{ -1,-1 };	bool check = false;
	mainrank = 1;	bool wrankstate = false;	bool brankstate = false;
	max = 0;	
	//°¡·Î
	for (int i = 0; i < line_2020180038; ++i)
	{
		for (int j = 0; j < length_2020180038; ++j)
		{
			if (Board_2020180038[i][j] == 1)
			{
				spc = 0;
				wcount = 0;
				++bcount;
				ch[i][j].lc = bcount;
				ch[i][j].c = 2;
				if (saveb <= bcount)
					saveb = bcount;
			}
			else if (Board_2020180038[i][j] == 2)
			{
				spc = 0;
				bcount = 0;
				++wcount;
				ch[i][j].lc = wcount;
				ch[i][j].c = 1;
				if (savew <= wcount)
					savew = wcount;
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
			if (wmax <= savew)
				wmax = savew;
			if (bmax <= saveb)
				bmax = saveb;
		}
		savew = 0;	saveb = 0; bcount = 0; wcount = 0;	space = 0;	before = 0;	state = 0;	spc = 0;
	}
	//¼¼·Î
	for (int j = 0; j < length_2020180038; ++j)
	{
		for (int i = 0; i < line_2020180038; ++i)
		{
			if (Board_2020180038[i][j] == 1)
			{
				spc = 0;
				wcount = 0;
				++bcount;
				ch[i][j].tc = bcount;
				ch[i][j].c = 2;
				if (saveb <= bcount)
					saveb = bcount;
			}
			else if (Board_2020180038[i][j] == 2)
			{
				spc = 0;
				bcount = 0;
				++wcount;
				ch[i][j].tc = wcount;
				ch[i][j].c = 1;
				if (savew <= wcount)
					savew = wcount;
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
			if (wmax <= savew)
				wmax = savew;
			if (bmax <= saveb)
				bmax = saveb;
		}
		savew = 0;	saveb = 0; bcount = 0; wcount = 0;	space = 0;	before = 0;	state = 0;	spc = 0;
	}
	//¿Þ->¿À ´ë°¢¼±
	for (int k = 0; k < size_2020180038; ++k)
	{
		int j = 0;
		for (int i = k; i < line_2020180038; ++i)
		{
			if (Board_2020180038[i][j] == 1)
			{
				spc = 0;
				wcount = 0;
				++bcount;
				ch[i][j].lrd = bcount;
				ch[i][j].c = 2;
				if (saveb <= bcount)
					saveb = bcount;
			}
			else if (Board_2020180038[i][j] == 2)
			{
				spc = 0;
				bcount = 0;
				++wcount;
				ch[i][j].lrd = wcount;
				ch[i][j].c = 1;
				if (savew <= wcount)
					savew = wcount;
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
			if (wmax <= savew)
				wmax = savew;
			if (bmax <= saveb)
				bmax = saveb;
			++j;
		}
		savew = 0;	saveb = 0; bcount = 0; wcount = 0;	space = 0;	before = 0;	state = 0;	spc = 0;
	}
	//¿Þ->¿À ´ë°¢¼±
	for (int k = size_2020180038; k < size_2020180038 * 2; ++k)
	{
		int j = 0;
		for (int i = k - size_2020180038 + 1; i < line_2020180038; ++i)
		{
			if (Board_2020180038[j][i] == 1)
			{
				spc = 0;
				wcount = 0;
				++bcount;
				ch[j][i].lrd = bcount;
				ch[j][i].c = 2;
				if (saveb <= bcount)
					saveb = bcount;
			}
			else if (Board_2020180038[j][i] == 2)
			{
				spc = 0;
				bcount = 0;
				++wcount;
				ch[j][i].lrd = wcount;
				ch[j][i].c = 1;
				if (savew <= wcount)
					savew = wcount;
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
			if (wmax <= savew)
				wmax = savew;
			if (bmax <= saveb)
				bmax = saveb;
			++j;
		}
		savew = 0;	saveb = 0; bcount = 0; wcount = 0;	space = 0;	before = 0;	state = 0;	spc = 0;
	}
	//¿À->¿Þ ´ë°¢¼±
	for (int k = 0; k < size_2020180038; ++k)
	{
		int i = 0;
		for (int j = k; j >= 0; --j)
		{
			if (Board_2020180038[i][j] == 1)
			{
				spc = 0;
				wcount = 0;
				++bcount;
				ch[i][j].rld = bcount;
				ch[i][j].c = 2;
				if (saveb <= bcount)
					saveb = bcount;
			}
			else if (Board_2020180038[i][j] == 2)
			{
				spc = 0;
				bcount = 0;
				++wcount;
				ch[i][j].rld = wcount;
				ch[i][j].c = 1;
				if (savew <= wcount)
					savew = wcount;
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
			if (wmax <= savew)
				wmax = savew;
			if (bmax <= saveb)
				bmax = saveb;
			++i;
		}
		savew = 0;	saveb = 0; bcount = 0; wcount = 0;	space = 0;	before = 0;	state = 0;	spc = 0;
	}
	//¿À->¿Þ ´ë°¢¼±
	for (int k = size_2020180038; k < size_2020180038 * 2; ++k)
	{
		int j = 18;
		for (int i = k - size_2020180038 + 1; i < line_2020180038; ++i)
		{
			if (Board_2020180038[i][j] == 1)
			{
				spc = 0;
				wcount = 0;
				++bcount;
				ch[i][j].rld = bcount;
				ch[i][j].c = 2;
				if (saveb <= bcount)
					saveb = bcount;
			}
			else if (Board_2020180038[i][j] == 2)
			{
				spc = 0;
				bcount = 0;
				++wcount;
				ch[i][j].rld = wcount;
				ch[i][j].c = 1;
				if (savew <= wcount)
					savew = wcount;
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
			if (wmax <= savew)
				wmax = savew;
			if (bmax <= saveb)
				bmax = saveb;
			--j;
		}
		savew = 0;	saveb = 0; bcount = 0; wcount = 0;	space = 0;	before = 0;	state = 0;	spc = 0;
	}
BACK:
	for (int i = 0; i < size_2020180038; ++i)
	{
		for (int j = 0; j < size_2020180038; ++j)
		{
			if (wmax == ch[i][j].lc && wmax > 1 && ch[i][j].c == 1)
			{
				int sp = 0;
				for (int k = 0; k < wmax + sp; ++k)
				{
					if (Board_2020180038[i][j - k] == 0)
					{
						sp = 1;
						if (wmax == 3)
						{
							if (Board_2020180038[i][j - wmax - sp] == 0 && Board_2020180038[i][j + 1] == 0 && j - wmax - sp >= 0 && j + 1 <= 18)
							{
								rk[i][j - k].rank = 3;
								placecheck_2020180038(i, j - k, rk);
								rk[i][j - k].color = 1;
								rk[i][j - wmax - sp].rank = 3;
								placecheck_2020180038(i, j - wmax - sp, rk);
								rk[i][j - wmax - sp].color = 1;
								rk[i][j + 1].rank = 3;
								placecheck_2020180038(i, j + 1, rk);
								rk[i][j + 1].color = 1;
							}
						}
						if (wmax == 4)
						{
							rk[i][j - k].rank = 1;
							placecheck_2020180038(i, j - k, rk);
							rk[i][j - k].color = 1;
							//--wmaxcount;
							wrankstate = true;
						}
					}
					if (k == wmax + sp - 1 && sp == 0 && wmax == 3)
					{
						if (Board_2020180038[i][j - wmax - sp] == 0 && Board_2020180038[i][j + 1] == 0 && j - wmax - sp >= 0 && j + 1 <= 18)
						{
							rk[i][j - wmax - sp].rank = 3;
							placecheck_2020180038(i, j - wmax - sp, rk);
							rk[i][j - wmax - sp].color = 1;
							rk[i][j + 1].rank = 3;
							placecheck_2020180038(i, j + 1, rk);
							rk[i][j + 1].color = 1;
						}
					}
					if (k == wmax + sp - 1 && sp == 0 && wmax == 4)
					{
						if (Board_2020180038[i][j - wmax - sp] == 0 && i >= 0 && j - wmax - sp >= 0)
						{
							rk[i][j - wmax - sp].rank = 2;
							placecheck_2020180038(i, j - wmax - sp, rk);
							rk[i][j - wmax - sp].color = 1;
							wrankstate = true;
						}
						if (Board_2020180038[i][j + 1] == 0 && i <= 18 && j + 1 <= 18)
						{
							rk[i][j + 1].rank = 2;
							placecheck_2020180038(i, j + 1, rk);
							rk[i][j + 1].color = 1;
							wrankstate = true;
						}
					}
				}
			}

			if (bmax == ch[i][j].lc && bmax > 1 && ch[i][j].c == 2)
			{
				int sp = 0;
				for (int k = 0; k < bmax + sp; ++k)
				{
					if (Board_2020180038[i][j - k] == 0)
					{
						sp = 1;
						if (bmax == 3)
						{
							if (Board_2020180038[i][j - bmax - sp] == 0 && Board_2020180038[i][j + 1] == 0 && j - bmax - sp >= 0 && j + 1 <= 18)
							{
								rk[i][j - k].rank = 3;
								placecheck_2020180038(i, j - k, rk);
								rk[i][j - k].color = 2;
								rk[i][j - bmax - sp].rank = 3;
								placecheck_2020180038(i, j - bmax - sp, rk);
								rk[i][j - bmax - sp].color = 2;
								rk[i][j + 1].rank = 3;
								placecheck_2020180038(i, j + 1, rk);
								rk[i][j + 1].color = 2;
							}
						}
						if (bmax == 4)
						{
							rk[i][j - k].rank = 1;
							placecheck_2020180038(i, j - k, rk);
							rk[i][j - k].color = 2;
							//--bmaxcount;
							brankstate = true;
						}
					}
					if (k == bmax + sp - 1 && sp == 0 && bmax == 3)
					{
						if (Board_2020180038[i][j - bmax - sp] == 0 && Board_2020180038[i][j + 1] == 0 && j - bmax - sp >= 0 && j + 1 <= 18)
						{
							rk[i][j - bmax - sp].rank = 3;
							placecheck_2020180038(i, j - bmax - sp, rk);
							rk[i][j - bmax - sp].color = 2;
							rk[i][j + 1].rank = 3;
							placecheck_2020180038(i, j + 1, rk);
							rk[i][j + 1].color = 2;
						}
					}
					if (k == bmax + sp - 1 && sp == 0 && bmax == 4)
					{
						if (Board_2020180038[i][j - bmax - sp] == 0 && i >= 0 && j - bmax - sp >= 0)
						{
							rk[i][j - bmax - sp].rank = 2;
							placecheck_2020180038(i, j - bmax - sp, rk);
							rk[i][j - bmax - sp].color = 2;
							brankstate = true;
						}
						if (Board_2020180038[i][j + 1] == 0 && i <= 18 && j + 1 <= 18)
						{
							rk[i][j + 1].rank = 2;
							placecheck_2020180038(i, j + 1, rk);
							rk[i][j + 1].color = 2;
							brankstate = true;
						}
					}
				}
			}
			//°¡·Î ¿¬¼Ó ÁÂÇ¥
			if (wmax == ch[i][j].tc && wmax > 1 && ch[i][j].c == 1)
			{
				int sp = 0;
				for (int k = 0; k < wmax + sp; ++k)
				{
					if (Board_2020180038[i - k][j] == 0)
					{
						sp = 1;
						if (wmax == 3)
						{
							if (Board_2020180038[i - wmax - sp][j] == 0 && Board_2020180038[i + 1][j] == 0 && i - wmax - sp >= 0 && i + 1 <= 18)
							{
								rk[i - k][j].rank = 3;
								placecheck_2020180038(i - k, j, rk);
								rk[i - k][j].color = 1;
								rk[i - wmax - sp][j].rank = 3;
								placecheck_2020180038(i - wmax - sp, j, rk);
								rk[i - wmax - sp][j].color = 1;
								rk[i + 1][j].rank = 3;
								placecheck_2020180038(i + 1, j, rk);
								rk[i + 1][j].color = 1;
							}
						}
						if (wmax == 4)
						{
							rk[i - k][j].rank = 1;
							placecheck_2020180038(i - k, j, rk);
							rk[i - k][j].color = 1;
							wrankstate = true;
							//--wmaxcount;
						}
					}
					if (k == wmax + sp - 1 && sp == 0 && wmax == 3)
					{
						if (Board_2020180038[i - wmax - sp][j] == 0 && Board_2020180038[i + 1][j] == 0 && i - wmax - sp >= 0 && i + 1 <= 18)
						{
							rk[i - wmax - sp][j].rank = 3;
							placecheck_2020180038(i - wmax - sp, j, rk);
							rk[i - wmax - sp][j].color = 1;
							rk[i + 1][j].rank = 3;
							placecheck_2020180038(i + 1, j, rk);
							rk[i + 1][j].color = 1;
						}
					}
					if (k == wmax + sp - 1 && sp == 0 && wmax == 4)
					{
						if (Board_2020180038[i - wmax - sp][j] == 0 && i - wmax - sp >= 0 && j >= 0)
						{
							rk[i - wmax - sp][j].rank = 2;
							placecheck_2020180038(i - wmax - sp, j, rk);
							rk[i - wmax - sp][j].color = 1;
							wrankstate = true;
						}
						if (Board_2020180038[i + 1][j] == 0 && i + 1 <= 18 && j <= 18)
						{
							rk[i + 1][j].rank = 2;
							placecheck_2020180038(i + 1, j, rk);
							rk[i + 1][j].color = 1;
							wrankstate = true;
						}
					}
				}
			}
			if (bmax == ch[i][j].tc && bmax > 1 && ch[i][j].c == 2)
			{
				int sp = 0;
				for (int k = 0; k < bmax + sp; ++k)
				{
					if (Board_2020180038[i - k][j] == 0)
					{
						sp = 1;
						if (bmax == 3)
						{
							if (Board_2020180038[i - bmax - sp][j] == 0 && Board_2020180038[i + 1][j] == 0 && i - bmax - sp >= 0 && i + 1 <= 18)
							{
								rk[i - k][j].rank = 3;
								placecheck_2020180038(i - k, j, rk);
								rk[i - k][j].color = 2;
								rk[i - bmax - sp][j].rank = 3;
								placecheck_2020180038(i - bmax - sp, j, rk);
								rk[i - bmax - sp][j].color = 2;
								rk[i + 1][j].rank = 3;
								placecheck_2020180038(i + 1, j, rk);
								rk[i + 1][j].color = 2;
							}
						}
						if (bmax == 4)
						{
							rk[i - k][j].rank = 1;
							placecheck_2020180038(i - k, j, rk);
							rk[i - k][j].color = 2;
							brankstate = true;
							//--bmaxcount;
						}
					}
					if (k == bmax + sp - 1 && sp == 0 && bmax == 3)
					{
						if (Board_2020180038[i - bmax - sp][j] == 0 && Board_2020180038[i + 1][j] == 0 && i - bmax - sp >= 0 && i + 1 <= 18)
						{
							rk[i - bmax - sp][j].rank = 3;
							placecheck_2020180038(i - bmax - sp, j, rk);
							rk[i - bmax - sp][j].color = 2;
							rk[i + 1][j].rank = 3;
							placecheck_2020180038(i + 1, j, rk);
							rk[i + 1][j].color = 2;
						}
					}
					if (k == bmax + sp - 1 && sp == 0 && bmax == 4)
					{
						if (Board_2020180038[i - bmax - sp][j] == 0 && i - bmax - sp >= 0 && j >= 0)
						{
							rk[i - bmax - sp][j].rank = 2;
							placecheck_2020180038(i - bmax - sp, j, rk);
							rk[i - bmax - sp][j].color = 2;
							brankstate = true;
						}
						if (Board_2020180038[i + 1][j] == 0 && i + 1 <= 18 && j <= 18)
						{
							rk[i + 1][j].rank = 2;
							placecheck_2020180038(i + 1, j, rk);
							rk[i + 1][j].color = 2;
							brankstate = true;
						}
					}
				}
			}
			//¼¼·Î
			if (wmax == ch[i][j].lrd && wmax > 1 && ch[i][j].c == 1)
			{
				int sp = 0;
				for (int k = 0; k < wmax + sp; ++k)
				{
					if (Board_2020180038[i - k][j - k] == 0)
					{
						sp = 1;
						if (wmax == 3)
						{
							if (Board_2020180038[i - wmax - sp][j - wmax - sp] == 0 && Board_2020180038[i + 1][j + 1] == 0 && i - wmax - sp >= 0 && j - wmax - sp >= 0 && j + 1 <= 18 && i + 1 <= 18)
							{
								rk[i - k][j - k].rank = 3;
								placecheck_2020180038(i - k, j - k, rk);
								rk[i - k][j - k].color = 1;
								rk[i - wmax - sp][j - wmax - sp].rank = 3;
								placecheck_2020180038(i - wmax - sp, j - wmax - sp, rk);
								rk[i - wmax - sp][j - wmax - sp].color = 1;
								rk[i + 1][j + 1].rank = 3;
								placecheck_2020180038(i + 1, j + 1, rk);
								rk[i + 1][j + 1].color = 1;
							}
						}
						if (wmax == 4)
						{
							rk[i - k][j - k].rank = 1;
							placecheck_2020180038(i - k, j - k, rk);
							rk[i - k][j - k].color = 1;
							wrankstate = true;
							//--wmaxcount;
						}
					}
					if (k == wmax + sp - 1 && sp == 0 && wmax == 3)
					{
						if (Board_2020180038[i - wmax - sp][j - wmax - sp] == 0 && Board_2020180038[i + 1][j + 1] == 0 && i - wmax - sp >= 0 && i + 1 <= 18 && j - wmax - sp >= 0 && j + 1 <= 18)
						{
							rk[i - wmax - sp][j - wmax - sp].rank = 3;
							placecheck_2020180038(i - wmax - sp, j - wmax - sp, rk);
							rk[i - wmax - sp][j - wmax - sp].color = 1;
							rk[i + 1][j + 1].rank = 3;
							placecheck_2020180038(i + 1, j + 1, rk);
							rk[i + 1][j + 1].color = 1;
						}
					}
					if (k == wmax + sp - 1 && sp == 0 && wmax == 4)
					{
						if (Board_2020180038[i - wmax - sp][j - wmax - sp] == 0 && i - wmax - sp >= 0 && j - wmax - sp >= 0)
						{
							rk[i - wmax - sp][j - wmax - sp].rank = 2;
							placecheck_2020180038(i - wmax - sp, j - wmax - sp, rk);
							rk[i - wmax - sp][j - wmax - sp].color = 1;
							wrankstate = true;
						}
						if (Board_2020180038[i + 1][j + 1] == 0 && i + 1 <= 18 && j + 1 <= 18)
						{
							rk[i + 1][j + 1].rank = 2;
							placecheck_2020180038(i + 1, j + 1, rk);
							rk[i + 1][j + 1].color = 1;
							wrankstate = true;
						}
					}
				}
			}//¿Þ->¿À
			if (bmax == ch[i][j].lrd && bmax > 1 && ch[i][j].c == 2)
			{
				int sp = 0;
				for (int k = 0; k < bmax + sp; ++k)
				{
					if (Board_2020180038[i - k][j - k] == 0)
					{
						sp = 1;
						if (bmax == 3)
						{
							if (Board_2020180038[i - bmax - sp][j - bmax - sp] == 0 && Board_2020180038[i + 1][j + 1] == 0 && i - bmax - sp >= 0 && j - bmax - sp >= 0 && j + 1 <= 18 && i + 1 <= 18)
							{
								rk[i - k][j - k].rank = 3;
								placecheck_2020180038(i - k, j - k, rk);
								rk[i - k][j - k].color = 2;
								rk[i - bmax - sp][j - bmax - sp].rank = 3;
								placecheck_2020180038(i - bmax - sp, j - bmax - sp, rk);
								rk[i - bmax - sp][j - bmax - sp].color = 2;
								rk[i + 1][j + 1].rank = 3;
								placecheck_2020180038(i + 1, j + 1, rk);
								rk[i + 1][j + 1].color = 2;
							}
						}
						if (bmax == 4)
						{
							rk[i - k][j - k].rank = 1;
							placecheck_2020180038(i - k, j - k, rk);
							rk[i - k][j - k].color = 2;
							//--bmaxcount;
						}
					}
					if (k == bmax + sp - 1 && sp == 0 && bmax == 3)
					{
						if (Board_2020180038[i - bmax - sp][j - bmax - sp] == 0 && Board_2020180038[i + 1][j + 1] == 0 && i - bmax - sp >= 0 && i + 1 <= 18 && j - bmax - sp >= 0 && j + 1 <= 18)
						{
							rk[i - bmax - sp][j - bmax - sp].rank = 3;
							placecheck_2020180038(i - bmax - sp, j - bmax - sp, rk);
							rk[i - bmax - sp][j - bmax - sp].color = 2;
							rk[i + 1][j + 1].rank = 3;
							placecheck_2020180038(i + 1, j + 1, rk);
							rk[i + 1][j + 1].color = 2;
						}
					}
					if (k == bmax + sp - 1 && sp == 0 && bmax == 4)
					{
						if (Board_2020180038[i - bmax - sp][j - bmax - sp] == 0 && i - bmax - sp >= 0 && j - bmax - sp >= 0)
						{
							rk[i - bmax - sp][j - bmax - sp].rank = 2;
							placecheck_2020180038(i - bmax - sp, j - bmax - sp, rk);
							rk[i - bmax - sp][j - bmax - sp].color = 2;
							brankstate = true;
						}
						if (Board_2020180038[i + 1][j + 1] == 0 && i + 1 <= 18 && j + 1 <= 18)
						{
							rk[i + 1][j + 1].rank = 2;
							placecheck_2020180038(i + 1, j + 1, rk);
							rk[i + 1][j + 1].color = 2;
							brankstate = true;
						}
					}
				}
			}//¿Þ->¿À
			if (wmax == ch[i][j].rld && wmax > 1 && ch[i][j].c == 1)
			{
				int sp = 0;
				for (int k = 0; k < wmax + sp; ++k)
				{
					if (Board_2020180038[i - k][j + k] == 0)
					{
						sp = 1;
						if (wmax == 3)
						{
							if (Board_2020180038[i - wmax - sp][j + wmax + sp] == 0 && Board_2020180038[i + 1][j - 1] == 0 && i - wmax - sp >= 0 && j + wmax + sp >= 0 && j - 1 <= 18 && i + 1 <= 18)
							{
								rk[i - k][j + k].rank = 3;
								placecheck_2020180038(i - k, j + k, rk);
								rk[i - k][j + k].color = 1;
								rk[i - wmax - sp][j + wmax + sp].rank = 3;
								placecheck_2020180038(i - wmax - sp, j + wmax + sp, rk);
								rk[i - wmax - sp][j + wmax + sp].color = 1;
								rk[i + 1][j - 1].rank = 3;
								placecheck_2020180038(i + 1, j - 1, rk);
								rk[i + 1][j - 1].color = 1;
							}
						}
						if (wmax == 4)
						{
							rk[i - k][j + k].rank = 1;
							placecheck_2020180038(i - k, j + k, rk);
							rk[i - k][j + k].color = 1;
							wrankstate = true;
							//--wmaxcount;
						}
					}
					if (k == wmax + sp - 1 && sp == 0 && wmax == 3)
					{
						if (Board_2020180038[i - wmax - sp][j + wmax + sp] == 0 && Board_2020180038[i + 1][j - 1] == 0 && i - wmax - sp >= 0 && i + 1 <= 18 && j + wmax + sp <= 18 && j - 1 <= 18)
						{
							rk[i - wmax - sp][j + wmax + sp].rank = 3;
							placecheck_2020180038(i - wmax - sp, j + wmax + sp, rk);
							rk[i - wmax - sp][j + wmax + sp].color = 1;
							rk[i + 1][j - 1].rank = 3;
							placecheck_2020180038(i + 1, j - 1, rk);
							rk[i + 1][j - 1].color = 1;
						}
					}
					if (k == wmax + sp - 1 && sp == 0 && wmax == 4)
					{
						if (Board_2020180038[i - wmax - sp][j + wmax + sp] == 0 && i - wmax - sp >= 0 && j + wmax + sp <= 18)
						{
							rk[i - wmax - sp][j + wmax + sp].rank = 2;
							placecheck_2020180038(i - wmax - sp, j + wmax + sp, rk);
							rk[i - wmax - sp][j + wmax + sp].color = 1;
							wrankstate = true;
						}
						if (Board_2020180038[i + 1][j - 1] == 0 && i + 1 <= 18 && j - 1 <= 18)
						{
							rk[i + 1][j - 1].rank = 2;
							placecheck_2020180038(i + 1, j - 1, rk);
							rk[i + 1][j - 1].color = 1;
							wrankstate = true;
						}
					}
				}
			}//¿Þ->¿À
			if (bmax == ch[i][j].rld && bmax > 1 && ch[i][j].c == 2)
			{
				int sp = 0;
				for (int k = 0; k < bmax + sp; ++k)
				{
					if (Board_2020180038[i - k][j + k] == 0)
					{
						sp = 1;
						if (bmax == 3)
						{
							if (Board_2020180038[i - bmax - sp][j + bmax + sp] == 0 && Board_2020180038[i + 1][j - 1] == 0 && i - bmax - sp >= 0 && j + bmax + sp >= 0 && j - 1 <= 18 && i + 1 <= 18)
							{
								rk[i - k][j + k].rank = 3;
								placecheck_2020180038(i - k, j + k, rk);
								rk[i - k][j + k].color = 2;
								rk[i - bmax - sp][j + bmax + sp].rank = 3;
								placecheck_2020180038(i - bmax - sp, j + bmax + sp, rk);
								rk[i - bmax - sp][j + bmax + sp].color = 2;
								rk[i + 1][j - 1].rank = 3;
								placecheck_2020180038(i + 1, j - 1, rk);
								rk[i + 1][j - 1].color = 2;
							}
						}
						if (bmax == 4)
						{
							rk[i - k][j + k].rank = 1;
							placecheck_2020180038(i - k, j + k, rk);
							rk[i - k][j + k].color = 2;
							brankstate = true;
						}
					}
					if (k == bmax + sp - 1 && sp == 0 && bmax == 3)
					{
						if (Board_2020180038[i - bmax - sp][j + bmax + sp] == 0 && Board_2020180038[i + 1][j - 1] == 0 && i - bmax - sp >= 0 && i + 1 <= 18 && j + bmax + sp <= 18 && j - 1 <= 18)
						{
							rk[i - bmax - sp][j + bmax + sp].rank = 3;
							placecheck_2020180038(i - bmax - sp, j + bmax + sp, rk);
							rk[i - bmax - sp][j + bmax + sp].color = 2;
							rk[i + 1][j - 1].rank = 3;
							placecheck_2020180038(i + 1, j - 1, rk);
							rk[i + 1][j - 1].color = 2;
						}
					}
					if (k == bmax + sp - 1 && sp == 0 && bmax == 4)
					{
						if (Board_2020180038[i - bmax - sp][j + bmax + sp] == 0 && i - bmax - sp >= 0 && j + bmax + sp <= 18)
						{
							rk[i - bmax - sp][j + bmax + sp].rank = 2;
							placecheck_2020180038(i - bmax - sp, j + bmax + sp, rk);
							rk[i - bmax - sp][j + bmax + sp].color = 2;
							brankstate = true;
						}
						if (Board_2020180038[i + 1][j - 1] == 0 && i + 1 <= 18 && j - 1 <= 18)
						{
							rk[i + 1][j - 1].rank = 2;
							placecheck_2020180038(i + 1, j - 1, rk);
							rk[i + 1][j - 1].color = 2;
							brankstate = true;
						}
					}
				}
			}//¿Þ->¿À
		}
	}

	if (wmax == 4 && wrankstate == false)
	{
		wmax = 3;
		goto BACK;
	}
	if (bmax == 4 && brankstate == false)
	{
		bmax = 3;
		goto BACK;
	}
	while (true)
	{
		black = putwhite_2020180038(black, rk, wmax, ch, Board_2020180038);
		if (black.x < 0 || black.y < 0 || black.x>18 || black.y>18)
		{
			continue;
		}
		else if (Board_2020180038[black.x][black.y] == 1 || Board_2020180038[black.x][black.y] == 2 || Board_2020180038[black.x][black.y] == 3)
		{
			continue;
		}
		else
		{
			*y = black.x;
			*x = black.y;
			Board_2020180038[black.x][black.y] = 2;
			break;
		}
	}
}

void WhiteDefence_2020180038(int x, int y)
{
	Board_2020180038[y][x] = 1;
}

blackstone_2020180038 putwhite_2020180038(blackstone_2020180038 stone, Stone_2020180038 rk[size_2020180038][size_2020180038], int wmax, check_2020180038 ch[size_2020180038][size_2020180038], char Board[size_2020180038][size_2020180038])
{
	int putrank = 1;
	while (putrank != 4)
	{
		for (int i = 0; i < size_2020180038; ++i)
		{
			for (int j = 0; j < size_2020180038; ++j)
			{
				if (rk[i][j].rank == putrank && rk[i][j].color == 2)
				{
					stone.x = i;
					stone.y = j;
					if (Board[i][j] == 0)
						return stone;
					else
						continue;
				}
			}
		}
		++putrank;
	}

	putrank = 1;
	while (putrank != 4)
	{
		for (int i = 0; i < size_2020180038; ++i)
		{
			for (int j = 0; j < size_2020180038; ++j)
			{
				if (rk[i][j].rank == putrank && rk[i][j].color == 1)
				{
					stone.x = i;
					stone.y = j;
					if (Board[i][j] == 0)
						return stone;
				}
			}
		}
		++putrank;
	}

	while (wmax != 0)
	{
		for (int i = 0; i < size_2020180038; ++i)
		{
			for (int j = 0; j < size_2020180038; ++j)
			{
				if (wmax == ch[i][j].lc && ch[i][j].c == 1)
				{
					stone.x = i;
					stone.y = j + 1;
					if (Board[i][j + 1] == 0 && j + 1 <= 18)
						return stone;
					stone.x = i;
					stone.y = j - wmax;
					if (Board[i][j - wmax] == 0 && j - wmax >= 0)
						return stone;
				}
				if (wmax == ch[i][j].lrd && ch[i][j].c == 1)
				{
					stone.x = i + 1;
					stone.y = j + 1;
					if (Board[i + 1][j + 1] == 0 && i + 1 <= 18 && j + 1 <= 18)
						return stone;
					stone.x = i - wmax;
					stone.y = j - wmax;
					if (Board[i - wmax][j - wmax] == 0 && i - wmax >= 0 && j - wmax >= 0)
						return stone;
				}
				if (wmax == ch[i][j].tc && ch[i][j].c == 1)
				{
					stone.x = i + 1;
					stone.y = j;
					if (Board[i + 1][j] == 0 && i + 1 <= 18)
						return stone;
					stone.x = i - wmax;
					stone.y = j;
					if (Board[i - wmax][j] == 0 && i - wmax >= 0)
						return stone;
				}
				if (wmax == ch[i][j].rld && ch[i][j].c == 1)
				{
					stone.x = i + 1;
					stone.y = j - 1;
					if (Board[i + 1][j - 1] == 0 && i + 1 <= 18 && j - 1 >= 0)
						return stone;
					stone.x = i - wmax;
					stone.y = j + wmax;
					if (Board[i - wmax][j + wmax] == 0 && i - wmax >= 0 && j + wmax <= 18)
						return stone;
				}
			}
		}
		--wmax;
	}
	stone.x = rand() % size_2020180038;
	stone.y = rand() % size_2020180038;

	return stone;
}