#include "rectangle.h"
#include <memory>
#include <iostream>

/*void createRectangle(std::unique_ptr<Rectangle>& ptr) {
    ptr = std::make_unique<Rectangle>(7, 4);
}

int main() {
    std::unique_ptr<Rectangle> rect1 = std::make_unique<Rectangle>(10, 5);
    rect1->printArea();

    std::unique_ptr<Rectangle> rect3 = std::move(rect1);
    if (!rect1) std::cout << "rect1 is null after move\n";

    std::unique_ptr<Rectangle> rect2;
    createRectangle(rect2);
    rect2->printArea();
    
    Rectangle* raw = new Rectangle(4, 3);
    std::unique_ptr<Rectangle> badPtr(raw); // BAD!

        
    return 0;
}
*/

/*
int main() {
    std::shared_ptr<Rectangle> r1 = std::make_shared<Rectangle>(10, 10);
    std::shared_ptr<Rectangle> r2 = r1;

    std::cout << "Use count: " << r1.use_count() << std::endl;

    r1.reset();

    std::cout << "After r1.reset(), use count: " << r2.use_count() << std::endl;

    std::weak_ptr<Rectangle> weak;
    {
        auto shared = std::make_shared<Rectangle>(3, 3);
        weak = shared;
        std::cout << "Inside block: expired = " << weak.expired() << std::endl;
    }
    std::cout << "Outside block: expired = " << weak.expired() << std::endl;

    return 0;
}*/

struct Node {
    std::shared_ptr<Node> next;
    Node() { std::cout << "Node constructed\n"; }
    ~Node() { std::cout << "Node destructed\n"; }
};

int main() {
    auto a = std::make_shared<Node>();
    auto b = std::make_shared<Node>();
    a->next = b;
    b->next = a;
}