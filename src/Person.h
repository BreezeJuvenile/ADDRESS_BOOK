#pragma
#include<iostream>
using namespace std;
#include<string>


#define MAX 1000
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