// TP1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "fonction.h"
#include<ctime>
#include <time.h>
#include <iostream> // Inclut la bibliothèque iostream
#include <string> // Inclut la bibliothèque string
#include <windows.h>
using namespace std; // Indique quel espace de noms on va utiliser

int main() {
	int EndGame = 0;
	srand(time(NULL));
	while (EndGame == 0) {
	const int NbCouleur = 8;
	const int NbPion = 4;
	int NbPionsPlaces = 0;
	int NbPionsMalPlaces = 0;
	int Combinaison[NbPion];
	int CombinaisonCache[NbPion];
	int Coup = 10;
		AfficherRegles();
		ChoisirCombinaition(CombinaisonCache, NbPion, NbCouleur);	
		for (int i = 0; i <= Coup - 1; i) {
			NbPionsPlaces = 0;
			NbPionsMalPlaces = 0;
			cout << "\nIl vous reste : " << Coup << " coup a jouer" << endl;
			
			SaisirCombinaison(Combinaison, NbPion);
			TesterCombinaison(CombinaisonCache, Combinaison, NbPion, NbPionsPlaces, NbPionsMalPlaces);
			cout << "Votre combinaison ";
			AfficherCombinaison(Combinaison, NbPion);
			cout << " contient " << NbPionsPlaces << " pions bien places et " << NbPionsMalPlaces << " pion mal places" << endl;
			Coup--;
			
			if (NbPionsPlaces == 4){
				cout << "Bravo, vous avez gagne, la combinaison etait : " << endl;
				AfficherCombinaison(Combinaison, NbPion);
				EndGame = 1;
				break;
			}
			else if (Coup == 0) {
				cout << " Desole vous avez perdu ! La combinaison etait " << endl;
				AfficherCombinaisonCache(CombinaisonCache, NbPion); 
				cout << endl;
				EndGame = 1;	
				break;
			}
		}
		cout << "Voulez-vous rejouer si oui taper 0" << endl;
		cin >> EndGame;
		
	}
	cout << "Fin de la partie ! Merci." << endl;
	
	
}
/*constantes pour stocker :
- le nombre de couleur
- le nombre de position à trouver
- le nombre d'essais possible */
// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage
