/*This program defines exception usinf 2 empty classes*/
#include <iostream>
using namespace std;
class c1
{
};

class c2
{
};

int main()
{
    for (int i = 1; i <= 2; i++)
    {
        try
        {
            if (i == 1)
                throw c1();
            else if (i == 2)
                throw c2();
        }

        catch (class c1)
        {
            cout << "Class 1 is caught";
        }

        catch (class c2)
        {
            cout << "Class 2 is caught";
        }
    }
}