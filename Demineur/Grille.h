#pragma once


typedef struct {
    char lettre;
    int nbr;
    int nbrCoupHistorique; // Nombre de coup de lhistorique
} ElementsHistorique;



void Insertion(Elements& tmp, ElementsHistorique& eHistorique);

void initialiserTab2(Elements& e, unsigned int capacite);

void detruireTabJeu2(Elements& e);

void tailleTabJeu2(Elements& e, unsigned int capacite);

void insertMinesDansTabJeu2(Elements& e);

void initialiser2(Elements& e, unsigned int capacite);

void detruire2(Elements& e);

void Mines(Elements& e, unsigned int capacite);

// test
void MineACoteSolution2(Elements& e);

void afficheGrille2(Elements& e);

// suite test 
void afficheGrilleActuel(Elements& e);

void afficheGrilleActuel(ElementsHistorique& tmp, Elements& e);

void condition(ElementsHistorique& tmp, Elements& e);