/*static should not be used again in the function definition outside the class. It should only be declared static inside the class.*/
#include <iostream>
using namespace std;

class Count
{
public:
    static int count; // Static variable declaration

    Count() { count++; } // Constructor increments count

    static void display(); // Static function declaration
};

// ✅ Remove `static` from the function definition
void Count::display()
{
    cout << "No of times object instantiated: " << count << endl;
}

// ✅ Define and initialize static variable outside the class
int Count::count = 0;

int main()
{
    Count c1, c2, c3; // Three objects created, count should be 3
    Count::display(); // Call static function
}
