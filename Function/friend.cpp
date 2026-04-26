/*private memebers of a class can only be accessed using public methods like getters ans seeters. also special function called friend function to access them directly.*/

#include <iostream>
using namespace std;
class emp
{
    string place; // default private
public:
    emp(string city) { place = city; } // construtor

    friend void displayBirthPlace(emp e); //declare friend function - A non-member function that can access the class's private data
};

void displayBirthPlace(emp e)
{
    cout << e.place;
}
int main()
{

    emp e1("Salem");
    displayBirthPlace(e1);
    return 0;
}