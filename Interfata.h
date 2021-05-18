#ifndef COLOCVIU_POO_2020_INTERFATA_H
#define COLOCVIU_POO_2020_INTERFATA_H

#include <iostream>

using namespace std;

class Interfata {
public:
    void primesteComenzi() {
        while (primesteComanda());
    }

private:
    bool primesteComanda() {
        int comanda;
        while (true) {
            cout << "(1) Adauga un nou dezinfectant in stoc\n"
                 << "(2) Adauga o noua masca in stoc\n"
                 << "(3) Adauga o noua achizitie\n"
                 << "(4) Afiseaza dezinfectantul cel mai eficient\n"
                 << "(5) Calculeaza venitul dintr-o anumita luna\n"
                 << "(6) Calculeaza venitul obtinut din mastile chirurgicale cu model\n"
                 << "(7) Modifica reteta unui dezinfectant\n"
                 << "(8) Afiseaza cel mai fidel client\n"
                 << "(9) Calculeaza TVA-ul pentru un anumit an\n"
                 << "(10) Opreste programul\n"
                 << "Alegeti comanda (1-10): ";
            if (cin >> comanda && comanda >= 1 && comanda <= 10) {
                break;
            } else {
                cout << "\n[!] Comanda nerecunoscuta.\n\n";
                cin.clear();
                cin.ignore(256, '\n');
            }
        }

        if (comanda == 10) {
            return false;
        }

        return false;
    }
};

#endif //COLOCVIU_POO_2020_INTERFATA_H
