//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//struct StructuraMasina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;
//};
//
//typedef struct StructuraMasina Masina;
//
////creare structura pentru un nod dintr-un arbone binar de cautare
//struct Nod {
//	Masina info;
//	struct Nod* st;
//	struct Nod* dr;
//};
//
//typedef struct Nod Nod;
//
//Masina citireMasinaDinFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	char* aux;
//	Masina m1;
//	aux = strtok(buffer, sep);
//	m1.id = atoi(aux);
//	m1.nrUsi = atoi(strtok(NULL, sep));
//	m1.pret = atof(strtok(NULL, sep));
//	m1.model = malloc(strlen(aux) + 1);
//	strcpy_s(m1.model, strlen(aux) + 1, aux);
//	aux = strtok(NULL, sep);
//	m1.numeSofer = malloc(strlen(aux) + 1);
//	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
//	m1.serie = *strtok(NULL, sep);
//	return m1;
//}
//
//void afisareMasina(Masina masina) {
//	printf("ID: %d\n", masina.id);
//	printf("Numar usi: %d\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n\n", masina.serie);
//}
//
//void adaugaMasinaInArbore(Nod** arbore, Masina masinaNoua) {
//	//adauga o noua masina pe care o primim ca parametru in arbore
//	//astfel incat sa respecte principiile de arbore binar de cautare
//	//dupa o anumita cheie pe care o decideti - poate fi ID
//
//	if ((*arbore) == NULL) {
//		Nod* nod = (Nod*)malloc(sizeof(Nod));
//		nod->info = masinaNoua;
//		nod->dr = NULL;
//		nod->st = NULL;
//		(*arbore) = nod;
//	}
//	else {
//		if ((*arbore)->info.id > masinaNoua.id) {
//			adaugaMasinaInArbore(&((*arbore)->st), masinaNoua);
//		}
//		if ((*arbore)->info.id < masinaNoua.id) {
//			adaugaMasinaInArbore(&((*arbore)->dr), masinaNoua);
//		}
//	}
//}
//
//Nod* citireArboreDeMasiniDinFisier(const char* numeFisier) {
//	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
//	//prin apelul repetat al functiei citireMasinaDinFisier
//	//ATENTIE: sa nu uiti sa inchizi stream-ul
//	Nod* arbore = NULL;
//	FILE* f = fopen(numeFisier, "r");
//	if (f) {
//		while (!feof(f)) {
//			Masina m = citireMasinaDinFisier(f);
//			adaugaMasinaInArbore(&arbore, m);
//		}
//	}
//	fclose(f);
//	return arbore;
//}
//
//void afisareMasiniDinArbore(Nod* arbore) {
//	//afiseaza toate elementele de tip masina din arborele creat
//	//prin apelarea functiei afisareMasina()
//	//exista 3 moduri de parcurgere:
//	//RSD - radacina, nod stanga, nod dreapta
//	//SRD - nod stanga, radacina, nod dreapta
//	//SDR - nod stanga, nod dreapta, radacina
//	if (arbore) {
//		afisareMasiniDinArbore(arbore->st);
//		afisareMasina(arbore->info);
//		afisareMasiniDinArbore(arbore->dr);
//	}
//}
//
//void afisarePreordine(Nod* arbore) {
//	if (arbore) {
//		afisareMasina(arbore->info);
//		afisarePreordine(arbore->st);
//		afisarePreordine(arbore->dr);
//	}
//}
//
//void dezalocareArboreDeMasini(Nod** arbore) {
//	//sunt dezalocate toate masinile si arborele de elemente
//	if (*arbore) {
//		dezalocareArboreDeMasini(&(*arbore)->st);
//		dezalocareArboreDeMasini(&(*arbore)->dr);
//		free((*arbore)->st);
//		free((*arbore)->dr);
//		free((*arbore));
//		(*arbore) = NULL;
//	}
//}
//
//Masina getMasinaById(Nod* arbore, int id) {
//	//cauta un id dat in arbore
//	Masina m;
//	m.id = -1;
//
//	if (arbore) {
//		if (arbore->info.id == id) {
//			m = arbore->info;
//			m.model = malloc(sizeof(char) * (strlen(arbore->info.model) + 1));
//			strcpy_s(m.model, sizeof(char) * (strlen(arbore->info.model) + 1), arbore->info.model);
//			m.numeSofer = malloc(sizeof(char) * (strlen(arbore->info.numeSofer) + 1));
//			strcpy_s(m.numeSofer, sizeof(char) * (strlen(arbore->info.numeSofer) + 1), arbore->info.numeSofer);
//		}
//		if (id < arbore->info.id) {
//			m = getMasinaById(arbore->st, id);
//		}
//		if (id > arbore->info.id) {
//			m = getMasinaById(arbore->dr, id);
//		}
//		return m;
//	}
//}
//
//int determinaNumarNoduri(Nod* arbore) {
//	//calculeaza numarul total de noduri din arbore
//	if (arbore) {
//		return determinaNumarNoduri(arbore->st) + determinaNumarNoduri(arbore->dr) + 1;
//	}
//	return 0;
//}
//
//int maxim(int a, int b) {
//	return (a > b ? a : b);
//}
//
//int calculeazaInaltimeArbore(Nod* arbore) {
//	//calculeaza inaltimea arborelui care este data de
//	//lungimea maxima de la radacina pana la cel mai indepartat nod frunza
//	if (arbore) {
//		return maxim(calculeazaInaltimeArbore(arbore->st), calculeazaInaltimeArbore(arbore->dr)) + 1;
//	}
//	return 0;
//}
//
//float calculeazaPretTotal(Nod* arbore) {
//	//calculeaza pretul tutror masinilor din arbore
//	if (arbore) {
//		return arbore->info.pret + calculeazaPretTotal(arbore->st) + calculeazaPretTotal(arbore->dr);
//	}
//	return 0;
//}
//
//float calculeazaPretulMasinilorUnuiSofer(Nod* arbore, const char* numeSofer) {
//	if (arbore) {
//		float suma = calculeazaPretulMasinilorUnuiSofer(arbore->st, numeSofer) + calculeazaPretulMasinilorUnuiSofer(arbore->dr, numeSofer);
//		if (strcmp(arbore->info.numeSofer, numeSofer) == 0) {
//			suma += arbore->info.pret;
//		}
//	}
//	return 0;
//}
//
//int main() {
//	Nod* arbore = citireArboreDeMasiniDinFisier("masini.txt");
//	afisarePreordine(arbore);
//
//	printf("\n==========================================\n\n");
//	afisareMasina(getMasinaById(arbore, 10));
//
//	printf("\n==========================================\n\n");
//	printf("Numar noduri: %d\n", determinaNumarNoduri(arbore));
//
//	printf("\n==========================================\n\n");
//	printf("Inaltime arbore: %d\n", calculeazaInaltimeArbore(arbore));
//
//	printf("\n==========================================\n\n");
//	printf("Pret total: %.2f\n", calculeazaPretTotal(arbore));
//
//	printf("\n==========================================\n\n");
//	printf("Suma preturilor masinilor unui sofer: %.2f\n", calculeazaPretulMasinilorUnuiSofer(arbore, "Gheorghe"));
//
//	dezalocareArboreDeMasini(&arbore);
//	afisareMasiniDinArbore(arbore);
//
//	return 0;
//}