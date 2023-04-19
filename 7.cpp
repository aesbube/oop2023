#include <stdio.h>
#include <string.h>

typedef struct Vozenje {
	char ime[100];
	int traenje;
	float cena;
	int daliPopust;
}Vozenje;

typedef struct ZabavenPark {
	char ime[100];
	char lokacija[100];
	Vozenje niza[100];
	int k;
}ZabavenPark;

void pecati(ZabavenPark ff[100], int n) {
	int i, j;
	for (i = 0; i < n; ++i) {
		printf("%s %s\n", ff[i].ime, ff[i].lokacija);
		for (j = 0; j < ff[i].k; j++) {
			printf("%s %d %.2f\n", ff[i].niza[j].ime, ff[i].niza[j].traenje, ff[i].niza[j].cena);
		}
	}
}

void najdobar_park(ZabavenPark ff[100], int n) {
	int temp[100];
	int maxTraenje[100];
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < ff[i].k; j++) {
			if (ff[i].niza[j].daliPopust) {
				temp[i]++;
				//maxTraenje[i]+=ff[i].niza[j].traenje;
			}
			maxTraenje[i] += ff[i].niza[j].traenje;
		}
	}
	int maxi = 0;
	int max = temp[0];
	int max1 = maxTraenje[0];
	for (i = 1; i < n; i++)
	{
		if (max < temp[i]|| (max = temp[i] && max1 < maxTraenje[i])) {
			max = temp[i];
			max1 = maxTraenje[i];
			maxi = i;
		}
	}
	printf("Najdobar park: %s %s", ff[maxi].ime, ff[maxi].lokacija);
}

int main()
{
	int i, j, n;
	//kreiraj niza od maksimum 100 zabavni parkovi
	ZabavenPark ff[100];
	scanf("%d", &n);
	//citanje na podatocite
	for (i = 0; i < n; i++) {
		//ime na festivalot
		scanf("%s", ff[i].ime);
		//mesto
		scanf("%s", ff[i].lokacija);
		//broj na filmovi
		scanf("%d", &ff[i].k);

		for (j = 0; j < ff[i].k; j++) {
			scanf("%s", ff[i].niza[j].ime);  			/* Ime na filmot */
			scanf("%d", &ff[i].niza[j].traenje); 		/* Vremetraenje   */
			scanf("%f", &ff[i].niza[j].cena); 	/* Cena */
			scanf("%d", &ff[i].niza[j].daliPopust);	/* Popust */

		}


	}
	pecati(ff, n);
	najdobar_park(ff, n);

	return 0;
}
