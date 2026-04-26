#include<iostream>
using namespace std;

// Lambda assigned to a global variable
auto multiply = [](int a, int b) { return a * b; };

int main(){
    // 1.simple lambda
    // Lambdas don’t have a name, so auto is needed
    auto add = [](int a, int b) { return a + b; };  // Lambda function
    cout << "Sum: " << add(3, 5) << endl;           // Calling lambda


    //2.lambda without parameters
    auto greet = []()
    { cout << "Hello, Elakiya! 😊" << endl; };
    greet();

    //3.capturing variables
    int x = 10;
    auto printX = [x]()
    { cout << "Captured x: " << x << endl; };
    printX();

    //4.declaring lamda outside main()
    cout << "Product: " << multiply(4, 5) << endl; // Calling lambda
    return 0;
}