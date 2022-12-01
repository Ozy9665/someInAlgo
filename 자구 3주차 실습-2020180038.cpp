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
			printf("è�Ǿ�: %s, HP: %d MP: %d, SPEED: %d, RANGE: %d, POSITION: %s"
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
	Champ L_D[200] = { {"����",620,0,340,175,"top"},
	{"������",562,500,335,125,"mid"},
	{"����", 515,231,330,550,"bot"},
	{"Ƽ��",528,267,330,500,"top"},
	{"�Ҷ�ī",535,425,325,550,"suport"},
	{"����",585,275,345,125,"jungle"},
	{"����ũ��ũ",582,267,325,125,"support"},
	{"��",532,568,335,525,"top"},
	{"������",620,0,350,500,"bot"},
	{"�ú�",530,300,325,350,"bot"},
	{"�𸣰���",500,350,320,550,"support"},
	{"�ڸ�Ű",550,450,125,330,"mid"},
	{"����",619,0,350,250,"jungle"},
	{"����Ÿ �۶�ũ",500,235,330,125,"suport"},
	{"�Ƹ�",500,340,330,500,"mid"},
	{"�ٵ�",490,300,330,300,"support"},
	{"�ٷ罺",510,250,345,570,"bot"},
	{"��",620,0,330,200,"top"},
	{"�ֽ�",500,350,330,500,"bot"},
	{"������",550,400,325,400,"mid"},
	};

	int select = 0;	int champ_num = 20;
	char search_name[20];	char delete_name[20];
	
	while (true)
	{
		printf("------------MENU--------------\n");
		printf("1. è�Ǿ� �˻�\n2. è�Ǿ� ���� �Է�\n3. è�Ǿ� ���� ����\n4. è�Ǿ� ���� ��� ���\n");
		printf("Input command(1~4): ");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			getchar();
			printf("�˻��� è�Ǿ� �̸��� �Է����ּ���: ");
			while (true)
			{
				gets_s(search_name, 20);
				if (search_compare(L_D, search_name, champ_num) == 1)
					break;
				else 
				{
					printf("è�Ǿ� �̸��� �ٽ� �Է����ּ���: ");
					continue;
				}
			}
			printf("\n");
			break;
		case 2:
			printf("������ �Է��� è�Ǿ� �̸��� �Է����ּ���: ");
			getchar();
			gets_s(L_D[champ_num].name, 20);
			printf("è�Ǿ��� HP�� �Է����ּ���: ");
			scanf("%d", &L_D[champ_num].hp);
			printf("è�Ǿ��� MP�� �Է����ּ���: ");
			scanf("%d", &L_D[champ_num].mp);
			printf("è�Ǿ��� SPEED�� �Է����ּ���: ");
			scanf("%d", &L_D[champ_num].speed);
			printf("è�Ǿ��� RANGE�� �Է����ּ���: ");
			scanf("%d", &L_D[champ_num].range);
			printf("è�Ǿ��� �������� �Է����ּ���(EX: top, mid, bot, support, jungle): ");
			getchar();
			gets_s(L_D[champ_num].position, 20);
			++champ_num;
			break;
		case 3:
			getchar();
			printf("������ è�Ǿ� �̸��� �Է����ּ���: ");
			while (true)
			{
				gets_s(delete_name, 20);
				if (delete_compare(L_D, delete_name, champ_num) == 1)
					break;
				else {
					printf("è�Ǿ� �̸��� �ٽ� �Է����ּ���: ");
					continue;
				}
			}
			break;
		case 4:
			for (int i = 0; i < champ_num; ++i)
			{
				if (L_D[i].hp != 0)
				{
					printf("è�Ǿ�: %s, HP: %d MP: %d, SPEED: %d, RANGE: %d, POSITION: %s\n"
						, L_D[i].name, L_D[i].hp, L_D[i].mp, L_D[i].speed, L_D[i].range, L_D[i].position);
				}
			
			}
			break;
		}
		printf("\n");
	}
}