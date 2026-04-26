#include <iostream>
using namespace std;
class message
{
    public:
        string name;

    private:
        string place;
};
int main()
{

    message m;
    m.name = "elaks"; //(public)
    // m.place  -> not allowed (private)
    return 0;
}