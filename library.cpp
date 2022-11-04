#include<iostream>
#include<string.h>

using namespace std;

class Library {
    int book_id;
    char *bookname;
    char *author;
    int no_of_copies;

    public:
    Library(int id, char *b, char *a, int n) {
        book_id = id;
        bookname = new char[strlen(b) + 1];
        strcpy(bookname, b);

        author = new char[strlen(a) + 1];
        strcpy(author, a);

        no_of_copies = n;
    }

    void display_book() {
        cout << "BOOK ID: " << book_id << endl;
        cout << "NAME: " << bookname << endl;
        cout << "AUTHOR: " << author << endl;
        cout << "NUMBER OF COPIES: " << no_of_copies << endl;
    }

    ~Library() {
        delete[] bookname;
        delete[] author;
    }
};

class Issue_return : private Library {
    //using Unix timestamp to represent date
    unsigned long int date_of_issue;
    unsigned long int date_of_return;
    float fine;
    int max_days;

    public:
    Issue_return(int id, char *b, char *a, int n, unsigned long int doi, unsigned long int dor, float f, int max) : Library(id, b, a, n) {
        date_of_issue = doi;
        date_of_return = dor;
        fine = f;
        max_days = max;
    }

    int find_days() {
        int days = date_of_return - date_of_issue;
        days /= 86400; //converting seconds into days

        return days;
    }

    float find_fine() {
        return fine * find_days();
    }

    //assuming 'book' is available or not instead of 'author'
    int is_book_available() {
        return date_of_issue == 0 ? 1 : 0;
    }

    void display() {
        display_book();
        cout << "IS BOOK AVAILABLE: " << is_book_available() << endl;
        if(!is_book_available())
            cout << "FINE: " << find_fine() << "rs. " << endl;
    }
};

int main() {
    // Issue_return b1(1, "Test", "Foo", 5, 1667289643, 1667548843, 500, 2);

    Issue_return books[2] = {Issue_return(1, "Test", "Foo", 5, 1667289643, 1667548843, 500, 2), Issue_return(2, "Test 2", "Bar", 1, 0, 0, 500, 5)};

    for(int i = 0; i < 2; i++) {
        books[i].display();
        cout << endl;
    }
}