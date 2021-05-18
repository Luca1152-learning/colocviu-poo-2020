#ifndef COLOCVIU_POO_2020_DEZINFECTANT_H
#define COLOCVIU_POO_2020_DEZINFECTANT_H

#include <vector>
#include <string>
#include <ostream>
#include <iostream>
#include <istream>
#include "../Produs.h"

using namespace std;

class Dezinfectant : public Produs {
public:
    virtual double getEficienta() const = 0;

    double getPret() const override;

    friend ostream &operator<<(ostream &out, const Dezinfectant &dezinfectant);

    friend istream &operator>>(istream &in, Dezinfectant &dezinfectant);

    vector<string> &getIngrediente();

    vector<string> &getSuprafete();

    void setNrSpeciiUcise(double nr);

    virtual ~Dezinfectant() = default;

protected:
    double m_nrSpeciiUcise;
    vector<string> m_ingrediente, m_suprafete;

    Dezinfectant(double nrSpeciiUcise, const vector<string> &ingrediente, const vector<string> &suprafete);
};

#endif //COLOCVIU_POO_2020_DEZINFECTANT_H
