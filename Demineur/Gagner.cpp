#include "Probleme.h"
#include <fstream>
#include <iostream>
#include <cassert>
#include "Grille.h"

using namespace std;

bool Gagner(ifstream& fE) {
	Elements e;
	bool gagné = true;
	ElementsHistorique eh;
	fE >> e.nbrLignes;
	fE >> e.nbrColonnes;
	fE >> e.nbrMines;
	unsigned int capacite;
	capacite = e.nbrLignes * e.nbrColonnes;
	e.tableauMines = new unsigned int[capacite];
	for (unsigned int i = 0; i < e.nbrMines; i++) {
		fE >> e.tableauMines[i];
	}
	unsigned int capacite2;
	capacite2 = e.nbrLignes * e.nbrColonnes - e.nbrMines;
	e.tableauJeu = new unsigned int[capacite2];
	for (unsigned int i = 0; i < capacite2; i++) {
		for (unsigned int j = 0; j < capacite; j++) {
			if (i != e.tableauMines[j]) {
				e.tableauJeu[i] = i;
			}
		}
	}
	fE >> eh.nbrCoupHistorique;
	for (unsigned int i = 0; i < eh.nbrCoupHistorique; i++) {
		fE >> eh.lettre;
		fE >> eh.nbr;
		if (eh.lettre == 'D') {
			e.tableauJeu[eh.nbr] = 0;
		}
	}
	for (unsigned int i = 0; i < capacite2; i++) {
		if (e.tableauJeu[i] != 0) {
			gagné = false;
			break;
		}
	}
	if (gagné == false) {
		return true;
	}
	else {
		return false;
	}
}

void ResultatGagner(ifstream& fE) {
	if (Gagner(fE) == true) {
		cout << "game lost" << endl;
	}
	else {
		cout << "game not lost" << endl;
	}
}