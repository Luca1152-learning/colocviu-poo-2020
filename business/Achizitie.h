#ifndef COLOCVIU_POO_2020_ACHIZITIE_H
#define COLOCVIU_POO_2020_ACHIZITIE_H

#include <string>
#include <vector>
#include "../produs/dezinfectant/Dezinfectant.h"
#include "../produs/dezinfectant/DezinfectantBacterii.h"
#include "../produs/dezinfectant/DezinfectantFungi.h"
#include "../produs/dezinfectant/DezinfectantVirusuri.h"
#include "../produs/masca/Masca.h"
#include "../produs/masca/MascaChirurgicala.h"
#include "../produs/masca/MascaPolicarbonat.h"

using namespace std;

class Achizitie {
public:
    explicit Achizitie(int zi = 1, int luna = 1, int an = 1970, string numeClient = "Default") :
            m_zi(zi), m_luna(luna), m_an(an), m_numeClient(move(numeClient)) {
    }

    vector<Dezinfectant *> getDezinfectantiAchizitionati() {
        return m_dezinfectantiAchizitionati;
    }

    vector<Masca *> getMastiAchizitionate() {
        return m_mastiAchizitionate;
    }

    Achizitie(const Achizitie &achizitie) {
        *this = achizitie;
    }

    string getNumeClient() const {
        return m_numeClient;
    }

    int getZiAchizitie() const {
        return m_zi;
    }

    int getLunaAchizitie() const {
        return m_luna;
    }

    int getAnAchizitie() const {
        return m_an;
    }

    Achizitie &operator+=(Dezinfectant *dezinfectant) {
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

    Achizitie &operator+=(Masca *masca) {
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

    Achizitie &operator=(const Achizitie &other) {
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

    ~Achizitie() {
        for (auto &it: m_dezinfectantiAchizitionati) {
            delete it;
        }
        for (auto &it: m_mastiAchizitionate) {
            delete it;
        }
        m_dezinfectantiAchizitionati.clear();
        m_mastiAchizitionate.clear();
    }

    double getValoareFactura() const {
        double valoare = 0;
        for (auto &it: m_dezinfectantiAchizitionati) {
            valoare += it->getPret();
        }
        for (auto &it: m_mastiAchizitionate) {
            valoare += it->getPret();
        }
        return valoare;
    }

    bool operator<(const Achizitie &other) const {
        return getValoareFactura() < other.getValoareFactura();
    }

    bool operator>(const Achizitie &other) const {
        return other < *this;
    }

    bool operator<=(const Achizitie &other) const {
        return !(other < *this);
    }

    bool operator>=(const Achizitie &other) const {
        return !(*this < other);
    }

    bool operator==(const Achizitie &other) const {
        return getValoareFactura() == other.getValoareFactura();
    }

    bool operator!=(const Achizitie &other) const {
        return !(other == *this);
    }

private:
    int m_zi, m_luna, m_an;
    string m_numeClient;

    vector<Dezinfectant *> m_dezinfectantiAchizitionati;
    vector<Masca *> m_mastiAchizitionate;
};

#endif //COLOCVIU_POO_2020_ACHIZITIE_H
