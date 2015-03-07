#include <iostream>
using namespace std;

#define StkType char

struct StkNode { //ջ�ڵ�
    StkType data;//�ڵ�����ݣ�����Ϊdata
    StkNode *next;//�ڵ��next�ڵ�

    //���εĹ��캯��
    StkNode(StkType _data = '\0', StkNode *_next = NULL) {
        data = _data;
        next = _next;
        cout << "StkNode() -> " << data << endl;
    }
    //����
    ~StkNode() {
        cout << "~StkNode() -> " << data << endl;
    }
};

class Stack {
private:
    StkNode *top; // ջ��ָ�룬��ջΪ��ʱ��ָ��ΪNULL
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
    //������һ��ջ��Ҫ���ǵ���һ��ջ�޸�ʱ����Ӱ�쵽��ջ���������ν����ƣ�
    ~Stack();
    Stack& operator= (const Stack & copyStk);
    void push(StkType newNodeData);
    StkType pop();
    //pop��ջ�����Ұ�ջ�������ݷ��أ����ջ�ǿ� ����'\0'
    void clear();
    // ���ջ
    int getSize() const;
    // ��ȡջ�ڵ���Ŀ
    StkType getTop() const;
    bool isEmpty() const;
    //��ӡ��ջ����ջ��
    //���磺
    //��ջ��5��Ԫ�ص�ʱ�򣬴�ӡ���ң�Stack(5): a->c->b->d->e
    //��ջû��Ԫ�ص�ʱ�򣬴�ӡ���У�Stack(0)
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
