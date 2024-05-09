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

/*----------------------------------------------------------*/
/*--------------------Création de types--------------------*/
/*--------------------------------------------------------*/

// Création de Types de fonctions à l'aide de pointeurs, ils permettent la création de tableaux de fonctions 
// utilisés  de faciliter et d'alléger le programme principal.
using TabFunction = std::vector<int>(*)(size_t);
using TriFunction = unsigned int (*)(std::vector<int>&);
using InitFunction = std::vector<int>(*)(size_t);

/*------------------------------------------------*/
/*--------------------Les tris--------------------*/
/*------------------------------------------------*/

//triSelection permet de trier un tableau selon les règles définies du tri par selection 
unsigned int triSelection(std::vector<int>& tab);

//triBulles permet de trier un tableau selon les règles définies du tri à bulles
unsigned int triBulles(std::vector<int>& tab);

//triBullesOpti permet de trier un tableau selon les règles définies du tri à bulles, mais dans une version optimisée
unsigned int triBullesOpti(std::vector<int>& tab);

//triRapideInit permet d'initialiser la fonction de triRapide
unsigned int triRapideInit(std::vector<int>& tab);

//tri Rapide permet de trier un tableau selon les règles définies du tri rapide
unsigned int triRapide(std::vector<int>& tab, int debut, int fin);

//triPeigne permet de trier un tableau selon les règles définies du tri à Peigne
unsigned int triPeigne(std::vector<int>& tab);

//triFusionInit permet d'initialiser la fonction triFusion
unsigned int triFusionInit(std::vector<int>& tab);

//triFusion permet de trier un tableau selon les règles définies du Tri par Fusion
unsigned int triFusion(std::vector<int>& tab, int Pivot);

//triInsertion permet de trier un tableau selon les règles définies du Tri par Insertion
unsigned int triInsertion(std::vector<int>& tab);

//triParTasInit permet d'initialiser la fonction triParTas
unsigned int triParTasInit(std::vector<int>& tab);

//triParTas permet de trier un tableau selon les règles définies du Tri Par Tas
unsigned int triParTas(std::vector<int>& tab, int noeud, int n);

//triParComptage permet de trier un tableau selon les règles définies du Tri par comptage
unsigned int triParComptage(std::vector<int>& tab);

/*-------------------------------------------------------------*/
/*--------------------Les autres fonctions--------------------*/
/*-----------------------------------------------------------*/

//triEtVerif permet de vérifier à l'aide de la fonction verifTri et de renvoyer le nombre de comparaisons effectuées lors 
// de l'execution des fonctions. De plus cette fonction gère l'affichage dans la console des résultats obtenus.
unsigned int triEtVerif(std::vector<int>& table, const std::string& Titre, int occ, TriFunction);

// ToCSV permet de creer un fichier CSV et d'inserer les données crées
void ToCSV(std::vector<std::vector<int>>& tab, std::vector<std::string> TypeTab, std::vector<std::string> TypeTri);