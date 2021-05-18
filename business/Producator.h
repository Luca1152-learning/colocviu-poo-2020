#ifndef COLOCVIU_POO_2020_PRODUCATOR_H
#define COLOCVIU_POO_2020_PRODUCATOR_H

#include "Achizitie.h"
#include "../produs/dezinfectant/Dezinfectant.h"
#include "../produs/masca/Masca.h"
#include <unordered_map>

class Producator {
public:
    vector<Achizitie *> &getAchizitii() {
        return m_achizitii;
    }

    void adaugaDezinfectant(Dezinfectant *dezinfectant) {
        m_dezinfectanti.push_back(dezinfectant);
    }

    void adaugaMasca(Masca *masca) {
        m_masti.push_back(masca);
    }

    void adaugaAchizitie(Achizitie *achizitie) {
        m_achizitii.push_back(achizitie);
    }

    Dezinfectant *getCelMaiEficientDezinfectant() {
        double eficientaMax = 0;
        Dezinfectant *dezinfectantEficientaMax = nullptr;

        for (auto &it: m_dezinfectanti) {
            if (it->getEficienta() > eficientaMax) {
                eficientaMax = it->getEficienta();
                dezinfectantEficientaMax = it;
            }
        }

        return dezinfectantEficientaMax;
    }

    double getVenitLuna(int luna, int an) {
        double venit = 0;
        for (auto &it: m_achizitii) {
            if (it->getLunaAchizitie() == luna && it->getAnAchizitie() == an) {
                auto masti = it->getMastiAchizitionate();
                for (auto &masca: masti) {
                    venit += masca->getPret();
                }
                auto dezinfectanti = it->getDezinfectantiAchizitionati();
                for (auto &dezinfectant: dezinfectanti) {
                    venit += dezinfectant->getPret();
                }
            }
        }
        return venit;
    }

    double getVenitMastiChirurgicaleCuModel() {
        double venit = 0;
        for (auto &it: m_achizitii) {
            auto masti = it->getMastiAchizitionate();
            for (auto &masca: masti) {
                auto mascaChirurgicala = dynamic_cast<MascaChirurgicala *>(masca);
                if (mascaChirurgicala) {
                    if (mascaChirurgicala->areModel()) {
                        venit += mascaChirurgicala->getPret();
                    }
                }
            }
        }
        return venit;
    }

    void modificaRetetaDezinfectant() {
        // TODO
    }

    string getCelMaiFidelClient() {
        unordered_map<string, double> venitClient;
        for (auto &it: m_achizitii) {
            double venit = 0;
            auto masti = it->getMastiAchizitionate();
            for (auto &masca: masti) {
                venit += masca->getPret();
            }
            auto dezinfectanti = it->getDezinfectantiAchizitionati();
            for (auto &dezinfectant: dezinfectanti) {
                venit += dezinfectant->getPret();
            }
            venitClient[it->getNumeClient()] += venit;
        }

        double maxVenit = 0;
        string numeClientMaxVenit;

        for (auto &it: venitClient) {
            if (it.second > maxVenit) {
                maxVenit = it.second;
                numeClientMaxVenit = it.first;
            }
        }

        return numeClientMaxVenit;
    }

    void afiseazaCeaMaiSlabaZi() {
        unordered_map<string, double> venitZi;
        for (auto &it: m_achizitii) {
            double venit = 0;
            auto masti = it->getMastiAchizitionate();
            for (auto &masca: masti) {
                venit += masca->getPret();
            }
            auto dezinfectanti = it->getDezinfectantiAchizitionati();
            for (auto &dezinfectant: dezinfectanti) {
                venit += dezinfectant->getPret();
            }
            venitZi[to_string(it->getZiAchizitie()) + "/" + to_string(it->getLunaAchizitie()) + "/" +
                    to_string(it->getAnAchizitie())] += venit;
        }

        double minVenit = 0;
        string dataMinVenit;

        for (auto &it: venitZi) {
            if (it.second < minVenit) {
                minVenit = it.second;
                dataMinVenit = it.first;
            }
        }

        cout << dataMinVenit << " (" << minVenit << " lei)";
    }

    double getTVA(int an) {
        double venit = 0;
        for (auto &it: m_achizitii) {
            if (it->getAnAchizitie() == an) {
                auto masti = it->getMastiAchizitionate();
                for (auto &masca: masti) {
                    venit += masca->getPret();
                }
                auto dezinfectanti = it->getDezinfectantiAchizitionati();
                for (auto &dezinfectant: dezinfectanti) {
                    venit += dezinfectant->getPret();
                }
            }
        }
        return venit * 0.19;
    }

private:
    vector<Achizitie *> m_achizitii;
    vector<Dezinfectant *> m_dezinfectanti;
    vector<Masca *> m_masti;
};

#endif //COLOCVIU_POO_2020_PRODUCATOR_H
