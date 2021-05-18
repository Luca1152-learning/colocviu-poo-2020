#ifndef COLOCVIU_POO_2020_ACHIZITIE_H
#define COLOCVIU_POO_2020_ACHIZITIE_H

#include <string>
#include <vector>
#include "../produs/dezinfectant/Dezinfectant.h"
#include "../produs/dezinfectant/DezinfectantBacterii.h"
#include "../produs/dezinfectant/DezinfectantFungi.h"
#include "../produs/dezinfectant/DezinfectantVirusuri.h"
#include "../produs/masca/Masca.h"
#include "../produs/masca/MascaChirurgicala.h"
#include "../produs/masca/MascaPolicarbonat.h"

using namespace std;

class Achizitie {
public:
    explicit Achizitie(int zi = 1, int luna = 1, int an = 1970, string numeClient = "Default");

    vector<Dezinfectant *> &getDezinfectantiAchizitionati();

    vector<Masca *> &getMastiAchizitionate();

    Achizitie(const Achizitie &achizitie);

    string getNumeClient() const;

    int getZiAchizitie() const;

    int getLunaAchizitie() const;

    int getAnAchizitie() const;

    Achizitie &operator+=(Dezinfectant *dezinfectant);

    Achizitie &operator+=(Masca *masca);

    Achizitie &operator=(const Achizitie &other);

    ~Achizitie();

    double getValoareFactura() const;

    bool operator<(const Achizitie &other) const;

    bool operator>(const Achizitie &other) const;

    bool operator<=(const Achizitie &other) const;

    bool operator>=(const Achizitie &other) const;

    bool operator==(const Achizitie &other) const;

    bool operator!=(const Achizitie &other) const;

private:
    int m_zi, m_luna, m_an;
    string m_numeClient;

    vector<Dezinfectant *> m_dezinfectantiAchizitionati;
    vector<Masca *> m_mastiAchizitionate;
};

#endif //COLOCVIU_POO_2020_ACHIZITIE_H
