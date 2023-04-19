    #include <stdio.h>
    #include <stdlib.h>
    #include <iostream>
    #include <string.h>
    #include <limits.h>

    using namespace std;

    struct Voz {
        char relacija[50];
        double kilometri;
        int brojPatnici;
    };

    struct ZeleznickaStanica {
        char grad[20];
        Voz niza[30];
        int brojVozovi;
    };

    void najkratkaRelacija(ZeleznickaStanica *zs, int n, char *grad) {
        int temp[100];
        int maxi = 0;
        int maxj = 0;
        for (int i = 0; i < n; ++i) {
            if (strcmp(grad, zs[i].grad) == 0) {
                for (int j = 0; j < zs[i].brojVozovi; ++j) {
                    temp[j] = zs[i].niza[j].kilometri;
                }
                maxi = i;
            }
        }
        int min = INT_MAX;
        for (int i = 0; i < zs[maxi].brojVozovi; ++i) {
            if (min >= temp[i]) {
                min = temp[i];
                maxj = i;
            }
        }
        cout << "Najkratka relacija: " << zs[maxi].niza[maxj].relacija << " ("
             << zs[maxi].niza[maxj].kilometri << " km)" << endl;
    }

    int main() {

        int n;
        cin >> n; //se cita brojot na zelezlnichki stanici

        ZeleznickaStanica zStanica[100];
        for (int i = 0; i < n; i++) {
            cin >> zStanica[i].grad;
            cin >> zStanica[i].brojVozovi;
            for (int j = 0; j < zStanica[i].brojVozovi; ++j) {
                cin >> zStanica[i].niza[j].relacija >> zStanica[i].niza[j].kilometri >> zStanica[i].niza[j].brojPatnici;
            }
        }

        char grad[25];
        cin >> grad;

        najkratkaRelacija(zStanica, n, grad);
        return 0;
    }


