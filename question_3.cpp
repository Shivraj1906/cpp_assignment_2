/**
 * Yes
 * Reason:
 * Suppose we also have parameterized constructor in base class.
 * Then we have no way to invoke that constuctor if we don't write any constructor in sub-class.
 * 
 * Explained in example:
*/


#include<iostream>

using namespace std;

class B {
    int a;

    public:
    B() {
        a = 0;
    }


    //We can't invoke this constructor if we don't write constuctor in sub-class
    B(int a) {
        this->a = a;
    }

    void display() {
        cout << a << endl;
    }
};

class D : public B {
};

int main() {
    
    D d;

    d.display(); // Output: 0
    return 0;
}