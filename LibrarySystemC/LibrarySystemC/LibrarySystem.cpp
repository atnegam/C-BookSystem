#pragma warning( disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *Name;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char ch[2];
typedef struct nbook{
	char *num;
	char *name;
	char *zname;
	char *cbs;
	struct nbook* Next;
}*book, Nbook; //�鼮Book

typedef struct nuser{
	char *uname;
	char *sex;
	char *old;
	char *tel;
	char *pwd;
	struct nuser *Next;
}*user, Nuser; //�û�User


void showall(book pHead)
{
	if (pHead->Next == NULL) printf("\t*�����鼮��Ϣ*\n");
	else{

		printf("�������Ϊ:\n");
		book pTra = pHead;
		printf("\t-------------------------------------------------------------------\n");
		printf("\t���\t\t����\t\t����\t\t������\n");
		printf("\t-------------------------------------------------------------------\n");
		while ((pTra->Next) != NULL)
		{
			printf("\t%s ", pTra->Next->num);
			printf("\t\t%s", pTra->Next->name);
			printf("\t\t%s", pTra->Next->zname);
			printf("\t\t%s", pTra->Next->cbs);
			printf("\n");

			pTra = pTra->Next;
		}
	}
	printf("\t*�鿴���*\n");
}

void showuser(user pHead)
{
	if (pHead->Next == NULL) printf("\t*������ͨ�û���Ϣ*\n");
	else{

		printf("�������Ϊ:\n");
		user pTra = pHead;
		printf("\t-------------------------------------------------------------------\n");
		printf("\t����\t\t�Ա�\t\t����\t\t�绰\n");
		printf("\t-------------------------------------------------------------------\n");
		while ((pTra->Next) != NULL)
		{
			printf("\t%s ", pTra->Next->uname);
			printf("\t\t%s", pTra->Next->sex);
			printf("\t\t%s", pTra->Next->old);
			printf("\t\t%s", pTra->Next->tel);
			printf("\n");

			pTra = pTra->Next;
		}
	}
	printf("\t*�鿴���*\n");
}

void Adduser(user pHead)
{
	int pos = 1;
	if (pos<1){
		printf("error\n");
	}
	else{
		user pInsert = pHead;
		for (int i = 1; i<pos; i++){
			pInsert = pInsert->Next;
		}

		user pNew = (user)malloc(sizeof(Nuser));
		printf("������������\n");
		pNew->uname = (char*)malloc(sizeof(char)* 50);
		scanf("%s", pNew->uname);
		getchar();
		printf("�������Ա�\n");
		pNew->sex = (char*)malloc(sizeof(char)* 2);
		scanf("%s", pNew->sex);
		getchar();
		printf("���������䣺\n");
		pNew->old = (char*)malloc(sizeof(char)* 5);
		scanf("%s", pNew->old);
		getchar();
		printf("������绰��\n");
		pNew->tel = (char*)malloc(sizeof(char)* 20);
		scanf("%s", pNew->tel);
		getchar();
		printf("���������룺\n");
		pNew->pwd = (char*)malloc(sizeof(char)* 20);
		scanf("%s", pNew->pwd);
		pNew->Next = pInsert->Next;
		pInsert->Next = pNew;
		printf("��ӳɹ�\n");
	}
}
void Addbook(book pHead)
{
	int pos = 1;
	if (pos<1){
		printf("error\n");
	}
	else{
		book pInsert = pHead;
		for (int i = 1; i<pos; i++){
			pInsert = pInsert->Next;
		}

		book pNew = (book)malloc(sizeof(Nbook));
		printf("���������ţ�\n");
		pNew->num = (char*)malloc(sizeof(char)* 20);
		scanf("%s", pNew->num);
		getchar();
		printf("������������\n");
		pNew->name = (char*)malloc(sizeof(char)* 50);
		scanf("%s", pNew->name);
		getchar();
		printf("�����������ߣ�\n");
		pNew->zname = (char*)malloc(sizeof(char)* 50);
		scanf("%s", pNew->zname);
		getchar();
		printf("�������鼮�����磺\n");
		pNew->cbs = (char*)malloc(sizeof(char)* 50);
		scanf("%s", pNew->cbs);
		getchar();
		pNew->Next = pInsert->Next;
		pInsert->Next = pNew;
		printf("��ӳɹ�\n");
	}
}

void del(book pHead)
{
	char* s = (char*)malloc(sizeof(char)* 50);
	printf("������Ҫɾ��������\n");
	scanf("%s", s);
	book pDel = pHead;
	while (strcmp((pDel->Next->name), s) != 0 && pDel->Next != NULL){
		pDel = pDel->Next;
	}
	if (pDel->Next != NULL){
		book pNext = pDel->Next->Next;
		free(pDel->Next);
		pDel->Next = pNext;
		printf("/tɾ�����\n");
	}
	else{
		printf("�޴���\n");
	}

}
void seachbname(book pHead)
{
	char* s = (char*)malloc(sizeof(char)* 50);
	printf("������Ҫ��������ͼ��������\n");
	scanf("%s", s);
	book pDel = pHead;
	while (strcmp((pDel->Next->name), s) != 0 && pDel->Next != NULL){
		pDel = pDel->Next;
	}
	if (pDel->Next == NULL){
		printf("û���ҵ�<< %s >>\n", s);
	}
	else{
		printf("���ҵ��鼮<< %s >>\n", s);
		printf("\t%s ", pDel->Next->num);
		printf("\t\t%s", pDel->Next->name);
		printf("\t\t%s", pDel->Next->zname);
		printf("\t\t%s", pDel->Next->cbs);
		printf("\n");
	}


}

void seachzname(book pHead)
{
	char* s = (char*)malloc(sizeof(char)* 50);
	printf("������Ҫ��������ͼ����������\n");
	scanf("%s", s);
	book pDel = pHead;
	while (strcmp((pDel->Next->zname), s) != 0 && pDel->Next != NULL){
		pDel = pDel->Next;
	}

	if (pDel->Next == NULL){
		printf("û���ҵ��������\n");
	}
	else{
		printf("���ҵ��������* %s *\n", s);
		printf("\t%s ", pDel->Next->num);
		printf("\t\t%s", pDel->Next->name);
		printf("\t\t%s", pDel->Next->zname);
		printf("\t\t%s", pDel->Next->cbs);
		printf("\n");
	}

}

void seacher(book pHead)
{
	int n;
	printf("\t--------------------------------\n");
	printf("\t1.���������� \t2.�����߲���\n");
	printf("\t---------------------------------\n");
	printf("��ѡ��");
	scanf("%d", &n);
	if (n == 1){
		seachbname(pHead);
	}
	else if (n == 2){
		seachzname(pHead);
	}
	else {
		printf("�˳�\n");
	}
}

int userture(user pHead, char* s1, char* s2)
{
	user pDel = pHead;
	while ((strcmp(pDel->Next->uname, s1) && strcmp(pDel->Next->pwd, s2)) != 0 && pDel->Next != NULL){
		pDel = pDel->Next;
	}

	if (pDel->Next == NULL){
		return 0;
	}
	else{
		Name = pDel->Next->uname;
		return 1;
	}

}

void finduser(user pHead)
{
	user pDel = pHead;
	while (strcmp(pDel->Next->uname, Name) != 0 && pDel->Next != NULL){
		pDel = pDel->Next;
	}

	if (pDel->Next == NULL){
		printf("error\n");
	}
	else{
		printf("\t%s ", pDel->Next->uname);
		printf("\t\t%s", pDel->Next->sex);
		printf("\t\t%s", pDel->Next->old);
		printf("\t\t%s", pDel->Next->tel);
		printf("\n");

	}

}

int isture(char a[], char b[], int n, user pHead)
{
	if (n == 1){
		if (strcmp(a, "admin") == 0 && strcmp(b, "password") == 0)
		{
			return 1;
		}
		else
		{
			printf("�Ƿ���¼���Զ��˳�\n");
			exit(0);
		}
	}
	else if (n == 2){
		if (userture(pHead, a, b))
		{
			return 2;
		}
		else
		{
			printf("�Ƿ���¼���Զ��˳�");
			exit(0);
		}
	}
	else exit(0);
}


int denglu(int n, user pHead){
	char a[50];
	char b[50];
	if (n == 1){

		printf("����Ա�˺�����");
		scanf("%s", a);
		printf("\n");
		printf("���룺");
		scanf("%s", b);
		return isture(a, b, n, pHead);
	}
	else if (n == 2){

		printf("�û�����");
		scanf("%s", a);
		printf("���룺");
		scanf("%s", b);
		return isture(a, b, n, pHead);
	}
	else{
		exit(0);
	}
}

int printmenu1(){
	int n1;
	printf("��ӭʹ��ͼ�����ϵͳ\n");
	printf("\t-------------------------------------------------------------------\n");
	printf("\t              1.����Ա��¼                  2.�û���¼             |\n");
	printf("\t              3.�û�ע��                    4.�˳�                 |\n");
	printf("\t-------------------------------------------------------------------|\n");
	printf("��ѡ��");
	scanf("%d", &n1);
	return n1;
}

int adminmenu(){
	getchar();
	int n2;
	printf("\t********************    ��ӭ����Ա   ********************************\n");
	printf("\n");
	printf("\t -------------------------------------------------------------------\n");
	printf("\t|         1.��ʾ����ͼ��                 2.���ͼ��                 |\n");
	printf("\t|         3.ɾ��ͼ��                     4.��ʾ�����û�             |\n");
	printf("\t|         5.�������˵�     										  |\n");
	printf("\t -------------------------------------------------------------------\n");
	printf("��ѡ��");
	scanf("%d", &n2);
	return n2;
}

int usermenu(){
	int n2;
	printf("\t********************      ��ӭ�û�    ******************************\n");
	printf("\n");
	printf("\t--------------------------------------------------------------------\n");
	printf("\t         1.��ʾ����ͼ��                 2.��������ͼ��             |\n");
	printf("\t         3.������Ϣ                     4.�˳�                     |\n");
	printf("\t                  										         |\n");
	printf("\t--------------------------------------------------------------------\n");
	printf("��ѡ��");
	scanf("%d", &n2);
	return n2;
}

int main(int argc, char *argv[]) {
	int n1, n2;
	char n3;
	book blist = (book)malloc(sizeof(Nbook));
	blist->Next = NULL;
	user ulist = (user)malloc(sizeof(Nuser));
	ulist->Next = NULL;
	while (1){
		n1 = printmenu1();
		if (n1 == 3){
			printf("ok\n");
			Adduser(ulist);
			continue;
		}
		else{
			denglu(n1, ulist);
			if (n1 == 1){
				n2 = adminmenu();
				while (n2){
					switch (n2){
					case 1:
						showall(blist);
						break;
					case 2:
						Addbook(blist);
						break;
					case 3:
						del(blist);
						break;
					case 4:
						showuser(ulist);
						break;
					case 5:
						break;
					default:
						break;
					}
					printf("�Ƿ������ʾ�˵���1ȷ�� 0�˳�\n");
					scanf("%d", &n3);
					if (n3 == 1){
						n2 = adminmenu();
					}
					else if (n3 == 0){
						continue;
					}
				}
			}
		}
				else if (n1 == 2){
					n2 = usermenu();
					while (n2){
						switch (n2){
						case 1:
							showall(blist);
							break;
						case 2:
							seacher(blist);
							break;
						case 3:
							finduser(ulist);
							break;
						case 4:
							break;
						default:break;
						}
						printf("�Ƿ������ʾ�˵���1ȷ�� 0�˳�\n");
						scanf("%d", &n3);
						if (n3 == 1){
							n2 = usermenu();
						}
						else if (n3 == 0){
							continue;
						}
					}
				}
				else{
					exit(0);
				}

	}

	getchar();
	return 0;
}
