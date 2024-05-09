- [介绍](#介绍)
- [目的](#目的)
- [测试文件描述](#测试文件描述)
  - [输入描述](#输入描述)
  - [输出描述](#输出描述)
- [与标准库的差异](#与标准库的差异)


# 介绍

[什么是红黑树，一篇文章解决所有疑惑~~](https://zhuanlan.zhihu.com/p/143585797)<br>
[红黑树删除篇](https://zhuanlan.zhihu.com/p/145006031)<br>


# 目的

在STL中，红黑树是一个重要的底层数据结构，这里需要设计一个 RedBlackTree 类，实现如下功能：

1. 基础功能

    - 构造函数：初始化 RedBlackTree 实例
    - 析构函数：清理资源，确保无内存泄露

2. 核心功能

    - 在 RedBlackTree 中插入一个节点
    - 在 RedBlackTree 中删除一个节点
    - 查询 RedBlackTree 中某个节点是否存在
    - 获取 RedBlackTree 中节点的数量
    - 获取 RedBlackTree 中所有的节点

RedBlackTree 中的节点拥有两个属性，一个是 key，一个是 value，本题题意规定如果 key 相同，则代表是同一个节点。


# 测试文件描述


## 输入描述

包含多行输入，第一行为正整数 N, 代表后续有 N 行命令序列。<br>
接下来 N 行，每行包含一个命令，命令格式为 [operation] [parameters] ，具体命令如下：

```
insert 命令：
格式：insert [key] [value]
功能：在 RedBlackTree 中添加节点，如果节点已经存在，则不进行任何操作

remove 命令：
格式：remove [key]
功能：删除 RedBlackTree 中的节点，如果节点不存在，则不进行任何操作

at 命令：
格式：at [key]
功能：查询 RedBlackTree 中的节点

size 命令：
格式：size
功能：获取 RedBlackTree 中节点的数量

print 命令：
格式：print
功能：按照中序遍历输出 RedBlackTree 中所有节点，格式为 [key1] [value1] [key2] [value2]
```


## 输出描述

输出为每行命令执行后的结果，具体输出格式如下：

```
insert 命令: 无输出
remove 命令: 无输出
at 命令: 输出一个整数，独占一行，代表 RedBlackTree 中 key 对应的 value，如果 key 不存在，则输出 not exsit
size 命令: 输出一个整数，独占一行，代表 RedBlackTree 中节点的数量
print 命令: 按照中序遍历输出 RedBlackTree 中所有节点的 key 和 value，格式为 [key1] [value1] [key2] [value2]...每个数字后都跟有一个空格，输出独占一行，如果 RedBlackTree 中不包含任何节点，则输出 empty
```


# 与标准库的差异

这份简化的红黑树实现和C++ STL标准库中的红黑树相比存在很多差异，主要集中在以下几个方面：

1. 性能和优化： C++ STL标准库中的实现经过了严格的性能优化和调整，考虑了各种边界条件和特殊情况，以提供高效的性能。简化版本的实现没有进行这样的优化。
2. 异常处理： C++ STL标准库中的实现通常会包含对异常的处理，例如内存分配失败等情况。简化版本的实现没有涉及到这方面的处理。
3. 模板特化和配置： C++ STL的容器是可配置和可特化的，允许用户提供自定义的比较器、分配器等。上述简化版本没有考虑这些配置选项。
4. 迭代器和算法： C++ STL中的容器通常配有迭代器，方便使用STL算法。简化版本没有实现这些功能。
5. 内存管理： C++ STL标准库中的实现通常使用高效的内存管理技术，而简化版本可能没有考虑这方面的优化。
