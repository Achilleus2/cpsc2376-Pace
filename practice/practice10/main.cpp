#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <iomanip>

class Shape 
{
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape 
{
private:
    double width;
    double height;
public:
    Rectangle(double a, double b) : width(a), height(b) {}

    double getArea() const override 
    {
        return width * height;
    }
};

class Circle : public Shape 
{
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double getArea() const override 
    {
        return 3.14159 * radius * radius;
    }
};

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) 
{
    std::cout << std::fixed << std::setprecision(4);

    for (const auto& shape : shapes) 
    {
        std::cout << "Area: " << shape->getArea() << std::endl;
    }
}

int main() {
    std::ifstream inputFile("shapes.txt");
    if (!inputFile) 
    {
        std::cerr << "Error: Could not open file 'shapes.txt'.\n";
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;

    while (std::getline(inputFile, line)) 
    {
        std::istringstream iss(line);
        std::string shapeType;
        iss >> shapeType;

        if (shapeType == "rectangle") 
        {
            double width, height;

            if (iss >> width >> height) 
            {
                shapes.push_back(std::make_unique<Rectangle>(width, height));
            }
        }
        else if (shapeType == "circle") 
        {
            double radius;

            if (iss >> radius) 
            {
                shapes.push_back(std::make_unique<Circle>(radius));
            }
        }
    }

    printAllAreas(shapes);
    return 0;
}