#pragma once

typedef struct {
	int nbrLignes; // Nombre de lignes grille
	int nbrColonnes; // Nombre de colonnes grille
	int nbrMines; // Nombre de mines grille
	int capa;
	unsigned int* tableauMines; // Tableau dynamique
	unsigned int* tableauJeu; // Tableau dynamique du jeu solution
	unsigned int* tableauJeu2; // coup actuel tableau dynamique
	unsigned int NumeroCase;
} Elements;

void initialiserTab(Elements& e, unsigned int capacite); // tab jeu

void detruireTabJeu(Elements& e); // tab jeu

void tailleTabJeu(Elements& e, unsigned int capacite); // tab jeu

void insertMinesDansTabJeu(Elements& e); // tab jeu

void probleme(Elements& e); // operation 1


/**
*@brief Initialise un tableau d'unsigned int vide
*@see detruire, pour sa d�sallocation en fin d'utilisation
*@param[out] e : l'ensemble d'�l�ments
*@param[in] capacite : la capacit� du tableau
*@pre capacite > 0
*/
void initialiser(Elements& e, unsigned int capacite);


/**
*@brief D�salloue un tableau d'unsigned int en m�moire
*@see initialiser, le tableau � d�j� �t� allou�
*@param[out] e : l'ensemble d'�l�ments
*/
void detruire(Elements& e);

void desalouer(); // a voir quand utiliser

void randomMines(Elements& e, unsigned int capacite);
// Item grilletab[nbrLignes][nbrColonnes]; // Grille













void afficheGrille(Elements& e);
void MineACoteSolution2(Elements& e);
