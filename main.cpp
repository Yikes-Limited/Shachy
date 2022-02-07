#include <iostream>

using namespace std;

class Figura
{
public:
    int x; // A - H
    int y; // 1 - 8
    string rodzaj;
    char kolor; // B/C
    bool tyl;
    bool zbita;

    Figura(int x = 10, int y = 10, string rodzaj = "xyz", char kolor = 'x', bool tyl = true, bool zbita = false)
    {
        this->x = x;
        this->y = y;
        this->rodzaj = rodzaj;
        this->kolor = kolor;
        this->tyl = tyl;
        this->zbita = zbita;
    }
};
// czarne
Figura *KrolC = new Figura(4, 1, "krol", 'c', true, false);
Figura *DamaC = new Figura(5, 1, "krol", 'c', true, false);

// biale
Figura *KrolB = new Figura(4, 8, "krol", 'b', true, false);
Figura *DamaB = new Figura(5, 8, "krol", 'b', true, false);

Figura Szachownica[8][8];

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