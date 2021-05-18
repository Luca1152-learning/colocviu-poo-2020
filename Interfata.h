#ifndef COLOCVIU_POO_2020_INTERFATA_H
#define COLOCVIU_POO_2020_INTERFATA_H

#include <iostream>
#include "business/Producator.h"

using namespace std;

class Interfata {
public:
    void primesteComenzi();

private:
    Producator m_producator;

    bool primesteComanda();

    void adaugaDezinfectantInStoc();

    void adaugaMascaInStoc();

    void adaugaAchizitie(Achizitie *achizitie);
};

#endif //COLOCVIU_POO_2020_INTERFATA_H
