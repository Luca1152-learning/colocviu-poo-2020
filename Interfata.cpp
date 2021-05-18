#include "Interfata.h"

bool Interfata::primesteComanda() {
    int comanda;
    while (true) {
        cout << "(1) Adauga un nou dezinfectant in stoc\n"
             << "(2) Adauga o noua masca in stoc\n"
             << "(3) Adauga o noua achizitie\n"
             << "(4) Afiseaza dezinfectantul cel mai eficient\n"
             << "(5) Calculeaza venitul dintr-o anumita luna\n"
             << "(6) Calculeaza venitul obtinut din mastile chirurgicale cu model\n"
             << "(7) Modifica reteta unui dezinfectant\n"
             << "(8) Afiseaza cel mai fidel client\n"
             << "(9) Afiseaza cea mai slaba zi\n"
             << "(10) Calculeaza TVA-ul pentru un anumit an\n"
             << "(11) Opreste programul\n"
             << "Alegeti comanda (1-10): ";
        if (cin >> comanda && comanda >= 1 && comanda <= 11) {
            break;
        } else {
            cout << "\n[!] Comanda nerecunoscuta.\n\n";
            cin.clear();
            cin.ignore(256, '\n');
        }
    }

    if (comanda == 1) {
        adaugaDezinfectantInStoc();
    } else if (comanda == 2) {
        adaugaMascaInStoc();
    } else if (comanda == 3) {
        cout << "\n";
        int zi, luna, an;
        cout << "Zi: ";
        cin >> zi;
        cout << "Luna: ";
        cin >> luna;
        cout << "An: ";
        cin >> an;
        cout << "Nume client: ";
        cin.get();
        string numeClient;
        getline(cin, numeClient);
        adaugaAchizitie(new Achizitie(zi, luna, an, numeClient));
    } else if (comanda == 4) {
        cout << "\n" << *m_producator.getCelMaiEficientDezinfectant() << "\n\n";
    } else if (comanda == 5) {
        cout << "\n";
        int luna, an;
        cout << "Luna: ";
        cin >> luna;
        cout << "An: ";
        cin >> an;
        cout << "\n" << m_producator.getVenitLuna(luna, an) << " lei\n\n";
    } else if (comanda == 6) {
        cout << "\n" << m_producator.getVenitMastiChirurgicaleCuModel() << " lei\n\n";
    } else if (comanda == 7) {
        m_producator.modificaRetetaDezinfectant();
    } else if (comanda == 8) {
        cout << "\nCel mai fidel client este: " << m_producator.getCelMaiFidelClient() << "\n\n";
    } else if (comanda == 9) {
        cout << "\n";
        m_producator.afiseazaCeaMaiSlabaZi();
        cout << "\n\n";
    } else if (comanda == 10) {
        cout << "\n";
        int an;
        cout << "An: ";
        cin >> an;
        cout << "\n" << m_producator.getTVA(an) << " lei\n\n";
    } else {
        return false;
    }

    cout << "\n";
    return true;
}

void Interfata::adaugaDezinfectantInStoc() {
    cout << "\n";
    cout << "(1) Dezinfectant bacterii\n"
         << "(2) Dezinfectant fungi\n"
         << "(3) Dezinfectant virusuri\n"
         << "Alegeti tipul de dezinfectant (1-3): ";
    int comanda;
    cin >> comanda;
    Dezinfectant *dezinfectant;
    cout << "\n";
    if (comanda == 1) {
        dezinfectant = new DezinfectantBacterii();
    } else if (comanda == 2) {
        dezinfectant = new DezinfectantFungi();
    } else {
        dezinfectant = new DezinfectantVirusuri();
    }
    cin >> *dezinfectant;
    m_producator.adaugaDezinfectant(dezinfectant);
}

void Interfata::adaugaMascaInStoc() {
    cout << "\n";
    cout << "(1) Masca chirurgicala\n"
         << "(2) Masca policarbonat\n"
         << "Alegeti tipul de masca (1-3): ";
    int comanda;
    cin >> comanda;
    Masca *masca;
    cout << "\n";
    if (comanda == 1) {
        masca = new MascaChirurgicala();
        cin >> *((MascaChirurgicala *) masca);
    } else {
        masca = new MascaPolicarbonat();
        cin >> *((MascaPolicarbonat *) masca);
    }
    m_producator.adaugaMasca(masca);
}

void Interfata::adaugaAchizitie(Achizitie *achizitie) {
    cout << "\n";
    cout << "(1) Masca\n"
         << "(2) Dezinfectant\n"
         << "(3) Opreste achizitia\n"
         << "Alegeti tipul de produs: ";
    int comanda;
    cin >> comanda;

    if (comanda == 1) {
        cout << "\n";
        auto masti = m_producator.getMasti();
        for (int i = 0; i < masti.size(); i++) {
            cout << "(" << i + 1 << ") " << (*masti[i]) << "\n";
        }
        cout << "Alegeti masca dorita (1-" << masti.size() << "): ";
        int alegere;
        cin >> alegere;
        (*achizitie) += masti[alegere - 1];
        adaugaAchizitie(achizitie);
    } else if (comanda == 2) {
        cout << "\n";
        auto dezinfectanti = m_producator.getDezinfectanti();
        for (int i = 0; i < dezinfectanti.size(); i++) {
            cout << "(" << i + 1 << ") " << (*dezinfectanti[i]) << "\n";
        }
        cout << "Alegeti dezinfectantul dorit (1-" << dezinfectanti.size() << "): ";
        int alegere;
        cin >> alegere;
        (*achizitie) += dezinfectanti[alegere - 1];
        adaugaAchizitie(achizitie);
    } else {
        m_producator.adaugaAchizitie(achizitie);
        return;
    }
}

void Interfata::primesteComenzi() {
    while (primesteComanda());
}
