/**
 * \file fonctions.h
 *
 * Déclaration des fonctions fournies.
 */
#pragma once
#include <vector>
#include <string>
#include <fstream> 
#include <sstream> 

using TabInit = std::vector<int>(*)(unsigned int);
using TabFonc = unsigned int(*)(std::vector<int>);

//!\brief Crée un tableau aléatoire
std::vector<int> initTabAleat(size_t N);

//!\brief Crée un tableau presque trié
std::vector<int> initTabPresqueTri(size_t N);

//!\brief Crée un tableau presque trié au début
std::vector<int> initTabPresqueTriDeb(size_t N);

//!\brief Crée un tableau presque trié à la fin
std::vector<int> initTabPresqueTriFin(size_t N);

//!\brief Crée un tableau presque trié entre le début et la fin
std::vector<int> initTabPresqueTriDebFin(size_t N);

//!\brief Vérifie qu'un tableau est correctement trié
void verifTri(const std::vector<int>& tab, const std::string& algoName = {});

//!\Tri par selection
unsigned int triSelection(std::vector<int>& tab);

unsigned int triBullesopti(std::vector<int>& tab);

unsigned int triPeigne(std::vector<int>& tab);

unsigned int triRapide(std::vector<int>& T, int premier, int dernier);

//!\ ToCSV
void ToCSV(std::vector<std::vector<int>>& tab);

