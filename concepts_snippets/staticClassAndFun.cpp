#include <iostream>
#include <cmath>

class MathUtils
{
public:
    // Static function to calculate the area of a circle
    static double calculateCircleArea(double radius)
    {
        return M_PI * radius * radius;
    }
};

int main()
{
    double radius = 5.0;

    // Use the static function without creating an instance of MathUtils
    double area = MathUtils::calculateCircleArea(radius);

    std::cout << "Area of the circle with radius " << radius << " is: " << area << std::endl;

    return 0;
}
