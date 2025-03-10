/*#include <iostream>

class Animal {
public:
    virtual void speak() { std::cout << "Animal speaks\n"; }
};

class Cat : public Animal {
public:
    void speak() override { std::cout << "Meow\n"; }
};

class Dog : public Animal {
public:
    void speak() override { std::cout << "Woof\n"; }
};

int main() {
    Animal* a1 = new Cat();
    Animal* a2 = new Dog();

    a1->speak(); // Now prints "Meow"
    a2->speak(); // Now prints "Woof"

    delete a1;
    delete a2;
}*/


/*#include <iostream>

class Animal {
public:
    virtual void speak() { std::cout << "Animal speaks\n"; }
};

class Cat : public Animal {
public:
    void speak() override { std::cout << "Meow\n"; }
};

int main() {
    Cat c;
    Animal& a = c;  // Object slicing happens here!
    a.speak();     // What will this print?
}*/


/*#include <iostream>

class Animal {
public:
    virtual ~Animal() { std::cout << "Animal destroyed\n"; }
};

class Cat : public Animal {
public:
    ~Cat() { std::cout << "Cat destroyed\n"; }
};

int main() {
    Animal* a = new Cat();
    delete a;  // Ensures Cat's destructor is called
}
*/

#include <iostream>

class Animal {
public:
    virtual void speak() = 0;  // Pure virtual function
    virtual ~Animal() = default;
};

class Cat : public Animal {
public:
    void speak() override { std::cout << "Meow"; }
};

std::ostream& operator<<(std::ostream& os, Animal& a) {
    a.speak();
    return os;
}

int main() {
    Cat c;
    std::cout << c << std::endl;  // Prints "Meow"
}