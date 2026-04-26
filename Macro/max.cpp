#include <iostream>
using namespace std;

#define MAX(A,B) (((A) >= (B)) ? (A) : (B)) // ((a-- >= ++b) ? a-- : ++b)

int main() {
    int a = 10, b = 9;
    cout << MAX(a--, ++b) << endl;
    return 0;
}

/*
Step 1 — Pre-increment b

++b → b = 10

Step 2 — Compare a-- >= ++b

a-- is 10 (post-decrement, so a will become 9 after this expression)
++b is 10

Compare: 10 >= 10 → true --> Key

Step 3 — Conditional operator result

Since condition is true → result is a--

Current a is 9 (from Step 2)
a-- evaluates to 9 and then a becomes 8
Step 4 — Output

cout << 9 → prints:

*/