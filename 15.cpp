#include <stdio.h>
#include <string.h>

#define NEDELI 4
#define DENOVI 5

typedef struct RabotnaNedela {
    int casovi[DENOVI];
    int brojNedela;
} RN;

typedef struct Rabotnik {
    char ime[50];
    RN nedeli[NEDELI];
} R;

int maxNedela(R *r) {
    int max = 0;
    int maxi = 0;

    for (int i = 0; i < NEDELI; ++i) {
        int temp = 0;
        for (int j = 0; j < DENOVI; ++j) {
            temp += r->nedeli[i].casovi[j];
        }
        if (temp > max) {
            max = temp;
            maxi = i;
        }
    }
    return maxi + 1;
}

void table(R *r, int n) {

    printf("Rab\t1\t2\t3\t4\tVkupno\n");
    for (int i = 0; i < n; ++i) {
        printf("%s", r[i].ime);
        int temp[NEDELI] = {0};
        int vk = 0;
        for (int j = 0; j < NEDELI; ++j) {
            for (int k = 0; k < DENOVI; ++k) {
                temp[j] += r[i].nedeli[j].casovi[k];
            }
            vk += temp[j];
            printf("\t%d", temp[j]);
        }
        printf("\t%d\n", vk);
    }

}


int main() {
    int n;
    scanf("%d", &n);
    R rabotnici[n];
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%s", rabotnici[i].ime);
        int j;
        for (j = 0; j < NEDELI; ++j) {
            int k;
            for (k = 0; k < DENOVI; ++k) {
                scanf("%d", &rabotnici[i].nedeli[j].casovi[k]);
            }

        }
    }
    printf("TABLE\n");
    table(rabotnici, n);
    printf("MAX NEDELA NA RABOTNIK: %s\n", rabotnici[n / 2].ime);
    printf("%d\n", maxNedela(&rabotnici[n / 2]));
    return 0;
}