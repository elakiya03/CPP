/*In the program we have declared an empty class.In the try block
we are throwing an object of demo class type. The try block catches the object and displays.*/

#include <iostream>
using namespace std;

class Number
{
private:
    int a;
    int b;

public:
    Number(int x, int y)
    {
        a = x;
        b = y;
    }

    bool isPrime(int n)
    {
        if (n < 2)
            return false;
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int gcd()
    {
        if (a != b)
        {
            if (a > b)
                a = a - b;
            else
                b = b - a;
        }
        return a;
    }
};

class MyPrimeException
{
};

int main()
{
    Number n(12, 5);

    cout << n.gcd() << endl;

    if (n.isPrime(12))
    {
        cout << "Prime number" << endl;
    }

    if (n.isPrime(5))
    {
        cout << "Prime number" << endl;
    }

    if (n.isPrime(12) || n.isPrime(5))
    {
        try
        {
            throw MyPrimeException();
        }
        catch (MyPrimeException m)
        {
            cout << "Exception is caught" << endl;
        }
    }
}