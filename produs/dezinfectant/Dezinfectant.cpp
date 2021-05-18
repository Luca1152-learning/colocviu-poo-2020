#include "Dezinfectant.h"

double Dezinfectant::getPret() const {
    double eficienta = getEficienta();
    if (eficienta < 0.90) {
        return 10;
    } else if (eficienta < 0.95) {
        return 20;
    } else if (eficienta < 0.975) {
        return 30;
    } else if (eficienta < 0.99) {
        return 40;
    } else if (eficienta < 0.9999) {
        return 50;
    } else {
        throw runtime_error("Pentru eficienta " + to_string(eficienta) + " nu a fost stabilit un pret.");
    }
}

ostream &operator<<(ostream &out, const Dezinfectant &dezinfectant) {
    out << "Dezinfectant. "
        << "Specii ucise: " << dezinfectant.m_nrSpeciiUcise
        << " | Eficienta: " << dezinfectant.getEficienta() * 100 << "%"
        << " | Ingrediente: ";
    for (auto &it: dezinfectant.m_ingrediente) {
        out << it << " ";
    }
    out << "| Suprafete: ";
    for (auto &it: dezinfectant.m_suprafete) {
        out << it << " ";
    }
    return out;
}

istream &operator>>(istream &in, Dezinfectant &dezinfectant) {
    cout << "Nr. specii ucise: ";
    in >> dezinfectant.m_nrSpeciiUcise;

    dezinfectant.m_ingrediente.clear();
    in.get();
    for (int i = 1;; i++) {
        cout << "Ingredient " << i << ": ";
        string ingredient;
        getline(in, ingredient);
        if (ingredient.empty()) {
            break;
        } else {
            dezinfectant.m_ingrediente.push_back(ingredient);
        }
    }

    dezinfectant.m_suprafete.clear();
    in.get();
    for (int i = 1;; i++) {
        cout << "Suprafata " << i << ": ";
        string suprafata;
        getline(in, suprafata);
        if (suprafata.empty()) {
            break;
        } else {
            dezinfectant.m_suprafete.push_back(suprafata);
        }
    }

    return in;
}

vector<string> &Dezinfectant::getIngrediente() {
    return m_ingrediente;
}

vector<string> &Dezinfectant::getSuprafete() {
    return m_suprafete;
}

void Dezinfectant::setNrSpeciiUcise(double nr) {
    m_nrSpeciiUcise = nr;
}

Dezinfectant::Dezinfectant(double nrSpeciiUcise, const vector<string> &ingrediente, const vector<string> &suprafete)
        : m_nrSpeciiUcise(nrSpeciiUcise), m_ingrediente(ingrediente), m_suprafete(suprafete) {
}
