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

            // ���캯��
            Node();
            Node(const Key &k, const Value &v, Color c, Node *p = nullptr);
    };

private:
    Node *root;
    size_t size;
    Node *Nil;

    // ��ѯĳ�ڵ�
    Node *lookup(Key key);

    // ��������
    void rightRotate(Node *node);

    // ��������
    void leftRotate(Node *node);

    // �����޸�����
    void insertFixup(Node *target);

    // ����ڵ㺯��
    void insertNode(const Key &key, const Value &value);

    // �������
    void inorderTraversal(Node *node) const;

    // �������������½ڵ��滻�ɽڵ�
    void replaceNode(Node *targetNode, Node *newNode);

    // Ѱ����ĳ���ڵ�Ϊ�����������е���С�ڵ�
    Node *findMinNode(Node *node);

    // ɾ���ڵ��ָ������������
    void removeFixup(Node *node);

    // ��ȡ��ɫ
    Color getColor(Node *node);

    // ������ɫ
    void setColor(Node *node, Color color);

    // ȡ��Nil�ڱ�������
    void dieConnectNil();

    // ɾ���ڵ�
    void deleteNode(Node *del);

    // �ݹ��ͷŽڵ��ڴ�
    void deleteTree(Node *node);

public:
    // ���캯��
    MyRedBlackTree();

    // ����
    void insert(const Key &key, const Value &value);

    // ɾ��
    void remove(const Key &key);

    // ��ȡ�ڵ�ֵ
    Value *at(const Key &key);

    int getSize();

    bool empty();

    // ���������ӡ
    void print();

    void clear();

    // ��������
    ~MyRedBlackTree();
};

#endif