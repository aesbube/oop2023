#include <iostream>
#include <cstring>

using namespace std;

class Gitara {
    char type[40];
    char serialNumber[25];
    int yearOfProduction;
    double price;

public:
    Gitara(const char *type = "", const char *serialNumber = "", int yearOfProduction = 0, double price = 0) {
        strcpy(this->type, type);
        strcpy(this->serialNumber, serialNumber);
        this->price = price;
        this->yearOfProduction = yearOfProduction;
//        cout<<"default"<<endl;
    }

    Gitara(const Gitara &other) {
//        cout<<"copy"<<endl;
        strncpy(this->type, other.type, 40);
        strncpy(this->serialNumber, other.serialNumber, 25);
        this->yearOfProduction = other.yearOfProduction;
        this->price = other.price;
    }

    Gitara &operator=(const Gitara &other) {
//        cout<<"operator"<<endl;
        strncpy(this->type, other.type, 40);
        strncpy(this->serialNumber, other.serialNumber, 25);
        this->yearOfProduction = other.yearOfProduction;
        this->price = other.price;
        return *this;
    }


    ~Gitara() {
    }

    bool daliIsti(Gitara &other) {
        return strcmp(this->serialNumber, other.serialNumber) == 0;
    }

    void pecati() {
        cout << serialNumber << " " << type << " " << price << endl;
    }

    const char *getType() const {
        return type;
    }

    const char *getSerialNumber() const {
        return serialNumber;
    }

    int getYearOfProduction() const {
        return yearOfProduction;
    }

    double getPrice() const {
        return price;
    }

};

class Magacin {
    char name[50];
    char location[60];
    Gitara *array;
    int number;
    int yearOfOpening;

public:
    Magacin(const char *name = "", const char *location = "", int yearOfOpening = 0) {
        strcpy(this->name, name);
        strcpy(this->location, location);
        this->yearOfOpening = yearOfOpening;
        array = NULL;
        number = 0;
//        cout<<"default"<<endl;
    }

    Magacin(const Magacin &other) {
//        cout<<"copy"<<endl;
        strcpy(this->name, other.name);
        strcpy(this->location, other.location);
        this->yearOfOpening = other.yearOfOpening;
        array = new Gitara[other.number];
        for (int i = 0; i < other.number; ++i) {
            this->array[i] = other.array[i];
        }
        this->number = other.number;
    }

    Magacin &operator=(const Magacin &other) {
//        cout<<"operator"<<endl;
        delete[] array;
        strcpy(this->name, other.name);
        strcpy(this->location, other.location);
        this->yearOfOpening = other.yearOfOpening;
        array = new Gitara[other.number];
        for (int i = 0; i < other.number; ++i) {
            array[i] = other.array[i];
        }
        this->number = other.number;
        return *this;
    }

    ~Magacin() {
        delete[] array;
    }

    double Vrednost() {
        double temp = 0;
        for (int i = 0; i < number; ++i) {
            temp += array[i].getPrice();
        }
        return temp;
    }

    void dodadi(Gitara other) {
        Gitara *temp = new Gitara[number + 1];
        for (int i = 0; i < number; ++i) {
            temp[i] = array[i];
        }
        temp[number++] = other;
        delete[] array;
        array = temp;
    }

    void prodadi(Gitara other) {
        int t = 0;

        for (int i = 0; i < number; ++i) {
            if (array[i].daliIsti(other) == false) {
                t++;
            }
        }
        Gitara *temp = new Gitara[t];
        int k = 0;
        for (int i = 0; i < number; ++i) {
            if (array[i].daliIsti(other) == false) {
                temp[k] = array[i];
                k++;
            }
        }
        delete[] array;
        array = temp;
        number = t;
    }

    void pecati(bool daliNovi) {
        cout << name << " " << location << endl;
        for (int i = 0; i < number; ++i) {
            if (daliNovi == true && array[i].getYearOfProduction() > yearOfOpening) {
                array[i].pecati();
            } else if (daliNovi == false) array[i].pecati();
        }
    }
};

int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, godina;
    float cena;
    char seriski[50], tip[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Gitara ======" << endl;
        cin >> tip;
        cin >> seriski;
        cin >> godina;
        cin >> cena;
        Gitara g(tip, seriski, godina, cena);
        cout << g.getType() << endl;
        cout << g.getSerialNumber() << endl;
        cout << g.getYearOfProduction() << endl;
        cout << g.getPrice() << endl;
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata Magacin so metodot print() ======" << endl;
        Magacin kb("Magacin1", "Lokacija1");
        kb.pecati(false);
    } else if (testCase == 3) {
        cout << "===== Testiranje na klasata Magacin so metodot dodadi() ======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2005);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;
            Gitara g(tip, seriski, godina, cena);
            cout << "gitara dodadi" << endl;
            kb.dodadi(g);
        }
        kb.pecati(true);
    } else if (testCase == 4) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() ======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2012);
        cin >> n;
        Gitara brisi;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip, seriski, godina, cena);
            if (i == 2)
                brisi = g;
            cout << "gitara dodadi" << endl;
            kb.dodadi(g);
        }
        kb.pecati(false);
        kb.prodadi(brisi);
        kb.pecati(false);
    } else if (testCase == 5) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() i pecati(true) ======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2011);
        cin >> n;
        Gitara brisi;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip, seriski, godina, cena);
            if (i == 2)
                brisi = g;
            cout << "gitara dodadi" << endl;
            kb.dodadi(g);
        }
        kb.pecati(true);
        kb.prodadi(brisi);
        cout << "Po brisenje:" << endl;
        Magacin kb3;
        kb3 = kb;
        kb3.pecati(true);
    } else if (testCase == 6) {
        cout << "===== Testiranje na klasata Magacin so metodot vrednost()======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2011);
        cin >> n;
        Gitara brisi;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip, seriski, godina, cena);
            if (i == 2)
                brisi = g;
            kb.dodadi(g);
        }
        cout << kb.Vrednost() << endl;
        kb.prodadi(brisi);
        cout << "Po brisenje:" << endl;
        cout << kb.Vrednost();
        Magacin kb3;
        kb3 = kb;
    }
    return 0;
}
