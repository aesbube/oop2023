#include <iostream>
#include <cstring>

using namespace std;

class Gitara {
private:
    char serial[25];
    double price;
    int year;
    char type[40];

    void copy(const Gitara &other) {
        strcpy(this->serial, other.serial);
        this->price = other.price;
        this->year = other.year;
        strcpy(this->type, other.type);
    }

public:
    Gitara(char *type = "", char *serial = "", int year = 0, double price = 0.0) {
        strcpy(this->serial, serial);
        this->price = price;
        this->year = year;
        strcpy(this->type, type);
    }

    Gitara(const Gitara &other) {
        copy(other);
    }

    ~Gitara() {}

    Gitara &operator=(const Gitara &other) {
        if (this != &other) {
            copy(other);
        }
        return *this;
    }

    const char *getSeriski() const {
        return serial;
    }

    const double getNabavna() const {
        return price * 1.0;
    }

    const int getGodina() const {
        return year;
    }

    const char *getTip() const {
        return type;
    }

    bool daliIsti(Gitara &gitara) {
        return (strcmp(gitara.serial, this->serial) == 0);
    }

    void pecati() {
        cout << serial << " " << type << " " << price << endl;
    }
};

class Magacin {
private:
    char name[30];
    char location[60];
    Gitara *gitari;
    int number;
    int year;

    void copy(const Magacin &other) {
        strcpy(this->name, other.name);
        strcpy(this->location, other.location);
        this->gitari = new Gitara[other.number];
        for (int i = 0; i < other.number; i++) {
            this->gitari[i] = other.gitari[i];
        }
        this->number = other.number;
        this->year = other.year;
    }

public:
    Magacin(char *name = "", char *location = "", int year = 0, Gitara *gitari = 0, int number = 0) {
        strcpy(this->name, name);
        strcpy(this->location, location);
        this->gitari = new Gitara[number];
        for (int i = 0; i < number; i++) {
            this->gitari[i] = gitari[i];
        }
        this->number = number;
        this->year = year;
    }

    Magacin(const Magacin &other) {
        copy(other);
    }

    ~Magacin() {
        delete[] gitari;
    }

    Magacin &operator=(const Magacin &other) {
        if (this != &other) {
            delete[] gitari;
            copy(other);
        }
        return *this;
    }

    const char *getName() const {
        return name;
    }

    const char *getLocation() const {
        return location;
    }

    Gitara *getGitari() const {
        return gitari;
    }

    int getNumber() const {
        return number;
    }

    int getYear() const {
        return year;
    }

    double vrednost() {
        double zbir = 0;
        for (int i = 0; i < number; i++) {
            zbir += gitari[i].getNabavna();
        }
        return zbir;
    }

    void dodadi(Gitara d) {
        Gitara *tmp = new Gitara[number + 1];
        for (int i = 0; i < number; i++) {
            tmp[i] = gitari[i];
        }
        tmp[number++] = d;
        delete[] gitari;
        gitari = tmp;
    }

    void prodadi(Gitara p) {
        int a = 0;
        for (int i = 0; i < number; ++i) {
            if (p.daliIsti(gitari[i]) == false) a++;
        }
        Gitara *tmp = new Gitara[number - 1];
        int j = 0;
        for (int i = 0; i < number; i++) {
            if (p.daliIsti(gitari[i]) == false) {
                tmp[j] = gitari[i];
                j++;
            }
        }
        delete[] gitari;
        gitari = tmp;
        number = a;
    }

    void pecati(bool daliNovi) {
        cout << name << " " << location << endl;
        for (int i = 0; i < number; ++i) {
            if (daliNovi && gitari[i].getGodina() > year) {
                gitari[i].pecati();
            } else if (daliNovi == false) {
                gitari[i].pecati();
            }
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
        cout << g.getTip() << endl;
        cout << g.getSeriski() << endl;
        cout << g.getGodina() << endl;
        cout << g.getNabavna() << endl;
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
        cout << kb.vrednost() << endl;
        kb.prodadi(brisi);
        cout << "Po brisenje:" << endl;
        cout << kb.vrednost();
        Magacin kb3;
        kb3 = kb;
    }
    return 0;
}
