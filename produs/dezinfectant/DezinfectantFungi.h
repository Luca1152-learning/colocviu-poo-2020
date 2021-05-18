#ifndef COLOCVIU_POO_2020_DEZINFECTANTFUNGI_H
#define COLOCVIU_POO_2020_DEZINFECTANTFUNGI_H

#include <string>
#include <vector>
#include "Dezinfectant.h"

using namespace std;

class DezinfectantFungi : public Dezinfectant {
public:
    DezinfectantFungi(double nrSpeciiUcise, const vector<string> &ingrediente, const vector<string> &suprafete)
            : Dezinfectant(nrSpeciiUcise, ingrediente, suprafete) {}

    double getEficienta() const override {
        return m_nrSpeciiUcise / NR_TOTAL_FUNGI;
    }

private:
    static constexpr double NR_TOTAL_FUNGI = 1500000;
};

#endif //COLOCVIU_POO_2020_DEZINFECTANTFUNGI_H
