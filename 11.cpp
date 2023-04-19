#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

class Ucesnik {
    char *name;
    bool gender;
    int age;

public:
    Ucesnik() {}

    Ucesnik(char *name, bool gender, int age) : Ucesnik() : gender (gender), age(age) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    Ucesnik(const & other){
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        gender = other.gender;
        age = other.age;
    }

    ~Ucesnik() {
        delete[] name;
    }


};

int main() {

}