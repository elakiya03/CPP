#include <iostream>
using namespace std;
class BankAccount {
   private:  // only accessible inside the class
    double balance;
    string pin;

   protected:  // accessible inside class + derived classes
    string accountNumber;

   public:  // accessible from anywhere
    string ownerName;

    void deposit(double amount) {
        if (amount > 0)
            balance += amount;  // private member — accessible here
    }

    double getBalance() {
        return balance;  // controlled access to private data
    }
};

int main() {
    BankAccount acc;
    acc.ownerName = "Alice";  // OK — public
    acc.deposit(1000);        // OK — public method
    cout << acc.getBalance() << endl;
    // acc.balance = 9999;      // ERROR — private
    // acc.pin    = "1234";     // ERROR — private
}