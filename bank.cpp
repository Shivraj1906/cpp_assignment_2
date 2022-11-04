/*
*
* TODO:Finish this program later due to unclear instructions
*
*/
#include<iostream>
#include<string.h>

using namespace std;

class Account {
    int account_number;
    char *name;
    float balance; //Common attrubute in both sub-classes 
    //No need to store type of account

    static int id_counter;

    public:
    Account(char *n, float bal) {
        account_number = ++id_counter;
        
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        balance = bal;
    }
};

int Account::id_counter = 0;

int main() {

    return 0;
}