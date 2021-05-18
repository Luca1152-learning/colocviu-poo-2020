#ifndef COLOCVIU_POO_2020_MASCACHIRURGICALA_H
#define COLOCVIU_POO_2020_MASCACHIRURGICALA_H

#include "Masca.h"
#include <string>
#include <ostream>
#include <iostream>
#include <utility>

using namespace std;

class MascaChirurgicala : public Masca {
public:
    explicit MascaChirurgicala(string tipProtectie = "ffp1", string culoare = "neagra", int nrPliuri = 25,
                               string model = "");

    string getModel() const;

    bool areModel() const;

    friend istream &operator>>(istream &in, MascaChirurgicala &masca);

    friend ostream &operator<<(ostream &out, const MascaChirurgicala &masca);

    double getPret() const override;

private:
    int m_nrPliuri;
    string m_model;
};

#endif //COLOCVIU_POO_2020_MASCACHIRURGICALA_H
