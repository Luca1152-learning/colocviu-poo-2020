#ifndef COLOCVIU_POO_2020_MASCA_H
#define COLOCVIU_POO_2020_MASCA_H

#include <string>
#include <utility>
#include "../Produs.h"

using namespace std;

class Masca : public Produs {
public:
    double getPret() const override {
        if (m_tipProtectie == "ffp1") {
            return 5;
        } else if (m_tipProtectie == "ffp2") {
            return 10;
        } else if (m_tipProtectie == "ffp3") {
            return 15;
        }
        return 0;
    }

    virtual ~Masca() = default;

protected:
    string m_tipProtectie, m_culoare;

    Masca(string tipProtectie, string culoare) :
            m_tipProtectie(move(tipProtectie)), m_culoare(move(culoare)) {
    }
};

#endif //COLOCVIU_POO_2020_MASCA_H
