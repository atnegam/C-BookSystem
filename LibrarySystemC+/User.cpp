#include "User.h"

User::User(){

}

User::~User(){

}

void User::CreateNode(){
	head = new Nuser;
	head->next = NULL;
}

void User::ShowUser(){
	if (head->next == NULL){
		cout << "�����û���Ϣ" << endl;
	}
	else{
		Nuser* pshow = head;
		while (pshow->next != NULL)
		{
			pshow = pshow->next;
			cout << pshow->name << endl;
		}
	}
}

void User::AddUser(){
	Nuser* insert = head;
	while (insert->next != NULL)
	{
		insert = insert->next;
	}
	Nuser* pnew = new Nuser;
	pnew->next = NULL;
	cout << "�������û�������";
	getchar();
	getline(cin, pnew->name);
	cout << "�������Ա�";
	getline(cin, pnew->sex);
	cout << "���������䣺";
	getline(cin, pnew->old);
	cout << "������绰��";
	getline(cin, pnew->tel);
	cout << "���������룺";
	getline(cin, pnew->pwd);
	insert->next = pnew;
	cout << "��ϲ�㣡ע��ɹ�" << endl;
}



bool User::Userlogin(){
	getchar();
	string s1, s2;
	cout << "�û�����" << endl;
	getline(cin,s1);
	cout << "���룺" << endl;
	getline(cin,s2);
	Nuser* pserch = head;
	while (pserch->next != NULL && pserch->next->name != s1)
	{
		pserch = pserch->next;
	}
	if ((pserch->next != NULL) && (s2 == pserch->next->pwd)){
		cout << "��¼�ɹ���" << endl;
		return true;
	}
	else{
		cout << "��¼ʧ�ܣ�"<< endl;
		return false;
	}

}