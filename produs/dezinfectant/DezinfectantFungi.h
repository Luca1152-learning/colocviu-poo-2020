#ifndef COLOCVIU_POO_2020_DEZINFECTANTFUNGI_H
#define COLOCVIU_POO_2020_DEZINFECTANTFUNGI_H

#include <string>
#include <vector>
#include "Dezinfectant.h"

using namespace std;

class DezinfectantFungi : public Dezinfectant {
public:
    explicit DezinfectantFungi(double nrSpeciiUcise = 0, const vector<string> &ingrediente = {},
                               const vector<string> &suprafete = {});

    double getEficienta() const override;

private:
    static constexpr double NR_TOTAL_FUNGI = 1500000;
};

#endif //COLOCVIU_POO_2020_DEZINFECTANTFUNGI_H
