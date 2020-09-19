/*
	by yhonker 
	2018
	Dev-C++
	Random code problem, open it with dev, Try. 
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *Username;
typedef struct user{
	char *U_ser;
	char *Sex;
	char *Old;
	char *Tel;
	char *Pass;
	struct user *next; 
}*User,NUser;//用户链表 


typedef struct book{
	char *Bianhao;
	char *Bname;
	char *Zname;
	char *Press;
	struct book* next;
}*Book,NBook;//书籍链表 

int caidan1(){
	int n;
	printf("\t-----------------------\n");
	printf("\t欢迎进入阳光图书管理系统 \n");
	printf("\t-----------------------\n");
	printf("1.管理员登录 2.用户登录 3.注册 4.退出\n");
	printf("请选择：");
	scanf("%d",&n);
	return n;
}//菜单一 ：首页菜单 

int caidan2(){
	getchar();
	int n;
	printf("\t-----------\n");
	printf("\t欢迎管理员\n");
	printf("\t-----------\n");
	printf("1.查看所有图书 2.添加图书 3.注销图书 4.管理用户 5.图书查询(借阅)6.返回主菜单\n");
	printf("请选择：");
	scanf("%d",&n);
	return n;
} //菜单二：管理员菜单 

int caidan3(){
	int n;
	printf("\t----------\n");
	printf("\t欢迎用户\n");
	printf("\t----------\n");
	printf("1.显示所有图书 2.搜索借阅图书 3.个人管理 4.返回主菜单\n");
	printf("请选择：\n");
	scanf("%d",&n);
	return n;
}//菜单三：用户菜单 

void Showbook(Book head)
{
	if (head->next==NULL) {
		printf("\t没有图书信息\n");
	}
	else{
	
    		printf("\t(图书信息如下):\n");
    		Book pshow = head;
    		printf("\t-------------------------------------------------------------------\n");
    		printf("\t编号\t\t书名\t\t作者\t\t出版社\n");
    		printf("\t-------------------------------------------------------------------\n");
    		while((pshow->next) != NULL)
    		{
        		printf("\t%s ", pshow->next->Bianhao);
        		printf("\t\t%s", pshow->next->Bname);
        		printf("\t\t%s", pshow->next->Zname);
        		printf("\t\t%s", pshow->next->Press);
        		printf("\n");
        		pshow = pshow->next;
    		}
    }
    	printf("\t查看完成\n");
}

void Showuser(User head)
{
	if (head->next==NULL) printf("\t*暂无普通用户信息*\n");
	else{
	
    		printf("遍历结果为:\n");
    		User pshow = head;
    		printf("\t-------------------------------------------------------------------\n");
    		printf("\t姓名\t\t性别\t\t年龄\t\t电话\n");
    		printf("\t-------------------------------------------------------------------\n");
    		while((pshow->next) != NULL)
    		{
        		printf("\t%s ", pshow->next->U_ser);
        		printf("\t\t%s", pshow->next->Sex);
        		printf("\t\t%s", pshow->next->Old);
        		printf("\t\t%s", pshow->next->Tel);
        		printf("\n");
        	
        		pshow = pshow->next;
    		}
    }
    	printf("\t查看完成\n");
}//打印用户模块 

void Useradd(User head){
	int pos=1;
    User padd = head;
    for(int i=1;i<pos;i++){
        padd = padd->next;
    }
    User pnew = (User)malloc(sizeof(NUser));
    printf("您的姓名：");
    pnew->U_ser=(char*)malloc(sizeof(char)*20);
    scanf("%s",pnew->U_ser);
    getchar();
    printf("性别：");
    pnew->Sex=(char*)malloc(sizeof(char)*2);
    scanf("%s",pnew->Sex);
    getchar();
    printf("年龄：");
    pnew->Old=(char*)malloc(sizeof(char)*5);
    scanf("%s",pnew->Old);
    getchar();
    printf("联系电话：");
    pnew->Tel=(char*)malloc(sizeof(char)*20);
    scanf("%s",pnew->Tel);
    getchar();
    printf("注册密码：");
    pnew->Pass=(char*)malloc(sizeof(char)*20);
    scanf("%s",pnew->Pass);
    pnew->next = padd->next;
    padd->next = pnew;
    printf("注册成功\n");
    	
 }//用户注册模块
  
void Bookadd(Book head){
	int pos=1;
    Book padd = head;
    for(int i=1;i<pos;i++){
        padd = padd->next;
    }
    Book pnew = (Book)malloc(sizeof(NBook));
    printf("请输入书编号：");
    pnew->Bianhao=(char*)malloc(sizeof(char)*20);
    scanf("%s",pnew->Bianhao);
    getchar();
    printf("请输入书名：");
    pnew->Bname=(char*)malloc(sizeof(char)*20);
    scanf("%s",pnew->Bname);
    getchar();
    printf("请输入书作者：");
    pnew->Zname=(char*)malloc(sizeof(char)*20);
    scanf("%s",pnew->Zname);
    getchar();
    printf("请输入书籍出版社：");
    pnew->Press=(char*)malloc(sizeof(char)*50);
    scanf("%s",pnew->Press);
    getchar();
    pnew->next = padd->next;
    padd->next = pnew;
    printf("添加成功\n");
 }//添加书籍模块 
 
void Delbook(Book head)
{
		char* s1=(char*)malloc(sizeof(char)*20);
		printf("请输入要删除书名：\n");
		scanf("%s",s1);
        Book pdel = head;
        while(strcmp((pdel->next->Bname), s1) != 0 && pdel->next!=NULL){
            pdel = pdel->next;
        }   
        if(pdel->next!=NULL){
            Book pnext = pdel->next->next;
            free(pdel->next);
            pdel->next = pnext;
            printf("\t删除完成\n"); 
        }
        else{
        	printf("无此书\n");
		}
    
}//注销书籍模块 

void Seachbook(Book head)
{
		char* s1=(char*)malloc(sizeof(char)*20);
		printf("请输入要搜索借阅图书书名：\n");
		scanf("%s",s1);
        Book pseach = head;
        while(strcmp((pseach->next->Bname), s1) != 0 && pseach->next!=NULL){
            pseach = pseach->next;
        }
		if (pseach->next==NULL){
        	printf("没有找到 %s \n",s1);
		}   
        else{
        	printf("已找到书籍 %s \n", s1);
        	printf("\t%s ", pseach->next->Bianhao);
        	printf("\t\t%s", pseach->next->Bname);
        	printf("\t\t%s", pseach->next->Zname);
        	printf("\t\t%s", pseach->next->Press);
        	printf("\n");
        }
         
}//搜索书籍模块 

void Userfind(User head)
{
        User pfind = head;
        while(strcmp(pfind->next->U_ser, Username) != 0 && pfind->next!=NULL){
            pfind = pfind->next;
        }
        
		if (pfind->next==NULL)
			printf("未找到该用户\n");   
        else{
        	printf("\t-------------------------------------------------------------------\n");
    		printf("\t姓名\t\t性别\t\t年龄\t\t电话\n");
    		printf("\t-------------------------------------------------------------------\n");
        	printf("\t%s ", pfind->next->U_ser);
        	printf("\t\t%s", pfind->next->Sex);
        	printf("\t\t%s", pfind->next->Old);
        	printf("\t\t%s", pfind->next->Tel);
        	printf("\n");
        	     	
        }

}//搜索用户模块 

int Ture(User head, char* s1, char* s2)
{
        User pture = head;
        while((strcmp(pture->next->U_ser, s1) && strcmp(pture->next->Pass, s2))!= 0 && pture->next!=NULL){
            pture = pture->next;
        }
        
		if (pture->next==NULL)
			return 0; 
        else{
        	Username=pture->next->U_ser;
        	return 1;       	
        }

}//用户校验模块 



int isture(char a[], char b[], int n,User head)  
{
	if(n==1){
		if (strcmp(a, "yhonker") == 0 && strcmp(b, "yhonker") == 0)//管理员校验 
		{
			return 1;
		}
		else
		{
			printf("账号密码出错，自动退出！\n"); 
			exit(0);
		}
	}	
	else if(n==2){
		if(Ture(head,a,b))//用户校验 
		{
			return 2; 
		}
		else
		{
			printf("账号密码出错，自动退出！\n");
			exit(0);	
		}
	}
	else exit(0); 
}//账号密码校验模块 


int Login(int n,User head){
	char s1[20];
	char s2[20];
	if(n==1){
		printf("请输入管理员账号名：");
		scanf("%s",s1);
		printf("请输入密码：");
		scanf("%s",s2);
		return isture(s1,s2,n,head);
	}
	else if(n==2){
		
		printf("请输入用户名：");
		scanf("%s",s1);
		printf("请输入密码：");
		scanf("%s",s2); 
		return isture(s1,s2,n,head);
	}
	else{
		exit(0);
	}
}//登录模块 


 
int main(int argc, char *argv[]) {
	int n1,n2,n3;
	Book blist=(Book)malloc(sizeof(NBook));//初始化书籍表 
	blist->next=NULL;
	User ulist=(User)malloc(sizeof(NUser));//初始化用户表 
	ulist->next=NULL;
	while(n1=caidan1()){
		if(n1==3){//菜单一序号3跳转注册模块 
			printf("\t欢迎注册本软件\n"); 
			Useradd(ulist);
		}
		else{
			Login(n1,ulist);
			if(n1==1){//菜单二序号1管理员登录 
				n2=caidan2();
				while(n2){//n2=管理员菜单序号 
					switch(n2){
						case 1:
							Showbook(blist);//列出书籍信息 
							break;
						case 2:
							Bookadd(blist);//添加书籍信息 
							break;
						case 3:
							Delbook(blist);//删除书籍信息 
							break;
						case 4:
							Showuser(ulist);//列出用户信息 
							break;
						case 5:
							Seachbook(blist);//搜索书籍信息 
							break;
						case 6:
							break;
						default:
							break;
					}
					printf("是否继续显示菜单(1确定 0退出)：");
					scanf("%d", &n3);
					if(n3==1){
						n2=caidan2();
					}
					else if(n3==0){
						break; 
					}
				}
			}
			else if(n1==2){	//菜单一序号2用户登录		
				n2=caidan3();
					while(n2){
						switch(n2){
							case 1:
								Showbook(blist);//列出书籍信息  
								break;
							case 2:
								Seachbook(blist);//搜索书籍信息 
								break;
							case 3:
								Userfind(ulist);
								break;	
							case 4:
								break;
							default:break;
						}
						printf("继续进入菜单(1确定 0退出)：");
						scanf("%d", &n3);
						if(n3==1){
							n2=caidan3();
						}
						else if(n3==0){
							break;
						}
				}
			}
			else{
				continue;
			}
	}
}
 
	getchar();
	return 0;
}
