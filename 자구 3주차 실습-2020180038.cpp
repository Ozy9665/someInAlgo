#include <stdio.h>
#include <string.h>

typedef struct LOL_CHAMPION
{
	char name[20];
	int hp;
	int mp;
	int speed;
	int range;
	char position[20];
}Champ;

int search_compare(Champ L_D[200], char search_name[20], int champ_num)
{
	for (int i = 0; i < champ_num; ++i)
	{
		if (strcmp(L_D[i].name, search_name) == 0)
		{
			printf("챔피언: %s, HP: %d MP: %d, SPEED: %d, RANGE: %d, POSITION: %s"
				, L_D[i].name, L_D[i].hp, L_D[i].mp, L_D[i].speed, L_D[i].range, L_D[i].position);
			return 1;

		}
		else if (i == champ_num - 1 && strcmp(L_D[i].name, search_name) != 0)
		{
			for (int i = 0; i < 20; ++i)
				search_name[i] = ' ';
			return 0;
		}
	}
}

int delete_compare(Champ L_D[200], char delete_name[20], int champ_num)
{
	for (int i = 0; i < champ_num; ++i)
	{
		if (strcmp(L_D[i].name, delete_name) == 0)
		{
			L_D[i] = { 0 };
			return 1;

		}
		else if (i == champ_num - 1 && strcmp(L_D[i].name, delete_name) != 0)
		{
			for (int i = 0; i < 20; ++i)
				delete_name[i] = ' ';
			return 0;
		}
	}
}


int main()
{
	Champ L_D[200] = { {"가렌",620,0,340,175,"top"},
	{"갈리오",562,500,335,125,"mid"},
	{"베인", 515,231,330,550,"bot"},
	{"티모",528,267,330,500,"top"},
	{"소라카",535,425,325,550,"suport"},
	{"녹턴",585,275,345,125,"jungle"},
	{"블리츠크랭크",582,267,325,125,"support"},
	{"퀸",532,568,335,525,"top"},
	{"장지웅",620,0,350,500,"bot"},
	{"시비르",530,300,325,350,"bot"},
	{"모르가나",500,350,320,550,"support"},
	{"코르키",550,450,125,330,"mid"},
	{"리신",619,0,350,250,"jungle"},
	{"레나타 글라스크",500,235,330,125,"suport"},
	{"아리",500,340,330,500,"mid"},
	{"바드",490,300,330,300,"support"},
	{"바루스",510,250,345,570,"bot"},
	{"쉔",620,0,330,200,"top"},
	{"애쉬",500,350,330,500,"bot"},
	{"라이즈",550,400,325,400,"mid"},
	};

	int select = 0;	int champ_num = 20;
	char search_name[20];	char delete_name[20];
	
	while (true)
	{
		printf("------------MENU--------------\n");
		printf("1. 챔피언 검색\n2. 챔피언 정보 입력\n3. 챔피언 정보 삭제\n4. 챔피언 정보 모두 출력\n");
		printf("Input command(1~4): ");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			getchar();
			printf("검색할 챔피언 이름을 입력해주세요: ");
			while (true)
			{
				gets_s(search_name, 20);
				if (search_compare(L_D, search_name, champ_num) == 1)
					break;
				else 
				{
					printf("챔피언 이름을 다시 입력해주세요: ");
					continue;
				}
			}
			printf("\n");
			break;
		case 2:
			printf("정보를 입력할 챔피언 이름을 입력해주세요: ");
			getchar();
			gets_s(L_D[champ_num].name, 20);
			printf("챔피언의 HP를 입력해주세요: ");
			scanf("%d", &L_D[champ_num].hp);
			printf("챔피언의 MP를 입력해주세요: ");
			scanf("%d", &L_D[champ_num].mp);
			printf("챔피언의 SPEED를 입력해주세요: ");
			scanf("%d", &L_D[champ_num].speed);
			printf("챔피언의 RANGE를 입력해주세요: ");
			scanf("%d", &L_D[champ_num].range);
			printf("챔피언의 포지션을 입력해주세요(EX: top, mid, bot, support, jungle): ");
			getchar();
			gets_s(L_D[champ_num].position, 20);
			++champ_num;
			break;
		case 3:
			getchar();
			printf("삭제할 챔피언 이름을 입력해주세요: ");
			while (true)
			{
				gets_s(delete_name, 20);
				if (delete_compare(L_D, delete_name, champ_num) == 1)
					break;
				else {
					printf("챔피언 이름을 다시 입력해주세요: ");
					continue;
				}
			}
			break;
		case 4:
			for (int i = 0; i < champ_num; ++i)
			{
				if (L_D[i].hp != 0)
				{
					printf("챔피언: %s, HP: %d MP: %d, SPEED: %d, RANGE: %d, POSITION: %s\n"
						, L_D[i].name, L_D[i].hp, L_D[i].mp, L_D[i].speed, L_D[i].range, L_D[i].position);
				}
			
			}
			break;
		}
		printf("\n");
	}
}