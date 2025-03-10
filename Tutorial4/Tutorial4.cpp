#include <iostream>


struct Point
{
    int x;
    int y;

    friend std::ostream& operator<<(std::ostream& os, const Point& p)
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

template<typename T>
void display(T value) {
    std::cout << "Value: " << value << "\n";
}




template <typename T, typename U>
void showPair(T a, U b) {
    std::cout << a << " and " << b << "\n";
}

int main() {
    showPair(10, 3.5);
    showPair("Alice", 42);
    return 0;
}





template <typename T, typename U>
auto max(T a, U b) -> decltype(a > b ? a : b)  //decltype is stange syntax and I wouldn't normally suggest it but this is fun to play with anyways.
{
    if (a > b) return a;
    else return b;
}