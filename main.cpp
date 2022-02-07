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
};
Figura Szachownica[9][8];
// czarne
Figura *KrolC = new Figura(4, 1, "krol", 'k', 'c', true, false);
Figura *DamaC = new Figura(5, 1, "dama", 'd', 'c', true, false);
Figura *Goniec1C = new Figura(3, 1, "goniec", 'g', 'c', true, false);
Figura *Goniec2C = new Figura(6, 1, "goniec", 'g', 'c', true, false);
Figura *Skoczek1C = new Figura(2, 1, "skoczek", 's', 'c', true, false);
Figura *Skoczek2C = new Figura(7, 1, "skoczek", 's', 'c', true, false);
Figura *Wieza1C = new Figura(1, 1, "wieza", 'w', 'c', true, false);
Figura *Wieza2C = new Figura(8, 1, "wieza", 'w', 'c', true, false);

// biale
Figura *KrolB = new Figura(4, 8, "krol", 'K', 'b', true, false);
Figura *DamaB = new Figura(5, 8, "dama", 'D', 'b', true, false);
Figura *Goniec1B = new Figura(3, 8, "goniec", 'G', 'b', true, false);
Figura *Goniec2B = new Figura(6, 8, "goniec", 'G', 'b', true, false);
Figura *Skoczek1B = new Figura(2, 8, "skoczek", 'S', 'b', true, false);
Figura *Skoczek2B = new Figura(7, 8, "skoczek", 'S', 'b', true, false);
Figura *Wieza1B = new Figura(1, 8, "wieza", 'W', 'b', true, false);
Figura *Wieza2B = new Figura(8, 8, "wieza", 'W', 'b', true, false);

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
    cout << "Printf" << endl;
}