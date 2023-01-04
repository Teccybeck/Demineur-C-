#include "Probleme.h"
#include "grille.h"
#include <iostream>
#include <cassert>
#include <stdlib.h>

using namespace std;

void Insertion(Elements& tmp, ElementsHistorique& eHistorique) { // a voir si possible
	cout << "Saisissez le nombre de lignes que vous souhaitez : " << endl; //²
	cin >> tmp.nbrLignes;
	cout << "Saisissez le nombre de colonnes que vous souhaitez : " << endl; //²
	cin >> tmp.nbrColonnes;
	cout << "Saisissez le nombre de mines que vous souhaitez : " << endl; //²
	cin >> tmp.nbrMines;

	Mines(tmp, tmp.capa);
	afficheGrille2(tmp);



	cout << "nbrCoupHistorique" << endl; //²
	cin >> eHistorique.nbrCoupHistorique;
	cout << endl;
	for (int a = 0; a < eHistorique.nbrCoupHistorique; ++a) {
		cin >> eHistorique.lettre;
		cin >> eHistorique.nbr;
		condition(eHistorique, tmp);
		// appel de fonction
		cout << "carac " << eHistorique.lettre << endl; //²
		cout << "nbr " << eHistorique.nbr << endl; //²
		afficheGrilleActuel(eHistorique, tmp);
	}
	//desalouer(); // a voir où mettre
	cout << endl;
	afficheGrilleActuel(eHistorique, tmp);
	// appel tableau
	cout << endl;
	cout << endl;
	cout << endl;

	afficheGrille2(tmp);

}




void initialiserTab2(Elements& e, unsigned int capacite) { //tableaujeu
	assert(capacite > 0);
	e.capa = capacite;
	e.tableauJeu = new unsigned int[capacite];
	e.tableauJeu2 = new unsigned int[capacite];
	for (unsigned int i = 0; i < e.capa; ++i) {
		e.tableauJeu[i] = 48;
		e.tableauJeu2[i] = 46;
	}
	insertMinesDansTabJeu2(e);
}

void detruireTabJeuActuel(Elements& e) { //tableaujeu
	delete[] e.tableauJeu2;
	e.tableauJeu2 = NULL;
}

void detruireTabJeu2(Elements& e) { //tableaujeu
	delete[] e.tableauJeu;
	e.tableauJeu = NULL;
}

void tailleTabJeu2(Elements& e, unsigned int capacite) { //tableaujeu // et pas finie a revoir
// detruire(e); // a voir ou mettre en realiter (peut etre a la fin fin genre quand la partie est finis)
	capacite = e.nbrColonnes * e.nbrLignes;
	initialiserTab2(e, capacite);
}

void insertMinesDansTabJeu2(Elements& e) {
	for (int i = 0; i < e.nbrMines; ++i) { //boucle nbr de mines
		e.tableauJeu[e.tableauMines[i]] = 'm'; // mettre dans le tab jeu ou se situe lemplacement de la mine dans le tab mine la valeur 120 (x dans la table ascii) (a reformuler)
		//cout << e.tableauJeu[e.tableauMines[i]] << " ";
	}
}

void initialiser2(Elements& e, unsigned int capacite) {
	assert(capacite > 0);
	e.capa = capacite;
	e.tableauMines = new unsigned int[capacite];
}

void detruire2(Elements& e) {
	delete[] e.tableauMines;
	e.tableauMines = NULL;
}

void Mines(Elements& e, unsigned int capacite) {
	// detruire(e); // a voir ou mettre en realiter
	capacite = e.nbrMines;
	initialiser2(e, capacite);

	// repetition nbr de mines
	for (int i = 0; i < e.nbrMines; ++i) {
		while (e.tableauMines[i] > e.nbrLignes * e.nbrColonnes) {
			cout << "mine : "; //²
			cin >> e.tableauMines[i];
		}
	}

	for (int i = 0; i < e.nbrMines; ++i) {
		cout << e.tableauMines[i] << " "; // sortie test
	}
}




// test
void MineACoteSolution2(Elements& e) {
	tailleTabJeu2(e, e.capa);
	int x = 0; // initialisation au debut du tableau


	while (x < e.capa) { // boucle de toutes les cases du tableau
		int nbrDeMinesACotes = 0; // nbr de mine a cote initialiser a 0
		if (e.tableauJeu[x] != 'm') { // si case nest pas une mine
			for (int b = -1; b < 2; ++b) { // case de coord y : -1 ; 0 ; 1
				for (int a = -1; a < 2; ++a) { // case de coord x : -1 ; 0 ; 1
					if (((x - ((e.nbrColonnes * b) - a)) > 0 || x - ((e.nbrColonnes * b) - a)) < e.capa) { // si la case regarde ne se situe pas avant le jeu ou apres la derniere case du jeu
						if ((x + 1) % e.nbrColonnes == 0) { // si la case est en dehors a droite (ex: tab 2 3; 1 2 3 <| 4 5 6 (pour le 3, 4 ne doit pas etre scan))
							if ((x + a) % e.nbrColonnes != 0) { // enleve cas x + 1
								if (e.tableauJeu[x - ((e.nbrColonnes * b) - a)] == 'm') { // regarde si case est une mines
									nbrDeMinesACotes++; // ajoute une mine
								}
							}
						}
						else if (x % e.nbrColonnes == 0) { // si la case est en dehors a gauche
							if (a != -1) { // tous sauf a gauche
								if (e.tableauJeu[x - ((e.nbrColonnes * b) - a)] == 'm') { // regarde si case est une mines
									nbrDeMinesACotes++; // ajoute une mine
								}
							}
						}
						else { // tous les autres cas (les cases au milieu
							if (e.tableauJeu[x - ((e.nbrColonnes * b) - a)] == 'm') { // regarde si case est une mines
								nbrDeMinesACotes++; // ajoute une mine
							}
						}
					}
				}
			}
		}
		e.tableauJeu[x] = e.tableauJeu[x] + nbrDeMinesACotes; // incremente dans la case x du tableau les mines a cote
		x++; // case suivante
	}
}


void afficheGrille2(Elements& e) {
	MineACoteSolution2(e);

	int numcase = 0;
	cout << e.nbrLignes << " " << e.nbrColonnes << endl;
	for (int j = 0; j < e.nbrLignes; ++j) {
		for (int i = 0; i < e.nbrColonnes; ++i) {
			cout << " ___";
		}
		cout << endl;
		for (int i = 0; i < e.nbrColonnes; ++i) {
			cout << "| " << (char)e.tableauJeu[numcase] << " ";
			numcase++;
		}
		cout << "|" << endl;
	}
}



void condition(ElementsHistorique& tmp, Elements& e) {

	if (tmp.lettre == 'M') {
		if (e.tableauJeu[tmp.nbr] == 'm') {//alors c bon
			cout << "coucou" << tmp.nbr << endl;
			e.tableauJeu2[tmp.nbr] = 'x';
		}
		else {
			cout << "erreur";
			for (int i = 0; i < e.nbrMines; i++) {
				e.tableauJeu2[e.tableauMines[i]] = 'm';
				// a faire affiche toutes les mines
			}
		}
	}
	else if (tmp.lettre == 'D') {

	}
}

void afficheGrilleActuel(ElementsHistorique& tmp, Elements& e) {
	int numcase = 0;
	cout << e.nbrLignes << " " << e.nbrColonnes << endl;
	for (int j = 0; j < e.nbrLignes; ++j) {
		for (int i = 0; i < e.nbrColonnes; ++i) {
			cout << " ___";
		}
		cout << endl;
		for (int i = 0; i < e.nbrColonnes; ++i) {
			cout << "| " << (char)e.tableauJeu2[numcase] << " ";
			numcase++;
		}
		cout << "|" << endl;
	}
}