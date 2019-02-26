#pragma  once
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Admin{
public:
	string Admin_name;
	string Admin_pwd;
	Admin();
	~Admin();
	bool Adminlogin();//¹ÜÀíÔ±µÇÂ¼
};