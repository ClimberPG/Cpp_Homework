#include <iostream>
#include <string>
using namespace std;
class Visitor {
private:
    string IP, username;
    static int counter;
public:
    Visitor();
    ~Visitor();
    static int getCounter();
    void setInfo(string IP_, string username_);
    string getIP();
    string getUsername();
};

int main() {
    Visitor *v1 = new Visitor();
    Visitor *v2 = new Visitor();
    cout << Visitor::getCounter() << endl;
    delete v1;
    cout << Visitor::getCounter() << endl;
    v2->setInfo("172.168.0.1", "Visitor2");
    cout  << v2->getIP() << "," << v2->getUsername() << endl;
    delete v2;
    cout << Visitor::getCounter() << endl;
    return 0;
}

int Visitor::counter = 0;

Visitor::Visitor() {
    counter++;
}

Visitor::~Visitor() {
    counter--;
}

int Visitor::getCounter() {
    return counter;
}

void Visitor::setInfo(string IP_, string username_) {
    IP = IP_;
    username = username_;
    return;
}

string Visitor::getIP() {
    return IP;
}

string Visitor::getUsername() {
    return username;
}
