#include "MascaChirurgicala.h"

MascaChirurgicala::MascaChirurgicala(string tipProtectie, string culoare, int nrPliuri, string model) :
        Masca(move(tipProtectie), move(culoare)), m_nrPliuri(nrPliuri), m_model(move(model)) {}

string MascaChirurgicala::getModel() const {
    return m_model;
}

bool MascaChirurgicala::areModel() const {
    return !m_model.empty();
}

istream &operator>>(istream &in, MascaChirurgicala &masca) {
    string tipProtectie, culoare, model;
    int nrPliuri;

    cout << "Tip protectie masca chirurghicala (ffp1, ffp2, ffp3): ";
    cin.get();
    getline(in, tipProtectie);
    cout << "Culoare masca chirurgicala: ";
    getline(in, culoare);
    cout << "Numar de pliuri: ";
    in >> nrPliuri;
    cout << "Model: ";
    cin.get();
    getline(in, model);

    masca.m_tipProtectie = tipProtectie;
    masca.m_nrPliuri = nrPliuri;
    masca.m_culoare = culoare;

    return in;
}

ostream &operator<<(ostream &out, const MascaChirurgicala &masca) {
    out << "Masca chirurgicala (protectie " << masca.m_tipProtectie << ", " << masca.m_culoare << ", "
        << masca.m_nrPliuri << " pliuri";
    if (!masca.m_model.empty()) {
        out << ", model cu" << masca.m_model;
    }
    out << ")";

    return out;
}

double MascaChirurgicala::getPret() const {
    double pret = Masca::getPret();
    if (m_model.empty()) {
        return pret;
    } else {
        return 2 * pret;
    }
}
