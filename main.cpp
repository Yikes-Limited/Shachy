#include <iostream>

using namespace std;

class Figura
{
    int x; // A - H
    int y; // 1 - 8
    string rodzaj;
    bool tyl;
    bool zbita;

    Figura(int x = 10, int y = 10, string rodzaj = "xyz", bool tyl = true, bool zbita = false)
    {
        this->x = x;
        this->y = y;
        this->rodzaj = rodzaj;
        this->tyl = tyl;
        this->zbita = zbita;
    }
};