#include "Producator.h"

vector<Achizitie *> &Producator::getAchizitii() {
    return m_achizitii;
}

void Producator::adaugaDezinfectant(Dezinfectant *dezinfectant) {
    m_dezinfectanti.push_back(dezinfectant);
}

void Producator::adaugaMasca(Masca *masca) {
    m_masti.push_back(masca);
}

void Producator::adaugaAchizitie(Achizitie *achizitie) {
    m_achizitii.push_back(achizitie);
}

Dezinfectant *Producator::getCelMaiEficientDezinfectant() {
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

double Producator::getVenitLuna(int luna, int an) {
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

double Producator::getVenitMastiChirurgicaleCuModel() {
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

void Producator::modificaRetetaDezinfectant() {
    cout << "\n";
    auto dezinfectanti = getDezinfectanti();
    for (int i = 0; i < dezinfectanti.size(); i++) {
        cout << "(" << i + 1 << ") " << (*dezinfectanti[i]) << "\n";
    }
    cout << "Alegeti dezinfectantul dorit (1-" << dezinfectanti.size() << "): ";
    int alegere;
    cin >> alegere;

    auto dezinfectant = dezinfectanti[alegere - 1];

    dezinfectant->getIngrediente().clear();
    cin.get();
    for (int i = 1;; i++) {
        cout << "Ingredient " << i << ": ";
        string ingredient;
        getline(cin, ingredient);
        if (ingredient.empty()) {
            break;
        } else {
            dezinfectant->getIngrediente().push_back(ingredient);
        }
    }

    cout << "Nou nr. specii ucise: ";
    int nr;
    cin >> nr;
    dezinfectant->setNrSpeciiUcise(nr);

    dezinfectant->getSuprafete().clear();
    cin.get();
    for (int i = 1;; i++) {
        cout << "Suprafata " << i << ": ";
        string suprafata;
        getline(cin, suprafata);
        if (suprafata.empty()) {
            break;
        } else {
            dezinfectant->getSuprafete().push_back(suprafata);
        }
    }
}

string Producator::getCelMaiFidelClient() {
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

void Producator::afiseazaCeaMaiSlabaZi() {
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

double Producator::getTVA(int an) {
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

Producator::~Producator() {
    for (auto &it: m_achizitii) {
        delete it;
    }
    m_achizitii.clear();

    for (auto &it: m_dezinfectanti) {
        delete it;
    }
    m_dezinfectanti.clear();

    for (auto &it: m_masti) {
        delete it;
    }
    m_masti.clear();
}

vector<Dezinfectant *> &Producator::getDezinfectanti() {
    return m_dezinfectanti;
}

vector<Masca *> Producator::getMasti() {
    return m_masti;
}
