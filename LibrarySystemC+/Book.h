#pragma  once
#include <iostream>
#include <cstring>
using namespace std;

class Book{
public:
	struct Nbook
	{
		string book_number;
		string book_name;
		string book_author;
		string book_concern;
		string book_surplus;

		Nbook* next;
	};
	Nbook* head;
	Book();
	~Book();
	void CreateNode();//�����ձ�ͷ
	void ShowBook(); //��ӡͼ����Ϣ
	void AddBook();//���ͼ��
	void DelBook();//ɾ��ͼ��
	void SeacheBook();//����ͼ��

};