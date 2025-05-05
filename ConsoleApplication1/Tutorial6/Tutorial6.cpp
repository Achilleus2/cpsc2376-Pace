#include <iostream>

class A {
public:
     void show() { std::cout << "A" << std::endl; }
};

class B : public A {};
class C : public A {};
class D : public B, public C {};


class Engine {
public:
    Engine() { std::cout << "Engine created!" << std::endl; }
};

class Animal {
protected:
    int age = 5;
private:

    Engine engine;
public:
    void speak() {
        std::cout << "Animal speaks" << std::endl;
    }

    //Animal() {
    //    std::cout << "Animal created!" << std::endl;
    //}

    Animal(int age = 10) : age(age)
    {
        std::cout << "Animal created with age " << age << std::endl;
    }

    void setAge(int a) { age = a; }

    int getAge() { return age; }

    friend void showAge(Animal a);

    Animal operator+(Animal other) {
        return Animal(this->age + other.age);
    }

};
void showAge(Animal a) {
    std::cout << "Age: " << a.age << std::endl;
}

class Dog : public Animal {
public:
    Dog(int age) : Animal(age) {}

    void showDogAge() {
        std::cout << "Dog age: " << age << std::endl;
    }
};

int main() {

    Animal b;
    Animal c(11);
    Animal d = c + b;
    showAge(d);

    return 0;
}