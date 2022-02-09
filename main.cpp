#include <iostream>

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
// czarne
Figura *WiezaLC = new Figura(1, 1, "wieza", 'w', 'c', true, false);
Figura *SkoczekLC = new Figura(2, 1, "skoczek", 's', 'c', true, false);
Figura *GoniecLC = new Figura(3, 1, "goniec", 'g', 'c', true, false);
Figura *KrolC = new Figura(4, 1, "krol", 'k', 'c', true, false);
Figura *DamaC = new Figura(5, 1, "dama", 'd', 'c', true, false);
Figura *GoniecPC = new Figura(6, 1, "goniec", 'g', 'c', true, false);
Figura *SkoczekPC = new Figura(7, 1, "skoczek", 's', 'c', true, false);
Figura *WiezaPC = new Figura(8, 1, "wieza", 'w', 'c', true, false);

// biale
Figura *WiezaLB = new Figura(1, 8, "wieza", 'W', 'b', true, false);
Figura *SkoczekLB = new Figura(2, 8, "skoczek", 'S', 'b', true, false);
Figura *GoniecLB = new Figura(3, 8, "goniec", 'G', 'b', true, false);
Figura *KrolB = new Figura(4, 8, "krol", 'K', 'b', true, false);
Figura *DamaB = new Figura(5, 8, "dama", 'D', 'b', true, false);
Figura *GoniecPB = new Figura(6, 8, "goniec", 'G', 'b', true, false);
Figura *SkoczekPB = new Figura(7, 8, "skoczek", 'S', 'b', true, false);
Figura *WiezaPB = new Figura(8, 8, "wieza", 'W', 'b', true, false);

Figura *Figury[16]{WiezaLC, SkoczekLC, GoniecLC, KrolC, DamaC, GoniecPC, SkoczekPC, WiezaPC, WiezaLB, SkoczekLB, SkoczekPB, GoniecLB, KrolB, DamaB, GoniecPB, WiezaPB};

Figura Szachownica[9][8];

// Y       BIAŁE
// 8 |W|S|G|K|D|G|S|W|
// 7 |P|P|P|P|P|P|P|P|
// 6 |-|-|-|-|-|-|-|-|
// 5 |-|-|-|-|-|-|-|-|
// 4 |-|-|-|-|-|-|-|-|
// 3 |-|-|-|-|-|-|-|-|
// 2 |p|p|p|p|p|p|p|p|
// 1 |w|s|g|k|d|g|s|w|
//    A B C D E F G H
//    1 2 3 4 5 6 7 8 X
//        CZARNE

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
}

int main()
{
    for (int i = 0; i < 16; i++)
    {
        Figura *Temp = Figury[i];
        Szachownica[Temp->x - 1][Temp->y - 1].przypisz(Temp);
    }
    rysuj();
}