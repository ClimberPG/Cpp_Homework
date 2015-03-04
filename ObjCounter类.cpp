#include <iostream>
using namespace std;
class ObjCounter {
private:
    static int counter;
public:
    ObjCounter();
    ~ObjCounter();
    static int getCounter();
    
};

int ObjCounter::counter = 0;

ObjCounter::ObjCounter() {
    counter++;
}

ObjCounter::~ObjCounter() {
    counter--;
}

int ObjCounter::getCounter() {
    return counter;
}