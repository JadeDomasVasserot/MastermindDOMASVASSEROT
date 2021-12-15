#include "fonction.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<string>
#include<ctime>
#include <time.h>
#include <windows.h>

using namespace std;
int GetNombreAlleatoire(int Min, int Max) {
		int NombreAleatoire = rand() % Max + Min;
	return NombreAleatoire;
}
void SaisirCombinaison(int Combi[], int NbPions) {
	cout << "Entrez votre combinaison : " << endl;
		for (int i = 0; i < NbPions; i++) {
			if (Combi[i] > 8) {
				Couleur(16, 12, "Attention ! Vous avez rentre un chiffre superieur a 8 \n");

			}
			else {
				
				cin >> Combi[i];
			}
		}
}
void ChoisirCombinaition(int CombiCache[], int NbPions, int MaxCouleur) {
	for (int i = 0; i < NbPions ; i++) {

		CombiCache[i] = GetNombreAlleatoire(1, MaxCouleur);
	}
}
bool TesterCombinaison(int CombiCache[], int Combi[], int NbPions, int& NbPionsPlaces, int& NbPionsMalPlaces) {
	bool Correct = false;
	int RegarderCombi[4]=  { 0, 0, 0, 0 };
	for (int i = 0; i < NbPions; i++) {
		if (CombiCache[i]==Combi[i]){
			NbPionsPlaces += 1;
			RegarderCombi[i] = Combi[i];
			bool Correct = true;
		
		}
		else {
			Correct = false;
				for (int j = 0; j < NbPions; j++) {

					if (Combi[j] == CombiCache[i] && RegarderCombi[i] != Combi[j]) {
						NbPionsMalPlaces += 1;
						RegarderCombi[j] = Combi[i];
						break;
					}
				}
			 
		}
	}
	
	return Correct;
}

void AfficherCombinaison(int Combi[], int NbPions) {
	for (int i = 0; i < NbPions; i++) {
		Couleur(0, Combi[i], to_string(Combi[i]));
		cout << " ";
	}
	
}
void AfficherCombinaisonCache(int CombiCache[], int NbPions) {
	
	for (int i = 0; i < NbPions; i++) {
		Couleur( 0, CombiCache[i], to_string(CombiCache[i]));
		cout << " ";
	
	}
	
}
void AfficherRegles(){
	cout << "Bienvenue dans le Mastermind";
	cout <<
		"    _                      _           _ \n" <<
		"                               | |                    (_)         | |\n" <<
		"          _ __ ___    __ _ ___ | |_ ___ _ __ _ __ ___  _ _ __   __| |\n" <<
		"          | '_ ` _\\  / _` / __| __/ _ \\ '__ | '_ ` _ \\| | '_ \\ / _` |\n" <<
		"          | | | | | | (_ | \\__ \\ || __/ |  | | | | | | | | | | (_|  |\n" <<
		"          |_| |_| |_|\\__, _ | ___ / \\__\\___ | _|  |_| |_| |_ | _    | \n" << endl;

	cout << " Le but du jeu est de trouver la combinaison cachee de l'ordinateur. Il n'y a que 8 couleurs attention ! Bon jeu ! \n" << endl;
}
void Couleur(int couleurDuTexte, int couleurDuFond, string Text) {
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, couleurDuFond * 16 + couleurDuTexte);
	cout << " " << Text << " ";
	SetConsoleTextAttribute(H, 0 * 16 + 15);

	
}