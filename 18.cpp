#include <stdio.h>
#include <string.h>


typedef struct SkiLift {
    char ime[15];
    int maxNumber;
    int isWorking;
} skiLift;

typedef struct SkiCenter {
    char imeSkiCenter[20];
    char country[20];
    int numberLift;
    skiLift niza[20];
} skiCenter;

int capacity(skiCenter a) {
    int brojac = 0;
    for (int i = 0; i < a.numberLift; i++) {
        if (a.niza[i].isWorking) {
            brojac += a.niza[i].maxNumber;
        }
    }
    return brojac;
}

void najgolemKapacitet(skiCenter sc[], int n) {
    int max = 0, max1 = 0, tmp;
    for (int i = 0; i < n; i++) {
        tmp = capacity(sc[i]);
        if (tmp > max || (tmp == max && sc[i].numberLift > sc[max1].numberLift)) {
            max = tmp;
            max1 = i;
        }
    }
    printf("%s\n", sc[max1].imeSkiCenter);
    printf("%s\n", sc[max1].country);
    printf("%d\n", max);
}

int main() {
    int n;
    scanf("%d", &n);
    skiCenter a[20];
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i].imeSkiCenter);
        scanf("%s", a[i].country);
        scanf("%d", &a[i].numberLift);
        for (int j = 0; j < a[i].numberLift; j++) {
            scanf("%s", a[i].niza[j].ime);
            scanf("%d", &a[i].niza[j].maxNumber);
            scanf("%d", &a[i].niza[j].isWorking);

        }
    }

    najgolemKapacitet(a, n);


    return 0;
}