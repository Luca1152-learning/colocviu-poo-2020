#ifndef COLOCVIU_POO_2020_DEZINFECTANT_H
#define COLOCVIU_POO_2020_DEZINFECTANT_H

#include <vector>
#include <string>
#include <ostream>
#include "../Produs.h"

using namespace std;

class Dezinfectant : public Produs {
public:
    virtual double getEficienta() const = 0;

    double getPret() const override {
        double eficienta = getEficienta();
        if (eficienta < 0.90) {
            return 10;
        } else if (eficienta < 0.95) {
            return 20;
        } else if (eficienta < 0.975) {
            return 30;
        } else if (eficienta < 0.99) {
            return 40;
        } else if (eficienta < 0.9999) {
            return 50;
        } else {
            throw runtime_error("Pentru eficienta " + to_string(eficienta) + " nu a fost stabilit un pret.");
        }
    }

    friend ostream &operator<<(ostream &out, const Dezinfectant &dezinfectant) {
        out << "Dezinfectant."
            << "Specii ucise: " << dezinfectant.m_nrSpeciiUcise
            << " | Eficienta: " << dezinfectant.getEficienta() << "%"
            << " | Ingrediente: ";
        for (auto &it: dezinfectant.m_ingrediente) {
            out << it << " ";
        }
        out << "| Suprafete: ";
        for (auto &it: dezinfectant.m_suprafete) {
            out << it << " ";
        }
        return out;
    }

    virtual ~Dezinfectant() = default;

protected:
    double m_nrSpeciiUcise;
    vector<string> m_ingrediente, m_suprafete;

    Dezinfectant(double nrSpeciiUcise, const vector<string> &ingrediente, const vector<string> &suprafete)
            : m_nrSpeciiUcise(nrSpeciiUcise), m_ingrediente(ingrediente), m_suprafete(suprafete) {
    }
};

#endif //COLOCVIU_POO_2020_DEZINFECTANT_H
