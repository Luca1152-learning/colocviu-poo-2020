#ifndef COLOCVIU_POO_2020_INTERFATA_H
#define COLOCVIU_POO_2020_INTERFATA_H

#include <iostream>
#include "business/Producator.h"

using namespace std;

class Interfata {
public:
    void primesteComenzi() {
        while (primesteComanda());
    }

private:
    Producator producator;

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

        if (comanda == 1) {
            // TODO
            producator.adaugaDezinfectant(nullptr);
        } else if (comanda == 2) {
            // TODO
            producator.adaugaMasca(nullptr);
        } else if (comanda == 3) {
            // TODO
            producator.adaugaAchizitie(nullptr);
        } else if (comanda == 4) {
            cout << "\n" << *producator.getCelMaiEficientDezinfectant() << "\n\n";
        } else if (comanda == 5) {
            cout << "\n";
            int luna, an;
            cout << "Luna: ";
            cin >> luna;
            cout << "An: ";
            cin >> an;
            cout << "\n" << producator.getVenitLuna(luna, an) << " lei\n\n";
        } else if (comanda == 6) {
            cout << "\n" << producator.getVenitMastiChirurgicaleCuModel() << " lei\n\n";
        } else if (comanda == 7) {
            producator.modificaRetetaDezinfectant();
        } else if (comanda == 8) {
            cout << "\nCel mai fidel client este " << producator.getCelMaiFidelClient() << "\n\n";
        } else if (comanda == 9) {
            cout << "\n";
            int an;
            cout << "An: ";
            cin >> an;
            cout << "\n" << producator.getTVA(an) << "\n\n";
        } else {
            return false;
        }

        return true;
    }
};

#endif //COLOCVIU_POO_2020_INTERFATA_H
