#include "Console.h"

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

    // Deuxi�me ligne : comment
    std::getline(fichier, inputLine);

    //Troisi�me ligne : longueur et largeuer de l'image
    std::getline(fichier, inputLine);
    std::stringstream ss(inputLine);
    std::string element;
    std::vector<std::string> elements;
    while (std::getline(ss, element, ' ')) {
        elements.push_back(element);
    }
    int numline = std::stoi(elements[0]);
    int numcols = std::stoi(elements[1]);

    //Quatri�me ligne
    std::getline(fichier, inputLine);

    //d�but du programme
    std::vector<std::vector<char>>Table;
    std::vector<char> donnes(numline);

    for (size_t i = 0; i < numcols; i++)
    {
        fichier.read(donnes.data(), numline);
        Table.push_back(donnes);
    }
    pal palette = SetNewPalette(AskPaletteName());
    std::string filename = AskFileName();
    std::ofstream output(filename);
    for (size_t i = 0; i < Table.size(); i++)
    {
        for (size_t j = 0; j < Table[i].size(); j++)
        {
            std::string pixel = PixelToStr(Table[i][j], palette);
            output << pixel;
        }
        output << std::endl;
    }
}