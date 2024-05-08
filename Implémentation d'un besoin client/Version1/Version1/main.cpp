#include "PixelToChar.h"

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif // _WIN32
    //Ouverture du fichier "img1.pgm" en mode binaire :
    std::ifstream fichier("img1.pgm", std::ios_base::binary);

    //Ici on décode l'entête du fichier 
    
    // Première ligne
    std::string inputLine;
    std::getline(fichier, inputLine);
    if (inputLine.compare("P5") != 0) std::cerr << "Version error";
    else std::cout << "Version : " << inputLine << "\n";

    // Deuxième ligne : commentaire
    std::getline(fichier, inputLine);
    std::cout << "Comment : " << inputLine << "\n";

    //Troisième ligne : longueur et largeuer de l'image
    //On transforme la chaîne de caractère en tableau, chaques éléments du tableau sont les mots séparé par un espace
    std::getline(fichier, inputLine);
    std::stringstream ss(inputLine);
    std::string element;
    std::vector<std::string> elements;
    while (std::getline(ss, element, ' ')) {
        elements.push_back(element);
    }
    //On transformes les valeurs du tableaux en int pour s'en servir comme dimention du tableau 
    int numline = std::stoi(elements[0]);
    int numcols = std::stoi(elements[1]);
    std::cout << numline << " " << numcols << "\n";

    //Quatrième ligne
    std::getline(fichier, inputLine);
    std::cout << inputLine << "\n";

    //Début du programme V1
    std::vector<std::vector<char>>Table;
    std::vector<char> donnes(numline);
    //Récupération lignes par lignes puis ajout dans le tableau Table qui les stockes toutes
    for (size_t i = 0; i < numcols; i++)
    {
        fichier.read(donnes.data(), numline);
        Table.push_back(donnes);
    }
    //Convertion par la fonction mapPixelToChar des valeurs en nuance de gris puis affichage caractère par caractère
    for (size_t i = 0; i < Table.size(); i++)
    {
        for (size_t j = 0; j < Table[i].size(); j++)
        {
            std::cout << mapPixelToChar(Table[i][j]);
        }
        std::cout << "\n";
    }
}