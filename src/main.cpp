#include<iostream>
#include"function.h"
#include"Person.h"
int main()
{
	int select = 0;
	AddressBook abs;  //定义一个自己的通讯录
	abs.m_size = 0;  //初始化通讯录中联系人的人数
	while (true)
	{
		showmenu();    //显示主界面
		cin >> select;
		cout << "\n";
		switch (select)
		{
			case 1:    //添加联系人
				Addperson(&abs);   //调用添加函数
				break;
			case 2:    //显示
				Display(&abs);  //调用显示函数
				break;
			case 3:    //修改	
				Modify(&abs);    //修改联系人	
				break;
			case 4:    //删除
				DeletePerson(&abs);  //调用删除函数
				break;
			case 5:    //查找
				SearchPerson(&abs);  //调用查找函数
				break;
			case 6:    //清空
				ClearPerson(&abs);  //调用清空函数
				break;
			case 0:    //退出
				system("cls");
				cout << "****** 欢迎下次使用！******" << endl;
				system("pause");
				return 0;
				break;
			default:
				cout << "输入有误！请重新输入" << endl;
				system("pause");
				system("cls");
				break;
		}
	}
	system("pause");
	return 0;
}