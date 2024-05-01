#ifndef _MYREDBLACKTREE_H_
#define _MYREDBLACKTREE_H_

enum class Color { red, black };

template<typename Key, typename Value>
class MyRedBlackTree{
    class Node{
        public:
            Key key;
            Value value;
            Color color;
            Node *left;
            Node *right;
            Node *parent;

            // 构造函数
            Node();
            Node(const Key &k, const Value &v, Color c, Node *p = nullptr);
    };

private:
    Node *root;
    size_t size;
    Node *Nil;

    // 查询某节点
    Node *lookup(Key key);

    // 右旋函数
    void rightRotate(Node *node);

    // 左旋函数
    void leftRotate(Node *node);

    // 插入修复函数
    void insertFixup(Node *target);

    // 插入节点函数
    void insertNode(const Key &key, const Value &value);

    // 中序遍历
    void inorderTraversal(Node *node) const;

    // 辅助函数，用新节点替换旧节点
    void replaceNode(Node *targetNode, Node *newNode);

    // 寻找以某个节点为根结点的子树中的最小节点
    Node *findMinNode(Node *node);

    // 删除节点后恢复红黑树的性质
    void removeFixup(Node *node);

    // 获取颜色
    Color getColor(Node *node);

    // 设置颜色
    void setColor(Node *node, Color color);

    // 取消Nil哨兵的连接
    void dieConnectNil();

    // 删除节点
    void deleteNode(Node *del);

    // 递归释放节点内存
    void deleteTree(Node *node);

public:
    // 构造函数
    MyRedBlackTree();

    // 插入
    void insert(const Key &key, const Value &value);

    // 删除
    void remove(const Key &key);

    // 获取节点值
    Value *at(const Key &key);

    int getSize();

    bool empty();

    // 中序遍历打印
    void print();

    void clear();

    // 析构函数
    ~MyRedBlackTree();
};

#endif