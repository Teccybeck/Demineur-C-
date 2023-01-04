#include "Probleme.h"
#include <iostream>
#include <cassert>
#include <time.h>
#include <stdlib.h>

using namespace std;


void initialiserTab(Elements& e, unsigned int capacite) { //tableaujeu
	assert(capacite > 0);
	e.capa = capacite;
	e.tableauJeu = new unsigned int[capacite];
	for (unsigned int i = 0; i < e.capa; ++i) {
		e.tableauJeu[i] = 48;
	}
	insertMinesDansTabJeu(e);
}

void detruireTabJeu(Elements& e) { //tableaujeu
	delete[] e.tableauJeu;
	e.tableauJeu = NULL;
}

void tailleTabJeu(Elements& e, unsigned int capacite) { //tableaujeu // et pas finie a revoir
	// detruire(e); // a voir ou mettre en realiter (peut etre a la fin fin genre quand la partie est finis)
	capacite = e.nbrColonnes * e.nbrLignes;
	initialiserTab(e, capacite);
}

void insertMinesDansTabJeu(Elements& e) {
	for (int i = 0; i < e.nbrMines; ++i) { //boucle nbr de mines
		e.tableauJeu[e.tableauMines[i]] = 'x'; // mettre dans le tab jeu ou se situe lemplacement de la mine dans le tab mine la valeur 120 (x dans la table ascii) (a reformuler)
		//cout << e.tableauJeu[e.tableauMines[i]] << " ";
	}
}








void probleme(Elements& tmp) { // a voir si possible
	cout << "Saisissez le nombre de lignes que vous souhaitez : " << endl; //²
	cin >> tmp.nbrLignes;
	cout << "Saisissez le nombre de colonnes que vous souhaitez : " << endl; //²
	cin >> tmp.nbrColonnes;
	cout << "Saisissez le nombre de mines que vous souhaitez : " << endl; //²
	cin >> tmp.nbrMines;
	while (tmp.nbrMines > (tmp.nbrColonnes * tmp.nbrLignes) / 2) { // choix personnel maxmine a la moitier des cases
		cout << "Le nombre de mines est trop eleve, veuillez saisir un nombre plus petit : " << endl;
		cin >> tmp.nbrMines;
	}
	randomMines(tmp, tmp.capa);
	//desalouer(); // a voir où mettre
	cout << endl;
}

void initialiser(Elements& e, unsigned int capacite) {
	assert(capacite > 0);
	e.capa = capacite;
	e.tableauMines = new unsigned int[capacite];
}

void detruire(Elements& e) {
	delete[] e.tableauMines;
	delete[] e.tableauJeu;
	delete[] e.tableauJeu2;
	e.tableauMines = NULL;
	e.tableauJeu = NULL;
	e.tableauJeu2 = NULL;
}

void randomMines(Elements& e, unsigned int capacite) {
	// detruire(e); // a voir ou mettre en realiter
	capacite = e.nbrMines;
	initialiser(e, capacite);
	int a; // indice du sous tableau des mines

	// a verif si sa marche
	// repetition nbr de mines
	for (int i = 0; i < e.nbrMines; ++i) {
		int valeurrand;
		srand(time(NULL));
		valeurrand = rand() % (e.nbrLignes * e.nbrColonnes); // valeur entre 0 et nbrL * nbrC - 1 (a verif)

		bool absent = false;
		while (!absent) {
			a = 0;
			absent = true;
			while ((a < i) && absent) {
				if (e.tableauMines[a] == valeurrand) {
					absent = false;
					valeurrand = rand() % (e.nbrLignes * e.nbrColonnes);
				}
				else
					a++;
			}
		}
		e.tableauMines[i] = valeurrand;
	}
	for (int i = 0; i < e.nbrMines; ++i) {
		cout << e.tableauMines[i] << " ";
	}
}
















// azeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee










void finDePartie(Elements& e) { //a faire plus tard dans un autre endroit (peut etre dans le 5)
	for (int i = 0; i < e.nbrMines; ++i) { //boucle nbr de mines
		e.tableauJeu[e.tableauMines[i]] = 'x'; // mettre dans le tab jeu ou se situe lemplacement de la mine dans le tab mine la valeur 120 (x dans la table ascii) (a reformuler)
		//cout << e.tableauJeu[e.tableauMines[i]] << " ";
	}

	int numcase = 0;
	cout << "                                                               " << e.nbrLignes << " " << e.nbrColonnes << endl;
	for (int j = 0; j < e.nbrLignes; ++j) {
		cout << "                                                               ";
		for (int i = 0; i < e.nbrColonnes; ++i) {
			cout << " ___";
		}
		cout << endl;
		cout << "                                                               ";
		for (int i = 0; i < e.nbrColonnes; ++i) {
			cout << "| " << (char)e.tableauJeu[numcase] << " ";
			numcase++;
		}
		cout << "|" << endl;
	}
}
