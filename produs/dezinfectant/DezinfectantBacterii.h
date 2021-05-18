#ifndef COLOCVIU_POO_2020_DEZINFECTANTBACTERII_H
#define COLOCVIU_POO_2020_DEZINFECTANTBACTERII_H

#include <string>
#include "Dezinfectant.h"

using namespace std;

class DezinfectantBacterii : public Dezinfectant {
public:
    DezinfectantBacterii(double nrSpeciiUcise, const vector<string> &ingrediente, const vector<string> &suprafete)
            : Dezinfectant(nrSpeciiUcise, ingrediente, suprafete) {}

    double getEficienta() const override {
        return m_nrSpeciiUcise / NR_TOTAL_BACTERII;
    }

private:
    static constexpr double NR_TOTAL_BACTERII = 1000000000;
};

#endif //COLOCVIU_POO_2020_DEZINFECTANTBACTERII_H
