#include <iostream>
#include "Probleme.h"
#include "Grille.h"
#include "Perdre.h"
#include "Gagner.h"
#include <string>

using namespace std;

int main() {
	string nomfichier;
	unsigned int operation;
	ElementsHistorique eHistorique;
	Elements e;
	cout << "saisissez le nom du fichier � lire" << endl; //�
	cin >> nomfichier;
	ifstream monflux(nomfichier);
	if (monflux) {
		monflux >> operation;
		if (operation == 1) {
			probleme(e);
		}

		if (operation == 2) {
			Insertion(e, eHistorique);
		}
		if (operation == 3) {
		}
		if (operation == 4) {
			ResultatPerdre(monflux);
		}
		if (operation == 5) {
		}
		//desallouer
		if (operation == 6) { //op bonus (jeu a la main)
			probleme(e);
			//afficheGrille(e);
		}
	}
	else {
		cout << "Impossible d'ouvrir le fichier" << endl;
	}
	//detruire(e); a faire marcher
	system("PAUSE");
}
	//(�) a enlever a la fin
