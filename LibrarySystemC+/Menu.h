#pragma  once
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Menu{
public:
	Menu();
	~Menu();
	int MainMenu();//打印主菜单
	int AdminMenu();//打印管理员菜单
	int UserMenu();//打印用户菜单


};