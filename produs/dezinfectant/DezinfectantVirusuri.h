#ifndef COLOCVIU_POO_2020_DEZINFECTANTVIRUSURI_H
#define COLOCVIU_POO_2020_DEZINFECTANTVIRUSURI_H

#include "Dezinfectant.h"
#include <string>
#include <vector>

using namespace std;

class DezinfectantVirusuri : public Dezinfectant {
public:
    explicit DezinfectantVirusuri(double nrSpeciiUcise = 0, const vector<string> &ingrediente = {},
                                  const vector<string> &suprafete = {});

    double getEficienta() const override;

private:
    static constexpr double NR_TOTAL_VIRUSURI = 100000000;
};

#endif //COLOCVIU_POO_2020_DEZINFECTANTVIRUSURI_H
