#include "MascaPolicarbonat.h"

MascaPolicarbonat::MascaPolicarbonat(string tipPrindere, string culoare) :
        Masca("ffp0", move(culoare)), m_tipPrindere(move(tipPrindere)) {
}

istream &operator>>(istream &in, MascaPolicarbonat &masca) {
    string tipProtectie, culoare, tipPrindere;

    cout << "Tip protectie masca policarbonat (ffp1, ffp2, ffp3): ";
    cin.get();
    getline(in, tipProtectie);
    cout << "Tip prindere masca policarbonat: ";
    getline(in, tipPrindere);
    cout << "Culoare masca policarbonat: ";
    getline(in, culoare);

    masca.m_tipProtectie = tipProtectie;
    masca.m_tipPrindere = tipPrindere;
    masca.m_culoare = culoare;

    return in;
}

double MascaPolicarbonat::getPret() const {
    return 20;
}

ostream &operator<<(ostream &out, const MascaPolicarbonat &masca) {
    out << "Masca policarbonat (protectie " << masca.m_tipProtectie << ", prindere "
        << masca.m_tipPrindere << ", " << masca.m_culoare << ")";
    return out;
}
