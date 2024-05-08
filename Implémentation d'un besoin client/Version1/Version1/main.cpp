#include "PixelToChar.h"

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif // _WIN32
    //Ouverture du fichier "img1.pgm" en mode binaire :
    std::ifstream fichier("img1.pgm", std::ios_base::binary);

    //Ici on d�code l'ent�te du fichier 
    
    // Premi�re ligne
    std::string inputLine;
    std::getline(fichier, inputLine);
    if (inputLine.compare("P5") != 0) std::cerr << "Version error";
    else std::cout << "Version : " << inputLine << "\n";

    // Deuxi�me ligne : commentaire
    std::getline(fichier, inputLine);
    std::cout << "Comment : " << inputLine << "\n";

    //Troisi�me ligne : longueur et largeuer de l'image
    //On transforme la cha�ne de caract�re en tableau, chaques �l�ments du tableau sont les mots s�par� par un espace
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

    //Quatri�me ligne
    std::getline(fichier, inputLine);
    std::cout << inputLine << "\n";

    //D�but du programme V1
    std::vector<std::vector<char>>Table;
    std::vector<char> donnes(numline);
    //R�cup�ration lignes par lignes puis ajout dans le tableau Table qui les stockes toutes
    for (size_t i = 0; i < numcols; i++)
    {
        fichier.read(donnes.data(), numline);
        Table.push_back(donnes);
    }
    //Convertion par la fonction mapPixelToChar des valeurs en nuance de gris puis affichage caract�re par caract�re
    for (size_t i = 0; i < Table.size(); i++)
    {
        for (size_t j = 0; j < Table[i].size(); j++)
        {
            std::cout << mapPixelToChar(Table[i][j]);
        }
        std::cout << "\n";
    }
}