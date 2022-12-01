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
			printf("챔피언: %s, HP: %d, MP: %d, SPEED: %d, RANGE: %d, POSITION: %s",
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
		{"가렌", 620, 0, 340, 175, "top"},{"갈리오", 562, 500, 335, 125, "mid"}
	,{"베인", 515, 231, 330, 550, "bot"},{"티모", 528, 267, 330, 500, "top"},
	{"소라카", 535, 425, 325, 550, "support"},{"녹턴", 585, 275, 345, 125, "jungle"},
	{"블리츠크랭크", 582, 267, 325, 125, "support"},{"퀸", 532, 268, 335, 525, "top"},
	{"아펠리오스", 620, 0, 350, 500, "bot"},{"시비르", 530, 300, 325, 350, "bot"}
	,{"모르가나", 500, 350, 320, 550, "support"},{"코르키", 550, 450, 125, 330, "mid"},
	{"리신", 619, 0, 350, 250, "jungle"},{"레나타 글라스크", 500, 235, 330, 125, "support"},
	{"르블랑", 500, 340, 330, 500, "mid"},{"바드", 490, 300, 330, 300, "support"},
	{"바루스", 510, 250, 345, 570, "bot"},{"쉔", 620, 0, 330, 200, "top"},
	{"애쉬", 500, 350, 330, 500, "bot"},{"라이즈", 550, 400, 325, 400, "mid"}, };

	int select = 0;		int champ_num = 20;
	char search_name[20];	char delete_name[20];	char delete_position[10];
	while (true)
	{
		printf("1. 챔피언 검색\n2. 새로운 챔피언 입력\n3. 챔피언 삭제\n4. 특정 포지션에 있는 챔피언 정보 삭제\n5. 모든 챔피언 정보 출력\n6. HP가 가장 큰 챔피언 정보 출력\n7. 체력이 가장 큰 순서대로 정보 저장\n");
		printf("Input Command: ");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			getchar();
			printf("검색할 챔피언 이름을 입력해주세요: ");
			while (true)
			{
				gets_s(search_name, 20);
				if (search_compare(LOL_DIC, search_name, champ_num) == 1)
					break;
				else
				{
					printf("챔피언 이름을 다시 입력해주세요: ");
					continue;
				}
			}
			break;
		case 2:
			getchar();
			printf("새로 저장할 챔피언 이름을 입력해주세요: ");
			gets_s(LOL_DIC[champ_num].name, 20);
			printf("그 챔피언의 HP를 입력해주세요: ");
			scanf("%d", &LOL_DIC[champ_num].hp);
			printf("그 챔피언의 MP를 입력해주세요: ");
			scanf("%d", &LOL_DIC[champ_num].mp);
			printf("그 챔피언의 SPEED를 입력해주세요: ");
			scanf("%d", &LOL_DIC[champ_num].speed);
			printf("그 챔피언의 RANGE를 입력해주세요: ");
			scanf("%d", &LOL_DIC[champ_num].range);
			getchar();
			printf("그 챔피언 포지션을 입력해주세요: ");
			gets_s(LOL_DIC[champ_num].position, 10);
			++champ_num;
			break;
		case 3:
			getchar();
			printf("삭제할 챔피언 이름을 입력해주세요: ");
			while (true)
			{
				gets_s(delete_name, 20);
				if (delete_compare(LOL_DIC, delete_name, champ_num) == 1)
					break;
				else
				{
					printf("챔피언 이름을 다시 입력해주세요: ");
					continue;
				}
			}
			break;
		case 4:
			getchar();
			printf("삭제할 포지션을 입력해주세요: ");
			while (true)
			{
				gets_s(delete_position, 10);
				if (Delete_Position(LOL_DIC, delete_position, champ_num) == 123)
				{
					printf("포지션 이름을 다시 입력해주세요: ");
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
					printf("챔피언: %s, HP: %d, MP: %d, SPEED: %d, RANGE: %d, POSITION: %s\n",
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
					printf("챔피언: %s, HP: %d, MP: %d, SPEED: %d, RANGE: %d, POSITION: %s\n",
						LOL_DIC[i].name, LOL_DIC[i].hp, LOL_DIC[i].mp, LOL_DIC[i].speed, LOL_DIC[i].range, LOL_DIC[i].position);
				}
			}
			break;
		case 7:
			SortByHp(LOL_DIC, champ_num);
			printf("저장이 완료되었습니다.\n");
			break;

		}
		printf("\n");
	}
}