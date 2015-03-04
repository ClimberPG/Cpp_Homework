#include <iostream>
using namespace std;

class E {
public:
    E() {
        cout << "In E()" << endl;
    }
    ~E() {
        cout << "In ~E()" << endl;
    }
};


class C {
public:
    C() {
        cout << "In C()" << endl;
    }
    ~C() {
        cout << "In ~C()" << endl;
    }
};

class D : public C {
public:
    D() {
        cout << "In D()" << endl;
    }
    ~D() {
        cout << "In ~D()" << endl;
    }
};

class A : public C {
public:
    A() {
        cout << "In A()" << endl;
    }
    ~A() {
        cout << "In ~A()" << endl;
    }
};

class B : public E, public D, public A {
public:
    B() {
        cout << "In B()" << endl;
    }
    ~B() {
        cout << "In ~B()" << endl;
    }
};

int main() {
    B b;
    return 0;
}
