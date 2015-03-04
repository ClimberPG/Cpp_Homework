#include <iostream>
using namespace std;
struct LinkListNode {
    int data;
    LinkListNode *next;

    LinkListNode(int _data) {
        data = _data;
        next = NULL;
    }

    LinkListNode(int _data, LinkListNode * _next) {
        data = _data;
        next = _next;
    }
};
// 构造链表节点， 并且用重载给出初始化方法。

class LinkList {
public:
    LinkList(int _size); // 构建一个单向无环链

    int delNode(int pos);
    // 删除第pos个节点。
    // pos > size || pos <= 0, 返回-1
    // pos <= size, 删除第pos个节点, 从1开始计数

    int getNodeData(int pos) const;
    // 获取第pos个节点的数据

    int getSize() const;
    // 获取当前链表的大小

    void print() const;
    // 打印当前列表

    ~LinkList();
    // 析构函数，用于销毁资源
private:
    int size, del_data;
    mutable int i;
    LinkListNode *head;
};

class Josephus {
private:
    int n, s, m;
public:
    Josephus(int _n, int _s, int _m):n(_n), s(_s), m(_m) {};
    void sol();
};
int main() {
    Josephus j1(5, 2, 3),  j2(15, 2, 3), j3(10, 1, 1);
    j1.sol();
    j2.sol();
    j3.sol();
    return 0;
}

LinkList::LinkList(int _size) {
    size = _size;
    head = new LinkListNode(size);
    for (i = size - 1; i > 0; i--) {
        head = new LinkListNode(i, head);
    }
}

int LinkList::delNode(int pos) {
    if (pos <= 0 || pos > size) return -1;
    size--;
    LinkListNode *temp, *tmp;
    temp = head;
    if (pos == 1) {
        head = head->next;
        del_data = temp->data;
        delete temp;
        return del_data;
    } else {
        for (i = 2; i < pos; i++) temp = temp->next;
        tmp = temp->next;
        del_data= tmp->data;
        temp->next = temp->next->next;
        delete tmp;
        return del_data;
    }
}

int LinkList::getNodeData(int pos) const {
    if (pos <= 0 || pos > size) return -1;
    LinkListNode *temp = head;
    for (i = 1; i < pos; i++) temp = temp->next;
    return temp->data;
}

int LinkList::getSize() const {
    return size;
}

void LinkList::print() const {
    LinkListNode *temp = head;
    for (i = 0; i < size; i++) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

LinkList::~LinkList() {
    LinkListNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
    head = NULL;
}

void Josephus::sol() {
    LinkList l(n);
    while (n > 0) {
        s += m - 1;
        while (s > n) s -= n;
        cout << l.delNode(s) << " ";
        n--;
    }
    cout << endl;
}