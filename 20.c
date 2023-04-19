#include <stdio.h>
#include <string.h>

typedef struct Patient {
	char ime[100];
	int zdrastveno;
	int pregledi;
}Patient;

typedef struct Doctor {
	char ime[100];
	int br_pac;
	Patient niza[100];
	float cena;
}doktor;

void najuspesen_doktor(doktor doktori[], int n) {
	float najgolemaSuma[200] = { 0 };
	int numberPatients[200] = { 0 };
	for (int i = 0; i < n; ++i) {

		for (int j = 0; j < doktori[i].br_pac; ++j) {
			
				for (int z = 0; z < doktori[i].niza[j].pregledi; ++z) {
					if (doktori[i].niza[j].zdrastveno == 0) 
					najgolemaSuma[i] += doktori[i].cena;
					numberPatients[i]++;
				}
				
			
		}
	}

	int maxi = 0;
	float najgolem = najgolemaSuma[0];
	int najgolemNumberPatients = numberPatients[0];
	for (int i = 0; i < n; ++i) {
		if ((najgolemaSuma[i] >= najgolem)  && (najgolemNumberPatients < numberPatients[i])) {
			najgolem = najgolemaSuma[i];
			maxi = i;
			najgolemNumberPatients = numberPatients[i];
		}
		
	}
	printf("%s %.2f %d\n", doktori[maxi].ime, najgolemaSuma[maxi], numberPatients[maxi]);
	//printf("%d", numberPatients[2]);
}
		

int main()
{
	int i, j, n, broj;
	doktor md[100];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		//ime na doktor
		scanf("%s", md[i].ime);
		//broj na pacienti
		scanf("%d", &md[i].br_pac);
		//cena na pregled
		scanf("%f", &md[i].cena);

		for (j = 0; j < md[i].br_pac; ++j) {
			scanf("%s", md[i].niza[j].ime);
			scanf("%d", &md[i].niza[j].zdrastveno);
			scanf("%d", &md[i].niza[j].pregledi);
		}
	}
	najuspesen_doktor(md, n);

	return 0;
}
