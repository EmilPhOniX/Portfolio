#include <iostream>
#include "fonctions.h"
#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32

int main() {
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
#endif // _WIN32
	srand(time(NULL));
	
	// Initialisation de tableaux de fonctions � l'aide de pointeurs, ces tableaux sont utilis�s afin de faciliter et d'all�ger le programme principal.
	InitFunction init[] = { initTabAleat, initTabPresqueTri, initTabPresqueTriDeb, initTabPresqueTriDebFin, initTabPresqueTriFin };
	TriFunction Fonc[] = { triSelection, triBulles, triBullesOpti, triRapideInit, triPeigne, triFusionInit, triParTasInit, triInsertion, triParComptage };
	
	// Cr�ation de tableaux de string, ces tableaux sont utilis�s afin de faciliter et d'all�ger le programme principal et l'affichage console.
	std::vector<std::string> TriName = { "Select", "Bulle", "Bulle Opti", "Rapide", "Peigne", "Fusion","Tas", "Insertion", "Comptage"};
	std::vector<std::string> TypeTab = { "Aleat", "PresqueTri", "PresqueTriDeb", "PresqueTriDebFin", "PresqueTriFin" };
	
	// Cr�ation d'un vector de vector contenant les donn�es � inserer dans le fichier CSV � la fin du programme.
	std::vector<std::vector<int>> CSVdatas;
	
	// Cr�ation d'une boucle permettant de g�n�rer 10 tableaux de nombre al�atoires � l'aide des fonctions initTab*, chaque tableau contient un nombre al�atoire de valeurs.
	for (int n = 0; n < 10; n++) {
		unsigned int val = rand() % 100 + 2;
		std::vector<int> CSVdata;
		CSVdata.push_back(val);
		for (size_t i = 0; i < sizeof(Fonc) / sizeof(Fonc[0]); i++)
		{
			for (size_t j = 0; j < 5; ++j) {
				std::vector<int> tempTable = init[j](val);
				CSVdata.push_back(triEtVerif(tempTable, TriName[i], j, *Fonc[i]));
			}
		}
		CSVdatas.push_back(CSVdata);
	}
	ToCSV(CSVdatas, TypeTab, TriName);
}