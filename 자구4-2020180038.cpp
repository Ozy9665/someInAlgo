#include <stdio.h>
#include <string.h>
struct Champ
{
	char name[20];
	int hp;
	int mp;
	int speed;
	int range;
	char position[10];
};

int search_compare(Champ LOL_DIC[500], char search_name[20], int champ_num)
{
	for (int i = 0; i < champ_num; ++i)
	{
		if (strcmp(LOL_DIC[i].name, search_name) == 0)
		{
			printf("è�Ǿ�: %s, HP: %d, MP: %d, SPEED: %d, RANGE: %d, POSITION: %s",
				LOL_DIC[i].name, LOL_DIC[i].hp, LOL_DIC[i].mp, LOL_DIC[i].speed, LOL_DIC[i].range, LOL_DIC[i].position);
			return 1;
		}
		else if (strcmp(LOL_DIC[i].name, search_name) != 0 && i == champ_num - 1)
			return 0;
	}
}


int delete_compare(Champ LOL_DIC[500], char delete_name[20], int champ_num)
{
	for (int i = 0; i < champ_num; ++i)
	{
		if (strcmp(LOL_DIC[i].name, delete_name) == 0)
		{
			LOL_DIC[i] = { 0 };
			return 1;
		}
		else if (strcmp(LOL_DIC[i].name, delete_name) != 0 && i == champ_num - 1)
			return 0;
	}
}

int Delete_Position(Champ LOL_DIC[500], char delete_position[20], int champ_num)
{
	int num = 0;
	for (int i = 0; i < champ_num; ++i)
	{
		if (strcmp(LOL_DIC[i].position, delete_position) == 0)
		{
			LOL_DIC[i] = { 0 };
			++num;
		}
		else if (i == champ_num - 1) {
			if (num == 0)
				return 123;
			else
				return 0;
		}
	}
}

void SortByHp(Champ LOL_DIC[500],int champ_num)
{
	Champ temp;
	for (int i = 0; i < champ_num - 1; ++i)
	{
		for (int j = i; j < champ_num; ++j)
		{
			if (LOL_DIC[i].hp < LOL_DIC[j].hp)
			{
				temp = LOL_DIC[i];
				LOL_DIC[i] = LOL_DIC[j];
				LOL_DIC[j] = temp;
			}
		}
	}
}

int main()
{
	Champ LOL_DIC[500] = {
		{"����", 620, 0, 340, 175, "top"},{"������", 562, 500, 335, 125, "mid"}
	,{"����", 515, 231, 330, 550, "bot"},{"Ƽ��", 528, 267, 330, 500, "top"},
	{"�Ҷ�ī", 535, 425, 325, 550, "support"},{"����", 585, 275, 345, 125, "jungle"},
	{"����ũ��ũ", 582, 267, 325, 125, "support"},{"��", 532, 268, 335, 525, "top"},
	{"���縮����", 620, 0, 350, 500, "bot"},{"�ú�", 530, 300, 325, 350, "bot"}
	,{"�𸣰���", 500, 350, 320, 550, "support"},{"�ڸ�Ű", 550, 450, 125, 330, "mid"},
	{"����", 619, 0, 350, 250, "jungle"},{"����Ÿ �۶�ũ", 500, 235, 330, 125, "support"},
	{"�����", 500, 340, 330, 500, "mid"},{"�ٵ�", 490, 300, 330, 300, "support"},
	{"�ٷ罺", 510, 250, 345, 570, "bot"},{"��", 620, 0, 330, 200, "top"},
	{"�ֽ�", 500, 350, 330, 500, "bot"},{"������", 550, 400, 325, 400, "mid"}, };

	int select = 0;		int champ_num = 20;
	char search_name[20];	char delete_name[20];	char delete_position[10];
	while (true)
	{
		printf("1. è�Ǿ� �˻�\n2. ���ο� è�Ǿ� �Է�\n3. è�Ǿ� ����\n4. Ư�� �����ǿ� �ִ� è�Ǿ� ���� ����\n5. ��� è�Ǿ� ���� ���\n6. HP�� ���� ū è�Ǿ� ���� ���\n7. ü���� ���� ū ������� ���� ����\n");
		printf("Input Command: ");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			getchar();
			printf("�˻��� è�Ǿ� �̸��� �Է����ּ���: ");
			while (true)
			{
				gets_s(search_name, 20);
				if (search_compare(LOL_DIC, search_name, champ_num) == 1)
					break;
				else
				{
					printf("è�Ǿ� �̸��� �ٽ� �Է����ּ���: ");
					continue;
				}
			}
			break;
		case 2:
			getchar();
			printf("���� ������ è�Ǿ� �̸��� �Է����ּ���: ");
			gets_s(LOL_DIC[champ_num].name, 20);
			printf("�� è�Ǿ��� HP�� �Է����ּ���: ");
			scanf("%d", &LOL_DIC[champ_num].hp);
			printf("�� è�Ǿ��� MP�� �Է����ּ���: ");
			scanf("%d", &LOL_DIC[champ_num].mp);
			printf("�� è�Ǿ��� SPEED�� �Է����ּ���: ");
			scanf("%d", &LOL_DIC[champ_num].speed);
			printf("�� è�Ǿ��� RANGE�� �Է����ּ���: ");
			scanf("%d", &LOL_DIC[champ_num].range);
			getchar();
			printf("�� è�Ǿ� �������� �Է����ּ���: ");
			gets_s(LOL_DIC[champ_num].position, 10);
			++champ_num;
			break;
		case 3:
			getchar();
			printf("������ è�Ǿ� �̸��� �Է����ּ���: ");
			while (true)
			{
				gets_s(delete_name, 20);
				if (delete_compare(LOL_DIC, delete_name, champ_num) == 1)
					break;
				else
				{
					printf("è�Ǿ� �̸��� �ٽ� �Է����ּ���: ");
					continue;
				}
			}
			break;
		case 4:
			getchar();
			printf("������ �������� �Է����ּ���: ");
			while (true)
			{
				gets_s(delete_position, 10);
				if (Delete_Position(LOL_DIC, delete_position, champ_num) == 123)
				{
					printf("������ �̸��� �ٽ� �Է����ּ���: ");
					continue;
				}
				else
					break;
			}
			break;
		case 5:
			for (int i = 0; i < champ_num; ++i)
			{
				if (LOL_DIC[i].hp != 0)
				{
					printf("è�Ǿ�: %s, HP: %d, MP: %d, SPEED: %d, RANGE: %d, POSITION: %s\n",
						LOL_DIC[i].name, LOL_DIC[i].hp, LOL_DIC[i].mp, LOL_DIC[i].speed, LOL_DIC[i].range, LOL_DIC[i].position);
				}
			}
			break;
		case 6:
			SortByHp(LOL_DIC, champ_num);
			auto temp = LOL_DIC[0];
			for (int i = 0; i < champ_num; ++i)
			{
				if (LOL_DIC[i].hp == temp.hp)
				{
					printf("è�Ǿ�: %s, HP: %d, MP: %d, SPEED: %d, RANGE: %d, POSITION: %s\n",
						LOL_DIC[i].name, LOL_DIC[i].hp, LOL_DIC[i].mp, LOL_DIC[i].speed, LOL_DIC[i].range, LOL_DIC[i].position);
				}
			}
			break;
		case 7:
			SortByHp(LOL_DIC, champ_num);
			printf("������ �Ϸ�Ǿ����ϴ�.\n");
			break;

		}
		printf("\n");
	}
}