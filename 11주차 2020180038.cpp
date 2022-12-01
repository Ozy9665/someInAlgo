#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Champ
{
	char position[15]{};
	char name[20]{};
	int hp;
	int attack;
	int defend;
};

struct SL
{
	Champ champ;
	struct SL*link;
};

struct BT
{
	Champ champ;
	struct BT*left;
	struct BT*right;
};

SL*slhead = NULL, *sltail = NULL, *slp = NULL;
BT*root = NULL, *tree = NULL;

void slopen()
{
	FILE*fp = fopen("LOLDic.txt", "r");
	if (fp == NULL)
	{
		printf("파일 열기 실패\n");
		return;
	}
	while (!feof(fp))
	{
		slp = (SL*)malloc(sizeof(SL));

		fscanf(fp, "%s %s %d %d %d", slp->champ.position, slp->champ.name, &slp->champ.hp, &slp->champ.attack, &slp->champ.defend);

		slp->link = NULL;
		if (slhead == NULL)
		{
			slhead = slp;
			sltail = slp;
		}
		else
		{
			sltail->link = slp;
			sltail = slp;
		}

	}
	fclose(fp);
}

void slswap(SL*lhs, SL*rhs)
{
	auto tmp = lhs->champ;
	lhs->champ = rhs->champ;
	rhs->champ = tmp;
}

void slsort(SL*left, SL*right)
{
	SL*p = left;
	SL*q = NULL;

	if (left == NULL || left == right || left->link == right)
		return;

	char pivot[20]{};

	strcpy(pivot, left->champ.name);

	q = left->link;

	while(q != right)
	{
		if (strcmp(q->champ.name, pivot) < 0)
		{
			if (p->link != q)
				slswap(p->link, q);
			p = p->link;
		}
		q = q->link;
	}
	
	if (left != p)
		slswap(left, p);
	
	slsort(left, p);
	slsort(p->link, right);
}

void slprint()// 확인용
{
	slp = slhead;
	int count = 0;
	while (slp != NULL)
	{
		++count;
		if (count % 10000 == 0)
			printf("%s %s %d %d %d\n", slp->champ.position, slp->champ.name, slp->champ.hp, slp->champ.attack, slp->champ.defend);

		slp = slp->link;
	}
}


void freesl()
{
	slp = slhead;
	while (slp != NULL)
	{
		SL*tmp = slp;
		slp = slp->link;
		free(tmp);
	}
}

BT* InsertTree(BT*p, Champ cham);

void maketree()
{
	FILE*fp = fopen("LOLDic.txt", "r");
	Champ champ;
	if (fp == NULL)
	{
		printf("파일 열기 실패\n");
		return;
	}
	while (!feof(fp))
	{
		fscanf(fp, "%s %s %d %d %d", champ.position, champ.name, &champ.hp, &champ.attack, &champ.defend);

		if (root == NULL)
			root = InsertTree(root, champ);
		else
			tree = InsertTree(root, champ);
	}
	fclose(fp);
}

BT* InsertTree(BT*p, Champ cham)
{
	if (p == NULL)
	{
		p = (BT*)malloc(sizeof(BT));
		p->champ = cham;
		p->left = p->right = NULL;
		return p;
	}
	else
	{
		if (strcmp(p->champ.name, cham.name) < 0)
			p->right = InsertTree(p->right, cham);
		else if (strcmp(p->champ.name, cham.name) > 0)
			p->left = InsertTree(p->left, cham);
	}
	return p;
}

void SearchTree(BT*p, char name[20])
{
	if (p == NULL)
	{
		printf("정보가 없습니다.\n");
		return;
	}
	if (strcmp(p->champ.name, name) < 0)
		SearchTree(p->right, name);
	else if (strcmp(p->champ.name, name) > 0)
		SearchTree(p->left, name);
	else if (strcmp(p->champ.name, name) == 0)
	{
		printf("(FIND)%s %s %d %d %d\n", p->champ.position, p->champ.name, p->champ.hp, p->champ.attack, p->champ.defend);
		return;
	}
}

int DeleteSearch(BT*p, char name[20])
{
	if (p == NULL)
		return 0;
	if (strcmp(p->champ.name, name) < 0)
		DeleteSearch(p->right, name);
	else if (strcmp(p->champ.name, name) > 0)
		DeleteSearch(p->left, name);
	else if (strcmp(p->champ.name, name) == 0)
		return 1;
}

void PrintTree(BT* p)
{
	static int count = 0;
	if (p == NULL)
		return;
	++count;
	PrintTree(p->left);
	if(count % 10000 == 0)
		printf("%s %s %d %d %d\n", p->champ.position, p->champ.name, p->champ.hp, p->champ.attack, p->champ.defend);
	PrintTree(p->right);
}

void SortTree(BT*p)
{
	if (p == NULL)
		return;
	SortTree(p->left);
	//
	SortTree(p->right);
}

BT*FindTree(BT*p)
{
	if (p == NULL)
		return NULL;
	else if (p->left == NULL)
		return p;
	else
		return FindTree(p->left);
}

BT* DeleteTree(BT*parent, BT* p, char name[20])
{
	BT*Delete = NULL;
	if (p == NULL)
	{
		printf("삭제할 정보가 없습니다\n");
		return NULL;
	}
	else
	{
		if (strcmp(p->champ.name, name) < 0)
			Delete = DeleteTree(p, p->right, name);

		else if (strcmp(p->champ.name, name) > 0)
			Delete = DeleteTree(p, p->left, name);

		else if (strcmp(p->champ.name, name) == 0)
		{
			Delete = p;

			if (p->left == NULL && p->right == NULL)
			{
				if (parent->left == p)
					parent->left = NULL;
				else if (parent->right == p)
					parent->right = NULL;
			}
			else if (p->left != NULL && p->right != NULL)
			{
				BT*link = FindTree(p->right);
				link = DeleteTree(NULL, p, link->champ.name);
				p->champ = link->champ;
			}
			else
			{
				BT*link = NULL;

				if (p->left != NULL)
					link = p->left;
				else if (p->right != NULL)
					link = p->right;

				if (parent->left == p)
					parent->left = link;
				else if (parent->right == p)
					parent->right = link;
			}
		}
	}
	return Delete;
}

int main()
{
	clock_t start, end;
	double ssort, btsearch, btinsert, btdelete, btprint, btsort;

	char name[20] = "T209536035";

	slopen();
	start = clock();
	slsort(slhead, NULL);
	end = clock();
	ssort = (end - start) / CLOCKS_PER_SEC;
	freesl();

	maketree();
	printf("트리완성\n");

	start = clock();
	SearchTree(root, name);
	end = clock();
	btsearch = (end - start) / CLOCKS_PER_SEC;// 검색

	Champ *newchamp = (Champ*)malloc(sizeof(Champ));
	printf("INSERT 부분 정보 입력\n");
	printf("POSITION: ");
	gets_s(newchamp->position, 15);
	printf("NAME: ");
	gets_s(newchamp->name, 20);
	printf("HP: ");
	scanf("%d", &newchamp->hp);
	printf("ATTACK: ");
	scanf("%d", &newchamp->attack);
	printf("DEFEND: ");
	scanf("%d", &newchamp->defend);

	start = clock();
	if (DeleteSearch(root, newchamp->name) == 1)
	{
		printf("이미 있는 정보입니다.\n");
	}
	else
	{
		InsertTree(root, *newchamp);
		printf("정보 입력 성공\n");
	}
	end = clock();
	btinsert= (end - start) / CLOCKS_PER_SEC;//삽입

	start = clock();
	DeleteTree(NULL, tree, name);
	end = clock();
	btdelete = (end - start) / CLOCKS_PER_SEC;//삭제


	start = clock();
	PrintTree(root);
	end = clock();
	btprint= (end - start) / CLOCKS_PER_SEC;//출력

	start = clock();
	SortTree(root);
	end = clock();
	btsort = (end - start) / CLOCKS_PER_SEC;//정렬

	printf("SL 정렬시간: %f\n",ssort);
	printf("트리 검색시간: %f\n",btsearch);
	printf("트리 정보 입력시간: %f\n",btinsert);
	printf("트리 정보 삭제시간: %f\n",btdelete);
	printf("트리 출력시간: %f\n",btprint);
	printf("트리 정렬시간: %f\n",btsort);
}