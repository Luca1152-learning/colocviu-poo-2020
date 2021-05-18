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
    MascaPolicarbonat(string tipPrindere = "elastic", string culoare = "neagra") :
            Masca("ffp0", culoare), m_tipPrindere(move(tipPrindere)) {
    }

    friend istream &operator>>(istream &in, MascaPolicarbonat &masca) {
        string tipProtectie, culoare, tipPrindere;

        cout << "Tip protectie masca policarbonat (ffp1, ffp2, ffp3): ";
        cin.get();
        getline(in, tipProtectie);
        cout << "Tip prindere masca policarbonat: ";
        getline(in, tipPrindere);
        cout << "Culoare masca policarbonat: ";
        getline(in, culoare);

        masca.m_tipProtectie = tipProtectie;
        masca.m_tipPrindere = tipPrindere;
        masca.m_culoare = culoare;

        return in;
    }

    double getPret() const override {
        return 20;
    }

    friend ostream &operator<<(ostream &out, const MascaPolicarbonat &masca) {
        out << "Masca policarbonat (protectie " << masca.m_tipProtectie << ", prindere "
            << masca.m_tipPrindere << ", " << masca.m_culoare << ")";
        return out;
    }

private:
    string m_tipPrindere;
};

#endif //COLOCVIU_POO_2020_MASCAPOLICARBONAT_H
