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
	void CreateNode();//����userͷ
	void ShowUser();//��ӡ�û��б�
	void AddUser();//ע���û�
	//void ScherUser();//�����û�
	bool Userlogin();//�ж�����
};