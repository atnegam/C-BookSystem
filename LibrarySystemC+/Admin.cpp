#include "Admin.h"

Admin::Admin(){
	Admin_name = "admin";
	Admin_pwd = "password";
}

Admin::~Admin(){

}

bool Admin::Adminlogin(){
	string s1, s2;
	cout << "管理员账号：" << endl;
	getchar();
	getline(cin,s1);
	cout << "管理员密码：" << endl;
	getline(cin, s2);
	if (s1==Admin_name && s2==Admin_pwd)
	{
		cout << "登录成功，欢迎您管理员！" << endl;
		return true;
	}
	else
	{
		cout << "账号或密码错误" << endl;
		return false;
	}
}