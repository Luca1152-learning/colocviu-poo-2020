#ifndef COLOCVIU_POO_2020_DEZINFECTANTBACTERII_H
#define COLOCVIU_POO_2020_DEZINFECTANTBACTERII_H

#include <string>
#include "Dezinfectant.h"

using namespace std;

class DezinfectantBacterii : public Dezinfectant {
public:
    explicit DezinfectantBacterii(double nrSpeciiUcise = 0, const vector<string> &ingrediente = {},
                                  const vector<string> &suprafete = {});

    double getEficienta() const override;

private:
    static constexpr double NR_TOTAL_BACTERII = 1000000000;
};

#endif //COLOCVIU_POO_2020_DEZINFECTANTBACTERII_H
