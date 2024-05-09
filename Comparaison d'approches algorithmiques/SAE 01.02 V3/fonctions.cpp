/**
 * \file fonctions.cpp
 *
 * Définition des fonctions fournies.
 */
#include "fonctions.h"
#include <iostream>


 /**
  * Crée un tableau d'entiers dont tous les éléments sont choisis aléatoirement.
  *
  * Un tel tableau peut par exemple être 30968 28073 31177 2882 6140 17999 13828 20039 2310 24865.
  *
  * \param[in] N taille du tableau
  * \return le tableau initialisé
  */
std::vector<int> initTabAleat(size_t N) {
	std::vector<int> tab(N);
	for (auto& val : tab)
		val = rand();
	return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Chaque élément est quasiment à sa place définitive, échangé éventuellement d'une place.
 *
 * Un tel tableau peut par exemple être 1 3 2 4 6 5 8 7 9 10.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTri(size_t N) {
	std::vector<int> tab(N);
	for (int i = 0; i < N; i++)
		tab[i] = i;
	for (int i = 0; i < N - 1; i++)
	{
		if (rand() % 2 == 0)
		{
			std::swap(tab[i], tab[i + 1]);
			++i;
		}
	}
	return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Seuls le premier et le deuxième élément sont échangés.
 *
 * Un tel tableau peut par exemple être 2 1 3 4 5 6 7 8 9 10.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTriDeb(size_t N) {
	std::vector<int> tab(N);
	for (int i = 0; i < N; i++)
		tab[i] = i;
	std::swap(tab[0], tab[1]);
	return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Seuls le dernier et l'avant dernier élément sont échangés.
 *
 * Un tel tableau peut par exemple être 1 2 3 4 5 6 7 8 10 9.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTriFin(size_t N) {
	std::vector<int> tab(N);
	for (int i = 0; i < N; i++)
		tab[i] = i;
	std::swap(tab[N - 1], tab[N - 2]);
	return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Seuls le premier et le dernier élément sont échangés.
 *
 * Un tel tableau peut par exemple être 10 2 3 4 5 6 7 8 9 1.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTriDebFin(size_t N) {
	std::vector<int> tab(N);
	for (int i = 0; i < N; i++)
		tab[i] = i;
	std::swap(tab[N - 1], tab[0]);
	return tab;
}

/**
 * Vérifie qu'un tableau est correctement trié. Si le tableau est mal trié, un message d'erreur est
 * affiché sur le flux d'erreur et le programme est terminé.
 *
 * \param[in] tab Le tableau à vérifier
 * \param[in] algoName Le nom de l'algorithme de tri qui a été utilisé. Ce paramètre est optionnel.
 */
void verifTri(const std::vector<int>& tab, const std::string& algoName) {
	const size_t taille = tab.size();
	for (size_t i = 1; i < taille; i++)
	{
		if (tab[i - 1] > tab[i])
		{
			std::cerr << "Erreur dans le tri " << algoName << (algoName.empty() ? "!" : " !") << '\n';
			exit(EXIT_FAILURE);
		}
	}
}


/*------------------------------------------------*/
/*--------------------Les tris--------------------*/
/*------------------------------------------------*/

unsigned int triSelection(std::vector<int>& tab) {
	size_t n = tab.size();
	unsigned int nb_comparaisons = 0;
	for (int i = 0; i <= n - 2; i++) {
		for (int j = i + 1; j < n; j++) {
			if (tab[j] < tab[i]) {
				//swap(tab[i],tab[j]) permet d'interchanger les deux éléments du tableau, ainsi l'élément initialement en position i se trouvera en position j et inversement.
				std::swap(tab[j], tab[i]);
			}
			nb_comparaisons++;
		}
	}
	return nb_comparaisons;
}

unsigned int triBulles(std::vector<int>& tab) {
	unsigned int nb_comparaisons = 0;
	for (int i = tab.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (tab[j + 1] < tab[j]) {
				std::swap(tab[j], tab[j + 1]);
			}
			nb_comparaisons++;
		}
	}
	return nb_comparaisons;
}

unsigned int triBullesOpti(std::vector<int>& tab) {
	size_t n = tab.size();
	unsigned int nb_comparaisons = 0;
	for (int i = n - 1; i >= 1; i--) {
		bool tabtrie = true;
		for (int j = 0; j <= i - 1; j++) {
			if (tab[j + 1] < tab[j]) {
				std::swap(tab[j + 1], tab[j]);
				tabtrie = false;
			}
			nb_comparaisons++;

		}
		if (tabtrie)
			return nb_comparaisons;
	}
	return nb_comparaisons;
}

unsigned int triRapideInit(std::vector<int>& tab) {
	int nb_comparaisons = triRapide(tab, 0, tab.size() - 1);
	return nb_comparaisons;
}

unsigned int triRapide(std::vector<int>& tab, int debut, int fin) {
	unsigned int nb_comparaisons = 0;

	if (debut < fin) {
		int pivotIndex = debut + (fin - debut) / 2;
		int pivot = tab[pivotIndex];
		int i = debut;
		int j = fin;
		while (i <= j) {
			while (tab[i] < pivot) {
				i++;
				nb_comparaisons++;
			}
			while (tab[j] > pivot) {
				j--;
				nb_comparaisons++;
			}

			if (i <= j) {
				std::swap(tab[i], tab[j]);
				i++;
				j--;
			}
		}
		//Ici la récursivité est utilisé afin de parcourir chaque donnée du tableau de part et d'autre du pivot
		nb_comparaisons += triRapide(tab, debut, j);
		nb_comparaisons += triRapide(tab, i, fin);
	}
	return nb_comparaisons;
}

unsigned int triPeigne(std::vector<int>& tab) {
	size_t n = tab.size();
	int interval = n;
	int nb_comparaisons = 0;
	bool echange = true;

	while (interval > 1 || echange) {
		interval = static_cast<int>(interval / 1.3);

		if (interval < 1)
			interval = 1;

		int i = 0;
		echange = false;

		while (i < n - interval) {
			if (tab[i] > tab[i + interval])
			{
				std::swap(tab[i], tab[i + interval]);
				echange = true;
			}
			++i;
			++nb_comparaisons;
		}
	}
	return nb_comparaisons;
}

unsigned int triFusionInit(std::vector<int>& tab) {
	int nb_comparaisons = triFusion(tab, tab.size() / 2);
	return nb_comparaisons;
}

unsigned int triFusion(std::vector<int>& tab, int Pivot) {
	unsigned int nb_comparaisons = 0;

	if (tab.size() > 1) {
		std::vector<int> subgauche(tab.begin(), tab.begin() + Pivot);
		std::vector<int> subdroit(tab.begin() + Pivot, tab.end());
		
		//Ici la récursivité est utilisé afin de parcourir chaque donnée dans le sous tableau gauche et le sous tableau droit de chaque itteration.
		nb_comparaisons += triFusion(subgauche, subgauche.size() / 2);
		nb_comparaisons += triFusion(subdroit, subdroit.size() / 2);
		int i = 0, j = 0, k = 0;
		while (i < subgauche.size() && j < subdroit.size()) {
			if (subgauche[i] <= subdroit[j]) {
				tab[k] = subgauche[i];
				i++;
			}
			else {
				tab[k] = subdroit[j];
				j++;
			}
			k++;
			nb_comparaisons++;
		}
		while (i < subgauche.size()) {
			tab[k] = subgauche[i];
			i++;
			k++;
		}
		while (j < subdroit.size()) {
			tab[k] = subdroit[j];
			j++;
			k++;
		}
	}
	return nb_comparaisons;
}

unsigned int triInsertion(std::vector<int>& tab) {
	unsigned int nb_comparaisons = 0;
	for (int i = 0; i < tab.size(); i++) {
		int x = tab[i];
		int j = i;
		while (j > 0 && tab[j - 1] > x) {
			tab[j] = tab[j - 1];
			--j;
			++nb_comparaisons;
		}
		tab[j] = x;
	}
	return nb_comparaisons;
}

unsigned int triParTasInit(std::vector<int>& tab) {
	unsigned int nb_comparaisons = 0;
	int n = tab.size();
	for (int i = n / 2 - 1; i >= 0; --i) {
		nb_comparaisons += triParTas(tab, i, n);
	}

	for (int i = n - 1; i > 0; --i) {
		std::swap(tab[0], tab[i]);
		nb_comparaisons += triParTas(tab, 0, i);
	}
	return nb_comparaisons;
}

unsigned int triParTas(std::vector<int>& tab, int noeud, int n) {
	unsigned int nb_comparaisons = 0;
	int largest = noeud;
	int left = 2 * noeud + 1;
	int right = 2 * noeud + 2;

	if (left < n && tab[left] > tab[largest])
		largest = left;
	nb_comparaisons++;

	if (right < n && tab[right] > tab[largest])
		largest = right;
	nb_comparaisons++;

	if (largest != noeud) {
		std::swap(tab[noeud], tab[largest]);
		triParTas(tab, largest, n);
	}
	nb_comparaisons++;

	return nb_comparaisons;
}

unsigned int triParComptage(std::vector<int>& tab) {
	unsigned int nb_comparaisons = 0;
	int borneSup = 0;
	for (int k : tab) {
		if (k > borneSup){
			borneSup = k;
		}
		nb_comparaisons++;
	}
	
	std::vector<int>tabComptage(borneSup + 1, 0);
	for (int k : tab) {
		tabComptage[k]++;
	}

	int n = tabComptage.size();
	int cpt = 0;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < tabComptage[i]; j++) {
			tab[cpt] = i;
			cpt++;
		}
	}
	tabComptage = tab;
	return nb_comparaisons;
}

/*-------------------------------------------------------------*/
/*--------------------Les autres fonctions--------------------*/
/*-----------------------------------------------------------*/

unsigned int triEtVerif(std::vector<int>& table, const std::string& Titre, int occ, TriFunction fonction) {
	std::vector<std::string> GenType = { "Aleat","PresqueTri","PresqueTriDeb","PresqueTriDeFin","PresqueTriFin" };
	std::cout << "\n" << Titre << GenType[occ] << " : \n";
	std::cout << "Nombre d'éléments dans le tableau : " << table.size() << "\n";
	unsigned int comp = fonction(table);
	std::cout << "Nombre de comparaisons : " << comp << "\n";
	verifTri(table, { Titre });
	return comp;
}

void ToCSV(std::vector<std::vector<int>>& tab, std::vector<std::string> TypeTab, std::vector<std::string> TypeTri) {
	std::ofstream CSVfile;

	CSVfile.open("output.csv");
	CSVfile << "N;";
	for (size_t i = 0; i < TypeTri.size(); i++)
	{
		for (size_t j = 0; j < TypeTab.size(); j++)
			CSVfile << TypeTab[j] + " " + TypeTri[i] + ";";
	}
	CSVfile << "\n";

	for (int i = 0; i < tab.size(); ++i) {

		for (int j = 0; j < tab[i].size(); ++j) {
			CSVfile << tab[i][j];
			if (j < tab[i].size() - 1) {
				CSVfile << ";";
			}
		}
		CSVfile << "\n";
	}
	CSVfile.close();
}