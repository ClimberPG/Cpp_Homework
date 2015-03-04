#include <iostream>
#include <string>
using namespace std;
class Animal {
public:
    Animal(string n): name(n) {}
    virtual string shout() {
        return "";
    }
public:
    string name;
};

class Dog: public Animal {
public:
    Dog(string name, string color) : Animal(name), color(color) {}
    string shout();
    string getColor() {
        return color;
    }
private:
    string color;
};

class Donkey: public Animal {
public:
    Donkey(string name, int weight) : Animal(name), weight(weight) {}
    string shout();
    int getWeight() {
        return weight;
    }
private:
    int weight;
};

string Dog::shout() {
    return "bark";
}

string Donkey::shout() {
    return "hee-haw";
}
