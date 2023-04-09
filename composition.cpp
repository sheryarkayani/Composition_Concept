#include <iostream>
#include <cstring>
using namespace std;

class Birthday {
    int day, month, year;

public:
    //constructor
    Birthday() : day(0), month(0), year(0) {} //default constructor
    Birthday(int day, int month, int year) : day(day), month(month), year(year) {} //paramterized

    //member functions
    void setDate(int year, int month, int day) {
        this->year = year;
        this->month = month;
        this->day = day;
    } //setter

    string Display() const  {
        return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    }

    ~Birthday() {

         cout<<"Birthday destructor called"<<endl;
     }
};

class Person {
    char* name;
    Birthday obj;

public:

    Person(const char* name, int y = 0, int m = 0, int d = 0) : name(nullptr) {
        this->name = new char[strlen(name)+1]; //creating char array
        strcpy(this->name, name); //copying name
        obj.setDate(y, m, d); //setting date
    }

    ~Person() {
        cout<<"person destructor called"<<endl;
        delete[] name;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Birthdate: " << obj.Display() << endl;
    }

};

int main() {

    //we can call them independently
    Person obj("ali", 2002, 2, 2);
    obj.display();
    return 0;
}
