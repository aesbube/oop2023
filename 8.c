#include <stdio.h>
#include <string.h>
#include <limits.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
typedef struct Laptop {
    char nameOfBrand[100];
    float inches;
    int touch;
    int price;
} Laptop;

typedef struct ITStore {
    char nameOfStore[100];
    char location[100];
    Laptop array[100];
    int number;
} ITStore;

void print(ITStore array[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%s %s\n", array[i].nameOfStore, array[i].location);
        for (int j = 0; j < array[i].number; ++j) {
            printf("%s %g %d\n", array[i].array[j].nameOfBrand, array[i].array[j].inches, array[i].array[j].price);
        }
    }
}

//void najeftina_ponuda(ITStore array[], int n) {
//    int temp[100];
//    int maxi = 0;
//    for (int i = 0; i < n; ++i) {
//        int temp1[100];
//        int maxj = 0;
//        for (int j = 0; j < array[i].number; ++j) {
//            if (array[i].array[j].touch) {
//                temp1[j] = array[i].array[j].price;
//            } else temp1[j] = 0;
//        }
//        for (int j = 0; j < array[i].number; ++j) {
//            int max;
//            for (int i = 0; i < array[i].number; ++i) {
//                if (temp1[i] != 0) {
//                    max = temp1[i];
//                    break;
//                }
//            }
//            for (int k = 0; k < array[i].number; ++k) {
//                if (temp1[k] > 0) {
//                    if (max > temp1[k]) {
//                        max = temp1[k];
//                        maxj = k;
//                    }
//                }
//            }
//        }
//        if (array[i].array[maxj].touch) { temp[i] = array[i].array[maxj].price; }
//    }
//    int max;
//    for (int i = 0; i < n; ++i) {
//        if (temp[i] != 0) {
//            max = temp[i];
//            break;
//        }
//    }
//    for (int i = 0; i < n; ++i) {
//        if (max > temp[i]) {
//            max = temp[i];
//            maxi = i;
//        }
//        //printf("%d\n", max);
//    }
//    printf("Najeftina ponuda ima prodavnicata:\n%s %s\nNajniskata cena iznesuva: %d", array[maxi].nameOfStore,
//           array[maxi].location, max);
//}

void najeftina_ponuda(ITStore array[], int n) {
    int max = INT_MAX;
    int maxi = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < array[i].number; ++j) {
            if (array[i].array[j].touch) {
                if (max > array[i].array[j].price) {
                    max = array[i].array[j].price;
                    maxi = i;
                }
            }
        }
    }
    printf("Najeftina ponuda ima prodavnicata: \n%s %s \nNajniskata cena iznesuva: %d", array[maxi].nameOfStore, array[maxi].location, max);
}

int main() {
    ITStore s[100];
    int n;
    scanf("%d", &n); //broj na IT prodavnici
    //vnesuvanje na prodavnicite edna po edna, zaedno so raspolozlivite laptopvi vo niv
    for (int i = 0; i < n; ++i) {
        scanf("%s %s %d", s[i].nameOfStore, s[i].location, &s[i].number);
        for (int j = 0; j < s[i].number; ++j) {
            scanf("%s %f %d %d", s[i].array[j].nameOfBrand, &s[i].array[j].inches, &s[i].array[j].touch,
                  &s[i].array[j].price);
        }
    }


    //pecatenje na site prodavnici
    print(s, n);



    //povik na glavnata metoda
    najeftina_ponuda(s, n);

    return 0;
}

#pragma clang diagnostic pop
