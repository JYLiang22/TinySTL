- [目的](#目的)
- [测试文件介绍](#测试文件介绍)
  - [输入描述](#输入描述)
  - [输出描述](#输出描述)


# 目的

设计一个名为 MyList 的 List 类，该类具有以下功能和特性：

1. 基础成员函数

   - 构造函数：初始化 List 实例
   - 析构函数：清理资源，确保无内存泄露

2. 核心功能

   - 在 List 末尾添加元素
   - 在 List 开头添加元素
   - 获取 List 中节点的数量
   - 删除 List 末尾的元素
   - 删除 List 开头的元素
   - 删除 List 中指定值的节点

3. 迭代与遍历

   - 打印链表中的元素

4. 辅助功能

   - 重载[]运算符以对链表进行索引访问
   - 重载<<运算符以打印链表


# 测试文件介绍


## 输入描述

包含多行输入，第一行为正整数 N, 代表后续有 N 行命令序列。<br>
接下来 N 行，每行包含一个命令，命令格式为 [operation] [parameters] ，具体命令如下：

```
push_back 命令：
格式：push_back [value]
功能：在链表末尾添加值为 value 的元素

push_front 命令：
格式：push_front [value]
功能：在链表开头添加值为 value 的元素

pop_back 命令：
格式：pop_back
功能：删除链表末尾的元素

pop_front 命令：
格式：pop_front
功能：删除链表开头的元素

remove 命令：
格式：remove [value]
功能：删除链表中值为 value 的元素

clear 命令：
格式：clear
功能：清空链表

size 命令：
格式：size
功能：获取链表中节点的数量

get 命令：
格式：get [index]
功能：获取链表中索引为 index 的节点的值

print 命令：
格式：print
功能：打印链表中的元素
```


## 输出描述

输出为每行命令执行后的结果，具体输出格式如下：

```
push_back 命令：无输出
push_front 命令：无输出
pop_back 命令：无输出
pop_front 命令：无输出
remove 命令：无输出
clear 命令：无输出
size 命令：输出一个整数，独占一行，代表当前 List 中元素的数量
get 命令：输出一个整数，独占一行，代表 List 中索引为 index 的元素，如果索引无效，则输出 -1
print 命令：按照顺序打印当前 List 包含的所有元素，每个元素后都跟一个空格，打印结果独占一行；如果当前的 vector 为空，则打印 empty
```
