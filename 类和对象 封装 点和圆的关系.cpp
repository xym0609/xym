#include"类和对象 封装 点和圆的关系.h"
	void ponit::setX(int x)
	{
		X = x;
	}
	int ponit::getX()
	{
		return X;
	 }
	void ponit::setY(int y)
	{
		Y = y;
	}
	int ponit::getY()
	{
		return Y;
	}

	void circle::setR(int r)
	{
		R = r;
	}
	int circle::getR()
	{
		return R;
	}
	void circle::yuanxin(ponit a_A)
	{
		yx = a_A;
	}
	ponit circle::gc()
	{
		return yx;
	}
void panduan(circle &y,ponit& d)
{
	int distance = (y.gc().getX() - d.getX()) * (y.gc().getX() - d.getX()) + (y.gc().getY() - d.getY()) * (y.gc().getY() - d.getY());//(X1-X2)^2+(Y1-Y2)^2
    int rdistance = y.getR() * y.getR();//R^2
	if (distance==rdistance)
	{
		cout << "点在圆上" << endl;
	}
	else if (distance > rdistance)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
}

int main()
{
	//给一个自定义的点赋值坐标
	class ponit dian_a;
	dian_a.setX(10);
	dian_a.setY(10);
	//给圆心赋值坐标
	class ponit A;
	A.setX(10);
	A.setY(0);
	//创建一个圆 并给他赋值一个对应的半径的长度和圆心的坐标
	class circle yuan_a;
	yuan_a.setR(10);
	yuan_a.yuanxin(A);
	//判断点在哪里
	panduan(yuan_a, dian_a);
}