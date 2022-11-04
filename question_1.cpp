/**
 * Protected data members:
 * Protected specifier allows members to be inherited to sub-class.
 * But restricts access outside base-class and sub-class.
 * 
 * Protected specifier as mode of inheritance
 * When used, all protected and public members of base class becomes protected in subclass.
 * 
 * Example:
*/

#include<iostream>

using namespace std;

class Base {
    protected:
    int a;

    public:
    Base() {
        a = 0;
    }

    protected:
    void display_base() {
        cout << a << endl;
    }
};

class Sub : protected Base {
    public:
    void display_sub() {
        display_base(); //accessible, and protected in subclass
    }

    void change_a(int n) {
        a = n; //accessible because a is protected in sub-class
    }
};

int main() {
    Sub s;

    s.change_a(5); // valid
    s.display_sub(); // valid, output: 5

    //s.display_base(); //invalid
    //cout << s.a << endl; //invalid
    return 0;
}