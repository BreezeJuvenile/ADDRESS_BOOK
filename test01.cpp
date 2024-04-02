/*简易版通讯录管理系统*/
#include<iostream>
#include<string>
#define MAX 1000

using namespace std;

struct contactman  //定义联系人结构体
{
	string name;
	string sex;
	int age;
	long long phone;
	string adress;
};

struct AddressBook  //通讯录结构体  便于维护，增强可拓展性
{
	struct contactman Array[MAX];
	int m_size;
};

void showmenu(); //主界面函数声明
void Addperson(struct AddressBook* abs);   //添加联系人函数声明
void Display(struct AddressBook* abs);		//显示联系人函数声明
int testPersonExit(struct AddressBook* abs,string ModifyPerson);    //检测联系人是否存在函数声明
void Modify(struct AddressBook* abs);  //修改联系人函数声明
void DeletePerson(struct AddressBook* abs);  //删除联系人函数声明
void SearchPerson(struct AddressBook* abs);    //查找联系人函数声明
void ClearPerson(struct AddressBook* abs);    //清空联系人函数声明

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


void showmenu()  //定义主页面函数
{
	cout << "       <--欢迎来到通讯录管理系统-->         " << endl;
	cout << "**Welcome to AdsressBook ManagementSystem!**\n" << endl;
	cout << "       ***************************          " << endl;
	cout << "       ****** 1、添加联系人 ******          " << endl;
	cout << "       ****** 2、显示联系人 ******          " << endl;
	cout << "       ****** 3、修改联系人 ******          " << endl;
	cout << "       ****** 4、删除联系人 ******			 " << endl;
	cout << "       ****** 5、查找联系人 ******			 " << endl;
	cout << "       ****** 6、清空联系人 ******			 " << endl;
	cout << "       ****** 0、退出通讯录 ******			 " << endl;
	cout << "       ***************************			 " << endl;
	cout << "\n请按0-6数字键选择相应功能：";
}

void Addperson(struct AddressBook* abs)  //定义添加联系人函数
{
	if (abs->m_size >= MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
	}
	else
	{
		string name;
		//姓名
		cout << "请输入姓名：";
		cin >> name;
		abs->Array[abs->m_size].name = name;

		//性别
		string sex;
		cout << "请输入性别(男/女)：";
		while (true)
		{
			cin >> sex;
			if (sex == "男" || sex == "女")
			{
				abs->Array[abs->m_size].sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！"<<endl;			
		}

		//年龄
		int age;
		cout << "请输入年龄：";
		cin >> age;
		abs->Array[abs->m_size].age = age;
		
		//联系电话
		long long phone;
		cout << "请输入电话号码：";
		cin >> phone;
		abs->Array[abs->m_size].phone = phone;
		 
		//联系地址
		string address;
		cout << "请输入地址：";
		cin >> address;
		abs->Array[abs->m_size].adress = address;
		
		//更新通讯录联系人的人数
		abs->m_size++;

		cout << "添加成功！" << endl;
	}
	system("pause");  //暂停
	system("cls");   //清屏操作
}

void Display(struct AddressBook* abs)  //定义显示联系人函数
{
	int i;
	if (abs->m_size == 0)
	{
		cout << "暂未添加任何联系人！\n" << endl;
	}
	else
	{
		cout << "下面是您添加的所有联系人：\n" << endl;
		for (i = 0; i < (abs->m_size); i++)
		{
			cout << "姓名："
				<< abs->Array[i].name
				<< "\t性别：" << abs->Array[i].sex
				<< "\t年龄：" << abs->Array[i].age
				<< "\t    联系电话：" << abs->Array[i].phone
				<< "\t    家庭地址：" << abs->Array[i].adress << endl;
		}
	}
	
	system("pause");
	system("cls");
}

int testPersonExit(struct AddressBook* abs,string ModifyPerson)  //检测联系人是否存在
{
	int i;
	for (i = 0; i < (abs->m_size); i++)
	{
		if (abs->Array[i].name == ModifyPerson)
		{
			//若存在联系人则flag等于联系人下标
			return i;
		}
	}
	return -1;
}

void Modify(struct AddressBook* abs)    //定义修改函数
{
	string ModifyName,M0difySex,ModifyAddress;
	int ModifyAge = 0;
	long long ModifyPhone = 0;
	if (abs->m_size == 0)
	{
		cout << "无法修改，通讯录暂无联系人信息！" << endl;
	}
	else
	{
		cout << "请输入姓名：";
		cin >> ModifyName;
		int ret = testPersonExit(abs, ModifyName);
		if (ret != -1)
		{
			//姓名
			abs->Array[ret].name = ModifyName;
			//性别
			cout << "请输入性别(男/女)：";
			cin >> M0difySex;
			abs->Array[ret].sex = M0difySex;
			//年龄
			cout << "请输入年龄：";
			cin >> ModifyAge;
			abs->Array[ret].age = ModifyAge;
			//联系电话
			cout << "请输入电话号码：";
			cin >> ModifyPhone;
			abs->Array[ret].phone = ModifyPhone;
			//联系地址
			cout << "请输入地址：";
			cin >> ModifyAddress;
			abs->Array[ret].adress = ModifyAddress;

			cout << "\n修改成功！" << endl;
		}
		else
		{
			cout << "该联系人不存在！" << endl;
		}
	}
	
	system("pause");
	system("cls");
}

void DeletePerson(struct AddressBook* abs)  //定义删除函数
{
	if (abs->m_size == 0)
	{
		cout << "无法删除，通讯录暂无联系人信息！" << endl;
	}
	else
	{
		string DeleteName;
		cout << "请输入您想删除的联系人：" << endl;
		cin >> DeleteName;
		int ret = testPersonExit(abs, DeleteName);  //检测是否存在
	
		if (ret != -1)
		{
			int i;
			for (i = ret; i < abs->m_size; i++)
			{
				abs->Array[i] = abs->Array[i + 1];
				abs->m_size--;                       //将数据前移(赋值操作)覆盖需要删除项即可
			}
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "该联系人不存在！" << endl;
		}
	}
	system("pause");
	system("cls");
}

void SearchPerson(struct AddressBook* abs)  //定义查找联系人函数
{
	if (abs->m_size == 0)
	{
		cout << "无法查找，通讯录暂无联系人信息！" << endl;
	}
	else
	{
		string SearchName;
		cout << "请输入您想查找的联系人："<<endl;
		cin >> SearchName;
		int ret = testPersonExit(abs, SearchName);
		if (ret != -1)
		{
			cout << "查找成功！" << endl;
			cout << "姓名："<< abs->Array[ret].name
				<< "\t性别：" << abs->Array[ret].sex
				<< "\t年龄：" << abs->Array[ret].age
				<< "\t    联系电话：" << abs->Array[ret].phone
				<< "\t    家庭地址：" << abs->Array[ret].adress << endl;
		}
		else
		{
		cout << "该联系人不存在！" << endl;
		}

	}
	system("pause");
	system("cls");
}

void ClearPerson(struct AddressBook* abs)
{
	if (abs->m_size == 0)
	{
		cout << "通讯录空白，暂无联系人信息！" << endl;
	}
	else
	{
		int select = 0;
		cout << "您的通讯录中可能含很多重要联系人，您真的要清空通讯录吗？" << endl;
		cout << "确定删除[输1]/再考虑一下[输其他数字]:" << endl;
		cin >> select;
		if (select == 1)
		{
			abs->m_size = 0;    //逻辑上清空
			cout << "通讯录已清空！" << endl;
		}
		cout << "已退出清空选项" << endl;
	}
	system("pause");
	system("cls");
}
