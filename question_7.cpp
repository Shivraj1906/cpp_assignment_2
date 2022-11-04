//Program to justify need of copy constructor

#include<iostream>
#include<string.h>

using namespace std;

class Name {
    public:
    char *name;

    public:
    Name(char *name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    //Copy constructor
    Name(const Name& n) {
        this->name = new char[strlen(n.name) + 1];
        strcpy(this->name, n.name);
    }

    ~Name() {
        delete[] name;
    }
};

/**
 * Without copy constuctor actual argument will be bitwise copied into dummy argument 'n'.
 * Both dummy and actual argument's 'name' member will point to same memory.
 * When 'display_name(Name)' is finished destructor will be invoked for dummy argument 'n'.
 * It will free the memory pointed by 'name'.
 * Still, actual argument is pointing to that freed memory.
 * When program execution is finished, destructor is invoked and it will try to memory whichi is already freed.
*/
void display_name(Name n) {
    cout << n.name;
}

int main() {
    Name n("Foobar");

    display_name(n);
    return 0;
}