#include "Masca.h"

double Masca::getPret() const {
    if (m_tipProtectie == "ffp1") {
        return 5;
    } else if (m_tipProtectie == "ffp2") {
        return 10;
    } else if (m_tipProtectie == "ffp3") {
        return 15;
    }
    return 0;
}

ostream &operator<<(ostream &out, const Masca &masca) {
    out << "Masca. "
        << "Tip protectie: " << masca.m_tipProtectie
        << " | Culoare: " << masca.m_culoare;
    return out;
}
