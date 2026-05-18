//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//struct Telefon {
//	int id;
//	int memorieRAM;
//	float pret;
//	char* marca;
//	char* model;
//	unsigned char clasaEficienta;
//};
//
//typedef struct Telefon Telefon;
//
//struct Nod {
//	Telefon info;
//	struct Nod* st;
//	struct Nod* dr;
//};
//
//typedef struct Nod Nod;
//
//Telefon citireTelefonDinFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	char* aux;
//	Telefon t1;
//	aux = strtok(buffer, sep);
//	t1.id = atoi(aux);
//	t1.memorieRAM = atoi(strtok(NULL, sep));
//	t1.pret = atof(strtok(NULL, sep));
//	aux = strtok(NULL, sep);
//	t1.marca = malloc(strlen(aux) + 1);
//	strcpy_s(t1.marca, strlen(aux) + 1, aux);
//
//	aux = strtok(NULL, sep);
//	t1.model = malloc(strlen(aux) + 1);
//	strcpy_s(t1.model, strlen(aux) + 1, aux);
//
//	t1.clasaEficienta = *strtok(NULL, sep);
//	return t1;
//}
//
//void afisareTelefon(Telefon telefon) {
//	printf("ID: %d\n", telefon.id);
//	printf("Memorie RAM: %d\n", telefon.memorieRAM);
//	printf("Pret: %.2f\n", telefon.pret);
//	printf("Marca: %s\n", telefon.marca);
//	printf("Model: %s\n", telefon.model);
//	printf("Clasa eficienta: %c\n\n", telefon.clasaEficienta);
//}
//
//void adaugaTelefonInArbore(Nod** arbore, Telefon telefonNou) {
//	if ((*arbore) == NULL) {
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//		nou->info = telefonNou;
//		nou->st = NULL;
//		nou->dr = NULL;
//		(*arbore) = nou;
//	}
//	else {
//		if ((*arbore)->info.id > telefonNou.id) {
//			adaugaTelefonInArbore(&((*arbore)->st), telefonNou);
//		}
//		if ((*arbore)->info.id < telefonNou.id) {
//			adaugaTelefonInArbore(&((*arbore)->dr), telefonNou);
//		}
//	}
//}
//
//Nod* citireArboreDinFisier(const char* numeFisier) {
//	Nod* arbore = NULL;
//	FILE* f = fopen(numeFisier, "r");
//	if (f) {
//		while (!feof(f)) {
//			Telefon t = citireTelefonDinFisier(f);
//			adaugaTelefonInArbore(&arbore, t);
//		}
//	}
//	fclose(f);
//	return arbore;
//}
//
//void afisareTelefoaneDinArbore(Nod* arbore) {
//	if (arbore) {
//		afisareTelefon(arbore->info);
//		afisareTelefoaneDinArbore(arbore->st);
//		afisareTelefoaneDinArbore(arbore->dr);
//	}
//}
//
//void dezalocareArbore(Nod** arbore) {
//	if (*arbore) {
//		dezalocareArbore(&(*arbore)->st);
//		dezalocareArbore(&(*arbore)->dr);
//		free((*arbore)->st);
//		free((*arbore)->dr);
//		free(*arbore);
//		(*arbore) = NULL;
//	}
//}
//
//Telefon getTelefonById(Nod* arbore, int id) {
//	Telefon t;
//	t.id = -1;
//	if (arbore) {
//		if (arbore->info.id == id) {
//			t = arbore->info;
//			t.marca = malloc(sizeof(char) * (strlen(arbore->info.marca) + 1));
//			strcpy_s(t.marca, sizeof(char) * (strlen(arbore->info.marca) + 1), arbore->info.marca);
//			t.model = malloc(sizeof(char) * (strlen(arbore->info.model) + 1));
//			strcpy_s(t.model, sizeof(char) * (strlen(arbore->info.model) + 1), arbore->info.model);
//		}
//		if (arbore->info.id < id) {
//			t = getTelefonById(arbore->dr, id);
//		}
//		if (arbore->info.id > id) {
//			t = getTelefonById(arbore->st, id);
//		}
//	}
//	return t;
//}
//
//int determinaNumarulDeNoduri(Nod* arbore) {
//	if (arbore) {
//		return determinaNumarulDeNoduri(arbore->st) + determinaNumarulDeNoduri(arbore->dr) + 1;
//	}
//	return 0;
//}
//
//int maxim(int a, int b) {
//	return (a > b ? a : b);
//}
//
//int calculeazaInaltimeArbore(Nod* arbore) {
//	if (arbore) {
//		return (maxim(determinaNumarulDeNoduri(arbore->st), determinaNumarulDeNoduri(arbore->dr)) + 1);
//	}
//}
//
//float calculeazaPretTotal(Nod* arbore) {
//	if (arbore) {
//		return arbore->info.pret + calculeazaPretTotal(arbore->st) + calculeazaPretTotal(arbore->dr);
//	}
//}
//
//int main() {
//	Nod* arbore = citireArboreDinFisier("telefoane.txt");
//	afisareTelefoaneDinArbore(arbore);
//	afisareTelefon(getTelefonById(arbore, 10));
//	printf("\nNumarul de noduri: %d\n", determinaNumarulDeNoduri(arbore));
//	printf("\nInaltime Arbore: %d\n", calculeazaInaltimeArbore(arbore));
//	printf("\nPret total: %.2f\n", calculeazaPretTotal(arbore));
//	dezalocareArbore(arbore);
//
//	return 0;
//}