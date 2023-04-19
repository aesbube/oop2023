#include <iostream>
#include <string.h>

using namespace std;

enum type {
    LINUX, UNIX, WINDOWS
};

class OperativenSistem {
    char *name;
    float version;
    type tip;
    float capacity;

public:
    OperativenSistem(const char *name = "", float version = 0, float capacity = 0, type tip = LINUX) : version(version),
                                                                                                       capacity(
                                                                                                               capacity) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->tip = tip;
    }

    OperativenSistem(const OperativenSistem &other) : version(other.version), capacity(other.capacity) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, other.name);
        this->tip = other.tip;
    }

    virtual ~OperativenSistem() {
        delete[] name;
    }

    OperativenSistem &operator=(const OperativenSistem &other) {
        if (this != &other) {
            delete[] name;
            this->version = other.version;
            this->capacity = other.capacity;
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, other.name);
            this->tip = other.tip;
        }
        return *this;
    }

    void pecati() {
        cout << "Ime: " << name << " Verzija: " << version << " Tip: " << tip << " Golemina: " << capacity << "GB"
             << endl;
    }
};

class Repozitorium {

};

int main() {
    char repoName[20];
    cin >> repoName;
    Repozitorium repozitorium = Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin >> brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i < brojOperativniSistemi; i++) {
        cin >> ime;
        cin >> verzija;
        cin >> tip;
        cin >> golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip) tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();
    cin >> ime;
    cin >> verzija;
    cin >> tip;
    cin >> golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip) tip, golemina);
    cout << "=====Brishenje na operativen sistem=====" << endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}
