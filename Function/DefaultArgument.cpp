/* A default argument is a value provided for a parameter in a function declaration that is automatically
assigned by the compiler if the calling function doesn’t provide a value for those parameters. If the
value is passed for it, the default value is overridden by the passed value
 */

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

// Declaration with default argument
void func(int x = 10);

// Definition of func()
void func(int x)
{
    cout << "Value of x: " << x << endl;
}

// In a function with multiple parameters, default values must be provided from the rightmost parameter to the left
// Function with default height 'h' argument
double calcArea(double l, double h = 10.0)
{
    return l * h;
}

int main()
{
    func();
    func(8);
    
    // Uses default height
    cout << calcArea(5) << endl;

    // Uses custom height
    cout << calcArea(5, 7);
    return 0;
}