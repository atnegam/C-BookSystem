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
		cout << "暂无用户信息" << endl;
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
	cout << "请输入用户姓名：";
	getchar();
	getline(cin, pnew->name);
	cout << "请输入性别：";
	getline(cin, pnew->sex);
	cout << "请输入年龄：";
	getline(cin, pnew->old);
	cout << "请输入电话：";
	getline(cin, pnew->tel);
	cout << "请输入密码：";
	getline(cin, pnew->pwd);
	insert->next = pnew;
	cout << "恭喜你！注册成功" << endl;
}



bool User::Userlogin(){
	getchar();
	string s1, s2;
	cout << "用户名：" << endl;
	getline(cin,s1);
	cout << "密码：" << endl;
	getline(cin,s2);
	Nuser* pserch = head;
	while (pserch->next != NULL && pserch->next->name != s1)
	{
		pserch = pserch->next;
	}
	if ((pserch->next != NULL) && (s2 == pserch->next->pwd)){
		cout << "登录成功！" << endl;
		return true;
	}
	else{
		cout << "登录失败！"<< endl;
		return false;
	}

}