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
}*User,NUser;//�û����� 


typedef struct book{
	char *Bianhao;
	char *Bname;
	char *Zname;
	char *Press;
	struct book* next;
}*Book,NBook;//�鼮���� 

int caidan1(){
	int n;
	printf("\t-----------------------\n");
	printf("\t��ӭ��������ͼ�����ϵͳ \n");
	printf("\t-----------------------\n");
	printf("1.����Ա��¼ 2.�û���¼ 3.ע�� 4.�˳�\n");
	printf("��ѡ��");
	scanf("%d",&n);
	return n;
}//�˵�һ ����ҳ�˵� 

int caidan2(){
	getchar();
	int n;
	printf("\t-----------\n");
	printf("\t��ӭ����Ա\n");
	printf("\t-----------\n");
	printf("1.�鿴����ͼ�� 2.���ͼ�� 3.ע��ͼ�� 4.�����û� 5.ͼ���ѯ(����)6.�������˵�\n");
	printf("��ѡ��");
	scanf("%d",&n);
	return n;
} //�˵���������Ա�˵� 

int caidan3(){
	int n;
	printf("\t----------\n");
	printf("\t��ӭ�û�\n");
	printf("\t----------\n");
	printf("1.��ʾ����ͼ�� 2.��������ͼ�� 3.���˹��� 4.�������˵�\n");
	printf("��ѡ��\n");
	scanf("%d",&n);
	return n;
}//�˵������û��˵� 

void Showbook(Book head)
{
	if (head->next==NULL) {
		printf("\tû��ͼ����Ϣ\n");
	}
	else{
	
    		printf("\t(ͼ����Ϣ����):\n");
    		Book pshow = head;
    		printf("\t-------------------------------------------------------------------\n");
    		printf("\t���\t\t����\t\t����\t\t������\n");
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
    	printf("\t�鿴���\n");
}

void Showuser(User head)
{
	if (head->next==NULL) printf("\t*������ͨ�û���Ϣ*\n");
	else{
	
    		printf("�������Ϊ:\n");
    		User pshow = head;
    		printf("\t-------------------------------------------------------------------\n");
    		printf("\t����\t\t�Ա�\t\t����\t\t�绰\n");
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
    	printf("\t�鿴���\n");
}//��ӡ�û�ģ�� 

void Useradd(User head){
	int pos=1;
    User padd = head;
    for(int i=1;i<pos;i++){
        padd = padd->next;
    }
    User pnew = (User)malloc(sizeof(NUser));
    printf("����������");
    pnew->U_ser=(char*)malloc(sizeof(char)*20);
    scanf("%s",pnew->U_ser);
    getchar();
    printf("�Ա�");
    pnew->Sex=(char*)malloc(sizeof(char)*2);
    scanf("%s",pnew->Sex);
    getchar();
    printf("���䣺");
    pnew->Old=(char*)malloc(sizeof(char)*5);
    scanf("%s",pnew->Old);
    getchar();
    printf("��ϵ�绰��");
    pnew->Tel=(char*)malloc(sizeof(char)*20);
    scanf("%s",pnew->Tel);
    getchar();
    printf("ע�����룺");
    pnew->Pass=(char*)malloc(sizeof(char)*20);
    scanf("%s",pnew->Pass);
    pnew->next = padd->next;
    padd->next = pnew;
    printf("ע��ɹ�\n");
    	
 }//�û�ע��ģ��
  
void Bookadd(Book head){
	int pos=1;
    Book padd = head;
    for(int i=1;i<pos;i++){
        padd = padd->next;
    }
    Book pnew = (Book)malloc(sizeof(NBook));
    printf("���������ţ�");
    pnew->Bianhao=(char*)malloc(sizeof(char)*20);
    scanf("%s",pnew->Bianhao);
    getchar();
    printf("������������");
    pnew->Bname=(char*)malloc(sizeof(char)*20);
    scanf("%s",pnew->Bname);
    getchar();
    printf("�����������ߣ�");
    pnew->Zname=(char*)malloc(sizeof(char)*20);
    scanf("%s",pnew->Zname);
    getchar();
    printf("�������鼮�����磺");
    pnew->Press=(char*)malloc(sizeof(char)*50);
    scanf("%s",pnew->Press);
    getchar();
    pnew->next = padd->next;
    padd->next = pnew;
    printf("��ӳɹ�\n");
 }//����鼮ģ�� 
 
void Delbook(Book head)
{
		char* s1=(char*)malloc(sizeof(char)*20);
		printf("������Ҫɾ��������\n");
		scanf("%s",s1);
        Book pdel = head;
        while(strcmp((pdel->next->Bname), s1) != 0 && pdel->next!=NULL){
            pdel = pdel->next;
        }   
        if(pdel->next!=NULL){
            Book pnext = pdel->next->next;
            free(pdel->next);
            pdel->next = pnext;
            printf("\tɾ�����\n"); 
        }
        else{
        	printf("�޴���\n");
		}
    
}//ע���鼮ģ�� 

void Seachbook(Book head)
{
		char* s1=(char*)malloc(sizeof(char)*20);
		printf("������Ҫ��������ͼ��������\n");
		scanf("%s",s1);
        Book pseach = head;
        while(strcmp((pseach->next->Bname), s1) != 0 && pseach->next!=NULL){
            pseach = pseach->next;
        }
		if (pseach->next==NULL){
        	printf("û���ҵ� %s \n",s1);
		}   
        else{
        	printf("���ҵ��鼮 %s \n", s1);
        	printf("\t%s ", pseach->next->Bianhao);
        	printf("\t\t%s", pseach->next->Bname);
        	printf("\t\t%s", pseach->next->Zname);
        	printf("\t\t%s", pseach->next->Press);
        	printf("\n");
        }
         
}//�����鼮ģ�� 

void Userfind(User head)
{
        User pfind = head;
        while(strcmp(pfind->next->U_ser, Username) != 0 && pfind->next!=NULL){
            pfind = pfind->next;
        }
        
		if (pfind->next==NULL)
			printf("δ�ҵ����û�\n");   
        else{
        	printf("\t-------------------------------------------------------------------\n");
    		printf("\t����\t\t�Ա�\t\t����\t\t�绰\n");
    		printf("\t-------------------------------------------------------------------\n");
        	printf("\t%s ", pfind->next->U_ser);
        	printf("\t\t%s", pfind->next->Sex);
        	printf("\t\t%s", pfind->next->Old);
        	printf("\t\t%s", pfind->next->Tel);
        	printf("\n");
        	     	
        }

}//�����û�ģ�� 

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

}//�û�У��ģ�� 



int isture(char a[], char b[], int n,User head)  
{
	if(n==1){
		if (strcmp(a, "yhonker") == 0 && strcmp(b, "yhonker") == 0)//����ԱУ�� 
		{
			return 1;
		}
		else
		{
			printf("�˺���������Զ��˳���\n"); 
			exit(0);
		}
	}	
	else if(n==2){
		if(Ture(head,a,b))//�û�У�� 
		{
			return 2; 
		}
		else
		{
			printf("�˺���������Զ��˳���\n");
			exit(0);	
		}
	}
	else exit(0); 
}//�˺�����У��ģ�� 


int Login(int n,User head){
	char s1[20];
	char s2[20];
	if(n==1){
		printf("���������Ա�˺�����");
		scanf("%s",s1);
		printf("���������룺");
		scanf("%s",s2);
		return isture(s1,s2,n,head);
	}
	else if(n==2){
		
		printf("�������û�����");
		scanf("%s",s1);
		printf("���������룺");
		scanf("%s",s2); 
		return isture(s1,s2,n,head);
	}
	else{
		exit(0);
	}
}//��¼ģ�� 


 
int main(int argc, char *argv[]) {
	int n1,n2,n3;
	Book blist=(Book)malloc(sizeof(NBook));//��ʼ���鼮�� 
	blist->next=NULL;
	User ulist=(User)malloc(sizeof(NUser));//��ʼ���û��� 
	ulist->next=NULL;
	while(n1=caidan1()){
		if(n1==3){//�˵�һ���3��תע��ģ�� 
			printf("\t��ӭע�᱾���\n"); 
			Useradd(ulist);
		}
		else{
			Login(n1,ulist);
			if(n1==1){//�˵������1����Ա��¼ 
				n2=caidan2();
				while(n2){//n2=����Ա�˵���� 
					switch(n2){
						case 1:
							Showbook(blist);//�г��鼮��Ϣ 
							break;
						case 2:
							Bookadd(blist);//����鼮��Ϣ 
							break;
						case 3:
							Delbook(blist);//ɾ���鼮��Ϣ 
							break;
						case 4:
							Showuser(ulist);//�г��û���Ϣ 
							break;
						case 5:
							Seachbook(blist);//�����鼮��Ϣ 
							break;
						case 6:
							break;
						default:
							break;
					}
					printf("�Ƿ������ʾ�˵�(1ȷ�� 0�˳�)��");
					scanf("%d", &n3);
					if(n3==1){
						n2=caidan2();
					}
					else if(n3==0){
						break; 
					}
				}
			}
			else if(n1==2){	//�˵�һ���2�û���¼		
				n2=caidan3();
					while(n2){
						switch(n2){
							case 1:
								Showbook(blist);//�г��鼮��Ϣ  
								break;
							case 2:
								Seachbook(blist);//�����鼮��Ϣ 
								break;
							case 3:
								Userfind(ulist);
								break;	
							case 4:
								break;
							default:break;
						}
						printf("��������˵�(1ȷ�� 0�˳�)��");
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
