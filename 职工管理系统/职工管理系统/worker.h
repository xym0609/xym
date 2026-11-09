#pragma once
#include<iostream>
using namespace std;
#include<string>
//创建一个抽象基类
class Worker
{
public:
	//创建两个虚函数
	virtual void showInfo() = 0;
	virtual string getDeptName() = 0;
	virtual ~Worker() = default;
	//创建三个信息
	int m_Id;
	string m_Name;
	int m_DeptId;
};
