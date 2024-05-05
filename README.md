# TinySTL


## Implementation of vector

[Introduction](vector/readme.md)<br>

Implementation:

1. [MyVector.h](vector/include/MyVector.h)
2. [MyVector.cpp](vector/src/MyVector.cpp)
3. [MyVector_test.cpp](vector/test/MyVector_test.cpp)

**Compare with standard library**<br>

Use this program [MyVector_test.cpp](vector/test/MyVector_test.cpp) to compare with the vector implemented by the STL standard library [Vector_test.cpp](vector/test/Vector_test.cpp). The total number of operations is 1.5 million. The operation types include add, delete, modify, and check. The operation file is located [here](vector/file/test.txt). The time and memory consumption are as follows:<br>

```shell
TinySTL/vector/test$ ./MyVector_test 
Time taken: 6.05163 seconds
Memory usage: 1760 KB

TinySTL/vector/test$ ./Vector_test 
Time taken: 4.47986 seconds
Memory usage: 1856 KB
```

It can be found that the vector implemented by myself is not much different from the vector defined by the STL standard library during testing.


## Implementation of List

[Introduction](List/readme.md)<br>

Implementation:

1. [MyList.h](List/include/MyList.h)
2. [MyList.cpp](List/src/MyList.cpp)
3. [MyList_test.cpp](List//test/MyList_test.cpp)

**Compare with standard library**<br>

Use this program [MyList_test.cpp](List/test/MyList_test.cpp) to compare with the list implemented by the STL standard library [List_test.cpp](List/test/List_test.cpp). The total number of operations is 400000. The operation types include add, delete, modify, and check. The operation file is located [here](List/file/test.txt). The time and memory consumption are as follows:<br>

```shell
TinySTL/List/test$ ./MyList_test 
Time taken: 1.59229 seconds
Memory usage: 1772 KB

TinySTL/List/test$ ./List_test 
Time taken: 1.32541 seconds
Memory usage: 1760 KB
```

It can be found that the list implemented by myself is not much different from the list defined by the STL standard library during testing.


## Implementation of Deque

[Introduction](Deque/readme.md)<br>

Implementation:

1. [MyDeque.h](Deque/include/MyDeque.h)
2. [MyDeque.cpp](Deque/src/MyDeque.cpp)
3. [MyDeque_test.cpp](Deque/test/MyDeque_test.cpp)

**Compare with standard library**<br>

Use this program [MyDeque_test.cpp](Deque/test/MyDeque_test.cpp) to compare with the deque implemented by the STL standard library [Deque_test.cpp](Deque/test/Deque_test.cpp). The total number of operations is 60000. The operation types include add, delete, modify, and check. The operation file is located [here](Deque/file/test.txt). The time and memory consumption are as follows:<br>

```shell
TinySTL/Deque/test$ ./MyDeque_test
Time taken: 0.180536 seconds
Memory usage: 1924 KB

TinySTL/Deque/test$ ./Deque_test 
Time taken: 0.158233 seconds
Memory usage: 1780 KB
```

It can be found that the deque implemented by myself is not much different from the deque defined by the STL standard library during testing.


## Implementation of HashTable

[Introduction](HashTable/readme.md)<br>

Implementation:

1. [MyHashTable.h](HashTable/include/MyHashTable.h)
2. [MyHashTable.cpp](HashTable/src/MyHashTable.cpp)
3. [MyHashTable_test.cpp](HashTable/MyHashTable_test.cpp)


## Implementation of RedBlackTree

[Introduction](RedBlackTree/readme.md)<br>

Implementation:

1. [MyRedBlackTree.h](RedBlackTree/include/MyRedBlackTree.h)
2. [MyRedBlackTree.cpp](RedBlackTree/src/MyRedBlackTree.cpp)
3. [MyRedBlMyRedBlackTree_test.cpp](RedBlackTree/MyRedBlackTree_test.cpp)


## Implementation of Set
[Introduction](Set/readme.md)<br>

Implementation:

1. [MySet.h](Set/include/MySet.h)
2. [MySet.cpp](Set/src/MySet.cpp)
3. [MySet_test.cpp](Set/MySet_test.cpp)


## Implementation of unordered_set
[Introduction](unordered_set/readme.md)<br>

Implementation:

1. [Myunordered_set.h](unordered_set/include/Myunordered_set.h)
2. [Myunordered_set.cpp](unordered_set/src/Myunordered_set.cpp)
3. [Myunordered_set_test.cpp](unordered_set/Myunordered_set_test.cpp)


## Implementation of multiset
[Introduction](multiset/readme.md)<br>

Implementation:

1. [Mymultiset.h](multiset/include/Mymultiset.h)
2. [Mymultiset.cpp](multiset/src/Mymultiset.cpp)
3. [Mymultiset_test.cpp](multiset/Mymultiset_test.cpp)


## Implementation of map
[Introduction](map/readme.md)<br>

Implementation:

1. [Mymap.h](map/include/Mymap.h)
2. [Mymap.cpp](map/src/Mymap.cpp)
3. [Mymap_test.cpp](map/test/Mymap_test.cpp)

**Compare with standard library**<br>

Use this program [Mymap_test.cpp](map/test/Mymap_test.cpp) to compare with the map implemented by the STL standard library [Map_test.cpp](map/test/Map_test.cpp). The total number of operations is 60000. The operation types include add, delete, modify, and check. The operation file is located [here](map/file/test.txt). The time and memory consumption are as follows:<br>

```shell
TinySTL/map/test$ ./Mymap_test
Time taken: 0.20292 seconds
Memory usage: 1852 KB

TinySTL/map/test$ ./Map_test 
Time taken: 0.303157 seconds
Memory usage: 1880 KB
```

It can be found that the map implemented by myself is not much different from the map defined by the STL standard library during testing.


## Implementation of unordered_map
[Introduction](unordered_map/readme.md)<br>

Implementation:

1. [Myunordered_map.h](unordered_map/include/Myunordered_map.h)
2. [Myunordered_map.cpp](unordered_map/src/Myunordered_map.cpp)
3. [Myunordered_map_test.cpp](unordered_map/test/Myunordered_map_test.cpp)

**Compare with standard library**<br>

Use this program [Myunordered_map_test.cpp](unordered_map/test/Myunordered_map_test.cpp) to compare with the unordered_map implemented by the STL standard library [unordered_map_test.cpp](unordered_map/test/unordered_map_test.cpp). The total number of operations is 60000. The operation types include add, delete, modify, and check. The operation file is located [here](unordered_map_test/file/test.txt). The time and memory consumption are as follows:<br>

```shell
TinySTL/unordered_map/test$ ./Myunordered_map_test
Time taken: 0.228766 seconds
Memory usage: 1768 KB

TinySTL/unordered_map/test$ ./unordered_map_test 
Time taken: 0.205543 seconds
Memory usage: 1936 KB
```

It can be found that the unordered_map implemented by myself is not much different from the unordered_map defined by the STL standard library during testing.


## Implementation of multimap
[Introduction](multimap/readme.md)<br>

Implementation:

1. [Mymultimap.h](multimap/include/Mymultimap.h)
2. [Mymultimap.cpp](multimap/src/Mymultimap.cpp)
3. [Mymultimap_test.cpp](multimap/Mymultimap_test.cpp)


## Implementation of stack
[Introduction](stack/readme.md)<br>

Implementation:

1. [Mystack.h](stack/include/Mystack.h)
2. [Mystack.cpp](stack/src/Mystack.cpp)
3. [Mystack_test.cpp](stack/Mystack_test.cpp)


## Implementation of priority_queue

[Introduction](priority_queue/readme.md)<br>

Implementation:

1. [Mypriority_queue.h](priority_queue/include/Mypriority_queue.h)
2. [Mypriority_queue.cpp](priority_queue/src/Mypriority_queue.cpp)
3. [Mypriority_queue_test.cpp](priority_queue/test/Mypriority_queue_test.cpp)
