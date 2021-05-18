#ifndef COLOCVIU_POO_2020_MASCA_H
#define COLOCVIU_POO_2020_MASCA_H

#include <string>
#include <utility>
#include <ostream>
#include "../Produs.h"

using namespace std;

class Masca : public Produs {
public:
    double getPret() const override;

    virtual ~Masca() = default;

    friend ostream &operator<<(ostream &out, const Masca &masca);

protected:
    string m_tipProtectie, m_culoare;

    Masca(string tipProtectie, string culoare) :
            m_tipProtectie(move(tipProtectie)), m_culoare(move(culoare)) {
    }
};

#endif //COLOCVIU_POO_2020_MASCA_H
