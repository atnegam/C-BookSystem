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
}*book, Nbook; //书籍Book

typedef struct nuser{
	char *uname;
	char *sex;
	char *old;
	char *tel;
	char *pwd;
	struct nuser *Next;
}*user, Nuser; //用户User


void showall(book pHead)
{
	if (pHead->Next == NULL) printf("\t*暂无书籍信息*\n");
	else{

		printf("遍历结果为:\n");
		book pTra = pHead;
		printf("\t-------------------------------------------------------------------\n");
		printf("\t编号\t\t书名\t\t作者\t\t出版社\n");
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
	printf("\t*查看完成*\n");
}

void showuser(user pHead)
{
	if (pHead->Next == NULL) printf("\t*暂无普通用户信息*\n");
	else{

		printf("遍历结果为:\n");
		user pTra = pHead;
		printf("\t-------------------------------------------------------------------\n");
		printf("\t姓名\t\t性别\t\t年龄\t\t电话\n");
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
	printf("\t*查看完成*\n");
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
		printf("请输入姓名：\n");
		pNew->uname = (char*)malloc(sizeof(char)* 50);
		scanf("%s", pNew->uname);
		getchar();
		printf("请输入性别：\n");
		pNew->sex = (char*)malloc(sizeof(char)* 2);
		scanf("%s", pNew->sex);
		getchar();
		printf("请输入年龄：\n");
		pNew->old = (char*)malloc(sizeof(char)* 5);
		scanf("%s", pNew->old);
		getchar();
		printf("请输入电话：\n");
		pNew->tel = (char*)malloc(sizeof(char)* 20);
		scanf("%s", pNew->tel);
		getchar();
		printf("请输入密码：\n");
		pNew->pwd = (char*)malloc(sizeof(char)* 20);
		scanf("%s", pNew->pwd);
		pNew->Next = pInsert->Next;
		pInsert->Next = pNew;
		printf("添加成功\n");
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
		printf("请输入书编号：\n");
		pNew->num = (char*)malloc(sizeof(char)* 20);
		scanf("%s", pNew->num);
		getchar();
		printf("请输入书名：\n");
		pNew->name = (char*)malloc(sizeof(char)* 50);
		scanf("%s", pNew->name);
		getchar();
		printf("请输入书作者：\n");
		pNew->zname = (char*)malloc(sizeof(char)* 50);
		scanf("%s", pNew->zname);
		getchar();
		printf("请输入书籍出版社：\n");
		pNew->cbs = (char*)malloc(sizeof(char)* 50);
		scanf("%s", pNew->cbs);
		getchar();
		pNew->Next = pInsert->Next;
		pInsert->Next = pNew;
		printf("添加成功\n");
	}
}

void del(book pHead)
{
	char* s = (char*)malloc(sizeof(char)* 50);
	printf("请输入要删除书名：\n");
	scanf("%s", s);
	book pDel = pHead;
	while (strcmp((pDel->Next->name), s) != 0 && pDel->Next != NULL){
		pDel = pDel->Next;
	}
	if (pDel->Next != NULL){
		book pNext = pDel->Next->Next;
		free(pDel->Next);
		pDel->Next = pNext;
		printf("/t删除完成\n");
	}
	else{
		printf("无此书\n");
	}

}
void seachbname(book pHead)
{
	char* s = (char*)malloc(sizeof(char)* 50);
	printf("请输入要搜索借阅图书书名：\n");
	scanf("%s", s);
	book pDel = pHead;
	while (strcmp((pDel->Next->name), s) != 0 && pDel->Next != NULL){
		pDel = pDel->Next;
	}
	if (pDel->Next == NULL){
		printf("没有找到<< %s >>\n", s);
	}
	else{
		printf("已找到书籍<< %s >>\n", s);
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
	printf("请输入要搜索借阅图书作者名：\n");
	scanf("%s", s);
	book pDel = pHead;
	while (strcmp((pDel->Next->zname), s) != 0 && pDel->Next != NULL){
		pDel = pDel->Next;
	}

	if (pDel->Next == NULL){
		printf("没有找到相关作者\n");
	}
	else{
		printf("已找到相关作者* %s *\n", s);
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
	printf("\t1.按书名查找 \t2.按作者查找\n");
	printf("\t---------------------------------\n");
	printf("请选择：");
	scanf("%d", &n);
	if (n == 1){
		seachbname(pHead);
	}
	else if (n == 2){
		seachzname(pHead);
	}
	else {
		printf("退出\n");
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
			printf("非法登录，自动退出\n");
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
			printf("非法登录，自动退出");
			exit(0);
		}
	}
	else exit(0);
}


int denglu(int n, user pHead){
	char a[50];
	char b[50];
	if (n == 1){

		printf("管理员账号名：");
		scanf("%s", a);
		printf("\n");
		printf("密码：");
		scanf("%s", b);
		return isture(a, b, n, pHead);
	}
	else if (n == 2){

		printf("用户名：");
		scanf("%s", a);
		printf("密码：");
		scanf("%s", b);
		return isture(a, b, n, pHead);
	}
	else{
		exit(0);
	}
}

int printmenu1(){
	int n1;
	printf("欢迎使用图书管理系统\n");
	printf("\t-------------------------------------------------------------------\n");
	printf("\t              1.管理员登录                  2.用户登录             |\n");
	printf("\t              3.用户注册                    4.退出                 |\n");
	printf("\t-------------------------------------------------------------------|\n");
	printf("请选择：");
	scanf("%d", &n1);
	return n1;
}

int adminmenu(){
	getchar();
	int n2;
	printf("\t********************    欢迎管理员   ********************************\n");
	printf("\n");
	printf("\t -------------------------------------------------------------------\n");
	printf("\t|         1.显示所有图书                 2.添加图书                 |\n");
	printf("\t|         3.删除图书                     4.显示所有用户             |\n");
	printf("\t|         5.返回主菜单     										  |\n");
	printf("\t -------------------------------------------------------------------\n");
	printf("请选择：");
	scanf("%d", &n2);
	return n2;
}

int usermenu(){
	int n2;
	printf("\t********************      欢迎用户    ******************************\n");
	printf("\n");
	printf("\t--------------------------------------------------------------------\n");
	printf("\t         1.显示所有图书                 2.搜索借阅图书             |\n");
	printf("\t         3.个人信息                     4.退出                     |\n");
	printf("\t                  										         |\n");
	printf("\t--------------------------------------------------------------------\n");
	printf("请选择：");
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
					printf("是否继续显示菜单：1确定 0退出\n");
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
						printf("是否继续显示菜单：1确定 0退出\n");
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
