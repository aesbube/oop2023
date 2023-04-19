#include <iostream>
#include <string.h>

using namespace std;

enum tip {
    POP = 0, RAP = 1, ROK = 2
};


class Pesna {
    char *name;
    int duration;
    tip song;

public:
    Pesna(const char *name = "", int duration = 0, tip song = POP) : duration(duration) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->song = song;
    }

    Pesna(const Pesna &other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->song = other.song;
        this->duration = other.duration;
    }

    Pesna const operator=(const Pesna &other) {
        if (this != &other) {
            delete[] name;
            this->name = new char[strlen(other.name) + 1];
            strcpy(this->name, other.name);
            this->song = other.song;
            this->duration = other.duration;
        }
        return *this;
    };

    char *getName() const {
        return name;
    }

    void setName(char *name) {
        strcpy(this->name, name);
    }

    int getDuration() const {
        return duration;
    }

    void setDuration(int duration) {
        Pesna::duration = duration;
    }

    tip getTip() const {
        return song;
    }

    void setSong(tip song) {
        Pesna::song = song;
    }

    void pecati() {
        cout << "\"" << name << "\"" << "-" << duration << "min" << endl;
    }

    ~Pesna() {
        delete[] name;
    }
};

int temp = 0;

class CD {
    Pesna songs[10];
    int numberOfSongs;
    int maxDuration;

public:
    CD(int maxDuration = 0, Pesna *songs = 0, int numberOfSongs = 0) : numberOfSongs(numberOfSongs),
                                                                       maxDuration(maxDuration) {
//        songs = new Pesna[10];
        for (int i = 0; i < numberOfSongs; ++i) {
            this->songs[i] = songs[i];
        }

    }

    CD(const CD &other) {
        this->numberOfSongs = other.numberOfSongs;
        this->maxDuration = other.maxDuration;
//        songs = new Pesna[10];
        for (int i = 0; i < other.maxDuration; ++i) {
            this->songs[i] = other.songs[i];
        }
    }

    CD const operator=(const CD &other) {
        if (this != &other) {
            this->numberOfSongs = other.numberOfSongs;
            this->maxDuration = other.maxDuration;
//            delete[] songs;
//            songs = new Pesna[10];
            for (int i = 0; i < other.maxDuration; ++i) {
                this->songs[i] = other.songs[i];
            }
        }
        return *this;
    }

    Pesna getPesna(int i) const {
        return songs[i];
    }

    void setSongs(Pesna *songs) {
//        songs = new Pesna[10];
        for (int i = 0; i < numberOfSongs; ++i) {
            this->songs[i] = songs[i];
        }
    }

    int getNumberOfSongs() const {
        return numberOfSongs;
    }

    void setNumberOfSongs(int numberOfSongs) {
        CD::numberOfSongs = numberOfSongs;
    }

    int getMaxDuration() const {
        return maxDuration;
    }

    void setMaxDuration(int maxDuration) {
        CD::maxDuration = maxDuration;
    }

    void dodadiPesna(Pesna &p) {
        if (temp + p.getDuration() <= maxDuration) {
            temp += p.getDuration();

            if (numberOfSongs < 10) {
                songs[numberOfSongs] = p;
                numberOfSongs++;
            }
        }
    }


    void pecatiPesniPoTip(tip t) {
        for (int i = 0; i < numberOfSongs; ++i) {
            if (songs[i].getTip() == t) {
                songs[i].pecati();
            }
        }
    }

};


int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, minuti, kojtip;
    char ime[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime, minuti, (tip) kojtip);
        p.pecati();
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i = 0; i < n; i++)
            (omileno.getPesna(i)).pecati();
    } else if (testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i = 0; i < omileno.getNumberOfSongs(); i++)
            (omileno.getPesna(i)).pecati();
    } else if (testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        cin >> kojtip;
        omileno.pecatiPesniPoTip((tip) kojtip);

    } else if (testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        cin >> kojtip;
        omileno.pecatiPesniPoTip((tip) kojtip);

    }

    return 0;
}