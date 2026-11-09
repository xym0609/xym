# Minimal CMake C++20 Template

这是一个最小 CMake 项目模板，不是已经完成的产品项目。

## 目录
```text
cmake-cpp/
├── CMakeLists.txt
└── src/
    └── main.cpp
```

## 构建
需要安装 CMake 3.20 或更高版本，以及可用的 C++20 编译器。

```bash
cmake -S . -B build
cmake --build build
```

运行生成的 `cpp_template` 可执行文件。不同操作系统和生成器的输出路径可能不同。

后续项目再按实际需求加入单元测试、依赖管理、安装规则和 CI，不要一开始就堆复杂配置。