#include <iostream>

#include <memory>

class Strategy {
public:
    virtual void execute() const = 0;
    virtual ~Strategy() = default;
};

class Run : public Strategy {
public:
    void execute() const override {
        std::cout << "Running!\n";
    }
};

class Hide : public Strategy {
public:
    void execute() const override {
        std::cout << "Hiding!\n";
    }
};

class Agent {
    std::unique_ptr<Strategy> strategy;
public:
    void setStrategy(std::unique_ptr<Strategy> s) {
        strategy = std::move(s);
    }
    void act() const {
        if (strategy) strategy->execute();
    }
};

#include <vector>
#include <functional>

class Button {
    std::vector<std::function<void()>> listeners;
public:
    void click() {
        for (auto& l : listeners) {
            l();
        }
    }
    void subscribe(const std::function<void()>& f) {
        listeners.push_back(f);
    }
};

class Counter {
    int count = 0;
public:
    void increment() {
        ++count;
    }
    int getCount() const {
        return count;
    }
    std::function<void()> getCallback() {
        return [this]() { increment(); };
    }
};

class Writer {
public:
    virtual void write() const = 0;
    virtual ~Writer() = default;
};

class PlainWriter : public Writer {
public:
    void write() const override {
        std::cout << "[TEXT]";
    }
};


class TimestampDecorator : public Writer {
    std::shared_ptr<Writer> base;
public:
    TimestampDecorator(std::shared_ptr<Writer> b) : base(std::move(b)) {}
    void write() const override {
        std::cout << "[Start]";
        base->write();
        std::cout << "[End]";
    }
};

/*
class FancyDecorator : public Writer {
    std::shared_ptr<Writer> base;
public:
    TimestampDecorator(std::shared_ptr<Writer> b) : base(std::move(b)) {}
    void write() const override {
        std::cout << "*";
        base->write();
        std::cout << "*";
    }
};*/

int main()
{
    std::unique_ptr<Strategy> s = std::make_unique<Run>();
    s->execute();

    Agent a;
    a.setStrategy(std::make_unique<Hide>());
    a.act();

    Button b;
    Counter c;

    b.subscribe(c.getCallback());
    b.click();
    b.click();
    std::cout << c.getCount() << "\n";

    std::shared_ptr<Writer> w = std::make_shared<TimestampDecorator>(
        std::make_shared<PlainWriter>());
    w->write();

    return 0;
}