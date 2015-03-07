#include <iostream>
using namespace std;

#define StkType char

struct StkNode { //栈节点
    StkType data;//节点的数据，这里为data
    StkNode *next;//节点的next节点

    //带参的构造函数
    StkNode(StkType _data = '\0', StkNode *_next = NULL) {
        data = _data;
        next = _next;
        cout << "StkNode() -> " << data << endl;
    }
    //析构
    ~StkNode() {
        cout << "~StkNode() -> " << data << endl;
    }
};

class Stack {
private:
    StkNode *top; // 栈顶指针，当栈为空时，指针为NULL
    int size;
    void copyOtherStk(const Stack &copyStk) {
        StkNode *tmp = copyStk.top;
        size = copyStk.size;
        if (tmp != NULL) {
            top = new StkNode(tmp->data, NULL);
        }
        StkNode *current = top;
        while (tmp->next != NULL) {
            current->next = new StkNode(tmp->next->data, NULL);
            current = current->next;
            tmp = tmp->next;
        }
    }
public:
    Stack();
    Stack(const Stack &copyStk);
    //拷贝另一个栈，要求是当另一个栈修改时不会影响到本栈（这就是所谓的深复制）
    ~Stack();
    Stack& operator= (const Stack & copyStk);
    void push(StkType newNodeData);
    StkType pop();
    //pop出栈，并且把栈顶的数据返回，如果栈是空 返回'\0'
    void clear();
    // 清空栈
    int getSize() const;
    // 获取栈节点数目
    StkType getTop() const;
    bool isEmpty() const;
    //打印从栈顶到栈底
    //例如：
    //当栈有5个元素的时候，打印如右：Stack(5): a->c->b->d->e
    //当栈没有元素的时候，打印如有：Stack(0)
    void print() const;
};

Stack::Stack() {
    top = NULL;
    size = 0;
}

Stack::Stack(const Stack &copyStk):top(NULL), size(copyStk.size) {
    StkNode *tmp = copyStk.top;
    if (tmp != NULL) {
        top = new StkNode(tmp->data, NULL);
    } else {
        return;
    }
    StkNode *current = top;
    while (tmp->next != NULL) {
        current->next = new StkNode(tmp->next->data, NULL);
        current = current->next;
        tmp = tmp->next;
    }
}

Stack::~Stack() {
}

Stack& Stack::operator= (const Stack &copyStk) {
    if (copyStk.top == NULL) {
        this->clear();
        return *this;
    }
    this->clear();
    copyOtherStk(copyStk);
    return *this;
}

void Stack::push(StkType newNodeData) {
    top = new StkNode(newNodeData, top);
    size++;
    return;
}

StkType Stack::pop() {
    if (top == NULL) return '\0';
    int temp = top->data;
    StkNode *tmp = top;
    size--;
    top = top->next;
    delete tmp;
    return temp;
}

void Stack::clear() {
    StkNode *tmp = top;
    while (top != NULL) {
        top = top->next;
        delete tmp;
        tmp = top;
    }
    size = 0;
}

int Stack::getSize() const {
    return size;
}

StkType Stack::getTop() const {
    if (top == NULL) return '\0';
    else return top->data;
}
bool Stack::isEmpty() const {
    if (top == NULL) return true;
    else return false;
}

void Stack::print() const {
    StkNode *tmp = top;
    if (size == 0) cout << "Stack(0)";
    else cout << "Stack(" << size << "):";
    while (tmp != NULL) {
        cout << tmp->data;
        tmp = tmp->next;
        if (tmp != NULL) cout << "->";
    }
    cout << endl;
    return;
}
