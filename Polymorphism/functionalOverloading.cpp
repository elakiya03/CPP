/*polymorphism as the ability of a message to be displayed in more than one form*/
#include <iostream>
using namespace std;

class Display
{
public:
    void func(int x)
    {
        cout << x<<endl;
    }
    void func(float x)
    {
        cout << x<<endl;
    }
    void func(int x, string y)
    {
        cout << x << " " << y<<endl;
    }
};
int main()
{
    Display d;
    d.func(1);
    d.func(1.0f);
    d.func(1, "elakiya");
}