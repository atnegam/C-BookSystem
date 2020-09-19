#pragma  once
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class User{
public:
	struct Nuser
	{
		string name;
		string sex;
		string old;
		string tel;
		string pwd;

		Nuser* next;
	};

	Nuser* head;
	User();
	~User();
	void CreateNode();//创建user头
	void ShowUser();//打印用户列表
	void AddUser();//注册用户
	//void ScherUser();//查找用户
	bool Userlogin();//判断密码
};