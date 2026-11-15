# 职工管理系统

C++20 Windows 控制台练习项目，练习类与对象、继承、多态、动态内存管理和文件读写。

## 功能
- 添加、显示、删除、修改职工信息
- 按编号或姓名查找
- 按编号升序或降序排序
- 清空数据文件
- 从 empFile.txt 加载数据并保存变更
- 检查重复编号、非法数字输入和文件读写错误
- 保存先写入临时文件，再替换正式数据文件，避免直接截断原文件

## 项目结构
```
职工管理系统/
├── README.md
├── 职工管理系统.slnx
├── 职工管理系统.zip
└── 职工管理系统/
    ├── 职工管理系统.vcxproj
    ├── 职工管理系统.vcxproj.filters
    ├── 职工管理系统.cpp
    ├── WorkerManager.cpp
    ├── workermanager.h
    ├── worker.h
    ├── employee.h / employee.cpp
    ├── manager.h / manager.cpp
    ├── boss.h / boss.cpp
    └── empFile.txt
```

## 运行
- Windows 10/11
- Visual Studio，安装项目配置所需的 MSVC v145 工具集和 Windows SDK
- C++20

打开 `职工管理系统.slnx`，选择 Debug/Release 与 x64，生成并运行。调试工作目录应设置为包含 `empFile.txt` 的项目目录。

项目使用 UTF-8 源码，并在 MSVC 编译参数中启用 `/utf-8`。数据文件每行格式为 `编号 姓名 岗位编号`，岗位编号 1/2/3 分别代表普通职工、经理、老板。姓名暂不支持空格。

## 当前限制
这是学习项目，不适合直接用于真实人事数据。当前仍使用原始指针和动态数组；后续可学习使用 `std::vector<std::unique_ptr<Worker>>`。程序中的 `system("pause")` 和 `system("cls")` 面向 Windows 命令行。
