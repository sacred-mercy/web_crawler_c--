#include <iostream>
#include <cmath>

// Base class Shape
class Shape
{
public:
    virtual double area() const = 0; // Pure virtual function for calculating area
    virtual ~Shape() {}              // Virtual destructor to ensure proper cleanup of derived classes
};

// Derived class Circle
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Implementation of area calculation for the Circle
    virtual double area() const override
    {
        return M_PI * radius * radius;
    }
};

// Derived class Rectangle
class Rectangle : public Shape
{
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Implementation of area calculation for the Rectangle
    virtual double area() const override
    {
        return width * height;
    }
};

int main()
{
    // Create instances of Circle and Rectangle
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    // Polymorphic behavior using pointers to the base class
    Shape *shape1 = &circle;
    Shape *shape2 = &rectangle;

    // Calculate and display the areas of the shapes
    std::cout << "Area of Circle: " << shape1->area() << std::endl;
    std::cout << "Area of Rectangle: " << shape2->area() << std::endl;

    return 0;
}
