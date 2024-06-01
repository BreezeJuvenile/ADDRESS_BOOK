#pragma once
#include<iostream>
using namespace std;

void showmenu(); //主界面函数声明
void Addperson(struct AddressBook* abs);   //添加联系人函数声明
void Display(struct AddressBook* abs);		//显示联系人函数声明
int testPersonExit(struct AddressBook* abs,string ModifyPerson);    //检测联系人是否存在函数声明
void Modify(struct AddressBook* abs);  //修改联系人函数声明
void DeletePerson(struct AddressBook* abs);  //删除联系人函数声明
void SearchPerson(struct AddressBook* abs);    //查找联系人函数声明
void ClearPerson(struct AddressBook* abs);    //清空联系人函数声明