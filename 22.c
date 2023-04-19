#include <stdio.h>
#include <string.h>

typedef struct Proizvod {
    char code[20];
    int price;
    int availableProducts;
} Proizvod;


typedef struct Narachka {
    char nameOfCustomer[15];
    Proizvod proizvodi[10];
    int numberOfProducts[10];
    int n;
} Narachka;

void pecatiFaktura(Narachka n) {
    printf("Faktura za %s\n", n.nameOfCustomer);
    int flag = 1;
    for (int i = 0; i < n.n; ++i) {
        if (n.numberOfProducts[i] > n.proizvodi[i].availableProducts) {
            flag = 0;
            printf("Fakturata ne moze da se izgotvi\n");
            break;
        }
    }
    Proizvod temp;
    if (flag) {
        for (int i = 0; i < n.n - 1; ++i) {
            for (int j = 0; j < n.n - 1 - i; ++j) {
                if (strcmp(n.proizvodi[j].code, n.proizvodi[j + 1].code) > 0) {
                    temp = n.proizvodi[j];
                    n.proizvodi[j] = n.proizvodi[j + 1];
                    n.proizvodi[j + 1] = temp;
                }
            }
        }
        int max = 0;
        for (int i = 0; i < n.n; ++i) {
            printf("%s %d %d %d\n", n.proizvodi[i].code, n.proizvodi[i].price, n.numberOfProducts[i],
                   n.proizvodi[i].price * n.numberOfProducts[i]);
            max += n.proizvodi[i].price * n.numberOfProducts[i];
        }
        printf("Vkupnata suma na fakturata e %d", max);
    }
}

int main() {

    Narachka narachka;

    scanf("%s", narachka.nameOfCustomer);
    scanf("%d", &narachka.n);

    int i;
    for (i = 0; i < narachka.n; ++i) {
        scanf("%s %d %d", narachka.proizvodi[i].code, &narachka.proizvodi[i].price,
              &narachka.proizvodi[i].availableProducts);
    }
    int j;
    for (j = 0; j < narachka.n; ++j) {
        scanf("%d", &narachka.numberOfProducts[j]);
    }
    pecatiFaktura(narachka);

    return 0;
}