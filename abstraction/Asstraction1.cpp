#include<iostream>
using namespace std;

class Abstract{
    private:
        string myname;
        int myage;
    public:
        void setDetails(string name, int age){
            myname= name;
            myage = age;
        }

        void getDetails(){
            cout << "Her name is " << myname << " and her age is " << myage << endl;
        }
};

int main(){
    Abstract a;
    a.setDetails("elak", 23);
    a.getDetails();
}