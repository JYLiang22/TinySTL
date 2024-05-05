- [目的](#目的)
- [测试文件介绍](#测试文件介绍)
  - [输入描述](#输入描述)
  - [输出描述](#输出描述)


# 目的

设计一个 priority_queue 类，实现如下功能：

1. 基础功能

    - 构造函数：初始化 priority_queue 实例
    - 析构函数：清理资源，确保无内存泄露

2. 核心功能

    - 将元素添加到 priority_queue 中
    - 弹出 priority_queue 中的最大元素
    - 获取 priority_queue 中的最大元素
    - 获取 priority_queue 中元素的个数
    - 判断 priority_queue 是否为空


# 测试文件介绍


## 输入描述

包含多行输入，第一行为正整数 N, 代表后续有 N 行命令序列。<br>
接下来 N 行，每行包含一个命令，命令格式为 [operation] [parameters] ，具体命令如下：<br>

```
push 命令：
格式：push [element]
功能：将 element 添加到 priority_queue 中

pop 命令：
格式：pop
功能：弹出 priority_queue 中的最大元素

top 命令：
格式：top
功能：访问 priority_queue 中的最大元素

empty 命令：
格式：empty
功能：检查 priority_queue 是否为空

size 命令：
格式：size
功能：返回 priority_queue 的大小
```


## 输出描述

输出为每行命令执行后的结果，具体输出格式如下：

```
push 命令：无输出
pop 命令：无输出
top 命令：输出一个整数，独占一行，代表 priority_queue 中最大的元素，如果 priority_queue 为空，则输出 null
empty 命令：为空输出 true，不为空输出 false，输出独占一行
size 命令：输出一个整数，独占一行，代表 priority_queue 的大小
```