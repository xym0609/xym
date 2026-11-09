# C++ Algorithms & Data Structures

用于整理自己理解并能够独立讲解的算法与数据结构练习。

## 主题目录

- `topics/arrays/`：数组、字符串、双指针、滑动窗口
- `topics/linked-lists/`：链表、快慢指针、反转与合并
- `topics/trees/`：二叉树、BST、遍历、递归与迭代
- `topics/graphs/`：DFS、BFS、最短路径、拓扑排序
- `topics/dynamic-programming/`：状态定义、转移、边界与优化
- `templates/`：统一题解模板

## 每道题建议包含

1. 题目名称、平台/来源和原题链接
2. 自己总结的题意，不复制大段题目原文
3. 解题思路与关键不变量/正确性说明
4. 时间复杂度和空间复杂度
5. 边界测试、特殊输入和运行方式
6. 复盘：第一次错在哪里、如何改进

每道题一个独立源文件；文件名使用简短英文或平台题号，例如 `two_sum.cpp`。同一题有多种解法时，写在同一题目录中并明确比较。

质量要求：每道题要能脱离答案重新讲解；覆盖正常、边界和特殊输入；复杂度分析必须与实际实现一致。尚未学习的主题保留目录说明即可，不要填入伪造题解。

题解源码统一参考 [`templates/problem-template.cpp`](./templates/problem-template.cpp)。