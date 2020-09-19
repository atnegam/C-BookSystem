#include "Book.h"
#include "User.h"
#include "Admin.h"
#include "Menu.h"
#include <iostream>

using namespace std;

int main()
{

	Book book;
	book.CreateNode();
	User user;
	user.CreateNode();
	Admin admin;
	Menu menu;
	int T=1, n, N;
	while (T==1)
	{
		N = menu.MainMenu();
		if (N == 1)
		{
			n = admin.Adminlogin();
			while (n)
			{
				switch (menu.AdminMenu()){
				case 1:
					book.ShowBook();
					break;
				case 2:
					book.AddBook();
					break;
				case 3:
					book.DelBook();
					break;
				case 4:
					user.ShowUser();
					break;
				case 5:
					break;
				}
				cout << "0回到主菜单,非0继续！";
				cin >> n;
			}
			continue;
		}
		else if (N == 2)
		{
			n = user.Userlogin();
			while (n)
			{
				switch (menu.UserMenu()){
				case 1:
					book.ShowBook();
					break;
				case 2:
					book.SeacheBook();
					break;
				case 3:
					break;
				}
				cout << "0回到主菜单,非0继续！";
				cin >> n;
			}
			continue;
		}
		else if (N == 3)
		{
			user.AddUser();
			continue;
		}
		else{
			return 0;
		}

	}

	system("pause");
	return 0;
}