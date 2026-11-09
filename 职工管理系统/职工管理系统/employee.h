#pragma once
#include<iostream>
#include"worker.h"
using namespace std;
//创建一个子类employee并继承父类worker
class Employee :public Worker
{
public:
	//声明构造函数和要输入参数类型
	Employee(int id,string name,int dId);
	//声明两个虚函数
	virtual void showInfo();
	virtual string getDeptName();
};