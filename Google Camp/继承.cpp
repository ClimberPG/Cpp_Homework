#include <iostream>
using namespace std;

class Object {
public:
    string instance;
    Object() {};
    ~Object() {};
};

class Animal:public Object {
public:
    Animal() { instance = "Animal"; }
    ~Animal() {};
};

class Dog:public Animal {
public:
    Dog() { instance = "Dog"; }
    ~Dog() {};
};

class Cat:public Animal {
public:
    Cat() { instance = "Cat"; }
    ~Cat() {};
};

class Vehicle:public Object {
public:
    Vehicle() { instance = "Vehicle"; }
    ~Vehicle() {};
};

class Bus:public Vehicle {
public:
    Bus() { instance = "Bus"; }
    ~Bus() {};
};

class Car:public Vehicle {
public:
    Car() { instance = "Car"; }
    ~Car() {};
};

class Person:public Object {
public:
    Person() { instance = "Person"; }
    ~Person() {};
};

class Student:public Person {
public:
    Student() { instance = "Student"; }
    ~Student() {};
};

class Teacher:public Person {
public:
    Teacher() { instance = "Teacher"; }
    ~Teacher() {};
};

string instanceof(Object obj) {
    return obj.instance;
}
