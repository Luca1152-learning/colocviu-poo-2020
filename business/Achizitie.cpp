#include "Achizitie.h"

Achizitie::Achizitie(int zi, int luna, int an, string numeClient) :
        m_zi(zi), m_luna(luna), m_an(an), m_numeClient(move(numeClient)) {
}

vector<Dezinfectant *> &Achizitie::getDezinfectantiAchizitionati() {
    return m_dezinfectantiAchizitionati;
}

vector<Masca *> &Achizitie::getMastiAchizitionate() {
    return m_mastiAchizitionate;
}

Achizitie::Achizitie(const Achizitie &achizitie) {
    *this = achizitie;
}

string Achizitie::getNumeClient() const {
    return m_numeClient;
}

int Achizitie::getZiAchizitie() const {
    return m_zi;
}

int Achizitie::getLunaAchizitie() const {
    return m_luna;
}

int Achizitie::getAnAchizitie() const {
    return m_an;
}

Achizitie &Achizitie::operator+=(Dezinfectant *dezinfectant) {
    auto dezinfectantBacterii = dynamic_cast<DezinfectantBacterii *>(dezinfectant);
    if (dezinfectantBacterii) {
        m_dezinfectantiAchizitionati.push_back(new DezinfectantBacterii(*dezinfectantBacterii));
        return *this;
    }

    auto dezinfectantFungi = dynamic_cast<DezinfectantFungi *>(dezinfectant);
    if (dezinfectantFungi) {
        m_dezinfectantiAchizitionati.push_back(new DezinfectantFungi(*dezinfectantFungi));
        return *this;
    }

    auto dezinfectantVirusuri = dynamic_cast<DezinfectantVirusuri *>(dezinfectant);
    if (dezinfectantVirusuri) {
        m_dezinfectantiAchizitionati.push_back(new DezinfectantVirusuri(*dezinfectantVirusuri));
        return *this;
    }

    throw runtime_error("Tip de dezinfectant nedetectat.");
}

Achizitie &Achizitie::operator+=(Masca *masca) {
    auto mascaChirurgicala = dynamic_cast<MascaChirurgicala *>(masca);
    if (mascaChirurgicala) {
        m_mastiAchizitionate.push_back(new MascaChirurgicala(*mascaChirurgicala));
        return *this;
    }

    auto mascaPolicarbonat = dynamic_cast<MascaPolicarbonat *>(masca);
    if (mascaPolicarbonat) {
        m_mastiAchizitionate.push_back(new MascaPolicarbonat(*mascaPolicarbonat));
        return *this;
    }

    throw runtime_error("Tip de masca nedetectat.");
}

Achizitie &Achizitie::operator=(const Achizitie &other) {
    if (this != &other) {
        m_zi = other.m_zi;
        m_luna = other.m_luna;
        m_an = other.m_an;
        m_numeClient = other.m_numeClient;

        for (auto &it: m_dezinfectantiAchizitionati) {
            delete it;
        }
        for (auto &it: m_mastiAchizitionate) {
            delete it;
        }
        m_dezinfectantiAchizitionati.clear();
        m_mastiAchizitionate.clear();

        for (auto &it: other.m_dezinfectantiAchizitionati) {
            auto dezinfectantBacterii = dynamic_cast<DezinfectantBacterii *>(it);
            if (dezinfectantBacterii) {
                m_dezinfectantiAchizitionati.push_back(new DezinfectantBacterii(*dezinfectantBacterii));
                continue;
            }

            auto dezinfectantFungi = dynamic_cast<DezinfectantFungi *>(it);
            if (dezinfectantFungi) {
                m_dezinfectantiAchizitionati.push_back(new DezinfectantFungi(*dezinfectantFungi));
                continue;
            }

            auto dezinfectantVirusuri = dynamic_cast<DezinfectantVirusuri *>(it);
            if (dezinfectantVirusuri) {
                m_dezinfectantiAchizitionati.push_back(new DezinfectantVirusuri(*dezinfectantVirusuri));
                continue;
            }

            throw runtime_error("Tip de dezinfectant nedetectat.");
        }

        for (auto &it: other.m_mastiAchizitionate) {
            auto mascaChirurgicala = dynamic_cast<MascaChirurgicala *>(it);
            if (mascaChirurgicala) {
                m_mastiAchizitionate.push_back(new MascaChirurgicala(*mascaChirurgicala));
                continue;
            }

            auto mascaPolicarbonat = dynamic_cast<MascaPolicarbonat *>(it);
            if (mascaPolicarbonat) {
                m_mastiAchizitionate.push_back(new MascaPolicarbonat(*mascaPolicarbonat));
                continue;
            }

            throw runtime_error("Tip de masca nedetectat.");
        }
    }
    return *this;
}

Achizitie::~Achizitie() {
    for (auto &it: m_dezinfectantiAchizitionati) {
        delete it;
    }
    for (auto &it: m_mastiAchizitionate) {
        delete it;
    }
    m_dezinfectantiAchizitionati.clear();
    m_mastiAchizitionate.clear();
}

double Achizitie::getValoareFactura() const {
    double valoare = 0;
    for (auto &it: m_dezinfectantiAchizitionati) {
        valoare += it->getPret();
    }
    for (auto &it: m_mastiAchizitionate) {
        valoare += it->getPret();
    }
    return valoare;
}

bool Achizitie::operator<(const Achizitie &other) const {
    return getValoareFactura() < other.getValoareFactura();
}

bool Achizitie::operator>(const Achizitie &other) const {
    return other < *this;
}

bool Achizitie::operator<=(const Achizitie &other) const {
    return !(other < *this);
}

bool Achizitie::operator>=(const Achizitie &other) const {
    return !(*this < other);
}

bool Achizitie::operator==(const Achizitie &other) const {
    return getValoareFactura() == other.getValoareFactura();
}

bool Achizitie::operator!=(const Achizitie &other) const {
    return !(other == *this);
}
