# 目的

设计一个 unordered_map 类，实现如下功能：

1. 基础功能

    - 构造函数：初始化 unordered_map 实例
    - 析构函数：清理资源，确保无内存泄露

2. 核心功能

    - 在 unordered_map 中插入一个元素
    - 在 unordered_map 中删除元素
    - 判断一个元素是否在 unordered_map 中
    - 判断 unordered_map 是否为空
    - 获取 unordered_map 的大小


# 测试文件介绍


## 输入描述

包含多行输入，第一行为正整数 N, 代表后续有 N 行命令序列。<br>
接下来 N 行，每行包含一个命令，命令格式为 [operation] [parameters] ，具体命令如下：<br>

```
insert 命令：
格式：insert [key] [value]
功能：在 map 中添加 key-value 键值对，如果对应的 key 已经存在，则不进行任何操作

erase 命令：
格式：erase [key]
功能：删除 unordered_map 中 key 对应的键值对，如果 key 不存在，则不进行任何操作

find 命令：
格式：find [key]
功能：查询 unordered_map 是否存在 key 对应的键值对

empty 命令：
格式：empty
功能：判断 unordered_map 是否为空

size 命令：
格式：size
功能：获取 unordered_map 的大小
```


## 输出描述

输出为每行命令执行后的结果，具体输出格式如下：

```
insert 命令：无输出
erase 命令：无输出
empty 命令：如果 unordered_map 为空，则输出 true，否则输出 false，输出独占一行
size 命令：输出一个整数，独占一行，代表 unordered_map 的大小
find 命令：如果 key 存在，则输出 true，否则输出 false，输出独占一行
```


# 与标准库的区别

与C++标准库中的unordered_map相比，一个简化版本的实现可能存在以下区别：<br>
这个自定义的 Unordered_map 类在功能上与 STL (Standard Template Library) 中的 std::unordered_map 相似，但它们之间有几个关键区别。以下是一些潜在的差异：

1. 异常安全性：

    - std::unordered_map 提供了异常安全保证，特别是在操作可能抛出异常的情况下。例如，当类型 Key 或 Value 的构造函数或赋值操作可能抛出异常时，std::unordered_map 会确保在异常发生时不破坏现有数据。
    - 自定义 Unordered_map 类可能没有相应的异常安全机制，除非 HashTable 类内部提供了这种保护。
  
2. 迭代器支持：

    - std::unordered_map 提供了正向和常量迭代器，使得用户可以遍历容器中的所有元素。
    - Unordered_map 类没有提供迭代器的实现或接口，这限制了用户在集合上进行迭代的能力。

3. 方法的完整性和命名：

   - std::unordered_map 提供了一系列完整的成员函数，包括 emplace, emplace_hint, find, equal_range, bucket, load_factor, rehash 等。
   - 自定义 Unordered_map 类的成员函数较少，且命名可能与 STL 的约定不同，例如，find 方法返回一个布尔值而不是迭代器。

4. 内存管理：

    - std::unordered_map 使用了高度优化的内存分配器来管理内存，可以提供高效的内存使用和重用。
    - 自定义 Unordered_map 类的内存管理取决于 HashTable 类的实现，可能没有同样的优化。
    
5. 性能：

    - std::unordered_map 经过了广泛的优化以提供最佳性能，特别是在哈希函数和碰撞解决策略方面。
    - 自定义 Unordered_map 类的性能表现将取决于 HashTable 类的实现细节。

6. 可移植性和兼容性：

    - std::unordered_map 是 C++ 标准的一部分，因此它在所有标准兼容的编译器上行为一致。
    - 自定义 Unordered_map 类可能在不同编译器或平台上表现不一致，除非特别注意跨平台兼容性。

7. 模板参数：

    - std::unordered_map 允许用户指定哈希函数和键比较函数。
    - 自定义 Unordered_map 类似乎没有提供此类选项，它可能直接依赖 HashTable 的哈希函数和比较逻辑。

8. 默认构造元素：

    - 在 std::unordered_map 中，使用下标操作符访问一个不存在的键会自动创建一个该键的条目，并默认构造其值。
    - 自定义 Unordered_map 的下标操作符实现也似乎提供了类似的行为，但这依赖于 HashTable 类的 insertKey 方法的实现。

9. 拷贝控制操作：

    - std::unordered_map 定义了拷贝构造函数、移动构造函数、拷贝赋值运算符和移动赋值运算符，以及析构函数。
    - 自定义 Unordered_map 类可能没有提供所有这些拷贝控制操作，或者依赖 HashTable 类的实现。