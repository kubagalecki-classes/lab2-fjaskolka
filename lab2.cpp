#include <iostream>
using namespace std;

class Wektor
{
private:
    double* tablica;
    // double* tablica_pom;
    int    dlugosc;
    double pojemnosc;

public:
    Wektor(int dl_pom) : dlugosc(dl_pom), pojemnosc(dl_pom)
    {
        // dlugosc   = dl_pom;
        // pojemnosc = dl_pom;
        tablica = new double[dlugosc];
        for (int i = 0; i < dlugosc; i++) {
            tablica[i] = 1.;
        }
    }

    void print()
    {
        cout << endl;
        for (int j = 0; j < pojemnosc; j++) {
            cout << j + 1 << " element wektora = " << tablica[j] << endl;
        }
    }
    int get_dlugosc() { return dlugosc; }
    int get_pojemnosc() { return pojemnosc; }

    void zmienDlugosc(int dlugosc_n)
    {
        if (dlugosc_n <= pojemnosc) {
            for (int k = dlugosc_n; k < dlugosc; k++) {
                tablica[k] = 0.;
            }
            dlugosc = dlugosc_n;
        }
        else {
            double* tablica_pom = new double[dlugosc_n];
            for (int i = 0; i < dlugosc; i++) {
                tablica_pom[i] = tablica[i];
            }
            for (int j = dlugosc; j < dlugosc_n; j++) {
                tablica_pom[j] = 2.;
            }
            delete[] tablica;
            dlugosc   = dlugosc_n;
            pojemnosc = dlugosc_n;
            // tablica   = new double[dlugosc];
            // tablica = tablica_pom;
            for (int k = 0; k < dlugosc; k++) {
                tablica[k] = tablica_pom[k];
            }
            delete[] tablica_pom;
        }
    }
    double& operator[](int indeks)
    {
        if (indeks < pojemnosc) {
            return tablica[indeks];
        }
        else {
            cout << "opis bledu - wyjscie poza tablice" << endl;
            zmienDlugosc(indeks + 1);

            return tablica[indeks];
        }
    }
    ~Wektor()
    {
        delete[] tablica;
        cout << "Zwolniono pamiec wektora o dlugosci " << dlugosc << " i pojemnosci " << pojemnosc
             << endl;
    }
};

int main()
{
    Wektor a(3);
    cout << "dlugosc wektora = " << a.get_dlugosc() << endl;
    cout << "pojemnosc wektora = " << a.get_pojemnosc() << endl;
    a.print();
    cout << a.get_dlugosc() << endl;
    cout << a.get_pojemnosc() << endl;
    a.zmienDlugosc(2);
    a.print();
    cout << a.get_dlugosc() << endl;
    cout << a.get_pojemnosc() << endl;
    a.zmienDlugosc(4);
    a.print();
    cout << a.get_dlugosc() << endl;
    cout << a.get_pojemnosc() << endl;
    cout << a[3] << endl;
    cout << a[20] << endl << endl;
    a.print();
    return 0;
}