#include "Probleme.h"
#include <fstream>
#include <iostream>
#include <cassert>
#include "Grille.h"

using namespace std;

void CaseAleatoire(Elements& e) { // boucle a faire
	srand(time(NULL));
	e.NumeroCase = rand() % (e.nbrLignes * e.nbrColonnes); // valeur entre 0 et nbrL * nbrC - 1 (a verif)
}

bool VerificationCaseJouée(ElementsHistorique & eh, ifstream & fE, Elements& e) {
	for (unsigned int i = 0; i < eh.nbrCoupHistorique; i++) {
		fE >> eh.lettre;
		fE >> eh.nbr;
		if (e.NumeroCase = eh.nbr) {
			return false; // Case déjà jouée
		}
		else {
			return true; // Case non jouée
		}
	}
}

void Jouercoup() {

}

void NouveauCoup(ElementsHistorique& eh, ifstream& fE, Elements& e) {
	CaseAleatoire(e);
	while (VerificationCaseJouée(eh, fE, e) != true) {
		CaseAleatoire(e);
	}

}