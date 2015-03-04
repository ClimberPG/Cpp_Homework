#include <iostream>
#include <string>
using namespace std;
class Person {
public:
    Person() {
        cout << "Construct Person" << endl;
    }
    ~Person() {
        cout << "Destruct Person" << endl;
    }
public:
    string name;//姓名
    int sex;//1表示男0表示女
};

class Student : virtual public Person {
public:
    Student() {
        cout << "Construct Student" << endl;
    }
    ~Student() {
        cout << "Destruct Student" << endl;
    }
public:
    string sno;
};

class Worker : virtual public Person {
public:
    Worker() {
        cout << "Construct Worker" << endl;
    }
    ~Worker() {
        cout << "Destruct Worker" << endl;
    }
public:
    string wno;
};

class InService : virtual public Student, virtual public Worker {
public :
    InService() {
        cout << "Construct InService" << endl;
    }
    ~InService() {
        cout << "Destruct InService" << endl;
    }
};
int main() {
    InService is;
    is.name = "name";
    is.sex = 0;
    is.sno = "10390000";
    is.wno = "10990000";
    cout << ((Person*)(&is))->name << endl;
    cout << ((Person*)(&is))->sex << endl;
    cout << ((Student*)(&is))->sno << endl;
    cout << ((Worker*)(&is))->wno << endl;
    return 0;
}