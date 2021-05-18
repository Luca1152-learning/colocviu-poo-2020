#ifndef COLOCVIU_POO_2020_DEZINFECTANTVIRUSURI_H
#define COLOCVIU_POO_2020_DEZINFECTANTVIRUSURI_H

#include "Dezinfectant.h"
#include <string>
#include <vector>

using namespace std;

class DezinfectantVirusuri : public Dezinfectant {
public:
    DezinfectantVirusuri(double nrSpeciiUcise, const vector<string> &ingrediente, const vector<string> &suprafete)
            : Dezinfectant(nrSpeciiUcise, ingrediente, suprafete) {}

    double getEficienta() const override {
        return m_nrSpeciiUcise / NR_TOTAL_VIRUSURI;
    }

private:
    static constexpr double NR_TOTAL_VIRUSURI = 100000000;
};

#endif //COLOCVIU_POO_2020_DEZINFECTANTVIRUSURI_H
