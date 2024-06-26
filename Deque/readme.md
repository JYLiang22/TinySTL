- [目的](#目的)
- [测试文件介绍](#测试文件介绍)
  - [输入描述](#输入描述)
  - [输出描述](#输出描述)
- [本实现版本 和 C++ STL标准库实现版本的区别](#本实现版本-和-c-stl标准库实现版本的区别)


# 目的

设计一个名为 MyDeque 的 Deque 类，该类具有以下功能和特性：

1. 基础成员函数

    构造函数：初始化 Deque 实例
    析构函数：清理资源，确保无内存泄露

2. 核心功能

    在 Deque 末尾添加元素
    在 Deque 开头添加元素
    删除 Deque 末尾的元素
    删除 Deque 开头的元素
    获取 Deque 中节点的数量
    删除 Deque 中所有的元素

3. 迭代与遍历

    打印 Deque 中的元素

4. 辅助功能

    重载[]运算符以对 Deque 进行索引访问


# 测试文件介绍


## 输入描述

包含多行输入，第一行为正整数 N, 代表后续有 N 行命令序列。<br>
接下来 N 行，每行包含一个命令，命令格式为 [operation] [parameters] ，具体命令如下：<br>

```
push_back 命令：
格式：push_back [value]
功能：在双端队列末尾添加值为 value 的元素

push_front 命令：
格式：push_front [value]
功能：在双端队列开头添加值为 value 的元素

pop_back 命令：
格式：pop_back
功能：删除双端队列末尾的元素

pop_front 命令：
格式：pop_front
功能：删除双端队列开头的元素

clear 命令：
格式：clear
功能：清空双端队列

size 命令：
格式：size
功能：获取双端队列中节点的数量

get 命令：
格式：get [index]
功能：获取双端队列中索引为 index 的节点的值

print 命令：
格式：print
功能：打印双端队列中的元素
```


## 输出描述

输出为每行命令执行后的结果，具体输出格式如下：<br>

```
push_back 命令：无输出
push_front 命令：无输出
pop_back 命令：无输出
pop_front 命令：无输出
clear 命令：无输出
size 命令：输出一个整数，独占一行，代表 Deque 中元素的数量
get 命令：输出双端队列中索引为 index 的节点的值
print 命令：输出双端队列中的元素
```


# 本实现版本 和 C++ STL标准库实现版本的区别

1. 数据结构： 标准库中的 std::deque（双端队列）通常是通过一个或者多个连续存储区域（即一维数组）来实现的，而不是单一的连续数组, 这多个一维数组连接起来形成了deque数组, 目前的实现采用的是循环数组, 缺点就是resize时要复制旧数组, 而官方的std::deque只需要再串联一个一维数组就可以了, 效率更高, 本实现的优点在于:
   1. 不需要resize的场景下性能好
   2. 实现逻辑简单
2. 内存管理： 在实际的 STL 中，内存管理通常会更加复杂和高效。STL 会使用分配器（allocator）来管理内存，而不是直接使用 new 和 delete。分配器允许用户提供自定义的内存管理策略。
3. 异常安全性： 实际的 STL 通常会考虑异常安全性。在示例中，如果 pop_front 或 pop_back 操作遇到空的 Deque，它会抛出异常。在 STL 中，许多操作都设计成具有一定的异常安全性，以确保在发生异常时不会导致资源泄漏。
4. 迭代器和算法支持： STL 提供了丰富的迭代器和算法支持，允许通用的方式操作容器。示例中，尽管提供了基本的迭代器，但没有涉及 STL 中的迭代器范围（range）和算法。
5. 性能优化： 实际的 STL 库通常会进行更多的性能优化，包括使用更复杂的数据结构、考虑缓存友好性等。此外，STL 中的容器和算法通常会根据使用情况进行自动选择，以提供最佳性能。
6. 标准兼容性： 实际的 STL 遵循 C++ 标准，确保在不同的平台和编译器上的一致行为。它还提供了许多其他功能，如分配器的自定义、迭代器标签（iterator tags）等，以满足 C++ 标准的要求。
