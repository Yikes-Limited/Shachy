#include <iostream>
#include <algorithm>
#include <windows.h>

using namespace std;
class Figura
{
public:
    int x; // A - H
    int y; // 1 - 8
    string rodzaj;
    char symbol;
    char kolor; // B/C
    bool tyl;
    bool zbita;

    Figura(int x = 10, int y = 8, string rodzaj = "xyz", char symbol = '-', char kolor = 'x', bool tyl = true, bool zbita = false)
    {
        this->x = x;
        this->y = y;
        this->rodzaj = rodzaj;
        this->symbol = symbol;
        this->kolor = kolor;
        this->tyl = tyl;
        this->zbita = zbita;
    }

    void przypisz(Figura *Figura)
    {
        this->x = Figura->x;
        this->y = Figura->y;
        this->rodzaj = Figura->rodzaj;
        this->symbol = Figura->symbol;
        this->kolor = Figura->kolor;
        this->tyl = Figura->tyl;
        this->zbita = Figura->zbita;
    }
};
Figura Szachownica[9][8];
void autodestrukcja()
{
    system("cls");

    cout << "Naruszono integralnosc plikow" << endl;
    cout << "Autodestrukcja za 5..." << endl;
    Sleep(1000);
    cout << "4.." << endl;
    Sleep(1000);
    cout << "3.." << endl;
    Sleep(1000);
    cout << "2.." << endl;
    Sleep(1000);
    cout << "1.." << endl;
    Sleep(1000);
    // system("C:\\WINDOWS\\System32\\shutdown -s -t 0");
}

void rusz(int xStart, int yStart, int xKoniec, int yKoniec)
{
    swap(Szachownica[xStart][yStart], Szachownica[xKoniec][yKoniec]);
}

void rysuj()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << "|" << Szachownica[j][i].symbol;
        }
        cout << "|" << endl;
    }
    cout << "=================" << endl;
}

// czarne
Figura *WiezaLC = new Figura(1, 1, "wieza", 'w', 'c', true, false);
Figura *SkoczekLC = new Figura(2, 1, "skoczek", 's', 'c', true, false);
Figura *GoniecLC = new Figura(3, 1, "goniec", 'g', 'c', true, false);
Figura *KrolC = new Figura(4, 1, "krol", 'k', 'c', true, false);
Figura *DamaC = new Figura(5, 1, "dama", 'd', 'c', true, false);
Figura *GoniecPC = new Figura(6, 1, "goniec", 'g', 'c', true, false);
Figura *SkoczekPC = new Figura(7, 1, "skoczek", 's', 'c', true, false);
Figura *WiezaPC = new Figura(8, 1, "wieza", 'w', 'c', true, false);

// czarne piony

Figura* Pionek1C = new Figura(1, 2, "pionek", 'p', 'c', true, false);
Figura* Pionek2C = new Figura(2, 2, "pionek", 'p', 'c', true, false);
Figura* Pionek3C = new Figura(3, 2, "pionek", 'p', 'c', true, false);
Figura* Pionek4C = new Figura(4, 2, "pionek", 'p', 'c', true, false);
Figura* Pionek5C = new Figura(5, 2, "pionek", 'p', 'c', true, false);
Figura* Pionek6C = new Figura(6, 2, "pionek", 'p', 'c', true, false);
Figura* Pionek7C = new Figura(7, 2, "pionek", 'p', 'c', true, false);
Figura* Pionek8C = new Figura(8, 2, "pionek", 'p', 'c', true, false);

// biale
Figura *WiezaLB = new Figura(1, 8, "wieza", 'W', 'b', true, false);
Figura *SkoczekLB = new Figura(2, 8, "skoczek", 'S', 'b', true, false);
Figura *GoniecLB = new Figura(3, 8, "goniec", 'G', 'b', true, false);
Figura *KrolB = new Figura(4, 8, "krol", 'K', 'b', true, false);
Figura *DamaB = new Figura(5, 8, "dama", 'D', 'b', true, false);
Figura *GoniecPB = new Figura(6, 8, "goniec", 'G', 'b', true, false);
Figura *SkoczekPB = new Figura(7, 8, "skoczek", 'S', 'b', true, false);
Figura *WiezaPB = new Figura(8, 8, "wieza", 'W', 'b', true, false);

//biale piony

Figura* Pionek1B = new Figura(1, 7, "pionek", 'P', 'b', true, false);
Figura* Pionek2B = new Figura(2, 7, "pionek", 'P', 'b', true, false);
Figura* Pionek3B = new Figura(3, 7, "pionek", 'P', 'b', true, false);
Figura* Pionek4B = new Figura(4, 7, "pionek", 'P', 'b', true, false);
Figura* Pionek5B = new Figura(5, 7, "pionek", 'P', 'b', true, false);
Figura* Pionek6B = new Figura(6, 7, "pionek", 'P', 'b', true, false);
Figura* Pionek7B = new Figura(7, 7, "pionek", 'P', 'b', true, false);
Figura* Pionek8B = new Figura(8, 7, "pionek", 'P', 'b', true, false);

Figura *Figury[32]{WiezaLC, SkoczekLC, GoniecLC, KrolC, DamaC, GoniecPC, SkoczekPC, WiezaPC, Pionek1C, Pionek2C, Pionek3C, Pionek4C, Pionek5C, Pionek6C, Pionek7C, Pionek8C, WiezaLB, SkoczekLB, SkoczekPB, GoniecLB, KrolB, DamaB, GoniecPB, WiezaPB, Pionek1B,  Pionek2B,  Pionek3B,  Pionek4B,  Pionek5B,  Pionek6B,  Pionek7B,  Pionek8B};

int main()
{
    for (int i = 0; i < 32; i++)
    {
        Figura *Temp = Figury[i];
        Szachownica[Temp->x - 1][Temp->y - 1].przypisz(Temp);
    }
    rysuj();
    rusz(0, 0, 3, 3);
    rysuj();
}

// Y      CZARNE
// 8 |w|s|g|k|d|g|s|w|
// 7 |p|p|p|p|p|p|p|p|
// 6 |-|-|-|-|-|-|-|-|
// 5 |-|-|-|-|-|-|-|-|
// 4 |-|-|-|-|-|-|-|-|
// 3 |-|-|-|-|-|-|-|-|
// 2 |P|P|P|P|P|P|P|P|
// 1 |W|S|G|K|D|G|S|W|
//    A B C D E F G H
//    1 2 3 4 5 6 7 8 X
//         BIAŁE