#include <iostream>
#include "Figura.h"
using namespace std;

using namespace std;

class Figura
{
public:

    int x; // A - H
    int y; // 1 - 8
    char kolor; // B/C
    string rodzaj;
    char symbol;
    bool tyl;
    bool zbita;

    Figura()
    {
        this->x = 0;
        this->y = 0;
        this->rodzaj = " ";
        this->symbol = ' ';
        this->kolor = ' ';
        this->tyl = false;
        this->zbita = false;
    }

    Figura(int x, int y, string rodzaj, char symbol, char kolor, bool tyl, bool zbita)
    {
        this->x = x;
        this->y = y;
        this->rodzaj = rodzaj;
        this->symbol = symbol;
        this->kolor = kolor;
        this->tyl = tyl;
        this->zbita = zbita;
    }

    void przepisz(Figura* figura)
    {
        this->x = figura->x;
        this->y = figura->y;
        this->rodzaj = figura->rodzaj;
        this->symbol = figura->symbol;
        this->kolor = figura->kolor;
        this->tyl = figura->tyl;
        this->zbita = figura->zbita;
    }
};

// biale
Figura* WiezaLB = new Figura(1, 8, "wieza", 'W', 'b', true, false);
Figura* SkoczekLB = new Figura(2, 8, "skoczek", 'S', 'b', true, false);
Figura* GoniecLB = new Figura(3, 8, "goniec", 'G', 'b', true, false);
Figura* KrolB = new Figura(4, 8, "krol", 'K', 'b', true, false);
Figura* DamaB = new Figura(5, 8, "dama", 'D', 'b', true, false);
Figura* GoniecPB = new Figura(6, 8, "goniec", 'G', 'b', true, false);
Figura* SkoczekPB = new Figura(7, 8, "skoczek", 'S', 'b', true, false);
Figura* WiezaPB = new Figura(8, 8, "wieza", 'W', 'b', true, false);

// czarne
Figura* WiezaLC = new Figura(1, 1, "wieza", 'w', 'c', true, false);
Figura* SkoczekLC = new Figura(2, 1, "skoczek", 's', 'c', true, false);
Figura* GoniecLC = new Figura(3, 1, "goniec", 'g', 'c', true, false);
Figura *KrolC = new Figura(4, 1, "krol", 'k', 'c', true, false);
Figura *DamaC = new Figura(5, 1, "dama", 'd', 'c', true, false);
Figura *GoniecPC = new Figura(6, 1, "goniec", 'g', 'c', true, false);
Figura *SkoczekPC = new Figura(7, 1, "skoczek", 's', 'c', true, false);
Figura *WiezaPC = new Figura(8, 1, "wieza", 'w', 'c', true, false);

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

int main()
{
	Figura Szachownica[8][8];

	Szachownica[7][7].przepisz(WiezaPB);

	cout << Szachownica[7][7].rodzaj<<endl;
	cout << Szachownica[7][7].symbol<<endl;
	cout << Szachownica[0][0].symbol << endl;
}