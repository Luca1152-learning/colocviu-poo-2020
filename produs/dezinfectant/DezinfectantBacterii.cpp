#include "DezinfectantBacterii.h"

DezinfectantBacterii::DezinfectantBacterii(double nrSpeciiUcise, const vector<string> &ingrediente,
                                           const vector<string> &suprafete)
        : Dezinfectant(nrSpeciiUcise, ingrediente, suprafete) {}

double DezinfectantBacterii::getEficienta() const {
    return m_nrSpeciiUcise / NR_TOTAL_BACTERII;
}
