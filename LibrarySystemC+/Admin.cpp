#include "Admin.h"

Admin::Admin(){
	Admin_name = "admin";
	Admin_pwd = "password";
}

Admin::~Admin(){

}

bool Admin::Adminlogin(){
	string s1, s2;
	cout << "����Ա�˺ţ�" << endl;
	getchar();
	getline(cin,s1);
	cout << "����Ա���룺" << endl;
	getline(cin, s2);
	if (s1==Admin_name && s2==Admin_pwd)
	{
		cout << "��¼�ɹ�����ӭ������Ա��" << endl;
		return true;
	}
	else
	{
		cout << "�˺Ż��������" << endl;
		return false;
	}
}