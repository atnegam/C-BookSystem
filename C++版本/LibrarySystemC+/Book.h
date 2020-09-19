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
	void CreateNode();//创建空表头
	void ShowBook(); //打印图书信息
	void AddBook();//添加图书
	void DelBook();//删除图书
	void SeacheBook();//搜索图书

};