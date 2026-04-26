#include <iostream>
using namespace std;

enum week
{
    MON = 1,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
};

void printDay(week w)
{
    switch (w)
    {
    case MON:
        cout << "Monday" << endl;
        break;
    case TUE:
        cout << "Tuesday" << endl;
        break;
    case WED:
        cout << "Wednesday" << endl;
        break;
    case THU:
        cout << "Thursday" << endl;
        break;
    case FRI:
        cout << "Friday" << endl;
        break;
    case SAT:
        cout << "Saturday" << endl;
        break;
    case SUN:
        cout << "Sunday" << endl;
        break;
    }
}

int main()
{
    week today = FRI;

    printDay(today);
}
