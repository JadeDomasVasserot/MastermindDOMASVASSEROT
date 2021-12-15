#include<iostream>
#include<string>
#include<ctime>
#include <windows.h>
int GetNombreAlleatoire(int Min, int Max);
void SaisirCombinaison(int Combi[], int NbPions);
void ChoisirCombinaition(int CombiCache[], int NbPions, int MaxCouleur);
bool TesterCombinaison(int CombiCache[], int CombiSaisie[], int NbPions, int& NbPionsPlaces, int& NbPionsMalPlaces);
void AfficherCombinaison(int Combi[], int NbPions);
void AfficherCombinaisonCache(int CombiCache[], int NbPions);
void AfficherRegles();
void Couleur(int couleurDuTexte, int couleurDuFond,std::string Text);
