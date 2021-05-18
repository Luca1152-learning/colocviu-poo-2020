#ifndef COLOCVIU_POO_2020_PRODUCATOR_H
#define COLOCVIU_POO_2020_PRODUCATOR_H

#include "Achizitie.h"
#include "../produs/dezinfectant/Dezinfectant.h"
#include "../produs/masca/Masca.h"
#include <unordered_map>

class Producator {
public:
    vector<Achizitie *> &getAchizitii();

    void adaugaDezinfectant(Dezinfectant *dezinfectant);

    void adaugaMasca(Masca *masca);

    void adaugaAchizitie(Achizitie *achizitie);

    Dezinfectant *getCelMaiEficientDezinfectant();

    double getVenitLuna(int luna, int an);

    double getVenitMastiChirurgicaleCuModel();

    void modificaRetetaDezinfectant();

    string getCelMaiFidelClient();

    void afiseazaCeaMaiSlabaZi();

    double getTVA(int an);

    virtual ~Producator();

    vector<Dezinfectant *> &getDezinfectanti();

    vector<Masca *> getMasti();

private:
    vector<Achizitie *> m_achizitii;
    vector<Dezinfectant *> m_dezinfectanti;
    vector<Masca *> m_masti;
};

#endif //COLOCVIU_POO_2020_PRODUCATOR_H
