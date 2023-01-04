#include "Probleme.h"
#include <fstream>
#include <iostream>
#include <cassert>
#include "Grille.h"

using namespace std;


bool Perdre(ifstream& fE) {
	Elements e;
	bool perdu = true;
	ElementsHistorique eh;
	fE >> e.nbrLignes;
	fE >> e.nbrColonnes;
	fE >> e.nbrMines;
	unsigned int capacite;
	capacite = e.nbrLignes * e.nbrColonnes;
	e.tableauJeu = new unsigned int[capacite];
	for (unsigned int i = 0; i < e.nbrMines; i++) {  // On rentre les mines dans un tableau
		fE >> e.tableauJeu[i];
	}
	fE >> eh.nbrCoupHistorique;
	for (int i = 0; i < eh.nbrCoupHistorique; i++) { // La boucle for nous permet de remplacer les précédents nombre et lettre
		fE >> eh.lettre;							 // par les suivants et donc d'obtenir la dernière combinaison à la fin.
		fE >> eh.nbr;
	}
	if (eh.lettre == 'D') {
		for (unsigned int i = 0; i < e.nbrMines; i++) {
			if (eh.nbr == e.tableauJeu[i]) { // On compare la case du dernier coup joué (ici démasqué) aux cases contenant des mines
				perdu = false;				 // et si on trouve une equivalence la partie est perdue
			}
		}
	}
	else if (eh.lettre == 'M') {
		for (unsigned int i = 0; i < e.nbrMines; i++) {
			if (eh.nbr == e.tableauJeu[i]) { // On compare la case du dernier coup joué (ici marqué) aux cases contenant des mines
				perdu = true;				 // et si on trouve une équivalence alors on quite la boucle car le dernier coup marque une mine.
				break;
			}
			else {
				perdu = false;				 // Si il n'y a pas d'équivalence la partie est perdue car la dernière case marqué n'est pas une mine.
			}
		}
	}
	if (perdu == false) {
		return true;
	}
	else {
		return false;
	}
}

void ResultatPerdre(ifstream& fE) {
	if (Perdre(fE) == true) {
		cout << "game lost" << endl;
	}
	else {
		cout << "game not lost" << endl;
	}
}