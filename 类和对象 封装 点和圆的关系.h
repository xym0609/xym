#pragma once
#include<iostream>
#include<string>
using namespace std;

class ponit
{
private:
	int X;
	int Y;
public:
	void setX(int x);
	int getX();
	void setY(int y);
	int getY();
};
class circle
{
private:
	int R;
	ponit yx;
public:
	void setR(int r);
	int getR();
	void yuanxin(ponit a_A);
	ponit gc();
};
void panduan(circle& y, ponit& d);