#include "DezinfectantVirusuri.h"

DezinfectantVirusuri::DezinfectantVirusuri(double nrSpeciiUcise, const vector<string> &ingrediente,
                                           const vector<string> &suprafete)
        : Dezinfectant(nrSpeciiUcise, ingrediente, suprafete) {}

double DezinfectantVirusuri::getEficienta() const {
    return m_nrSpeciiUcise / NR_TOTAL_VIRUSURI;
}
