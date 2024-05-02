- [目的](#目的)
- [测试文件介绍](#测试文件介绍)
  - [输入描述](#输入描述)
  - [输出描述](#输出描述)
- [与标准库的区别](#与标准库的区别)


# 目的

设计一个 multimap 类，实现如下功能：

1. 基础功能

    - 构造函数：初始化 multimap 实例
    - 析构函数：清理资源，确保无内存泄露

2. 核心功能

    - 在 multimap 中插入一个元素
    - 在 multimap 中删除指定的键值
    - 在 multimap 中删除所有的值
    - 判断 multimap 是否为空
    - 获取 multimap 的大小
    - 遍历打印 multimap 中的key 对应的 values
    - 获取 multimap 中 key 对应的 values


# 测试文件介绍


## 输入描述

包含多行输入，第一行为正整数 N, 代表后续有 N 行命令序列。<br>
接下来 N 行，每行包含一个命令，命令格式为 [operation] [parameters] ，具体命令如下：<br>

```
insert 命令：
格式：insert [key] [value]
功能：在 map 中添加 key-value 键值对，如果对应的 key 已经存在，则不进行任何操作

remove 命令：
格式：remove [key] [value]
功能：在 map 中删除 key 对应的 value

remove_all 命令：
格式：remove_all [key]
功能：在 map 中删除 key 对应的所有 value

at 命令：
格式：at [key]
功能：在 map 中获取 key 对应的 value

empty 命令：
格式：empty
功能：判断 multimap 是否为空

size 命令：
格式：size
功能：获取 multimap 的大小
```


## 输出描述

输出为每行命令执行后的结果，具体输出格式如下：

```
insert 命令：无输出
remove 命令：无输出
remove_all 命令：无输出
empty 命令：如果 multimap 为空，则输出 true，否则输出 false，输出独占一行
size 命令：输出一个整数，独占一行，表示 multimap 的大小
at 命令：在 map 中获取 key 对应的 value，如果有多个 value，则打印所有的 value，每个 value 后都拥有一个空格，如果不存在，则输出 not exist，输出独占一行
```


# 与标准库的区别

与C++标准库中的相比，一个简化版本的实现可能存在以下区别：

1. 完整性和功能性： 这份代码只是一个简单的红黑树实现，包括插入和中序遍历，但实现基于迭代器的接口函数。std::multimap是一个完整的容器类，提供了更多功能。
2. 标准库实现的性能和稳定性： C++标准库中的std::multimap是经过高度优化和测试的，具有出色的性能和稳定性。它在各种情况下都能提供高效的操作，而这份代码可能不具备相同的性能特性和稳定性。
3. 泛型和容错性： 标准库中的容器是通用的，可以存储各种数据类型。而这份代码是针对特定数据类型的键值对进行了硬编码。std::multimap具有更高的泛型性和容错性。
4. 内存管理： 这份代码没有包括内存管理的细节，如资源的释放。在实际应用中，需要确保内存分配和释放的正确性，而标准库会处理这些细节。
