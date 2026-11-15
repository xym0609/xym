#include"workermanager.h"
//四个workermanager作用域下的函数实现
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在!" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//存在文件但文件为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空!" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//存在文件且有数据
	
	//计算当前文件中有几组数据
	int num = this->get_EmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;
	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据，存到数组中
	this->init_Emp();
	//测试代码
	/*for (int i = 0;i < this->m_EmpNum;i++)
	{
		cout << "职工编号：" << this->m_EmpArray[i]->m_Id
			<< "  姓名：" << this->m_EmpArray[i]->m_Name
			<< "  部门编号：" << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
}
void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统!  **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);

}
void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工数量：" << endl;
	int addNum = 0;//保存用户的输入数量
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;//计算添加后最新人数newsize
		Worker ** newSpace=new Worker* [newSize];//创建一个新的空间存放有newsize个指针的数组
		//将原来空间下数据拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0;i < this->m_EmpNum;i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//批量添加新数据
		for (int i = 0;i < addNum;i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "请输入第：" << i + 1 << "个新职工编号：" << endl;
			cin >> id;
			while (true)
			{
				bool isrepeat = false;
				for (int j = 0;j < this->m_EmpNum;j++)
				{
					if (this->m_EmpArray[j]->m_Id == id)
					{
						isrepeat = true;
						break;
					}
				}
				if (isrepeat)
				{
					cout << "输入的职工编号重复，请重新输入！" << endl;
					cin >> id;
					}
				else
				{
					break;
				}
			}
			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				cout << "输入错误，请重新输入岗位编号！" << endl;
				cin >> dSelect;
				continue;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;
		this->m_FileIsEmpty = false;
		cout << "成功添加" << addNum << "名新职工！" << endl;
		this->save();
	}
	else
	{
		cout<<"输入数据有误"<<endl;
	}
	system("pause");
	system("cls");
}
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0;i < this->m_EmpNum;i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();

}
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	} 
	else
	{
		for (int i = 0;i < m_EmpNum;i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入想要删除职工编号：" << endl;
		int id = 0;
		cin >> id;

		//查找文件里是否有这个编号，并把编号的数组下标赋值给index
		int index=this->IsExist(id);
		//如果查找到这个编号且下标不等于-1
		if (index != -1)
		{
			for (int i = index;i < this->m_EmpNum - 1;i++)
			{
				//先释放要删除的那个数据的内存
				delete this->m_EmpArray[index];
				//把数组后面每一位从前往后向前覆盖一位
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//更新当前人数-1
			this->m_EmpNum--;
			this->save();
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0;i < this->m_EmpNum;i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号" << endl;
		int id;
		cin >> id;

		//查找文件里是否有这个编号，并把编号的数组下标赋值给ret
		int ret = this->IsExist(id);
		//如果编号的下标存在
		if (ret != -1)
		{
			//删除要修改的职工的数据
			delete this ->m_EmpArray[ret];
			//重新给新的职工的三个数据赋初值
			int newId = 0;
			string newName = " ";
			int dSelect = 0;

			cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
			cin >> newId;
			cout << "请输入新的姓名：" << endl;
			cin >> newName;
			cout << "请输入新的岗位：" << endl;
			cout << "1、普通岗位：" << endl;
			cout << "2、经理：" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			}
			//把修改后的职工的数据存入数组
			this->m_EmpArray[ret] = worker;
			cout << "修改成功！" << endl;
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人!" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			//查找是否存在这个职工编号对应的数据，若有就把下标赋值给ret
			int ret = IsExist(id);
			//如果查找到了
			if (ret != -1)
			{
				cout << "查找成功！该职工的信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			//先假设不存在
			bool flag =false;
			for (int i = 0;i < m_EmpNum;i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，职工编号为："
						<< m_EmpArray[i]->m_Id
						<< "号的信息如下：" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
		
	}
	system("pause");
	system("cls");
}
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空!" << endl;
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;
		int select = 0;
		//判断是否输入正确，若不正确则提醒并重新输入直到正确
		while (true)
		{
			cin >> select;
			if (select != 1 && select != 2)
			{
				cout << "输入有误，请重新输入！" << endl;
			}
			else
			{
				break;
			}
		}
		//选择排序
		for (int i = 0;i < m_EmpNum;i++)
		{
			//先假设最大或最小值的下标为i
			int minOrMax = i;
			//遍历i后面每一个数据
			for (int j = i + 1;j < this->m_EmpNum;j++)
			{
				//若要求升序排列
				if (select == 1)
				{
					//如果最开始假设的最大值大于遍历后的i下标对应的值
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						//交换两者下标
						minOrMax = j;
					}
				}
				//若要求降序排列
				else if(select == 2)
				{
					//如果最开始假设的最小值小于遍历后的i下标对应的值
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						//交换两者下标
						minOrMax = j;
					}
				}
			}
			//如果假设的最大或最小值的下标不等于遍历后比较得到的下标
			if (i != minOrMax)
			{
				//将两个数据交换位置
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;

			}
		}
		cout << "排序成功！排序后的结果为：" << endl;
		this->save();
		this->Show_Emp();
	}
	system("pause");
	system("cls");
}
void WorkerManager::Clean_File()
{
	cout << "确定清空？" << endl;
	cout << "1、确定" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//清空文件并重新创建文件
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		//如果堆区的数组不为空
		if (this->m_EmpArray != NULL)
		{
			//遍历数组内每一位数据并删除且指向空
			for (int i = 0;i < this->m_EmpNum;i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//删除完数组内的数据后删除数组并指向空
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			//更新人数为0
			this->m_EmpNum = 0;
			//更新文件状态为空
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");

}
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0;i < this->m_EmpNum;i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
