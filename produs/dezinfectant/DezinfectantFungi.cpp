#include "DezinfectantFungi.h"

DezinfectantFungi::DezinfectantFungi(double nrSpeciiUcise, const vector<string> &ingrediente,
                                     const vector<string> &suprafete)
        : Dezinfectant(nrSpeciiUcise, ingrediente, suprafete) {}

double DezinfectantFungi::getEficienta() const {
    return m_nrSpeciiUcise / NR_TOTAL_FUNGI;
}
