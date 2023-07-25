#include <iostream>
#include <string>

// Base class: Person
class Person
{
public:
    std::string name; // Public member accessible directly from outside the class
    int age;          // Public member accessible directly from outside the class

    Person(const std::string &name, int age)
        : name(name), age(age) {}

    void displayInfo()
    {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

protected:
    std::string address; // Protected member accessible within the class and derived class

private:
    int ssn; // Private member inaccessible from outside the class

    // Private function only accessible within the class
    void setSSN(int ssn)
    {
        this->ssn = ssn;
    }
};

// Derived class: Employee
class Employee : public Person
{
public:
    int employeeId; // Public member accessible directly from outside the class

    Employee(const std::string &name, int age, int employeeId)
        : Person(name, age), employeeId(employeeId) {}

    void displayEmployeeInfo()
    {
        std::cout << "Employee ID: " << employeeId << std::endl;
        std::cout << "Address (protected): " << address << std::endl;
    }

    // Public function to access the protected member of the base class
    void setAddress(const std::string &address)
    {
        this->address = address;
    }
};

int main()
{
    // Create an Employee object and access its members
    Employee employee("John Doe", 30, 12345);

    employee.name = "Jane Smith"; // Accessible (public member of the base class)
    employee.age = 35;            // Accessible (public member of the base class)
    // employee.address = "123 Main St"; // Not accessible (protected member of the base class)
    employee.setAddress("123 Main St"); // Accessible through public function
    // employee.ssn = 987654321; // Not accessible (private member of the base class)

    employee.displayInfo();         // Display name and age
    employee.displayEmployeeInfo(); // Display employee ID and address

    return 0;
}
