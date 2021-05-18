#ifndef COLOCVIU_POO_2020_MASCAPOLICARBONAT_H
#define COLOCVIU_POO_2020_MASCAPOLICARBONAT_H

#include <string>
#include <istream>
#include <ostream>
#include <iostream>
#include "Masca.h"

using namespace std;

class MascaPolicarbonat : public Masca {
public:
    explicit MascaPolicarbonat(string tipPrindere = "elastic", string culoare = "neagra");

    friend istream &operator>>(istream &in, MascaPolicarbonat &masca);

    double getPret() const override;

    friend ostream &operator<<(ostream &out, const MascaPolicarbonat &masca);

private:
    string m_tipPrindere;
};

#endif //COLOCVIU_POO_2020_MASCAPOLICARBONAT_H
