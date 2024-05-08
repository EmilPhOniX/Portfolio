#include "Console.h"

//On demande à l'utilisateur de renseigner le nom qui souhaite pour le fichier
std::string AskFileName() {
    std::string filename;
    std::cout << "Veuillez renseigner le nom du fichier que vous souhaitez creer : ";
    std::cin >> filename;
    std::cout << std::endl;
    std::cout << "Votre fichier est en cours de creation\n";
    //on prend le soint d'ajouter l'extention pour le confort d'utilisation 
    filename = filename + ".txt";
    return filename;
}