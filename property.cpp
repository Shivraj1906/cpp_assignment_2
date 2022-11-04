#include<iostream>
#include<string.h>
#define MAX 2

using namespace std;

class Property {
    protected:
    char *address;
    int rooms;
    char condition;

    public:
    void init_property(char *a, int r, char c) {
        address = new char[strlen(a) + 1];
        strcpy(address, a);

        rooms = r;
        condition = c;
    }

    void display_property() {
        cout << "ADDRESS: " << address << endl;
        cout << "ROOMS: " << rooms << endl;
        cout << "CONDITION: " << condition << endl;
    }

    ~Property() {
        delete[] address;
    }
};

class Rental : private Property {
    float rent;
    int max_occupants;

    public:
    void init_rent(char *a, int rooms, char c, float rent, int max) {
        init_property(a, rooms, c);

        this->rent = rent;
        max_occupants = max;
    }

    float get_rent() {
        return rent;
    }

    void display() {
        display_property();
        cout << "RENT: " << rent << endl;
        cout << "MAX OCCUPANTS: " << max_occupants << endl;
    }
};

class Sale : private Property {
    double price;

    public:
    void init_sale(char *a, int r, char c, double p) {
        init_property(a, r, c);
        price = p;
    }

    double get_price() {
        return price;
    }

    void display() {
        display_property();
        cout << "PRICE: " << price << endl;
    }
};

int main() {
    Rental rent[MAX];
    Sale sale[MAX];

    //Not using for loop to init the objects

    rent[0].init_rent("Anand", 3, 'A',  3000, 3);
    rent[1].init_rent("Nadiad", 5, 'B',  6000, 3);

    sale[0].init_sale("Anand", 3, 'A', 1600000);
    sale[1].init_sale("Nadiad", 5, 'B', 6600000);

    for(int i = 0; i < MAX; i++) {
        if(rent[i].get_rent() < 5000)
            rent[i].display();
    }

    for(int i = 0; i < MAX; i++) {
        if(sale[i].get_price() < 6000000)
            sale[i].display();
    }
    
    return 0;
}