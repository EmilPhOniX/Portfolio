#include "Console.h"

//On demande à l'utilisateur de renseigner le nom qui souhaite pour le fichier
std::string AskFileName() {
    std::string filename;
    std::cout << "Veuillez renseigner le nom de votre fichier : ";
    std::cin >> filename;
    std::cout << std::endl;
    return filename + ".txt";
}

std::string AskPaletteName() {
    std::string palettename;
    std::cout << "Veuillez renseigner le nom de votre palette : ";
    std::cin >> palettename;
    std::cout << std::endl;
    return palettename + ".txt";
}

pal SetNewPalette(std::string paletteName) {
    std::ifstream palettefile(paletteName);
    std::string line;
    pal newPalette{};
    while (std::getline(palettefile, line)) {
        if (line.empty()) {
            newPalette.push_back(" ");
        }
        else {
            newPalette.push_back(line);
        }
    }
    return newPalette;
}