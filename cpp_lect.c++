#include <bits/stdc++.h> //includes all libraries
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip> // Required for manipulators
// In C++, the iostream header file contains declarations and definitions for input and output operations. It provides classes like std::cin and std::cout that allow you to read from and write to the standard input/output streams, respectively.

// There are two main types of header files in C++:
//  System Header Files: System header files are provided by the C++ standard library and the operating system.Examples of system header files include <iostream>, <vector>, <string>, and <cmath>.
// User-Defined Header Files:User-defined header files are created by programmers to define their own functions, classes, and other entities. These files typically have names that end with the .h or .hpp extensions.

// Local variable and global variables can have same name but precedence will be given to local variable ie if there are 2 variables with name a=4(local),a=6(global) then when adding a with lets say b=10 in any function, the output will be 14;

// In C++, there are several built-in data types that you can use to declare variables. Here are some commonly used data types in C++:

// Fundamental Data Types:
// int: Used to represent integers (whole numbers).
// float: Used to represent floating-point numbers with single precision.
// double: Used to represent floating-point numbers with double precision.
// char: Used to represent single characters.
// bool: Used to represent Boolean values (true or false).

// Modifier Data Types:
// unsigned int: Used to represent non-negative integers (greater than or equal to 0).
// long: Used to represent larger range integers.
// long long: Used to represent even larger range integers.
// unsigned long: Used to represent non-negative larger range integers.
// unsigned long long: Used to represent non-negative even larger range integers.

// Derived Data Types:
// array: A fixed-size collection of elements of the same data type.
// string: A sequence of characters.
// struct: A user-defined data type that allows you to group together multiple variables of different types.
// class: A user-defined data type that allows you to define complex data structures with member variables and functions.

// Pointer and Reference Types:
// pointer: A variable that holds the memory address of another variable.
// reference: An alias for an existing variable.

using namespace std; // we can either include using namespace std at the top or do std::cout
int a1 = 6;

void display1(vector<int> &v){
for (int i = 0; i < v.size(); i++)
{
    cout<<v[i]<<" ";
}
cout<<endl;

}

struct employee
{
    // data
    int eId;
    char favChar;
    float salary;
};

union money
{
    int rice;
    char car;
    float pounds;
};

enum Color
{
    RED,
    GREEN,
    BLUE
};

int calculateSquare(int num) // num is called formal parameter
{
    int square = num * num;
    return square;
}

inline int product(int a, int b)
{
    return a * b;
}

int product1(int a, int b)
{
    static int c = 0;
    c = c + 1;
    return a * b + c;
}

void printMessage(const string &message = "Hello, World!") // NOTE: if there are multiple arguments always write default arguments at the end
{
    cout << message << endl;
}

void printNumber(const int num)
{
    // Attempting to modify the constant parameter will result in a compilation error
    // num = 10; // Error: assignment of read-only parameter 'num'

    cout << "Number: " << num << endl;
}

// Call by Value
void swapByValue(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Call by Reference
void swapByReference(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
// AND CAN BE DONE THIS WAY TOO
void swapByReference1(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

// Function to calculate the volume of a cube
double calculateVolume(double sideLength)
{
    return sideLength * sideLength * sideLength;
}

// Function to calculate the volume of a cylinder
double calculateVolume(double radius, double height)
{
    const double pi = 3.14159;
    return pi * radius * radius * height;
}

class Employee
{
private:
    int a, b, c;

public:
    int d, e;
    void setData(int a, int b, int c); // Declaration
    void getData()
    {
        cout << a << " " << b << " " << c << " " << d << " " << e << endl;
    }
};

void Employee ::setData(int a1, int b1, int c1)
{
    a = a1;
    b = b1;
    c = c1;
}

class Binary
{
    string s;

public:
    void read(void); // You can declare a function inside a class like this and define it outside like done below, just add void classname :: before function name
    void chk_bin(void);
    void onescomplement(void);
    void display(void);
};

void Binary ::read(void)
{
    cout << "Enter a binary number" << endl;
    cin >> s;
}

void Binary ::chk_bin(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "Incorrect binary number" << endl;
            exit(0);
        }
    }
}

void Binary ::onescomplement(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '0')
        {
            s.at(i) = '1';
        }
        else if (s.at(i) == '1')
        {
            s.at(i) = '0';
        }
    }
}

void Binary ::display(void)
{
    cout << "Displaying your binary number" << endl;
    for (int i = 0; i < s.length(); i++)
    {
        cout << s.at(i);
    }
    cout << endl;
}

class Shop
{
    int itemId[100]; // by default private
    int itemPrice[100];
    int counter;

public:
    void initCounter(void) { counter = 0; }
    // void getPrice(void);
    void setPrice(void); // methods (a method is a function that belongs to a class or an object)
    void displayPrice(void);
};

void Shop ::setPrice(void)
{
    cout << "Enter Id of your item" << endl;
    cin >> itemId[counter];
    cout << "Enter Price of you item" << endl;
    cin >> itemPrice[counter];
    counter++;
}

void Shop ::displayPrice(void)
{
    for (int i = 0; i < counter; i++)
    {
        cout << itemId[i] << " " << itemPrice[i] << endl;
    }
}

class Employee1
{
    int id;
    static int count2;

public:
    void setData(void)
    {
        cout << "Enter id of employee " << endl;
        cin >> id;
        count2++;
    }
    void getData(void)
    {
        cout << "The id of employee is " << id << " and this is employee number " << count2 << endl;
    }
};

int Employee1 ::count2; // default value is 0

class Complex
{
    int a;
    int b;

public:
    void setData(int v1, int v2)
    {
        a = v1;
        b = v2;
    }

    void setDataByValue(Complex o1, Complex o2)
    {
        a = o1.a + o2.a;
        b = o1.b + o2.b;
    }

    void printNumber()
    {
        cout << "Your complex number is " << a << " + " << b << "i" << endl;
    }
};

int main()
{
    int a = 5, number1;
    int b = 7;
    int a1 = 4, a2 = 7;
    float a3 = 9.9, a4 = 5.6;
    char a5 = 'v';
    // cout << "The value of a1 is " << a1 << " and the value of a2 is " << a2 << "\n";
    // cout << "The value of a5 is " << a5 << "\n";
    // cout << a1 + a2 << "\n";
    // float num1, num2;
    // cout << "Enter first number: "; //'<<' is insertion operator
    // cin >> num1;                    //'>>' is extraction operator
    // cout << "Enter second number: ";
    // cin >> num2;
    // cout<<"The output is "<<num1+num2<<endl; //endl -> similar to "\n"
    // cout << "new line" << endl; // endl -> similar to "\n";
    // cout << "The value of a2++ is " << a2++ << endl;
    // cout << "The value of a2-- is " << a2-- << endl;
    // cout << "The value of ++a2 is " << ++a2 << endl;
    // cout << "The value of --a2 is " << --a2 << endl;
    // cout<<"Global a1 is "<<::a1<<endl; //global scope resolution operator ,gives 6

    //-------------------------------------------------------------------------------
    // //Comparison Operators

    // bool result1 = (a == b);
    // bool result2 = (a != b);
    // bool result3 = (a < b);
    // bool result4 = (a > b);
    // bool result5 = (a <= b);
    // bool result6 = (a >= b);
    // cout << result1 << endl; // 0 means false and 1 means true in output
    // cout << result2 << endl;
    // cout << result3 << endl;
    // cout << result4 << endl;
    // cout << result5 << endl;
    // cout << result6 << endl;

    //-------------------------------------------------------------------------------
    // Logical Operators
    // string username = "admin";
    // string password = "password";

    // cout << "Enter username: ";
    // string inputUsername;
    // cin >> inputUsername;

    // cout << "Enter password: ";
    // string inputPassword;
    // cin >> inputPassword;

    // if (inputUsername == username && inputPassword == password) {
    //     cout << "Access granted. Welcome, " << username << "!" << endl;
    // } else {
    //     cout << "Access denied. Invalid username or password." << endl;
    // }

    // cout << "Enter a number: ";
    // cin >> number1;

    // if (number1 == 0 || number1 == 10) {
    //     cout << "The number is either 0 or 10." << endl;
    // } else {
    //     cout << "The number is not 0 or 10." << endl;
    // }

    //-------------------------------------------------------------------------------
    // Reference Variable
    // float x = 455;
    // float &y = x;
    // cout<<x<<endl;
    // cout<<y<<endl;

    //-------------------------------------------------------------------------------
    // Typecasting
    // int c1 = 45;
    // cout<<"the value of c1 is "<<(float)c1<<endl;
    // //OR
    // cout<<"the value of c1 is "<<float(c1)<<endl;

    //-------------------------------------------------------------------------------
    // Constants in CPP
    // const int a10 = 34;
    // cout<<a10<<endl;
    // a10 =56;
    // cout<<a10<<endl; //you will get an error as a10 is a constant

    //-------------------------------------------------------------------------------
    // Manipulator

    // The iomanip header file is included, which provides functionality for manipulators.
    //  The std::setprecision manipulator is used to set the precision of the floating-point number pi to 4 decimal places.
    //  The std::setw manipulator is used to set the width of the output field for the string name to 10 characters.
    //  The std::left manipulator is used to align the string name to the left within the specified width.

    // int number2 = 42;
    // double pi = 3.14159;
    // string name = "John Doe";

    // cout << "Number: " << number2 << endl;
    // cout << "Pi: " << setprecision(4) << pi << endl;
    // cout << "Name: " << setw(10) << name << endl;
    // cout << "Name: " << setw(10) << left << name << endl;

    //-------------------------------------------------------------------------------
    // Operator Precedence
    // int result8 = 5 + 10 * 2 / 4 - 1;
    // std::cout << "Result: " << result8 << std::endl;

    //-------------------------------------------------------------------------------
    // Switch Case
    // int choice;

    // cout << "Menu:\n";
    // cout << "1. Option 1\n";
    // cout << "2. Option 2\n";
    // cout << "3. Option 3\n";
    // cout << "Enter your choice: ";
    // cin >> choice;

    // switch (choice)
    // {
    // case 1:
    //     cout << "You selected Option 1." << endl;
    //     break;
    // case 2:
    //     cout << "You selected Option 2." << endl;
    //     break;
    // case 3:
    //     cout << "You selected Option 3." << endl;
    //     break;
    // default:
    //     cout << "Invalid choice." << endl;
    //     break;
    // }

    //-------------------------------------------------------------------------------
    // Loops
    // Example of a for loop
    // cout << "For Loop:" << endl;
    // for (int i = 1; i <= 5; i++) {
    //     cout << "Iteration: " << i << endl;
    // }

    // // Example of a while loop
    // cout << "\nWhile Loop:" << endl;
    // int j = 1;
    // while (j <= 5) {
    //     cout << "Iteration: " << j << endl;
    //     j++;
    // }

    // // Example of a do-while loop
    // cout << "\nDo-While Loop:" << endl;
    // int k = 1;
    // do {
    //     cout << "Iteration: " << k << endl;
    //     k++;
    // } while (k <= 5);

    //-------------------------------------------------------------------------------
    // Break Continue
    //     for (int i = 1; i <= 10; i++) {
    //     if (i == 5) {
    //         break; // Terminate the loop when i becomes 5
    //     }
    //     cout << i << " ";
    // }
    // cout << "Loop terminated!" << endl;

    // for (int i = 1; i <= 10; i++) {
    //     if (i % 2 == 0) {
    //         continue; // Skip the rest of the loop body for even values of i
    //     }
    //     cout << i << " ";
    // }
    // cout << "Loop completed!" << endl;

    //-------------------------------------------------------------------------------
    // Pointers
    // int a11 = 3;
    // int *a12;
    // a12 = &a11;
    // //& -> (Address of) operator , (a12 stores address of a11)(whereas *a12 gives the value)
    // //* -> (value at) Dereference operator
    // cout << "Address of a11 is " << a12 << endl;
    // cout << "Address of a11 is " << &a11 << endl;
    // cout << "The value at address a12 is " << *a12 << endl; // output->3

    //-------------------------------------------------------------------------------
    // Arrays

    // int a13[] = {1, 2, 3, 4, 5}; // OR int a13[5] = {1, 2, 3, 4, 5};
    // int length1 = sizeof(a13) / sizeof(a13[0]);
    // for(int i = 0;i<length1;i++){
    //     cout << a13[i] << " ";
    // }

    // int numbers[] = {1, 2, 3, 4, 5};

    // // Print the elements of the array using array indexing
    // cout << "Array elements using array indexing: ";
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << numbers[i] << " ";
    // }
    // cout << endl;

    // // Print the elements of the array using pointers
    // cout << "Array elements using pointers: ";
    // int *ptr = numbers; // Pointer to the first element of the array

    // for (int i = 0; i < 5; i++)
    // {
    //     cout << *(ptr + i) << " ";
    // }
    // cout << endl;

    //-------------------------------------------------------------------------------
    // Structures/Unions

    // struct employee emp; //structure employee is made above -> struct employee{int eId,char favChar,int salary};
    // emp.eId=1;
    // emp.favChar='J';
    // emp.salary=20000;
    // cout<<"The value is "<<emp.eId<<endl;
    // cout<<"The value is "<<emp.favChar<<endl;
    // cout<<"The value is "<<emp.salary<<endl;

    // Memory Allocation:
    // Structure: Each member of a structure is allocated its own separate memory space, resulting in the total memory allocation equal to the sum of the sizes of all its members. Each member can hold a different value simultaneously.
    // Union: All members of a union share the same memory space, meaning that only one member can hold a value at a time. The size of a union is determined by the size of its largest member.

    // union money m1;
    // m1.rice = 1000;
    // cout << "The value is " << m1.rice << endl;
    // m1.car = 'T';
    // cout << "The value is " << m1.car << endl;
    // m1.pounds = 4.0;
    // cout << "The value is " << m1.pounds << endl;

    // enum Color myColor = GREEN;

    //     if (myColor == RED) {
    //         std::cout << "The color is red." << std::endl;
    //     } else if (myColor == GREEN) {
    //         std::cout << "The color is green." << std::endl;
    //     } else if (myColor == BLUE) {
    //         std::cout << "The color is blue." << std::endl;
    //     }

    //-------------------------------------------------------------------------------
    // Functions
    // int number2 = 5; //number2 is called actual parameter
    // int result2 = calculateSquare(number2);

    // cout << "The square of " << number2 << " is " << result2 << endl;

    //-------------------------------------------------------------------------------
    // Call By Reference/Call By Value
    // swapByValue is a call by value function. It takes two parameters a and b, which are passed by value. Inside the function, the values of a and b are swapped. However, these changes are local to the function and do not affect the original variables x and y in the main function.

    // swapByReference is a call by reference function. It takes two parameters a and b as references using the & symbol. Any changes made to a and b inside the function will directly modify the original variables x and y in the main function because it changes at the place of the addresses. When the values of a and b are swapped, it modifies the values at the memory locations of x and y in the main function. Thus, the original variables x and y are updated with the swapped values.

    int x = 10, x1 = 40;
    int y = 20, y1 = 50;

    // cout << "Before swapping: x = " << x << ", y = " << y << endl;

    // swapByValue(x, y);
    // cout << "After swapByValue: x = " << x << ", y = " << y << endl;

    // swapByReference(x, y);
    // cout << "After swapByReference: x = " << x << ", y = " << y << endl;

    // swapByReference1(&x1, &y1);
    // cout << "After swapByReference1: x1 = " << x1 << ", y1 = " << y1 << endl;

    //-------------------------------------------------------------------------------
    // Inline functions/Static variables/Functions with default argument

    // Inline functions are used for performance optimization and code organization purposes. When a function is declared as inline, it suggests to the compiler to replace the function call with the actual code of the function at the point where the function is invoked. This eliminates the overhead of the function call, such as stack manipulation and parameter passing.

    // int a14,b14;
    // cout<<"Enter a14 and b14"<<endl;
    // cin>>a14>>b14;
    // cout<<product(a14,b14);

    // int a14,b14;
    //     cout<<"Enter a14 and b14"<<endl;
    //     cin>>a14>>b14;
    //     cout<<product1(a14,b14)<<endl;
    //     cout<<product1(a14,b14)<<endl;
    //     cout<<product1(a14,b14)<<endl;
    //     cout<<product1(a14,b14)<<endl;

    // Call the function without specifying the message
    // printMessage(); // Output: Hello, World!

    // // Call the function with a custom message
    // printMessage("Welcome!"); // Output: Welcome!

    //   int value = 5;
    //     printNumber(value);

    //-------------------------------------------------------------------------------
    // Recursions
    // int num = 5;
    // int result = factorial(num);
    // cout << "Factorial of " << num << " is: " << result << endl;

    //-------------------------------------------------------------------------------
    // Function Overloading
    // Function overloading is a feature in C++ that allows you to define multiple functions with the same name but different parameter lists. The compiler determines which function to call based on the arguments provided during the function call. Function overloading enables you to perform similar operations on different data types or with different numbers of arguments.

    // double cubeSideLength = 3.0;
    // double cylinderRadius = 2.0;
    // double cylinderHeight = 5.0;

    // double cubeVolume = calculateVolume(cubeSideLength);
    // double cylinderVolume = calculateVolume(cylinderRadius, cylinderHeight);

    // cout << "Volume of the cube: " << cubeVolume << endl;
    // cout << "Volume of the cylinder: " << cylinderVolume << endl;

    //-------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------
    // OOPS
    // Class: A class is a blueprint or a template that defines the properties (attributes) and behaviors (methods) of objects. It serves as a blueprint for creating objects.

    // Object: An object is an instance of a class. It represents a real-world entity that has specific characteristics and behaviors defined by its class.

    // Encapsulation: Encapsulation is the process of bundling data (attributes) and methods (behaviors) together within a class. It hides the internal details of an object and provides controlled access to its properties through methods.

    // Inheritance: Inheritance is a mechanism that allows a class to inherit properties and behaviors from another class. It enables code reuse and promotes the concept of hierarchical relationships between classes.

    // Polymorphism: Polymorphism means the ability of an object to take on many forms. In the context of OOP, it refers to the ability of different objects to respond to the same message (method) in different ways. Polymorphism allows for flexibility and extensibility in code.

    // Abstraction: Abstraction is the process of simplifying complex systems by representing essential features and hiding unnecessary details. It allows you to focus on the relevant aspects of an object or system while ignoring the implementation details.

    // Method: A method is a function or behavior associated with an object or class. It defines the operations or actions that objects of a class can perform.

    // Attribute: An attribute, also known as a member variable or data member, represents the state or characteristics of an object. It holds the data associated with an object.

    // Constructor: A constructor is a special method that is called when an object is created. It initializes the object's state and performs any necessary setup.

    // Destructor: A destructor is a special method that is called when an object is destroyed or goes out of scope. It performs cleanup tasks and frees up any resources held by the object.

    //-------------------------------------------------------------------------------
    // Classes
    // Private members:
    // Private members are only accessible within the same class where they are declared.
    // They are not accessible from outside the class, including derived classes.
    // Private members are typically used for internal implementation details or sensitive data that should not be directly accessed or modified from outside the class.
    // To access or modify private members, public member functions (getters and setters) or friend functions can be used.

    // Public members:
    // Public members are accessible from anywhere, including outside the class and derived classes.
    // They can be accessed and modified directly without the need for any additional functions.
    // Public members represent the interface or the public contract of the class, providing access to the class's properties and behaviors to other parts of the program.
    // Public members should be carefully designed and documented as they have wider visibility and can affect the overall behavior of the class.

    // Example1:
    // Create object of the class Employee
    //  Employee john;
    //  // john.a = 90; //this will throw error as a is private cant be accessed outsite the class
    //  john.d = 35;
    //  john.e = 5;
    //  john.setData(1, 2, 4);
    //  john.getData();

    // Example2:
    // Binary var;
    // var.read();
    // var.chk_bin();
    // var.display();
    // var.onescomplement();
    // var.display();

    // Shop s1;
    // s1.initCounter();
    // s1.setPrice();
    // s1.setPrice();
    // s1.setPrice();
    // s1.displayPrice();

    // Employee1 ved1,nikola1,galileo1;
    // ved1.id = 1;
    // ved1.count2 = 1 //cannot do this as id and count are private
    // hence we make it a static variable use it accordingly in setData and getData

    // ved1.setData();
    // ved1.getData();

    // nikola1.setData();
    // nikola1.getData();

    // galileo1.setData();
    // galileo1.getData();

    // Complex c1,c2,c3;     // Create object of the class Complex
    // c1.setData(1,2);
    // c1.printNumber();

    // c2.setData(3,4);
    // c2.printNumber();
    // c3.setDataByValue(c1,c2);
    // c3.printNumber();

    //-------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------
    // STL(Standard Template Library)
    // The STL is divided into several components:

    // 1.Containers: These are data structures that store and manage collections of objects. Some commonly used containers in the STL include:
    //  Vector: A dynamic array that can resize itself as elements are added or removed.
    //  List: A doubly-linked list that allows for efficient insertions and deletions.
    //  Deque: A double-ended queue that allows for efficient insertions and deletions at both ends.
    //  Set: A container that stores unique elements in a sorted order.
    //  Map: A container that stores key-value pairs in a sorted order based on the keys.
    //  Stack: A container that provides a last-in, first-out (LIFO) data structure.
    //  Queue: A container that provides a first-in, first-out (FIFO) data structure.

    // 2. Algorithms: The STL provides a wide range of algorithms that operate on containers or other sequences of data. These algorithms include sorting, searching, and manipulation functions. Some commonly used algorithms include std::sort, std::find, std::transform, and more.

    // 3. Iterators: Iterators are used to access elements in containers sequentially. They provide a way to navigate through container elements without exposing the underlying implementation details.

    // 4. Function Objects (Functors): Function objects are objects that behave like functions. They are often used as arguments to algorithms to specify custom behavior.

    // 5. Allocators: Allocators provide a mechanism for managing memory allocation and deallocation for containers.

    //-------------------------------------------------------------------------------
    // Vectors
    // Here's a list of some important methods and operations available for std::vector:

    // Constructor and Destructor:
    // std::vector<T>: Creates an empty vector of type T.
    // std::vector<T>(size_t n): Creates a vector with n default-initialized elements.
    // std::vector<T>(size_t n, const T& value): Creates a vector with n copies of value.
    // std::vector<T>(const std::vector<T>& other): Creates a copy of another vector.
    // ~std::vector<T>(): Destructor, releases memory.

    // Element Access:
    // operator[], at(index): Access elements by index.
    // front(): Returns the first element.
    // back(): Returns the last element.
    // data(): Returns a pointer to the underlying array.

    // Modifiers:
    // push_back(value): Adds an element to the end.
    // pop_back(): Removes the last element.
    // insert(iterator, value): Inserts value before the iterator.
    // erase(iterator): Removes the element pointed to by the iterator.
    // clear(): Removes all elements.
    // resize(newSize), resize(newSize, value): Resizes the vector.
    // swap(other): Swaps the contents with another vector.

    // Capacity:
    // size(): Returns the number of elements.
    // empty(): Checks if the vector is empty.
    // reserve(newCapacity): Allocates memory for at least newCapacity elements.
    // capacity(): Returns the current capacity.
    // shrink_to_fit(): Reduces capacity to fit the size.
    // Iterators:

    // begin(), end(): Returns iterators to the beginning and end.
    // rbegin(), rend(): Reverse iterators.
    // Modifiers:

    // assign(first, last): Assigns elements from the range [first, last).
    // assign(count, value): Assigns count copies of value.
    // emplace(), emplace_back(args): Constructs elements in-place.
    // insert(iterator, count, value): Inserts count copies of value.
    // insert(iterator, first, last): Inserts elements from the range [first, last).
    // Algorithms:

    // std::sort(first, last): Sorts the range.
    // std::find(first, last, value): Finds the first occurrence of value.

    //Ways to create a vector
    vector<int> vec1; //zero length vector
    vector<int> vec2(4); //4-element vector
    vector<int> vec3(vec2); //4-element vector from vec2
    vector<int> vec4(6,3); //6-element vector of 3's (3 3 3 3 3 3)

    // int element,size;
    // cout<<"Enter size of vector"<<endl;
    // cin>>size;
    // for (int i = 0; i < size; i++)
    // {
    //     cout << "Enter an element to add to the vector ";
    //     cin >> element;
    //     vec1.push_back(element);
    // }
    // // vec1.pop_back();
    // display1(vec1);
    // vector<int>::iterator iter= vec1.begin(); //making an iterator named iter and pointing it to the start of vector
    // // vec1.insert(iter,555); //now as iter points to start of list 555 gets inserted at the start
    // // vec1.insert(iter+1,555); // 555 gets inserted at the start+1 position 
    // vec1.insert(iter+1,5,555); // inserts 5 copies of 555 at the start+1 position 
    // cout<<"New list"<<endl;
    // display1(vec1);

    // display1(vec4);
    // std::vector<int> numbers30 = {10, 20, 30, 40, 50};
    // int value = numbers30.at(2);  // Access the element at index 2 (30)
    // std::cout << "Value at index 2: " << value << std::endl;


    //-------------------------------------------------------------------------------
    // List
    // list<int> list1; //list of length 0
    // list<int> list2;
    // list<int> list3(7); //empty list of size 7
    // list1.push_back(6);
    // list1.push_back(2);
    // list1.push_back(5);
    // list1.push_back(45);

    // list2.push_back(7);
    // list2.push_back(14);
    // list1.sort();
    // list<int> :: iterator iter;
    // iter = list1.begin(); //iterator named iter will point at beginning of list list1
    // cout<< *iter<<endl; 
    // iter++;
    // cout<<*iter<<endl;
    // iter++;
    // cout<<*iter<<endl;
    // iter++;
    // cout<<*iter<<endl;

    // list1.merge(list2);
    // cout<<"List1 after merging with list2 "<<endl;
    // list<int> :: iterator iter2;
    // iter2 = list1.begin(); //iterator named iter will point at beginning of list list1
    // cout<< *iter2<<endl; 
    // iter2++;
    // cout<<*iter2<<endl;
    // iter2++;
    // cout<<*iter2<<endl;
    // iter2++;
    // cout<<*iter2<<endl;
    // iter2++;
    // cout<<*iter2<<endl;
    // iter2++;
    // cout<<*iter2<<endl;
    // list1.reverse();

    // list<int> myList;
    // list<int> anotherList = {1, 2, 3};

    // myList.push_back(4);
    // myList.push_front(0);
    // myList.insert(myList.begin(), 2);
    // myList.pop_back();
    // myList.pop_front();
    // // myList.erase(myList.begin());
    // // myList.clear();
    // int frontElement = myList.front();
    // int backElement = myList.back();
    // myList.front() = 10;
    // myList.back() = 20;

    // for (auto it = myList.begin(); it != myList.end(); ++it) {
    //     // Access or modify elements using iterator 'it'
    // }

    // for (const auto& element : myList) {
    //     // Access each element directly
    //     cout << element << " ";
    // }

    // bool isEmpty = myList.empty();
    // size_t size = myList.size();

    // auto it = find(myList.begin(), myList.end(), 3);
    // if (it != myList.end()) {
    //     // Element found, 'it' is the iterator to the found element
    // }

    // int countOfTwos = count(myList.begin(), myList.end(), 2);

    // myList.sort();
    // myList.reverse();

    //-------------------------------------------------------------------------------
    // Maps
    //used to store key value pairs
    // map<string, int> marksMap;
    
    // marksMap["Henry"] = 98;
    // marksMap["Jack"] = 58;
    // marksMap["Rohan"] = 2;

    // marksMap.insert({{"Person1",34},{"Person2",76}});
    // map<string, int> :: iterator itr;
    // for(itr=marksMap.begin();itr!=marksMap.end();itr++){
    //     cout<<(*itr).first<<" "<<(*itr).second<<"\n"; //like for first iteration first will fetch us Henry and second will fetch us 98
    // }
    // cout<<"The size is: "<<marksMap.size()<<endl;
    // cout<<"The max size is: "<<marksMap.max_size()<<endl;
    // cout<<"The empty's return value is: "<<marksMap.empty()<<endl;


    //-------------------------------------------------------------------------------
    // Function Objects(Functors)
    // A function wrapped inside a class so that it is available like an object
    int arr10[] = {134,32,4,12,540,77};
    sort(arr10,arr10+6); //sorts in ascending order
    sort(arr10,arr10+6, greater<int>()); //sorts in decending order
    for(int i = 0;i<6;i++){
        cout<<arr10[i]<<endl;
    }


    return 0;
}