    #include <iostream>
    #include "fonctions.h"
    #ifdef _WIN32
    #include <Windows.h>
#endif // _WIN32

int main()
{

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif // _WIN32
    srand(time(NULL));

    int comp;
    //std::vector<int> CSVdata;
    std::vector<TabFonction> Fontions = { initTabAleat, initTabPresqueTri, initTabPresqueTriDeb, initTabPresqueTriFin, initTabPresqueTriDebFin };
    std::vector<>;



    std::vector<std::vector<int>> CSVdatas;
    for (int i = 0; i < 10; i++) {
        std::vector<int> CSVdata;
        int val = rand() % 100;
        CSVdata.push_back(val);

        std::cout << "Table aléatoire : \n";
        std::vector<int> tabAleat = initTabAleat(val);
        std::cout << "nombre d'éléments dans le tableau : " << val << "\n";
        comp = triSelection(tabAleat);
        CSVdata.push_back(comp);
        std::cout << "Nombre de comparaisons : " << comp << "\n";
        verifTri(tabAleat, { "Tri par selection table aléatoire" });

        std::cout << "\nTable presque trier : \n";
        std::vector<int> TabPresqueTri = initTabPresqueTri(val);
        std::cout << "nombre d'éléments dans le tableau : " << val << "\n";
        comp = triSelection(TabPresqueTri);
        CSVdata.push_back(comp);
        std::cout << "Nombre de comparaisons : " << comp << "\n";
        verifTri(TabPresqueTri, { "Tri par selection presque tri" });

        std::cout << "\nTable presque trier au debut : \n";
        std::vector<int> TabPresqueTriDeb = initTabPresqueTriDeb(val);
        std::cout << "nombre d'éléments dans le tableau : " << val << "\n";
        comp = triSelection(TabPresqueTriDeb);
        CSVdata.push_back(comp);
        std::cout << "Nombre de comparaisons : " << comp << "\n";
        verifTri(TabPresqueTriDeb, { "Tri par selection presque tri debut" });

        std::cout << "\nTable presque trier a la fin : \n";
        std::vector<int> TabPresqueTriFin = initTabPresqueTriFin(val);
        std::cout << "nombre d'éléments dans le tableau : " << val << "\n";
        comp = triSelection(TabPresqueTriFin);
        CSVdata.push_back(comp);
        std::cout << "Nombre de comparaisons : " << comp << "\n";
        verifTri(TabPresqueTriFin, { "Tri par selection presque tri fin" });

        std::cout << "\nTable presque trier au debut et la fin : \n";
        std::vector<int> TabPresqueTriDebFin = initTabPresqueTriDebFin(val);
        std::cout << "nombre d'éléments dans le tableau : " << val << "\n";
        comp = triSelection(TabPresqueTriDebFin);
        CSVdata.push_back(comp);
        std::cout << "Nombre de comparaisons : " << comp << "\n";

        verifTri(TabPresqueTriDebFin, { "Tri par selection presque tri debut fin" });
        CSVdatas.push_back(CSVdata);

        std::cout << "Table aléatoire : \n";
        std::vector<int> tabbullesopti = initTabAleat(val);
        std::cout << "nombre d'éléments dans le tableau : " << val << "\n";
        comp = triBullesopti(tabbullesopti);
        CSVdata.push_back(comp);
        std::cout << "Nombre de comparaisons : " << comp << "\n";
        verifTri(tabbullesopti, { "Tri par bulles opti table aléatoire" });


        std::cout << "Table aléatoire : \n";
        std::vector<int> tabpeigne = initTabAleat(val);
        std::cout << "nombre d'éléments dans le tableau : " << val << "\n";
        comp = triPeigne(tabpeigne);
        CSVdata.push_back(comp);
        std::cout << "Nombre de comparaisons : " << comp << "\n";
        verifTri(tabpeigne, { "peigne" });
    }
    ToCSV(CSVdatas);
}