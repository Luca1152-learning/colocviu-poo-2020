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
                               string model = "") :
            Masca(move(tipProtectie), move(culoare)), m_nrPliuri(nrPliuri), m_model(move(model)) {}

    string getModel() const {
        return m_model;
    }

    bool areModel() const {
        return !m_model.empty();
    }

    friend istream &operator>>(istream &in, MascaChirurgicala &masca) {
        string tipProtectie, culoare, model;
        int nrPliuri;

        cout << "Tip protectie masca chirurghicala (ffp1, ffp2, ffp3): ";
        cin.get();
        getline(in, tipProtectie);
        cout << "Culoare masca chirurgicala: ";
        getline(in, culoare);
        cout << "Numar de pliuri: ";
        in >> nrPliuri;
        cout << "Model: ";
        cin.get();
        getline(in, model);

        masca.m_tipProtectie = tipProtectie;
        masca.m_nrPliuri = nrPliuri;
        masca.m_culoare = culoare;

        return in;
    }

    friend ostream &operator<<(ostream &out, const MascaChirurgicala &masca) {
        out << "Masca chirurgicala (protectie " << masca.m_tipProtectie << ", " << masca.m_culoare << ", "
            << masca.m_nrPliuri << " pliuri";
        if (!masca.m_model.empty()) {
            out << ", model cu" << masca.m_model;
        }
        out << ")";

        return out;
    }

    double getPret() const override {
        double pret = Masca::getPret();
        if (m_model.empty()) {
            return pret;
        } else {
            return 2 * pret;
        }
    }

private:
    int m_nrPliuri;
    string m_model;
};

#endif //COLOCVIU_POO_2020_MASCACHIRURGICALA_H
