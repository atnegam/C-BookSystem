#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

Book::Book(){
	
}

Book::~Book(){

}

void Book::CreateNode(){
	head = new Nbook;
	head->next = NULL;
}

void Book::ShowBook(){
	if (head->next == NULL){
		cout << "暂无书籍信息" << endl;
	}
	else{
		Nbook* pshow = head;
		while (pshow->next != NULL)
		{
			pshow = pshow->next;
			cout << "\t----------------------------------------------------------------------------"<<endl;
			cout << "\t编号" << "\t" << "书名" << "\t" << "作者" << "\t" << "出版社" <<"\t"<<"库存"<< endl;
			cout << "\t----------------------------------------------------------------------------" << endl;
			cout <<"\t"<<pshow->book_number<<"\t"<< pshow->book_name<<"\t" <<pshow->book_author<< "\t"<<pshow->book_concern<<"\t"<<pshow->book_surplus<<endl;
		}
	}
}

void Book::AddBook(){
	Nbook* Insert = head;
	while (Insert->next != NULL)
	{
		Insert = Insert->next;
	}
	Nbook* pnew = new Nbook;
	pnew->next = NULL;
	getchar();
	cout << "请录入书编号：";
	getline(cin,pnew->book_number);
	cout << "请录入书名：";
	getline(cin, pnew->book_name);
	cout << "请录入作者名：";
	getline(cin,pnew->book_author);
	cout << "请录入出版社：";
	getline(cin, pnew->book_concern);
	cout << "请录入余量：";
	getline(cin,pnew->book_surplus);
	Insert->next = pnew;
	cout << "录入成功，更新一条信息！"<<endl;

}

void Book::DelBook(){
	getchar();
	string s;
	cout << "请输入要删除的书名：" << endl;
	getline(cin,s);
	Nbook* pdel = head;
	while ((pdel->next != NULL) && (pdel->next->book_name != s))//&&判断顺序为先左
	{
		pdel = pdel->next;
	}
	if (pdel->next != NULL)
	{
		Nbook* pnew = pdel->next->next;
		delete pdel->next;
		pdel->next = pnew;
		cout << "删除完成\n" << endl;
	}
	else{
		cout << "无此书\n" << endl;
	}
}  

void Book::SeacheBook(){
	getchar();
	string s;
	cout << "请输入要搜索的图书名" << endl;
	getline(cin,s);
	Nbook* pserch = head;
	while (pserch->next != NULL && pserch->next->book_name != s)//&&判断顺序为先左
	{
		pserch = pserch->next;
	}
	if (pserch->next != NULL)
	{
		cout << "已找到书籍！"<< endl;
		cout << "\t----------------------------------------------------------------------------" << endl;
		cout << "\t编号" << "\t" << "书名" << "\t" << "作者" << "\t" << "出版社" << "\t" << "库存" << endl;
		cout << "\t----------------------------------------------------------------------------" << endl;
		cout << "\t" << pserch->next->book_number<< "\t" << pserch->next->book_name << "\t" << pserch->next->book_author << "\t" << pserch->next->book_concern << "\t" << pserch->next->book_surplus << endl;
	}
	else
	{
		cout << "没有找到此书！"<<endl;
	}
}

