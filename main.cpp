#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Calc {
    string monitor;
    double procesor;
    int ram;
    string placa;
    string hdd;
    Calc *next;
};

Calc *head = NULL;

Calc *citeste() {
    Calc *c = new Calc;
    cout << "Monitor: ";
    cin >> c->monitor;
    cout << "Procesor (GHz): ";
    cin >> c->procesor;
    cout << "Memorie operativa: ";
    cin >> c->ram;
    cout << "Placa video: ";
    cin >> c->placa;
    cout << "Hard disk: ";
    cin >> c->hdd;
    c->next = NULL;
    return c;
}

void adaugaSfarsit(Calc *c) {
    c->next = NULL;
    if (!head) {
        head = c;
        return;
    }
    Calc *p = head;
    while (p->next)
        p = p->next;
    p->next = c;
}

void adaugaInceput(Calc *c) {
    c->next = head;
    head = c;
}

void insereaza(Calc *c, int poz) {
    if (poz <= 1 || !head) {
        adaugaInceput(c);
        return;
    }
    Calc *p = head;
    for (int i = 1; i < poz - 1 && p->next; i++)
        p = p->next;
    c->next = p->next;
    p->next = c;
}

void afisare1(Calc *p) {
    cout << p->monitor << " | " << p->procesor << " | " << p->ram << " | " << p->placa << " | "
         << p->hdd << endl;
}

void afisare() {
    if (!head) {
        cout << "Lista este goala.\n";
        return;
    }
    for (Calc *p = head; p; p = p->next)
        afisare1(p);
}

void afisareMonitor(string m) {
    bool gasit = false;
    for (Calc *p = head; p; p = p->next)
        if (p->monitor == m) {
            afisare1(p);
            gasit = true;
        }
    if (!gasit) cout << "Nu exista.\n";
}

void sorteaza() {
    for (Calc *i = head; i; i = i->next)
        for (Calc *j = i->next; j; j = j->next)
            if (i->procesor > j->procesor) {
                swap(i->monitor, j->monitor);
                swap(i->procesor, j->procesor);
                swap(i->ram, j->ram);
                swap(i->placa, j->placa);
                swap(i->hdd, j->hdd);
            }
}

void sterge() {
    while (head && head->ram < 124) {
        Calc *t = head;
        head = head->next;
        delete t;
    }
    Calc *p = head;
    while (p && p->next) {
        if (p->next->ram < 124) {
            Calc *t = p->next;
            p->next = t->next;
            delete t;
        } else
            p = p->next;
    }
}

void citesteFisier() {
    ifstream f("calculatoare.txt");
    if (!f) {
        cout << "Fisierul nu a putut fi deschis.\n";
        return;
    }
    while (true) {
        Calc *c = new Calc;
        if (!(f >> c->monitor >> c->procesor >> c->ram >> c->placa >> c->hdd)) {
            delete c;
            break;
        }
        adaugaSfarsit(c);
    }
    f.close();
}

int main() {
    int opt;
    do {
        cout << "\n1. Citirea listei din fisier\n"
             << "2. Adaugare la inceput\n"
             << "3. Adaugare la sfarsit\n"
             << "4. Inserare pe pozitie\n"
             << "5. Afisarea tuturor calculatoarelor\n"
             << "6. Afisare dupa tip monitor\n"
             << "7. Sortare dupa capacitatea procesorului\n"
             << "8. Stergere calculatoare cu memorie < 124\n"
             << "0. Iesire\n"
             << "Optiunea: ";
        cin >> opt;
        switch (opt) {
        case 1:
            citesteFisier();
            break;
        case 2:
            adaugaInceput(citeste());
            break;
        case 3:
            adaugaSfarsit(citeste());
            break;
        case 4: {
            int poz;
            cout << "Pozitia: ";
            cin >> poz;
            insereaza(citeste(), poz);
            break;
        }
        case 5:
            afisare();
            break;
        case 6: {
            string m;
            cout << "Monitor: ";
            cin >> m;
            afisareMonitor(m);
            break;
        }
        case 7:
            sorteaza();
            break;
        case 8:
            sterge();
            break;
        }
    } while (opt != 0);
    return 0;
}
